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

#include "MicroBooNE_CC1Mu1p_XSec_1D_nu.h"
#include "MicroBooNE_SignalDef.h"
#include "TH2D.h"
#include "TH1D.h"
#include <Eigen/Dense>

Eigen::VectorXd MaskBin(Eigen::VectorXd const &inv, int bin_to_skip) {
  int nbins = inv.size();
  int nbins_masked = nbins - 1;
  int nbins_after = nbins_masked - bin_to_skip;

  Eigen::VectorXd data_masked = Eigen::VectorXd::Zero(nbins_masked);

  // e.g. inv = [1,2,3,4], bin_to_skip = 1

  // Assign the first bin_to_skip = 1 entries to keep
  data_masked.head(bin_to_skip) = inv.head(bin_to_skip);
  // Assign the last nbins_after = nbins_masked - bin_to_skip = 3 - 1 = 2;
  data_masked.tail(nbins_after) = inv.tail(nbins_after);

  return data_masked;
}

Eigen::MatrixXd MaskBin(Eigen::MatrixXd const &inm, int bin_to_skip) {
  int nbins = inm.rows();
  int nbins_masked = nbins - 1;
  int nbins_after = nbins_masked - bin_to_skip;

  Eigen::MatrixXd data_masked = Eigen::MatrixXd::Zero(nbins_masked, nbins_masked);

  data_masked.matrix().topLeftCorner(bin_to_skip, bin_to_skip) =
      inm.topLeftCorner(bin_to_skip, bin_to_skip);
  data_masked.matrix().topRightCorner(bin_to_skip, nbins_after) =
      inm.topRightCorner(bin_to_skip, nbins_after);
  data_masked.matrix().bottomLeftCorner(nbins_after, bin_to_skip) =
      inm.bottomLeftCorner(nbins_after, bin_to_skip);
  data_masked.matrix().bottomRightCorner(nbins_after, nbins_after) =
      inm.bottomRightCorner(nbins_after, nbins_after);
  return data_masked;
}

void MaskedChi2(Eigen::VectorXd const &data, Eigen::VectorXd const &prediction,
                Eigen::MatrixXd const &covar) {

  Eigen::VectorXd diff = (prediction - data);
  std::cout << "chi2 for all bins = "
            << (diff.transpose() * covar.inverse() * diff) << std::endl;

  for (int i = 0; i < data.size(); ++i) {
    Eigen::VectorXd masked_diff = MaskBin(diff, i);
    Eigen::MatrixXd masked_covar = MaskBin(covar, i);

    std::cout << "chi2 except bin[" << i << "] = "
              << (masked_diff.transpose() * masked_covar.inverse() *
                  masked_diff)
              << std::endl;
  }
}

Eigen::MatrixXd InflateCovarWithMCHistError(Eigen::MatrixXd const &inm, Eigen::VectorXd const &mc_stats_error) {
  Eigen::MatrixXd covar = inm;

  for(int i = 0; i < covar.rows(); ++i){
    covar(i,i) += std::pow(mc_stats_error[i],2);
  }
  return covar;
}

