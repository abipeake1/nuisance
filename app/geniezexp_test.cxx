#include "Framework/GHEP/GHepParticle.h"

#include "TTree.h"

#include <iostream>

int main(){

  TTree *tn = new TTree("gtree");
  Long64_t nevt = tn->GetEntries();

  NtpMCEventRecord *genientpl = NULL;
  tn->SetBranchAddress("gmcrec", &genientpl);

  for(Long64_t e_it = 0; e_it < nevt; ++e_it){
    tn->GetEntry(e_it);

    std::cout << "[INFO]: Got entry " << e_it << std::endl;

    if(e_it > 100){
      break;
    } 
  }

}