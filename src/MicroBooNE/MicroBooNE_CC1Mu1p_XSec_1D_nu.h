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
#ifndef MICROBOONE_CC1MU1P_1D_NU_H_SEEN
#define MICROBOONE_CC1MU1P_1D_NU_H_SEEN

#include <TMatrixDfwd.h>
#include "Measurement1D.h"

#include <iostream>
#include <fstream>
#include <Eigen/Dense>
using namespace std;

class TH2D;

class MicroBooNE_CC1Mu1p_XSec_1D_nu : public Measurement1D {
public:
  /// Basic Constructor.
  MicroBooNE_CC1Mu1p_XSec_1D_nu(nuiskey samplekey);

  /// Virtual Destructor
  ~MicroBooNE_CC1Mu1p_XSec_1D_nu() {};

  /// Apply signal definition
  bool isSignal(FitEvent* nvect);

  /// Fill kinematic distributions
  void FillEventVariables(FitEvent* customEvent);

  /// Additional smearing matrix multiplication by Ac
  void ConvertEventRates();
  double GetLikelihood();

  //Validating the Chi2
  double GetMaskedChi2(Eigen::VectorXd &data, Eigen::VectorXd &prediction, Eigen::MatrixXd &covar, int bin_to_skip);

  std::string objSuffix; 
  std::string inputFile;
private:
  TMatrixD* fSmearingMatrix;
  enum Distribution { kDeltaPT=0, 
  kDeltaAlphaT=1, 
  kDeltaPhiT=2, 
  kMuonCosTheta=3, 
  kProtonCosTheta=4, 
  kMuonMomentum=5, 
  kProtonMomentum=6, 
  kDeltaPn=7, 
  kDeltaPtx=8, 
  kDeltaPty=9, 
  kECal=10, 
  kEQE=11 };
  Distribution fDist;

};

#endif