//********************************************************************
MicroBooNE_CC1Mu1p_XSec_1D_nu::MicroBooNE_CC1Mu1p_XSec_1D_nu(nuiskey samplekey) {
//********************************************************************
  fSettings = LoadSampleSettings(samplekey);
  std::cout<<"enetered fileMicroBooNE_CC1Mu1p_XSec_1D_nu.cc" <<std::endl;
  std::string name = fSettings.GetS("name");
  
//work out which sample you need, and set axii
  if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaPT_nu")) {
    fDist = kDeltaPT;
    objSuffix = "DeltaPT";
    fSettings.SetXTitle("#deltap_{T} (GeV/c)");
    fSettings.SetYTitle("d#sigma/d#deltap_{T} (cm^{2}/(GeV/c)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaAlphaT_nu")) {
    fDist = kDeltaAlphaT;
    objSuffix = "DeltaAlphaT";
    fSettings.SetXTitle("#delta#alpha_{T} (deg)");
    fSettings.SetYTitle("d#sigma/d#delta#alpha_{T} (cm^{2}/(deg)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaPhiT_nu")) {
    fDist = kDeltaPhiT;
    objSuffix = "DeltaPhiT";
    fSettings.SetXTitle("#delta#phi_{T} (deg)");
    fSettings.SetYTitle("d#sigma/d#delta#phi_{T} (cm^{2}/(deg)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DMuonCosTheta_nu")) {
    fDist = kMuonCosTheta;
    objSuffix = "MuonCosTheta";
    fSettings.SetXTitle("cos#theta_{#mu} (deg)");
    fSettings.SetYTitle("d#sigma/dcos#theta_{#mu} (cm^{2}/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DProtonCosTheta_nu")) {
    fDist = kProtonCosTheta;
    objSuffix = "ProtonCosTheta";
    fSettings.SetXTitle("cos#theta_{p} (deg)");
    fSettings.SetYTitle("d#sigma/dcos#theta_{p} (cm^{2}/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DMuonMomentum_nu")) {
    fDist = kMuonMomentum;
    objSuffix = "MuonMomentum";
    fSettings.SetXTitle("p_{#mu} (GeV/c)");
    fSettings.SetYTitle("d#sigma/dp_{#mu} (cm^{2}/(GeV/c)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaPn_nu")) {
    fDist = kDeltaPn;
    objSuffix = "DeltaPn";
    fSettings.SetXTitle("p_{n,proxy} (GeV/c)");
    fSettings.SetYTitle("d#sigma/dp_{n,proxy} (cm^{2}/(GeV/c)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaPtx_nu")) {
    fDist = kDeltaPtx;
    objSuffix = "DeltaPtx";
    fSettings.SetXTitle("#deltap_{T,x} (GeV/c)");
    fSettings.SetYTitle("d#sigma/d#deltap_{T,x} (cm^{2}/(GeV/c)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DDeltaPty_nu")) {
    fDist = kDeltaPty;
    objSuffix = "DeltaPty";
    fSettings.SetXTitle("#deltap_{T,y} (GeV/c)");
    fSettings.SetYTitle("d#sigma/d#deltap_{T,y} (cm^{2}/(GeV/c)/^{40}Ar)");
  }
  else if (!name.compare("MicroBooNE_CC1Mu1p_XSec_1DECal_nu")) {
    fDist = kECal;
    objSuffix = "ECal";
    fSettings.SetXTitle("E^{Cal} (GeV)");
    fSettings.SetYTitle("d#sigma/dE^{Cal} (cm^{2}/(GeV)/^{40}Ar)");
  }
  else {
    NUIS_ABORT("ARGHHH Didn’t get a valid name: " << name);
  }

  // Sample overview ---------------------------------------------------
  std::string descrip = name + " sample.\n" \
                        "Target: Ar\n" \
                        "Flux: BNB FHC numu\n" \
                        "Signal: CC1Mu1p\n";
  std::cout<<"string description: "<< descrip  <<std::endl;
  fSettings.SetDescription(descrip);
  fSettings.SetTitle(name);
  fSettings.SetAllowedTypes("FULL,DIAG/FREE,SHAPE,FIX/SYSTCOV/STATCOV", "FIX/FULL");
  fSettings.SetEnuRange(0.0, 6.8);
  fSettings.DefineAllowedTargets("Ar");
  fSettings.DefineAllowedSpecies("numu");
  FinaliseSampleSettings();
  
  // Load data ---------------------------------------------------------
  inputFile = FitPar::GetDataBase() + "/MicroBooNE/CC1Mu1p/All_XSecs_Combined_v08_00_00_52.root";
  SetDataFromRootFile(inputFile, "FullUnc_" + objSuffix + "Plot");
  ScaleData(1E-38);
  
  // ScaleFactor for DiffXSec/cm2/Nucleus // Already multiplied by the Ar mass number
  fScaleFactor = GetEventHistogram()->Integral("width") / fNEvents * 1E-38 / TotalIntegratedFlux() * 40;

  SetCovarFromRootFile(inputFile, "UnfCov_" + objSuffix + "Plot");

  // Set up the additional smearing matrix Ac
  // All the MC predictions need to be multiplied by Ac to move to the regularized phase space

  TFile* inputRootFile = TFile::Open(inputFile.c_str());
  assert(inputRootFile && inputRootFile->IsOpen());
  TH2D* hsmear = (TH2D*) inputRootFile->Get(("Ac_" + objSuffix + "Plot").c_str());
  assert(hsmear);

  int nrows = hsmear->GetNbinsX();
  int ncols = hsmear->GetNbinsY();
  fSmearingMatrix = new TMatrixD(nrows, ncols);
  for (int i=0; i<nrows; i++) {
    for (int j=0; j<ncols; j++) {
      fSmearingMatrix->operator()(i,j) = hsmear->GetBinContent(i+1, j+1);
    }
  }

 
  // Final setup ------------------------------------------------------
  FinaliseMeasurement();
};


