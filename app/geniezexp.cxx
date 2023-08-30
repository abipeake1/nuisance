#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include "Framework/GHEP/GHepParticle.h"
#include <vector>
#include "TTree.h"
#include "TVector3.h"
#include <TLorentzVector.h>
#include "Framework/EventGen/EventRecord.h"
#include "Framework/GHEP/GHepParticle.h"
#include "Framework/GHEP/GHepRecord.h"
#include "Framework/Ntuple/NtpMCEventRecord.h"
#include "TLorentzVector.h" 
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1D.h"
#include "TH3D.h"
#include "THStack.h"
#include <time.h>
#include <Eigen/Dense>
#include "TRandom3.h"
#include <iostream>
#include <fstream>
#include <vector>
 
//front matter for reweighting
#include "Framework/Utils/RunOpt.h"
#include "Framework/Utils/AppInit.h"
#include "RwFramework/GReWeightI.h"
#include "RwFramework/GSystSet.h"
#include "RwFramework/GSyst.h"
#include "RwFramework/GReWeight.h"
#include "RwCalculators/GReWeightNuXSecCCQEaxial.h"
#include "RwCalculators/GReWeightNuXSecCCQE.h"

using namespace std;
using namespace genie;
using namespace genie::rew;
fstream file;


void print(std::vector <float> const &a) {
   std::cout << "The random b values for the uncorellated basis are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}



//G18_02a_00_000

Eigen::MatrixXd Covariance_Matrix {{0.0169, 0.0455, -0.22035, 0.214461},
  {0.0455, 1. ,-2.245, 0.9909},
  {-0.22035, -2.245, 6.25, -4.62375},
  {0.214461, 0.9909, -4.62375, 7.29}};


Eigen::MatrixXd  corr{{1, 0.350, -0.678, 0.611}, 
{0.350,  1,     -0.898,  0.367}, 
{-0.678, -0.898,  1,  -0.685},
{0.611,  0.367, -0.685,  1}};


std::vector<double> random_b_params;
std::vector<double> translated_bparams;
std::vector<double> genie_values;
std::vector<vector<Double_t>> randbval_vector;

Eigen::MatrixXd GetPCAFromCorr(){
  Eigen::MatrixXd Eigenvalues;
  Eigen::VectorXd eigenvalues_sqrt;  //use for scaling new basis
  Eigen::MatrixXd eigenvector_colmatrix;
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(Covariance_Matrix);
    if (eigensolver.info() != Eigen::Success) abort();
    //std::cout << "The eigenvalues of covariance matrix are:\n" << eigensolver.eigenvalues() << std::endl;
    //std::cout << "Here's a matrix whose columns are eigenvectors of the covariance matrix"<< "corresponding to these eigenvalues:"<< eigensolver.eigenvectors() << std::endl;

    Eigenvalues = (eigensolver.eigenvalues()).asDiagonal();
    eigenvector_colmatrix = eigensolver.eigenvectors();
    eigenvalues_sqrt = (eigensolver.eigenvalues()).array().sqrt();
    
  Eigen::MatrixXd PCA = eigenvalues_sqrt * eigenvector_colmatrix;

  std::cout << "SQRT_Eigenvalues: " << eigenvalues_sqrt << std::endl;
  std::cout << "Eigenvectors: " << eigenvector_colmatrix << std::endl;
  std::cout << "Scaling aka PCA: " << PCA << std::endl;

 for(size_t i = 0; i < 4; ++i){
  eigenvector_colmatrix.col(i) *= eigenvalues_sqrt[i];
 }

 return eigenvector_colmatrix;
}


Eigen::VectorXd GetAVals(std::vector<double> const &BVals, Eigen::MatrixXd const &PCA){
 std::cout << "In GetAVals function: " << std::endl;
  Eigen::VectorXd avals = Eigen::VectorXd::Zero(4);
  for(size_t i = 0; i < 4; ++i){
    avals += PCA.col(i) * BVals[i];

   /* 
    std::cout<<"in for loop in GetAVals function and this is loop" << i <<std::endl;
    std::cout<< "The bvalues are" << BVals[i] <<std::endl;
    std::cout<<"PCA.col(i) is" << PCA.col(i)<<std::endl;
    */
  }
  std::cout<<"The a values just formed are" << avals<<std::endl;
 // avals = avals + a_central_values;
  return avals;
}

vector<Eigen::VectorXd> avalues_for_genie_vector;
vector<Eigen::VectorXd> syst_avals_vector;

Eigen::Array4d central_values_a_from_genie = {2.30 ,-0.60 ,-3.80 ,2.30};
Eigen::Array4d central_values_afrom_errors_genie_code = {0.14,0.67,1,0.75};//-----in genie
Eigen::Array4d central_values_afrom_errors_genie = {0.13,1,2.5,2.7};
Eigen::Vector4d product = central_values_a_from_genie*central_values_afrom_errors_genie;

Eigen::Array4d GetTransformedBparams(std::vector<double> const &BVals){
  Eigen::VectorXd ttree_systematic_avals = GetAVals(BVals, GetPCAFromCorr());
  return ttree_systematic_avals;
}

Eigen::Array4d ScaleAparamsforGenie(std::vector<double> const &BVals){
  Eigen::VectorXd syst_avals = GetAVals(BVals, GetPCAFromCorr());
  std::cout << " syst_avals......Systematic a values" << syst_avals << std::endl;
  Eigen::VectorXd avalues_for_genie = syst_avals.array()/central_values_afrom_errors_genie_code.array();
  return avalues_for_genie;
}

void SetSystematicInTermsOfB(std::vector<double> const &BVals, GReWeightNuXSecCCQE &grw){
  std::cout << "In SetSystematicintermsofb fn " << std::endl;
  Eigen::MatrixXd corr = Eigen::MatrixXd::Zero(4,4);
  std::vector<GSyst_t> syst_dials = {kXSecTwkDial_ZExpA1CCQE, kXSecTwkDial_ZExpA2CCQE,kXSecTwkDial_ZExpA3CCQE, kXSecTwkDial_ZExpA4CCQE};
  Eigen::VectorXd syst_avals = GetAVals(BVals, GetPCAFromCorr());
  Eigen::VectorXd avalues_for_genie = syst_avals.array()/central_values_afrom_errors_genie_code.array();
  syst_avals_vector.push_back(syst_avals);
  for(size_t i = 0; i < 4; ++i){
    std::cout << "i is" << i << std::endl;
    grw.SetMode(GReWeightNuXSecCCQE::kModeZExp);
    //grw.SetSystematic(syst_dials[i], syst_avals[i]);
    grw.SetSystematic(syst_dials[i], avalues_for_genie[i]);
     std::cout<<"sdone set systematic"<<std::endl;
     std::cout<<"syst dial"<< i << syst_dials[i] << "and syst_aval[i]" <<syst_avals[i]<<std::endl;
  }
  std::cout<<"about to reconfigure"<<std::endl;
  grw.Reconfigure();
  std::cout<<"done reconfigure"<<std::endl;
  
}

int main(int argc, char const *argv[]) {

TFile *file_out = TFile::Open("myoutput_test_new_10e5_2608_new_lowerbins.root","RECREATE");
TTree *tree_out = new TTree("mytree","mytreetitle");
  
  //Somewhere near the top of the main function, before we do any file reading
  genie::RunOpt *grunopt = genie::RunOpt::Instance();
  grunopt->EnableBareXSecPreCalc(true);

  //We need to work out what the EventGeneratorList actually is
  std::string EventGeneratorList_name = "Default";
  grunopt->SetEventGeneratorList(EventGeneratorList_name);

  //We need to work out what the TUNE name actually is
 // std::string Tune_name = "G18_02a_00_000"; //find Tune_name using echo $GENIE_XSEC_TUNE

  //Different TUNE THAT might work with z-expansion = G18_10i_02_11a
  std::string Tune_name = "G18_10i_02_11a"; 
  grunopt->SetTuneName(Tune_name);
  grunopt->BuildTune();
  std::string genv =
      std::string(getenv("GENIE")) + "/config/Messenger_laconic.xml";
  // genie::utils::app_init::MesgThresholds(genv);

  


  //This is the re-weighting tool in GENIE
  genie::rew::GReWeightNuXSecCCQEaxial myaxreweighter; //probably dont need this anymore
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_zexp_cv;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a2;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a3;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_altogether; //reweight a1 a2 a3 a4 simul.

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a2_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a3_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a4_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_altogether_minus; //reweight a1 a2 a3 a4 simul.


  
  //New calculator for the new basis
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_a_newbasis_plus;
  
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b3;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b4;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b3_minus;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b4_minus;
  
  
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b3;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b3_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b3;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b3_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b3_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b3_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b3_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b2_b3_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b3_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b3_b4_minus;
  
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3_b4;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3_b4_minus;

  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3_b4_point1;
  genie::rew::GReWeightNuXSecCCQE myccqereweighter_rw_b1_b2_b3_b4_minus_point1;


  myaxreweighter.Reset();
  //std::cout<< "ccqe reweighter b1"<<std::endl;
  SetSystematicInTermsOfB({1,0,0,0}, myccqereweighter_rw_b1);
  //std::cout<< "ccqe reweighter b2"<<std::endl;
  SetSystematicInTermsOfB({0,1,0,0}, myccqereweighter_rw_b2);
   //std::cout<< "ccqe reweighter b3"<<std::endl;
  SetSystematicInTermsOfB({0,0,1,0}, myccqereweighter_rw_b3);
  //std::cout<< "ccqe reweighter b4"<<std::endl;
  SetSystematicInTermsOfB({0,0,0,1}, myccqereweighter_rw_b4);

  SetSystematicInTermsOfB({-1,0,0,0}, myccqereweighter_rw_b1_minus);
  //std::cout<< "ccqe reweighter b2"<<std::endl;
  SetSystematicInTermsOfB({0,-1,0,0}, myccqereweighter_rw_b2_minus);
   //std::cout<< "ccqe reweighter b3"<<std::endl;
  SetSystematicInTermsOfB({0,0,-1,0}, myccqereweighter_rw_b3_minus);
  //std::cout<< "ccqe reweighter b4"<<std::endl;
  SetSystematicInTermsOfB({0,0,0,-1}, myccqereweighter_rw_b4_minus);
   
  SetSystematicInTermsOfB({1,1,0,0}, myccqereweighter_rw_b1_b2);
  SetSystematicInTermsOfB({-1,-1,0,0}, myccqereweighter_rw_b1_b2_minus);

  SetSystematicInTermsOfB({1,0,1,0}, myccqereweighter_rw_b1_b3);
  SetSystematicInTermsOfB({-1,0,-1,0}, myccqereweighter_rw_b1_b3_minus);

  SetSystematicInTermsOfB({1,0,0,1}, myccqereweighter_rw_b1_b4);
  SetSystematicInTermsOfB({-1,0,0,-1}, myccqereweighter_rw_b1_b4_minus);

  SetSystematicInTermsOfB({0,1,1,0}, myccqereweighter_rw_b2_b3);
  SetSystematicInTermsOfB({0,-1,-1,0}, myccqereweighter_rw_b2_b3_minus);

  SetSystematicInTermsOfB({0,1,1,1}, myccqereweighter_rw_b2_b4);
  SetSystematicInTermsOfB({0,-1-1,0}, myccqereweighter_rw_b2_b4_minus);

  SetSystematicInTermsOfB({0,0,1,1}, myccqereweighter_rw_b3_b4);
  SetSystematicInTermsOfB({0,0,-1,-1}, myccqereweighter_rw_b3_b4_minus);


  SetSystematicInTermsOfB({1,1,1,0}, myccqereweighter_rw_b1_b2_b3);
  SetSystematicInTermsOfB({-1,-1,-1,0}, myccqereweighter_rw_b1_b2_b3_minus);

  SetSystematicInTermsOfB({1,1,0,1}, myccqereweighter_rw_b1_b2_b4);
  SetSystematicInTermsOfB({-1,-1,0,-1}, myccqereweighter_rw_b1_b2_b4_minus);

  SetSystematicInTermsOfB({0,1,1,1}, myccqereweighter_rw_b2_b3_b4);
  SetSystematicInTermsOfB({0-1,-1,-1}, myccqereweighter_rw_b2_b3_b4_minus);

  SetSystematicInTermsOfB({0,1,1,1}, myccqereweighter_rw_b2_b3_b4);
  SetSystematicInTermsOfB({0,-1,-1,-1}, myccqereweighter_rw_b2_b3_b4_minus);
  
  SetSystematicInTermsOfB({1,1,1,1}, myccqereweighter_rw_b1_b2_b3_b4);   //shift the b params all by plus 1 std
  SetSystematicInTermsOfB({-1,-1,-1,-1}, myccqereweighter_rw_b1_b2_b3_b4_minus); //shift the b params all by minus 1 std
  
  SetSystematicInTermsOfB({0.1,0.1,0.1,0.1}, myccqereweighter_rw_b1_b2_b3_b4_point1);
  SetSystematicInTermsOfB({-0.1,-0.1,-0.1,-0.1}, myccqereweighter_rw_b1_b2_b3_b4_minus_point1);
  


  //reweight calculators for the a parameters
  myccqereweighter_zexp_cv.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_zexp_cv.Reconfigure();

  
  myaxreweighter.SetSystematic(kXSecTwkDial_AxFFCCQEshape, 1);
  myaxreweighter.Reconfigure(); 

  myccqereweighter.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  std::cout<< myaxreweighter.IsHandled(kXSecTwkDial_AxFFCCQEshape)<< "does the ccurrent weight calc. handle this param?" <<std::endl;

  myccqereweighter.SetSystematic(kXSecTwkDial_ZExpA1CCQE, 1); //shift a1 by plus 1 sigma
  myccqereweighter.Reconfigure();

  myccqereweighter_a2.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a2.SetSystematic(kXSecTwkDial_ZExpA2CCQE, 1);
  myccqereweighter_a2.Reconfigure();
  
  myccqereweighter_a3.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a3.SetSystematic(kXSecTwkDial_ZExpA3CCQE, 1);
  myccqereweighter_a3.Reconfigure();
   
  myccqereweighter_a4.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a4.SetSystematic(kXSecTwkDial_ZExpA4CCQE, 1);
  myccqereweighter_a4.Reconfigure();
 
  myccqereweighter_altogether.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_altogether.SetSystematic(kXSecTwkDial_ZExpA1CCQE, 1); //vary a1 a2 a3 a4 in same reweight calculation
  myccqereweighter_altogether.SetSystematic(kXSecTwkDial_ZExpA2CCQE, 1);
  myccqereweighter_altogether.SetSystematic(kXSecTwkDial_ZExpA3CCQE, 1);
  myccqereweighter_altogether.SetSystematic(kXSecTwkDial_ZExpA4CCQE, 1);
  myccqereweighter_altogether.Reconfigure();
  
  myccqereweighter_minus.SetSystematic(kXSecTwkDial_ZExpA1CCQE, -1);
  myccqereweighter_minus.Reconfigure();

  myccqereweighter_a2_minus.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a2_minus.SetSystematic(kXSecTwkDial_ZExpA2CCQE, -1);
  myccqereweighter_a2_minus.Reconfigure();
  
  myccqereweighter_a3_minus.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a3_minus.SetSystematic(kXSecTwkDial_ZExpA3CCQE, -1);
  myccqereweighter_a3_minus.Reconfigure();
   
  myccqereweighter_a4_minus.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_a4_minus.SetSystematic(kXSecTwkDial_ZExpA4CCQE, -1);
  myccqereweighter_a4_minus.Reconfigure();
 
  myccqereweighter_altogether_minus.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  myccqereweighter_altogether_minus.SetSystematic(kXSecTwkDial_ZExpA1CCQE, -1); //vary a1 a2 a3 a4 in same reweight calculation
  myccqereweighter_altogether_minus.SetSystematic(kXSecTwkDial_ZExpA2CCQE, -1);
  myccqereweighter_altogether_minus.SetSystematic(kXSecTwkDial_ZExpA3CCQE, -1);
  myccqereweighter_altogether_minus.SetSystematic(kXSecTwkDial_ZExpA4CCQE, -1);
  myccqereweighter_altogether_minus.Reconfigure();
 
//#if true
  
  /////New baisis Reweighting
  myccqereweighter_a_newbasis_plus.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  std::cout<<"Set mode on new basus reweighter"<<std::endl;
  if (argc < 2) {
    std::cout << "you didn't give me an argument..." << std::endl;
    return 1;
  }

  TFile *fin = TFile::Open(argv[1]);

  if (!fin) {
    std::cout << "[ERROR]: " << argv[1] << std::endl;
    return 2;
  }

  TTree *tr = nullptr;

  tr = static_cast<TTree *>(fin->Get("gtree"));
  if (!tr) {
    std::cout << "[ERROR]: gtree not found in  " << argv[1] << std::endl;
    return 2;
  }

  Long64_t nevt = tr->GetEntries();

  NtpMCEventRecord *ntpl = NULL;
  tr->SetBranchAddress("gmcrec", &ntpl);

  //auto canvas = new TCanvas("canvas", "canvas");
  auto *hs = new THStack("hs","1 sigma changes to [a1,a2,a3,a4]");
  
  TCanvas *c1 = new TCanvas("c1","Energy of final state muon");
  TH1 *emuon = new TH1D("emuon","Emu;E_{mu} (GeV);Count",250,0,70);

  TCanvas *c2 = new TCanvas("c2","Energy of initial state neutrino");
  TH1 *enu = new TH1D("enu","Enu;E_{nu} (GeV);Count",35,0,70); //new TH1 for energy of incoming neutrino

  TCanvas *c4 = new TCanvas("c4","Number of Final state protons per event");
  TH1 *protonnumber = new TH1D("protonnumber","Np;N_{p};Count",20,0,40); //new TH1 for energy of incoming neutrino
  
  //new TH3 for momentum (px,py,pz) of highest momentum final state protons
  TCanvas *c3 = new TCanvas("c3","Momentum of final proton");
  c3->Divide(3,1);
  TH1 *protonmomentumx = new TH1D("protonmomentumx","pproton;p_{px} (GeV/c);Count",40,-5,5); 
  TH1 *protonmomentumy = new TH1D("protonmomentumy","pproton;p_{py} (GeV/c);Count",40,-5,5); 
  TH1 *protonmomentumz = new TH1D("protonmomentumz","pproton;p_{pz} (GeV/c);Count",40,-5,5); 

  TH1 *finalstateprotons_with_greatestmomentum = new TH1D("pfinalstateprotons_with_greatestmomentum","pprotonmax;p_{pmax} (GeV/c);Count",100,-0.5,5); 

  TH1 *proton_momentum_total = new TH1D("protonmomentumtotal","pproton;p_{magnitude} (GeV/c);Count",100,-2,5);
  //vector<int> proton_counter;

  TH1 *q2_hist_cv_zexp = new TH1D("Q2histzex_cv", "q2;Q^{2};Count" , 35 ,0,7);
  TH1 *q2_hist = new TH1D("Q2hist","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw = new TH1D("Q2histrw","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a1 = new TH1D("Q2histrwa1","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a2 = new TH1D("Q2histrwa2","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a3 = new TH1D("Q2histrwa3","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a4 = new TH1D("Q2histrwa4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_altogether = new TH1D("Q2histrwaltogether","q2;Q^{2};Count",35,0,7);

  TH1 *q2_hist_rw_minus = new TH1D("Q2histrwminus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a1_minus = new TH1D("Q2histrwa1minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a2_minus = new TH1D("Q2histrwa2minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a3_minus = new TH1D("Q2histrwa3minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_a4_minus = new TH1D("Q2histrwa4minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_rw_altogether_minus = new TH1D("Q2histrwaltogetherminus","q2;Q^{2};Count",35,0,7);


  TH1 *q2_hist_myccqereweighter_rw_b1 = new TH1D("Q2hist_myccqereweighter_rw_b1","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b2 = new TH1D("Q2hist_myccqereweighter_rw_b2","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b3 = new TH1D("Q2hist_myccqereweighter_rw_b3","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b4 = new TH1D("Q2hist_myccqereweighter_rw_b4","q2;Q^{2};Count",35,0,7);


  TH1 *q2_hist_myccqereweighter_rw_b1_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b2_minus = new TH1D("Q2hist_myccqereweighter_rw_b2__minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b3_minus = new TH1D("Q2hist_myccqereweighter_rw_b3_minus","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b4_minus","q2;Q^{2};Count",35,0,7);

  TH1 *q2_hist_myccqereweighter_rw_b1_b2 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b3_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b3_b4_minus","q2;Q^{2};Count",35,0,7);
  

  TH1 *q2_hist_myccqereweighter_rw_b1_b3 = new TH1D("Q2hist_myccqereweighter_rw_b1_3","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b3_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b3_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b2_b3 = new TH1D("Q2hist_myccqereweighter_rw_b2_b3","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b2_b3_minus = new TH1D("Q2hist_myccqereweighter_rw_b2_b3_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b1_b4 = new TH1D("Q2hist_myccqereweighter_rw_b1_b34","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b2_b4 = new TH1D("Q2hist_myccqereweighter_rw_b2_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b2_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b2_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b3_b4 = new TH1D("Q2hist_myccqereweighter_rw_b3_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b3_b3_minus = new TH1D("Q2hist_myccqereweighter_rw_b3_b4_minus","q2;Q^{2};Count",35,0,7);
  

  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b4 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b2_b3_b4 = new TH1D("Q2hist_myccqereweighter_rw_b2_b3_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b2_b3_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b2_b3_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b1_b3_b4 = new TH1D("Q2hist_myccqereweighter_rw_b1_b3_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b3_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b3_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3_b4 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3_b4","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3_b4_minus","q2;Q^{2};Count",35,0,7);
  
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3_b4_point1 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3_b4_point1","q2;Q^{2};Count",35,0,7);
  TH1 *q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus_point1 = new TH1D("Q2hist_myccqereweighter_rw_b1_b2_b3_b4_minus_point1","q2;Q^{2};Count",35,0,7);
  
  std::vector<double> b_params_out;
  
  std::vector<double>  ttree_avalues_for_genie_vector;
  std::vector<double>  ttree_systematic_avals;
  b_params_out.resize(4);
  ttree_avalues_for_genie_vector.resize(4);
  ttree_systematic_avals.resize(4);
  tree_out->Branch("randombparameters",&b_params_out);
  tree_out->Branch("translated_bparams", &ttree_systematic_avals);
  tree_out->Branch("avalues_for_genie_vector", &ttree_avalues_for_genie_vector);
  

  int NThrows = 100;
  std::cout<<"Done N throws-------------------------"<<std::endl;
  std::vector<TH1D *> myhists;
    for (int throw_i = 0; throw_i < NThrows; throw_i++) {
        std::cout<<"in for loop-------------------------"<<std::endl;
      // build name string
      std::stringstream ss("");
      ss << "hist_throw_" << throw_i;

      myhists.push_back(new TH1D(ss.str().c_str(), ";Q2;count", 35, 0, 7));
    }
    
  // if we want to do throws
  
  int seed = 12345;
  TRandom3* ran = new TRandom3(seed);

  std::vector<vector<Double_t>> randbval_vector;
  //tree_out->Branch("randbval_vector",&random_basis_b);
  std::vector<std::unique_ptr<GReWeightNuXSecCCQE>> rand_b_reweight_engines; // vector of reweighters
  for (int throw_i = 0; throw_i < NThrows; throw_i++) {
    
    rand_b_reweight_engines.push_back(std::make_unique <genie::rew::GReWeightNuXSecCCQE>());
    vector<Double_t> randbvals;
    for (int i = 0; i < 4; ++i) {
      // n.b. this is flat throw in B, but we really want gaussian
      Double_t x = ran->Gaus(0,1);
      //std::cout<< x<< std::endl;
      randbvals.push_back(x);
      //std::cout<<"random b value in loop" << i << "is"<<randbvals[i]<<std::endl;
    }
    b_params_out[0]=randbvals[0];
    b_params_out[1]=randbvals[1];
    b_params_out[2]=randbvals[2];
    b_params_out[3]=randbvals[3];
    
    ttree_systematic_avals[0] = GetTransformedBparams(randbvals)(0);
    ttree_systematic_avals[1] = GetTransformedBparams(randbvals)(1);
    ttree_systematic_avals[2] = GetTransformedBparams(randbvals)(2);
    ttree_systematic_avals[3] = GetTransformedBparams(randbvals)(3);
    
    ttree_avalues_for_genie_vector[0]=ScaleAparamsforGenie(randbvals)(0);
    ttree_avalues_for_genie_vector[1]=ScaleAparamsforGenie(randbvals)(1);
    ttree_avalues_for_genie_vector[2]=ScaleAparamsforGenie(randbvals)(2);
    ttree_avalues_for_genie_vector[3]=ScaleAparamsforGenie(randbvals)(3);
    

    GetTransformedBparams(randbvals);
    ScaleAparamsforGenie(randbvals);
    std::cout<<"Have pushed back randbvals now goingt to set systematic interms of b-----"<<std::endl;
    SetSystematicInTermsOfB(randbvals, *rand_b_reweight_engines.back());
    randbval_vector.push_back(randbvals);
    std::cout << "The length of the vector rand_b_reweight_engines is " << rand_b_reweight_engines.size() <<std::endl;
    tree_out->Fill();
  }
  // make sure the throw_weights vector is the right size before we start
  // putting stuff in it.
  std::vector<double> throw_weights;
  for (int i = 0; i < NThrows; ++i) {
    throw_weights.push_back(1);
  }
  
  TFile *results = new TFile("10e5events_10GeV_test_new_2608_new_lowerbins.root","RECREATE","105events_10GeV_test_new");
  

  for (Long64_t e_it = 0; e_it < nevt; ++e_it){
     //std::cout<< "in event loop with entry----------------------------------- "<< e_it <<std::endl;
    tr->GetEntry(e_it);
    
    //get only CCQE events 
    bool is_qe = ntpl->event->Summary()->ProcInfo().IsQuasiElastic();
    bool is_cc = ntpl->event->Summary()->ProcInfo().IsWeakCC();
    if ( !is_qe || !is_cc ) continue;


    
    //create a Weight calculator
    double weight_zexp_cv = myccqereweighter_zexp_cv.CalcWeight(*ntpl->event);
    double weight = myaxreweighter.CalcWeight(*ntpl-> event);
    double weight2 = myccqereweighter.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_a2 = myccqereweighter_a2.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_a3 = myccqereweighter_a3.CalcWeight(*ntpl->event); //get event in object ntpl 
    
    double weight_a4 = myccqereweighter_a4.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_altogether = myccqereweighter_altogether.CalcWeight(*ntpl->event);

    //double weight_minus = myaxreweighter_minus.CalcWeight(*ntpl-> event);
    double weight2_minus = myccqereweighter_minus.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_a2_minus = myccqereweighter_a2_minus.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_a3_minus = myccqereweighter_a3_minus.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_a4_minus = myccqereweighter_a4_minus.CalcWeight(*ntpl->event); //get event in object ntpl 
    double weight_altogether_minus = myccqereweighter_altogether_minus.CalcWeight(*ntpl->event);
    double myccqereweighter_a_newbasis_plus = myccqereweighter_altogether_minus.CalcWeight(*ntpl->event);
    
    
    double weight_myccqereweighter_rw_b1 = myccqereweighter_rw_b1.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2 = myccqereweighter_rw_b2.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b3 = myccqereweighter_rw_b3.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b4 = myccqereweighter_rw_b4.CalcWeight(*ntpl->event);
     
    double weight_myccqereweighter_rw_b1_minus = myccqereweighter_rw_b1_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_minus = myccqereweighter_rw_b2_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b3_minus = myccqereweighter_rw_b3_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b4_minus = myccqereweighter_rw_b4_minus.CalcWeight(*ntpl->event);
    
    double weight_myccqereweighter_rw_b1_b2 = myccqereweighter_rw_b1_b2.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_b3 = myccqereweighter_rw_b2_b3.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b3 = myccqereweighter_rw_b1_b3.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b4 = myccqereweighter_rw_b1_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_b4 = myccqereweighter_rw_b2_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b3_b4 = myccqereweighter_rw_b3_b4.CalcWeight(*ntpl->event);

   
    double weight_myccqereweighter_rw_b1_b4_minus = myccqereweighter_rw_b1_b4_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_b4_minus = myccqereweighter_rw_b2_b4_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b2_minus = myccqereweighter_rw_b1_b2_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b3_minus = myccqereweighter_rw_b1_b3_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_b3_minus = myccqereweighter_rw_b2_b3_minus.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b3_b4_minus = myccqereweighter_rw_b3_b4_minus.CalcWeight(*ntpl->event);

    double weight_myccqereweighter_rw_b1_b2_b3 = myccqereweighter_rw_b1_b2_b3.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b2_b3_minus = myccqereweighter_rw_b1_b2_b3_minus.CalcWeight(*ntpl->event);

    double weight_myccqereweighter_rw_b1_b2_b4 = myccqereweighter_rw_b1_b2_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b2_b4_minus = myccqereweighter_rw_b1_b2_b4_minus.CalcWeight(*ntpl->event);

    double weight_myccqereweighter_rw_b2_b3_b4 = myccqereweighter_rw_b2_b3_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b2_b3_b4_minus = myccqereweighter_rw_b2_b3_b4_minus.CalcWeight(*ntpl->event);

    double weight_myccqereweighter_rw_b1_b3_b4 = myccqereweighter_rw_b1_b3_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b3_b4_minus = myccqereweighter_rw_b1_b3_b4_minus.CalcWeight(*ntpl->event);


    double weight_myccqereweighter_rw_b1_b2_b3_b4 = myccqereweighter_rw_b1_b2_b3_b4.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b2_b3_b4_minus = myccqereweighter_rw_b1_b2_b3_b4_minus.CalcWeight(*ntpl->event);

    double weight_myccqereweighter_rw_b1_b2_b3_b4_point1 = myccqereweighter_rw_b1_b2_b3_b4_point1.CalcWeight(*ntpl->event);
    double weight_myccqereweighter_rw_b1_b2_b3_b4_minus_point1 = myccqereweighter_rw_b1_b2_b3_b4_minus_point1.CalcWeight(*ntpl->event);
    

    TLorentzVector muon_4momentum;
   
    TLorentzVector neutrino_4momentum;
    vector<double> proton_3_momentum_magnitude_entry;
    int proton_count = 0;
    
    
    //std::cout << "[INFO]: Got entry " << e_it << std::endl;

    // Check for GENIE Event
    if (!ntpl) {
      continue;
    }
    if (!ntpl->event) {
      continue;
    }

    // Cast Event Record
    GHepRecord *ghep = static_cast<GHepRecord *>(ntpl->event);
    if (!ghep) {
      continue;
    }
  
    // Fill Particle Stack
    GHepParticle *p = 0;
    TObjArrayIter iter(ghep);

    // Loop over all particles
    int pitr = 0;
    


    while ((p = (dynamic_cast<GHepParticle *>((iter).Next())))){
      if (!p) {
        continue;
      }
      
        //std::cout << "  part[" << pitr++ << "]: pdg = " << p->Pdg()
          //   << ", status = " << p->Status() << std::endl;

      //re weight the neutrino event
      //double weight = wcalc.NewWeight(p);

          
      
      
      if((p->Pdg()==13) && (p->Status()==1)){
        // std::cout << "d energy of the muon is " << p->E() << std::endl;
        emuon->Fill(p->E());
      
        muon_4momentum = *p->P4();
        //std::cout << "d muon 4momentum " << p->P4() << std::endl;
        
      }
      if((p->Pdg()==14) && (p->Status()==0)){   //if particle incoming neutrino muon
        //std::cout << "d incoming neutrino has energy " << p->E() << std::endl;
        enu->Fill(p->E());
        neutrino_4momentum = *p->P4();
        //std::cout << "d neutrino 4momentum " << p->P4() << std::endl;
      }

      vector<vector<double> >final_state_protons_momenta_entry;
      
      if((p->Pdg()==2212) && (p->Status()==1)){ 
        //if particle is highest energy final state proton
        //std::cout << "d proton momentum is " << p->Px() << p->Py() << p->Pz() << std::endl;
        proton_count++;
        
        //protonnumber->Fill(proton_count++); //move later!!
        std::vector<double> proton_3_momentum_vector{p->Px(),p->Py(), p->Pz()};
        double px=p->Px();
        double py=p->Px();
        double pz=p->Px();
        double proton_3_momentum_mag = sqrt((px*px)+(py*py)+(pz*pz));
        
        //std::cout << "magnitude of proton momentum is" << proton_3_momentum_mag << "----------------------------" <<std::endl;
        proton_3_momentum_magnitude_entry.push_back(proton_3_momentum_mag);
        
        protonmomentumx->Fill(p->Px());
        protonmomentumy->Fill(p->Py());
        protonmomentumz->Fill(p->Pz());
        }
        final_state_protons_momenta_entry.push_back(proton_3_momentum_magnitude_entry);
      }
        
    //}
  //}
    std::cout << "---" << std::endl;
    




    
      ///// Working out which of the final state protons has the greatest momentum (magnitude)
      auto const max_iter = std::max_element(proton_3_momentum_magnitude_entry.begin(), proton_3_momentum_magnitude_entry.end());
      if (max_iter == proton_3_momentum_magnitude_entry.end())
      {
        auto const max_iter = 0;
          // do something to handle the special situation
      }
      else
      {
          auto const max = *max_iter;
          finalstateprotons_with_greatestmomentum->Fill(max);
          // normal program flow
      }
      Double_t s, s2;
      if(muon_4momentum.Mag()==0)
      {
        std::cout<<"no muon produced"<<std::endl;}
      else{
      s2=-(neutrino_4momentum - muon_4momentum).Mag2(); 
      //s2 = s2*(1e-6);
     // std::cout<<"Q2 ="<< s2 <<std::endl;
      q2_hist->Fill(s2);
      q2_hist_rw->Fill(s2, weight);
      }  
      q2_hist_cv_zexp->Fill(s2, weight_zexp_cv);
      q2_hist_rw_a1->Fill(s2, weight2);
      q2_hist_rw_a2->Fill(s2, weight_a2);
      q2_hist_rw_a3->Fill(s2,weight_a3);
      q2_hist_rw_a4->Fill(s2,weight_a4);
      q2_hist_rw_altogether->Fill(s2,weight_altogether);


      q2_hist_rw_a1_minus->Fill(s2, weight2_minus);
      q2_hist_rw_a2_minus->Fill(s2, weight_a2_minus);
      q2_hist_rw_a3_minus->Fill(s2,weight_a3_minus);
      q2_hist_rw_a4_minus->Fill(s2,weight_a4_minus);
      q2_hist_rw_altogether_minus->Fill(s2,weight_altogether_minus);

      
      q2_hist_myccqereweighter_rw_b1->Fill(s2, weight_myccqereweighter_rw_b1);
      q2_hist_myccqereweighter_rw_b2->Fill(s2, weight_myccqereweighter_rw_b2);
      q2_hist_myccqereweighter_rw_b3->Fill(s2, weight_myccqereweighter_rw_b3);
      q2_hist_myccqereweighter_rw_b4->Fill(s2, weight_myccqereweighter_rw_b4);
      
      q2_hist_myccqereweighter_rw_b1_minus->Fill(s2, weight_myccqereweighter_rw_b1_minus);
      q2_hist_myccqereweighter_rw_b2_minus->Fill(s2, weight_myccqereweighter_rw_b2_minus);
      q2_hist_myccqereweighter_rw_b3_minus->Fill(s2, weight_myccqereweighter_rw_b3_minus);
      q2_hist_myccqereweighter_rw_b4_minus->Fill(s2, weight_myccqereweighter_rw_b4_minus);

      q2_hist_myccqereweighter_rw_b1_b2->Fill(s2, weight_myccqereweighter_rw_b1_b2);
      q2_hist_myccqereweighter_rw_b1_b3->Fill(s2, weight_myccqereweighter_rw_b1_b3);
      q2_hist_myccqereweighter_rw_b2_b3->Fill(s2, weight_myccqereweighter_rw_b2_b3);
      q2_hist_myccqereweighter_rw_b1_b4->Fill(s2, weight_myccqereweighter_rw_b1_b4);
      q2_hist_myccqereweighter_rw_b2_b4->Fill(s2, weight_myccqereweighter_rw_b2_b4);
      q2_hist_myccqereweighter_rw_b3_b4->Fill(s2, weight_myccqereweighter_rw_b3_b4);

      q2_hist_myccqereweighter_rw_b1_b2_b3->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3);
      q2_hist_myccqereweighter_rw_b1_b3_b4->Fill(s2, weight_myccqereweighter_rw_b1_b3_b4);
      q2_hist_myccqereweighter_rw_b2_b3_b4->Fill(s2, weight_myccqereweighter_rw_b2_b3_b4);
      q2_hist_myccqereweighter_rw_b1_b2_b4->Fill(s2, weight_myccqereweighter_rw_b1_b2_b4);
      
      q2_hist_myccqereweighter_rw_b1_b2_minus->Fill(s2, weight_myccqereweighter_rw_b1_b2_minus);
      q2_hist_myccqereweighter_rw_b1_b3_minus->Fill(s2, weight_myccqereweighter_rw_b1_b3_minus);
      q2_hist_myccqereweighter_rw_b2_b3_minus->Fill(s2, weight_myccqereweighter_rw_b2_b3_minus);
      q2_hist_myccqereweighter_rw_b1_b4_minus->Fill(s2, weight_myccqereweighter_rw_b1_b4_minus);
      q2_hist_myccqereweighter_rw_b2_b4_minus->Fill(s2, weight_myccqereweighter_rw_b2_b4_minus);
      q2_hist_myccqereweighter_rw_b3_b4_minus->Fill(s2, weight_myccqereweighter_rw_b3_b4_minus);

      q2_hist_myccqereweighter_rw_b1_b2_b3_minus->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3_minus);
      q2_hist_myccqereweighter_rw_b1_b3_b4_minus->Fill(s2, weight_myccqereweighter_rw_b1_b3_b4_minus);
      q2_hist_myccqereweighter_rw_b2_b3_b4_minus->Fill(s2, weight_myccqereweighter_rw_b2_b3_b4_minus);
      q2_hist_myccqereweighter_rw_b1_b2_b4_minus->Fill(s2, weight_myccqereweighter_rw_b1_b2_b4_minus);

      q2_hist_myccqereweighter_rw_b1_b2_b3_b4->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3_b4);
      q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3_b4_minus);

      q2_hist_myccqereweighter_rw_b1_b2_b3_b4_point1->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3_b4_point1);
      q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus_point1->Fill(s2, weight_myccqereweighter_rw_b1_b2_b3_b4_minus_point1);
      // loop through throws
     
      // loop through throws
     
      for (int i = 0; i < NThrows; ++i) {
        // for each throw get the pre-set-up-calculator for that throw and ask for
        // its weight
        throw_weights[i] = rand_b_reweight_engines[i]->CalcWeight(*ntpl->event);
        myhists[i]->Fill(s2, throw_weights[i]);
      }

    
    if (e_it > 100000) {
      break;
    }
    protonnumber->Fill(proton_count++); //move later!!
    ntpl->Clear();
    //tree_out->Fill(); 
  }
  std::cout << "left for loop" << std::endl;
  protonmomentumx->SetXTitle("px(GeV/c)");
  protonmomentumy->SetXTitle("py(GeV/c)");
  protonmomentumz->SetXTitle("pz(GeV/c)");
  finalstateprotons_with_greatestmomentum->SetYTitle("Highest momentum final state proton events");
  finalstateprotons_with_greatestmomentum->SetXTitle("p (GeV/c)");
  enu->SetXTitle("Energy (GeV)");
  enu->SetYTitle("Neutrino Events");
  emuon->SetXTitle("Energy (GeV)");
  emuon->SetYTitle("Muon Events");
  emuon->Write();
  enu->Write();
  protonmomentumx->Write();
  protonmomentumy->Write();
  protonmomentumz->Write();
  proton_momentum_total->Write();
  protonnumber->SetXTitle("Number of final state protons");
  protonnumber->Write();
  finalstateprotons_with_greatestmomentum->Write();

  q2_hist->Write();
  q2_hist_rw->Write();
  q2_hist_rw_a1->Write();
  q2_hist_rw_a2->Write();
  q2_hist_rw_a3->Write();
  q2_hist_rw_a4->Write();
  q2_hist_rw_altogether->Write();


  q2_hist_rw_minus->Write();
  q2_hist_rw_a1_minus->Write();
  q2_hist_rw_a2_minus->Write();
  q2_hist_rw_a3_minus->Write();
  q2_hist_rw_a4_minus->Write();
  q2_hist_rw_altogether_minus->Write();

  
  q2_hist_myccqereweighter_rw_b1->Write();
  q2_hist_myccqereweighter_rw_b2->Write();
  q2_hist_myccqereweighter_rw_b3->Write();
  q2_hist_myccqereweighter_rw_b4->Write();
  
  q2_hist_myccqereweighter_rw_b1_minus->Write();
  q2_hist_myccqereweighter_rw_b2_minus->Write();
  q2_hist_myccqereweighter_rw_b3_minus->Write();
  q2_hist_myccqereweighter_rw_b4_minus->Write();

  q2_hist_myccqereweighter_rw_b1_b2->Write();
  q2_hist_myccqereweighter_rw_b1_b3->Write();
  q2_hist_myccqereweighter_rw_b2_b3->Write();
  q2_hist_myccqereweighter_rw_b1_b4->Write();
  q2_hist_myccqereweighter_rw_b2_b4->Write();
  q2_hist_myccqereweighter_rw_b3_b4->Write();

  q2_hist_myccqereweighter_rw_b1_b2_b3->Write();
  q2_hist_myccqereweighter_rw_b1_b3_b4->Write();
  q2_hist_myccqereweighter_rw_b2_b3_b4->Write();
  q2_hist_myccqereweighter_rw_b1_b2_b4->Write();
  
  q2_hist_myccqereweighter_rw_b1_b2_minus->Write();
  q2_hist_myccqereweighter_rw_b1_b3_minus->Write();
  q2_hist_myccqereweighter_rw_b2_b3_minus->Write();
  q2_hist_myccqereweighter_rw_b1_b4_minus->Write();
  q2_hist_myccqereweighter_rw_b2_b4_minus->Write();
  q2_hist_myccqereweighter_rw_b3_b4_minus->Write();

  q2_hist_myccqereweighter_rw_b1_b2_b3_minus->Write();
  q2_hist_myccqereweighter_rw_b1_b3_b4_minus->Write();
  q2_hist_myccqereweighter_rw_b2_b3_b4_minus->Write();
  q2_hist_myccqereweighter_rw_b1_b2_b4_minus->Write();

  q2_hist_myccqereweighter_rw_b1_b2_b3_b4->Write();
  q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus->Write();

  q2_hist_myccqereweighter_rw_b1_b2_b3_b4_point1->Write();
  q2_hist_myccqereweighter_rw_b1_b2_b3_b4_minus_point1->Write();
  
  for(int i=0 ; i < NThrows ; ++i){
    TString histname = Form("histogram_throw_%d", i);
    //myhists.at(i) = (TH1F*) GetOutputList()->FindObject(histname.Data());
    myhists[i]->Write();

  }
  //myhists.Write();
 
 

  TH1D *mystatshisto = new TH1D("mystatshisto", ";Q2;count", 25, 0, 7);

  //now do stats on the throws
  for (int bin_i = 0; bin_i < myhists.front()->GetXaxis()->GetNbins(); ++bin_i) {

    double mean = 0;

    for (int throw_j = 0; throw_j < NThrows; ++throw_j) {
      //add the bin content for bin i from throw j
      // the +1 is to skip the underflow bin
      mean += myhists[throw_j]->GetBinContent(bin_i+1);
    }

    mean /= double(NThrows);

    double variance = 0;

    for (int throw_j = 0; throw_j < NThrows; ++throw_j) {
      double diff_from_mean = myhists[throw_j]->GetBinContent(bin_i+1) - mean;
      variance += std::pow(diff_from_mean,2);
    }

    variance /= double(NThrows-1);
   
    double stddev = std::sqrt(variance);

    mystatshisto->SetBinContent(bin_i+1,mean);
    mystatshisto->SetBinError(bin_i+1,stddev);

  }
    mystatshisto->Write();
    
   q2_hist_cv_zexp->Write();
  std::cout << "done with priting histos" << std::endl;

  fin->Close();
  results->Close();
  std::cout << "closed ROOT file" << std::endl;
  std::cout << "closed ROOT file" << std::endl;
  //#endif

std::cout<<"random b values basis-------------------------------------------------"<<std::endl;
for (int i = 0; i < randbval_vector.size(); i++)
    {
        for (int j = 0; j < randbval_vector[i].size(); j++)
        {
            cout << randbval_vector[i][j] << " ";
        }    
        cout << endl;
    }
  
std::cout<<"syst a values------------------------------------------------------"<<std::endl;
for (int i = 0; i < syst_avals_vector.size(); i++)
    {
        for (int j = 0; j < syst_avals_vector[i].size(); j++)
        {
            cout << syst_avals_vector[i][j] << " ";
        }    
        cout << endl;
    }

std::cout<<"avalues_for_genie_vector------------------------------------------------------"<<std::endl;
for (int i = 0; i < avalues_for_genie_vector.size(); i++)
    {
        for (int j = 0; j < avalues_for_genie_vector[i].size(); j++)
        {
            cout << avalues_for_genie_vector[i][j] << " ";
        }    
        cout << endl;
    }
tree_out->Write();
file_out->Write();
file_out->Close();

    
}