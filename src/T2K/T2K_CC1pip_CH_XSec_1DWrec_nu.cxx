#include "T2K_CC1pip_CH_XSec_1DWrec_nu.h"
#include <iomanip>

// The constructor
T2K_CC1pip_CH_XSec_1DWrec_nu::T2K_CC1pip_CH_XSec_1DWrec_nu(std::string inputfile, FitWeight *rw, std::string  type, std::string fakeDataFile){

  measurementName = "T2K_CC1pip_CH_XSec_1DWrec_nu";
  plotTitles = "; W_{rec} (GeV/c); d#sigma/dW_{rec} (cm^{2}/(GeV/c^{2})/nucleon)";
  EnuMin = 0.;
  EnuMax = 10.;
  isDiag = false;
  Measurement1D::SetupMeasurement(inputfile, type, rw, fakeDataFile);

  this->SetDataValues(std::string(std::getenv("EXT_FIT"))+"/data/T2K/CC1pip/CH/W.root");
  this->SetCovarMatrix(std::string(std::getenv("EXT_FIT"))+"/data/T2K/CC1pip/CH/W.root");

  this->SetupDefaultHist();

  this->scaleFactor = (this->eventHist->Integral("width")*1E-38)/double(nevents)/TotalIntegratedFlux("width");
};

// Override this for now
// Should really have Measurement1D do this properly though
void T2K_CC1pip_CH_XSec_1DWrec_nu::SetDataValues(std::string fileLocation) {
  std::cout << "Reading: " << this->measurementName << "\nData: " << fileLocation.c_str() << std::endl;
  TFile *dataFile = new TFile(fileLocation.c_str()); //truly great .root file!

  // Don't want the first and last bin of dataCopy
  TH1D *dataCopy = (TH1D*)(dataFile->Get("hResult_sliced_0_1"))->Clone();

  std::cout << dataCopy->GetNbinsX() << std::endl;
  const int dataPoints = dataCopy->GetNbinsX()-2;
  double *binEdges = new double[dataPoints+1];
  // Want to skip the first bin here
  for (int i = 0; i < dataPoints+1; i++) {
    binEdges[i] = dataCopy->GetBinLowEdge(i+2);
  }

  for (int i = 0; i < dataPoints+1; i++) {
    std::cout << "binEdges[" << i << "] = " << binEdges[i] << std::endl;
  }

  dataHist = new TH1D((measurementName+"_data").c_str(), (measurementName+"_data"+plotTitles).c_str(), dataPoints, binEdges);

  for (int i = 0; i < dataHist->GetNbinsX(); i++) {
    dataHist->SetBinContent(i+1, dataCopy->GetBinContent(i+2)*1E-38);
    dataHist->SetBinError(i+1, dataCopy->GetBinError(i+2)*1E-38);
    std::cout << dataHist->GetBinLowEdge(i+1) << " " << dataHist->GetBinContent(i+1) << " " << dataHist->GetBinError(i+1) << std::endl;
  }


  dataHist->SetDirectory(0); //should disassociate dataHist with dataFile
  //dataHist->SetNameTitle((measurementName+"_data").c_str(), (measurementName+"_MC"+plotTitles).c_str());


  dataFile->Close();
};

// Override this for now
// Should really have Measurement1D do this properly though
void T2K_CC1pip_CH_XSec_1DWrec_nu::SetCovarMatrix(std::string fileLocation) {
  std::cout << "Covariance: " << fileLocation.c_str() << std::endl;
  TFile *dataFile = new TFile(fileLocation.c_str()); //truly great .root file!

  TH2D *covarMatrix = (TH2D*)(dataFile->Get("TMatrixDBase;1"))->Clone();

  const int nBinsX = covarMatrix->GetXaxis()->GetNbins();
  const int nBinsY = covarMatrix->GetYaxis()->GetNbins();

  if ((nBinsX != nBinsY)) std::cerr << "covariance matrix not square!" << std::endl;

  std::cout << nBinsX << std::endl;
  std::cout << dataHist->GetNbinsX() << std::endl;
  this->covar = new TMatrixDSym(nBinsX-3);
  this->fullcovar = new TMatrixDSym(nBinsX-3);

  for (int i = 0; i < nBinsX-3; i++) {
    for (int j = 0; j < nBinsY-3; j++) {
      (*this->covar)(i, j) = covarMatrix->GetBinContent(i+4, j+4); //adds syst+stat covariances
      std::cout << "covar(" << i << ", " << j << ") = " << (*this->covar)(i,j) << std::endl;
    }
  } //should now have set covariance, I hope

  TDecompChol tempMat = TDecompChol(*this->covar);
  this->covar = new TMatrixDSym(nBinsX, tempMat.Invert().GetMatrixArray(), "");
  *this->covar *= 1E-38*1E-38;

  return;
};


void T2K_CC1pip_CH_XSec_1DWrec_nu::FillEventVariables(FitEvent *event) {

  TLorentzVector Pnu = (event->PartInfo(0))->fP;
  TLorentzVector Ppip;
  TLorentzVector Pmu;

  // Loop over the particle stack
  for (int j = 2; j < event->Npart(); ++j) {
    if (!(event->PartInfo(j))->fIsAlive && (event->PartInfo(j))->fStatus != 0) continue;
    int PID = (event->PartInfo(j))->fPID;
    if (PID == 211) {
      Ppip = event->PartInfo(j)->fP;
    } else if (PID == 13) {
      Pmu = (event->PartInfo(j))->fP;  
    }
  }

  double Wrec = FitUtils::WrecCC1pip_T2K_MB(Pnu, Pmu, Ppip);

  this->X_VAR = Wrec;

  return;
};

//******************************************************************** 
bool T2K_CC1pip_CH_XSec_1DWrec_nu::isSignal(FitEvent *event) {
//******************************************************************** 
// This sample includes the Michel e tag so do not have to cut into the pion phase space
  return SignalDef::isCC1pip_T2K_CH(event, EnuMin, EnuMax, true);
}