bool MicroBooNE_CC1Mu1p_XSec_1D_nu::isSignal(FitEvent* event) {

  return SignalDef::MicroBooNE::isCC1Mu1p(event, EnuMin, EnuMax);

};


void MicroBooNE_CC1Mu1p_XSec_1D_nu::FillEventVariables(FitEvent* event) {

  if (event->NumFSParticle(13) == 0) return;
  if (event->NumFSParticle(2212) < 1) return;

  if ( !(SignalDef::MicroBooNE::isCC1Mu1p(event, EnuMin, EnuMax) ) ) { return; }

  TVector3 vpmu = event->GetHMFSParticle(13)->fP.Vect();
  if (vpmu.Mag() < 100 || vpmu.Mag() > 1200) { return; }

  int ProtonCounter = 0;
  std::vector<int> ProtonIndices = event->GetAllFSProtonIndices();
  std::vector<int> SignalProtonIndices;

  for (int i = 0; i < (int)(ProtonIndices.size()); i++) {

    double mom = event->GetParticleMom( ProtonIndices.at(i) );
    if (mom > 300 && mom < 1000) { 
      
      ProtonCounter++; 
      SignalProtonIndices.push_back( ProtonIndices.at(i) );

    }

  }

  if (ProtonCounter != 1) { return; }

  //using definitions in https://journals.aps.org/prd/pdf/10.1103/PhysRevD.108.053002

  TVector3 vp = event->GetParticleP3(SignalProtonIndices.at(0) );
  TVector3 vSum = vpmu + vp; //missing momentum in the plane transverse to the beam direction

  TVector3 vpmuT(vpmu.X(),vpmu.Y(),0.);   //transverse muon momentum
  TVector3 vpT(vp.X(),vp.Y(),0.); //transverse proton momentum
  TVector3 vSumT(vSum.X(),vSum.Y(),0.); //transverse missing momentum (eq. 1)

  TVector3 vpmuL(0.,0.,vpmu.Z());
  TVector3 vpL(0.,0.,vp.Z());

  double DeltaPT = vSum.Pt() / 1000.; // GeV/c
  double DeltaAlphaT = TMath::ACos( (- vpmuT * vSumT) / ( vpmuT.Mag() * vSumT.Mag() ) ) * 180./TMath::Pi(); // deg
  double DeltaPhiT =  TMath::ACos( (- vpmuT * vpT) / ( vpmuT.Mag() * vpT.Mag() ) ) * 180./TMath::Pi(); // deg   -////////////changed by Abi 5/12/23 using (eq 3)

  double MuonCosTheta = vpmu.CosTheta();
  double ProtonCosTheta = vp.CosTheta();

  double MuonMomentum = vpmu.Mag()/1000.; // GeV/c
  double ProtonMomentum = vp.Mag()/1000.; // GeV/c


  double BE = 0.04; // GeV, binding energy
  double NeutronMass_GeV = 0.939565; // GeV
  double ProtonMass_GeV = 0.938272; // GeV 
  double MuonMass_GeV = 0.106; // GeV 
  double DeltaM2 =  TMath::Power(NeutronMass_GeV,2.) - TMath::Power(ProtonMass_GeV,2.); // GeV^2
  double MuonEnergy = (event->GetHMFSParticle(13)->fP.E())/1000.0; //GeV/c Abi 
  //std::cout<<"MuonEnergy"<<MuonEnergy<<std::endl;
  double ProtonEnergy = (event->GetParticleP4(SignalProtonIndices.at(0) ).E())/1000.0; //GeV/c Abi;
  //std::cout<<"ProtonEnergy"<<ProtonEnergy<<std::endl;
  double ProtonKE = ProtonEnergy - ProtonMass_GeV;

  // ECal energy reconstruction
  double ECal =  ((MuonEnergy) + (ProtonKE) + BE); // GeV
  //std::cout<<"ECal"<<ECal<<std::endl;
  // QE Energy Reconstruction

  double EQENum = 2 * (NeutronMass_GeV - BE) * MuonEnergy - (BE*BE - 2 * NeutronMass_GeV *BE + MuonMass_GeV * MuonMass_GeV + DeltaM2);
  double EQEDen = 2 * ( NeutronMass_GeV - BE - MuonEnergy + vpmu.Mag() * vpmu.CosTheta() );
  double EQE = EQENum / EQEDen;

  // 3D KI variables

  // For the calculation of the masses
  //https://journals.aps.org/prc/pdf/10.1103/PhysRevC.95.065501

  double MA = (22 * NeutronMass_GeV) + (18 * ProtonMass_GeV )- 0.34381; // GeV

  // For the calculation of the excitation energies
  // https://doi.org/10.1140/epjc/s10052-019-6750-3

  double MAPrime = MA - NeutronMass_GeV + 0.0309; // GeV, constant obtained from table 7 

  // For the calculation of p_n, back to the Minerva PRL
  // https://journals.aps.org/prl/pdf/10.1103/PhysRevLett.121.022504

  double R = MA + vpmuL.Mag() + vpL.Mag() - MuonEnergy - ProtonEnergy; // Equation 8

  // Equation 7

  double PL = 0.5 * R - (MAPrime * MAPrime + vSumT.Mag() * vSumT.Mag()) / (2 * R);

  double DeltaPn = TMath::Sqrt( (vSumT.Mag() * vSumT.Mag()) +(PL * PL) )/1000.0;
  //std::cout<<"DeltaPn: "<< DeltaPn<< std::endl;
  //std::cout<<"fDist: "<< fDist<< std::endl;
  // https://journals.aps.org/prd/pdf/10.1103/PhysRevD.101.092001

  TVector3 UnitZ(0,0,1);
  //double Ptx = ( UnitZ.Cross(vpmuT) ).Dot(vSumT) / vpmuT.Mag(); -original in code 
  double DeltaPtx = DeltaPT*TMath::Sin(DeltaAlphaT);//changed by Abi 06/12/23
  //std::cout<< "Ptx is :"<<DeltaPtx<< "------------------------"<<std::endl;
  double Pty = - (vpmuT).Dot(vSumT) / vpmuT.Mag();

  double DeltaPty = DeltaPT*TMath::Sin(DeltaAlphaT);//changed by Abi 06/12/23
  //----------------------------------------//

  if (fDist == kDeltaPT) {
    fXVar = DeltaPT;
  }

  else if (fDist == kDeltaAlphaT) {
    fXVar = DeltaAlphaT;
  }

  else if (fDist == kDeltaPhiT) {
    fXVar = DeltaPhiT;
  }

  else if (fDist == kMuonCosTheta) {
    fXVar = MuonCosTheta;
  }

  else if (fDist == kProtonCosTheta) {
    fXVar = ProtonCosTheta;
  }

  else if (fDist == kMuonMomentum) {
    fXVar = MuonMomentum;
  }

  else if (fDist == kProtonMomentum) {
    fXVar = ProtonMomentum;
  }

  else if (fDist == kDeltaPn) {
    fXVar = DeltaPn;
  }

  else if (fDist == kDeltaPtx) {
    fXVar = DeltaPtx;
  }

  else if (fDist == kDeltaPty) {
    fXVar = DeltaPty;
  }

  else if (fDist == kECal) {
    fXVar = ECal;
  }

  else if (fDist == kEQE) {
    fXVar = EQE;
  }
 

 //Get Chi2 using raw covariance matrix (cov file in Measument1D.cxx)
 //Do in Eigen , copy from ROOT to Eigen data structure
 //(O-E)^2/uncertainty

 

}

