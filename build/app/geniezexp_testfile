#include <iostream>
#include "Framework/GHEP/GHepParticle.h"

#include "TTree.h"

#include <iostream>
#include "Framework/EventGen/EventRecord.h"
#include "Framework/GHEP/GHepParticle.h"
#include "Framework/GHEP/GHepRecord.h"
#include "Framework/Ntuple/NtpMCEventRecord.h"

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1D.h"
//#include "TH3D.h"

#include <iostream>

using namespace genie;

int main(int argc, char const *argv[]) {

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

  for (Long64_t e_it = 0; e_it < nevt; ++e_it) {
    tr->GetEntry(e_it);

    std::cout << "[INFO]: Got entry " << e_it << std::endl;

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

      std::cout << "  part[" << pitr++ << "]: pdg = " << p->Pdg()
                << ", status = " << p->Status() << std::endl;
    
      }
    std::cout << "---" << std::endl;
    ntpl->Clear();
    if (e_it > 1000) {
      break;
    }
  }
  std::cout << "left while loop" << std::endl;
}
