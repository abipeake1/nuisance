include <iostream>
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

#include <iostream>

//front matter for reweighting
#include "Framework/Utils/RunOpt.h"
#include "Framework/Utils/AppInit.h"
#include "RwFramework/GReWeightI.h"
#include "RwFramework/GSystSet.h"
#include "RwFramework/GSyst.h"
#include "RwFramework/GReWeight.h"

#include "RwCalculators/GReWeightNuXSecCCQEaxial.h"
#include "RwCalculators/GReWeightNuXSecCCQE.h"



#include <iostream>
#include <Eigen/Dense>
 

using namespace std;
using namespace genie;
using namespace genie::rew;


using Eigen::MatrixXd;
using Eigen::VectorXd;
 
int main()
{
  MatrixXd m = MatrixXd::Random(3,3);
  m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;
  VectorXd v(3);
  v << 1, 2, 3;
  std::cout << "m * v =" << std::endl << m * v << std::endl;
}




Eigen::VectorXd GetAParams(Eigen::MatrixXd const &PCA, Eigen::VectorXd const &BParams);