void MicroBooNE_CC1Mu1p_XSec_1D_nu::ConvertEventRates() {
  // Do standard conversion
  Measurement1D::ConvertEventRates();

  // Apply Weiner-SVD additional smearing Ac
  int n = fMCHist->GetNbinsX();
  
  TVectorD v(n);
  for (int i=0; i<n; i++) {
    v(i) = fMCHist->GetBinContent(i+1);
    //std::cout<< "bin content for bin" << i << "is" <<  v(i) << std::endl;
  }

  TVectorD vs = (*fSmearingMatrix) * v;

  for (int i=0; i<n; i++) {
    fMCHist->SetBinContent(i+1, vs(i));
  }
  
  //Calculating the Chi2 manually using fMCHist fDataHist and the covariance matrix using NUISANCE untils
  string projectionname = fMCHist->GetName();
  Double_t Chi2_test = StatUtils::GetChi2FromCov(fDataHist, fMCHist, fFullCovar);
  std::cout<<"Chi2 using Nuisance Utils is     "   << projectionname << "  =   "<< Chi2_test  <<std::endl;

 

}

double MicroBooNE_CC1Mu1p_XSec_1D_nu::GetLikelihood(){

  //Get data from histogram 
  TH1D* relevant_histogram = PlotUtils::GetTH1DFromRootFile(inputFile, "FullUnc_" + objSuffix + "Plot");
  TH1D* mc_histogram = PlotUtils::GetTH1DFromRootFile(inputFile, "Genie_v3_0_6_Out_Of_The_Box_" + objSuffix + "Plot");
  Eigen::VectorXd binned_data = Eigen::VectorXd::Zero(relevant_histogram->GetNbinsX());
 
for(int i = 0; i < relevant_histogram->GetNbinsX(); ++i){
  binned_data[i] = relevant_histogram->GetBinContent(i+1); // +1 is important to skip the underflow bin.
  
}

int numberofbins_ref = mc_histogram->GetNbinsX();
//TVectorD mc_data_ref(numberofbins_ref);
Eigen::VectorXd mc_data_binned_ref = Eigen::VectorXd::Zero(numberofbins_ref);


  for (int i=0; i<numberofbins_ref; i++) {
    mc_data_binned_ref[i] = mc_histogram->GetBinContent(i+1);
  }

int numberofbins_MC = fMCHist->GetNbinsX();
TVectorD mc_data(numberofbins_MC);
Eigen::VectorXd mc_data_binned = Eigen::VectorXd::Zero(numberofbins_MC);
Eigen::VectorXd mc_data_error = Eigen::VectorXd::Zero(numberofbins_MC);
std::cout<< "bin " << "  binned data " << " Nuisance MC" << "  MicroBooNE MC"  << "  data-Nuisance" << " data-MicroBooNE " << std::endl;
  for (int i=0; i<numberofbins_MC; i++) {
    mc_data_binned[i] = fMCHist->GetBinContent(i+1);
    mc_data_binned[i] = mc_data_binned[i]*(1e38);

    mc_data_error[i] = fMCHist->GetBinError(i+1);
    mc_data_error[i] = mc_data_error[i]*(1e38);
    std::cout<< i << "--" << binned_data[i] << " -- " << mc_data_binned[i] << " -- " << mc_data_binned_ref[i] << " -- " << binned_data[i] - mc_data_binned_ref[i] <<  " -- "  << binned_data[i] - mc_data_binned[i]  << std::endl;
  }


  //TMatrixDSym* rCovar = new TMatrixDSym;
  TMatrixDSym *rCovar = StatUtils::GetCovarFromRootFile("/root/software/nuisance_version2/nuisance/data/MicroBooNE/CC1Mu1p/All_XSecs_Combined_v08_00_00_52.root",   
    "UnfCov_" + objSuffix + "Plot" );
  //Get Covariance matrix from ROOT file
  Eigen::MatrixXd eCovar = Eigen::MatrixXd::Zero(rCovar->GetNrows(),rCovar->GetNrows());
  for(int i = 0; i < rCovar->GetNrows(); ++i){
    for(int j = 0; j < rCovar->GetNrows(); ++j){
    eCovar(i,j) = (*rCovar)(i,j); 
    }
  }
  //Now calculate Chi2
    double det_Matrix = eCovar.determinant();
    std::cout<<"determinant is  "  << det_Matrix <<std::endl;
    Eigen::MatrixXd inverse_eCovar=eCovar.inverse();
    double Chi2_MC = (binned_data-mc_data_binned).transpose()*  inverse_eCovar *(binned_data-mc_data_binned);
    double Chi2_ref = (binned_data-mc_data_binned_ref).transpose()*  inverse_eCovar *(binned_data-mc_data_binned_ref);
    
    std::cout<< "Chi2_MC" << objSuffix << " is =   " << Chi2_MC <<std::endl;
    std::cout<< "Chi2_ref" << objSuffix << " is =   " << Chi2_ref <<std::endl;

    std::cout<<"___________________________________  MaskedChi2(binned_data, mc_data_binned_ref, eCovar)  MicroBooNE MC data"<<std::endl;
    MaskedChi2(binned_data, mc_data_binned_ref, eCovar);
    std::cout<<"___________________________________ MaskedChi2(binned_data, mc_data_binned_ref, eCovar) Nuisance MC data"<<std::endl;
    MaskedChi2(binned_data, mc_data_binned, eCovar);
    //std::cout<<"___________________________________ InflateCovarWithMCHistError(Eigen::MatrixXd const &inm, TH1 const *MCHist) MicroBooNE MC data"<<std::endl;
    double Chi_2_inflated =  (binned_data-mc_data_binned).transpose()*  (InflateCovarWithMCHistError(eCovar, mc_data_error)).inverse() *(binned_data-mc_data_binned); 
    std::cout<<"___________________________ inflated Chi2 =  " << Chi_2_inflated <<std::endl;

return Chi2_MC, Chi2_ref, Chi_2_inflated;
};
