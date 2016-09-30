// Copyright 2016 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

/*******************************************************************************
*    This file is part of NUISANCE.
*
*    NUISANCE is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    NUISANCE is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#include "MINERvA_CCinc_XSec_1Dx_ratio.h"

//********************************************************************  
MINERvA_CCinc_XSec_1Dx_ratio::MINERvA_CCinc_XSec_1Dx_ratio(std::string name, std::string inputfiles, FitWeight *rw, std::string  type, std::string fakeDataFile){
//********************************************************************  

  // Setup The Measurement
  fName = name;
  nBins = 6;
  fPlotTitles = "; Reconstructed Bjorken x; d#sigma/dx (cm^{2}/nucleon)";
  fIsRatio = true;
  fIsDiag  = false; 
  target  = "";
  SetupMeasurement(inputfiles, type, rw, fakeDataFile);

  if      (name.find("C12")   != std::string::npos) target =   "C12";
  else if (name.find("Fe56")  != std::string::npos) target =  "Fe56";
  else if (name.find("Pb208") != std::string::npos) target = "Pb208";
  else ERR(WRN) << "target " << target << " was not found!" << std::endl;
  
  // Get parsed input files
  if (fSubInFiles.size() != 2) ERR(FTL) << "MINERvA CCinc ratio requires input files in format: NUMERATOR;DENOMINATOR"<<std::endl;
  std::string inFileNUM = fSubInFiles.at(0);
  std::string inFileDEN = fSubInFiles.at(1);
    
  // Push classes back into list for processing loop
  this->fSubChain.push_back(NUM);
  this->fSubChain.push_back(DEN);

  // Setup the Data input                          
  std::string basedir = FitPar::GetDataBase()+"/MINERvA/CCinc/";
  std::string datafilename  = "CCinc_"+target+"_CH_ratio_x_data.csv";
  std::string covarfilename = "CCinc_"+target+"_CH_ratio_x_covar.csv";

  this->SetDataValues( basedir + datafilename );
  this->SetCovarMatrixFromText( basedir + covarfilename, nBins);

  // Setup Experiments
  NUM  = new MINERvA_CCinc_XSec_1Dx_nu("MINERvA_CCinc_XSec_1Dx_"+target+"_CH_NUM", inFileNUM, rw, type, fakeDataFile);
  DEN  = new MINERvA_CCinc_XSec_1Dx_nu("MINERvA_CCinc_XSec_1Dx_"+target+"_CH_DEN", inFileDEN, rw, type, fakeDataFile);
 
  // Add to chain for processing
  this->fSubChain.clear();
  this->fSubChain.push_back(NUM);
  this->fSubChain.push_back(DEN);

  // Setup Default MC Hists
  this->SetupDefaultHist();

};

//********************************************************************  
void MINERvA_CCinc_XSec_1Dx_ratio::MakePlots(){
//********************************************************************  

  UInt_t sample = 0;
  for (std::vector<MeasurementBase*>::const_iterator expIter = this->fSubChain.begin(); expIter != this->fSubChain.end(); expIter++){
    MeasurementBase* exp = static_cast<MeasurementBase*>(*expIter);
 
    if      (sample == 0) this->NUM = static_cast<MINERvA_CCinc_XSec_1Dx_nu*>(exp);
    else if (sample == 1) this->DEN = static_cast<MINERvA_CCinc_XSec_1Dx_nu*>(exp);
    else break;
    sample++;
  }

  // Now make the ratio histogram
  TH1D* NUM_MC = (TH1D*)this->NUM->GetMCList().at(0)->Clone();
  TH1D* DEN_MC = (TH1D*)this->DEN->GetMCList().at(0)->Clone();

  for (int i=0; i < nBins; ++i){
    double binVal = 0;
    double binErr = 0;

    if (DEN_MC->GetBinContent(i+1) && NUM_MC->GetBinContent(i+1)) {
      binVal = NUM_MC->GetBinContent(i+1)/DEN_MC->GetBinContent(i+1);
      double fractErrNUM = NUM_MC->GetBinError(i+1)/NUM_MC->GetBinContent(i+1);
      double fractErrDEN = DEN_MC->GetBinError(i+1)/DEN_MC->GetBinContent(i+1);
      binErr = binVal*sqrt(fractErrNUM*fractErrNUM + fractErrDEN*fractErrDEN);
    }

    this->fMCHist->SetBinContent(i+1, binVal);
    this->fMCHist->SetBinError(i+1, binErr);
  }

  return;
}


//********************************************************************
void MINERvA_CCinc_XSec_1Dx_ratio::SetCovarMatrixFromText(std::string covarFile, int dim){
//********************************************************************

  // WARNING this reads in the data CORRELATIONS
  // Make a counter to track the line number
  int row = 0;

  std::string line;
  std::ifstream covar(covarFile.c_str(),ifstream::in);

  this->covar = new TMatrixDSym(dim);
  this->fullcovar = new TMatrixDSym(dim);
  if(covar.is_open()) LOG(SAM) << "Reading covariance matrix from file: " << covarFile << std::endl;
  else ERR(FTL) <<"Covariance matrix provided is incorrect: "<<covarFile<<std::endl;

  while(std::getline(covar, line, '\n')){
    std::istringstream stream(line);
    double entry;
    int column = 0;

    // Loop over entries and insert them into matrix
    // Multiply by the errors to get the covariance, rather than the correlation matrix
    while(stream >> entry){

      double val = entry * this->fDataHist->GetBinError(row+1)*this->fDataHist->GetBinError(column+1);

      (*this->covar)(row, column) = val;
      (*this->fullcovar)(row, column) = val;
      column++;
    }
    row++;
  }

  // Robust matrix inversion method
  TDecompSVD LU = TDecompSVD(*this->covar);
  this->covar = new TMatrixDSym(dim, LU .Invert().GetMatrixArray(), "");

  return;
};



//********************************************************************
void MINERvA_CCinc_XSec_1Dx_ratio::Write(std::string drawOpt){
//********************************************************************

  LOG(SAM)<<"Writing Normal Plots in MINERvA_CCinc_XSec_1Dx_ratio::Write()" <<std::endl;
  this->GetDataList().at(0)->Write();
  this->GetMCList()  .at(0)->Write();

  if (this->fullcovar){
    TH2D cov = TH2D((*this->fullcovar));
    cov.SetNameTitle((this->fName+"_cov").c_str(),(this->fName+"_cov;Bins; Bins;").c_str());
    cov.Write();
  }
  
  if (this->covar){
    TH2D covinv = TH2D((*this->covar));
    covinv.SetNameTitle((this->fName+"_covinv").c_str(),(this->fName+"_covinv;Bins; Bins;").c_str());
    covinv.Write();
  }

  return;
}
