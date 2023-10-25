/*
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <vector>
#include "TRandom3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

#define private public
#define protected public
using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;
//using namespace genie;
//using namespace genie::rew;
fstream file;


//global variables
namespace PRD_93_113015 {
Eigen::Vector4d a_14_cv{2.3,-0.6, -3.8, 2.3,};
Eigen::Vector4d a_14_errors{0.13, 1, 2.5, 2.7};
Eigen::MatrixXd Covariance_Matrix {{0.0169, 0.0455, -0.22035, 0.214461},
  {0.0455, 1. ,-2.245, 0.9909},
  {-0.22035, -2.245, 6.25, -4.62375},
  {0.214461, 0.9909, -4.62375, 7.29}};
Eigen::Array4d central_values_a_from_genie = {2.30 ,-0.60 ,-3.80 ,2.30};
Eigen::Array4d central_values_afrom_errors_genie_code = {0.14,0.67,1,0.75};//-----in genie
Eigen::Array4d central_values_afrom_errors_genie = {0.13,1,2.5,2.7};
}


//functions for NuSystematics    

//Function that takes covariance matrix and returns PCA matrix
Eigen::MatrixXd GetPCAFromCovarianceMatrix(Eigen::MatrixXd const &Covariance_Matrix){
  Eigen::MatrixXd Eigenvalues;
  Eigen::MatrixXd eigenvector_colmatrix;
  Eigen::MatrixXd eigenvalue_sqrt_matrix;
  Eigen::VectorXd eigenvalues_sqrt; 
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(PRD_93_113015::Covariance_Matrix);
    if (eigensolver.info() != Eigen::Success) abort();
    Eigenvalues = (eigensolver.eigenvalues()).asDiagonal();
    eigenvector_colmatrix = eigensolver.eigenvectors();
    eigenvalue_sqrt_matrix = eigenvalues_sqrt.asDiagonal();    
  Eigen::MatrixXd PCA = eigenvalue_sqrt_matrix * eigenvector_colmatrix; 
 return PCA;
}


//Function that takes uncorellated b values, and transforms them into a values using PCA
Eigen::VectorXd GetAValuesFromBValues(std::vector<double> const &BVals, Eigen::MatrixXd const &PCA){
  Eigen::VectorXd avals = Eigen::VectorXd::Zero(4);
  for(size_t i = 0; i < 4; ++i){
    avals += PCA.col(i) * BVals[i]; 
  }
  return avals;
}

//Function to rescale the a parameters for GENIE ReWeight
Eigen::Array4d ScaleAparamsforGenie(Eigen::VectorXd &avals, 
Eigen::Array4d &central_values_from_genie, 
Eigen::Array4d &central_values_errors_from_genie,
Eigen::Vector4d &a_14_cv){
  Eigen::VectorXd avalues_for_genie =
      (((PRD_93_113015::a_14_cv + avals).array() /PRD_93_113015::central_values_a_from_genie.array()) -1.0) /PRD_93_113015::central_values_afrom_errors_genie .array();
  return avalues_for_genie;
}


// Function to pass rotated b parameters to GENIE ReWeight
void SetSystematicInTermsOfB(Eigen::Array4d avalues_for_genie, GReWeightNuXSecCCQE &grw){
  std::vector<GSyst_t> syst_dials = {kXSecTwkDial_ZExpA1CCQE, kXSecTwkDial_ZExpA2CCQE,kXSecTwkDial_ZExpA3CCQE, kXSecTwkDial_ZExpA4CCQE};
  for(size_t i = 0; i < 4; ++i){
    grw.SetMode(GReWeightNuXSecCCQE::kModeZExp);
    grw.SetSystematic(syst_dials[i], avalues_for_genie[i]);
  }
}

*/

