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

using namespace std;
using namespace genie;
using namespace genie::rew;



//G18_02a_00_000

int main(int argc, char const *argv[]) {

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


  //myaxreweighter.Reset();


  myaxreweighter.SetSystematic(kXSecTwkDial_AxFFCCQEshape, 1);
  myaxreweighter.Reconfigure(); 

  myccqereweighter.SetMode(GReWeightNuXSecCCQE::kModeZExp);
  std::cout<< myaxreweighter.IsHandled(kXSecTwkDial_AxFFCCQEshape)<< "does the ccurrent weight calc. handle this param?" <<std::endl;

  myccqereweighter.SetSystematic(kXSecTwkDial_ZExpA1CCQE, 1);
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
  TH1 *enu = new TH1D("enu","Enu;E_{nu} (GeV);Count",100,0,70); //new TH1 for energy of incoming neutrino

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

 TH1 *q2_hist = new TH1D("Q2hist","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw = new TH1D("Q2histrw","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a1 = new TH1D("Q2histrwa1","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a2 = new TH1D("Q2histrwa2","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a3 = new TH1D("Q2histrwa3","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a4 = new TH1D("Q2histrwa4","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_altogether = new TH1D("Q2histrwaltogether","q2;Q^{2};Count",25,0,7);

TH1 *q2_hist_rw_minus = new TH1D("Q2histrwminus","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a1_minus = new TH1D("Q2histrwa1minus","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a2_minus = new TH1D("Q2histrwa2minus","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a3_minus = new TH1D("Q2histrwa3minus","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_a4_minus = new TH1D("Q2histrwa4minus","q2;Q^{2};Count",25,0,7);
 TH1 *q2_hist_rw_altogether_minus = new TH1D("Q2histrwaltogetherminus","q2;Q^{2};Count",25,0,7);




  TFile *results = new TFile("050623_newtune_resultsfile_10e5.root","RECREATE","050623newtune_resultsfile_10e5");
  
  for (Long64_t e_it = 0; e_it < nevt; ++e_it){

    tr->GetEntry(e_it);
    
    //get only CCQE events 
    bool is_qe = ntpl->event->Summary()->ProcInfo().IsQuasiElastic();
    bool is_cc = ntpl->event->Summary()->ProcInfo().IsWeakCC();
    if ( !is_qe || !is_cc ) continue;



    //create a Weight calculator
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



/*
    std::cout<< "weight is" << weight << std::endl;
    std::cout<< "weight  a1 is" << weight2 << std::endl;
    std::cout<< " weight a2 is" << weight_a2 << std::endl;
    std::cout<< "weight a3 is" << weight_a3 << std::endl;
    std::cout<< "weight a4 is" << weight_a4 << std::endl;
    */
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
        std::cout << "d incoming neutrino has energy " << p->E() << std::endl;
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
    
    ntpl->Clear();
    if (e_it > 100000) {
      break;
    }
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
      
      protonnumber->Fill(proton_count++); //move later!!

  }

  
  //gStyle->SetPalette(kOcean);
  auto canvas = new TCanvas("canvas", "canvas");
  //TLegend *myLegend=new TLegend(0.4,0.5,0.7,0.7,”My Legend”);
//x1,y1,x2,y2,header
  //myLegend -> SetTextSize(0.04);
  

  q2_hist_rw->Draw();
  //myLegend->AddEntry(&q2_hist, “axial reweighted”, “l”);
  q2_hist_rw_a1->Draw("same");
  q2_hist_rw_a1-> SetLineColor(kRed);

  
  //myLegend->AddEntry(&q2_hist_rw_a1, “a1 reweighted”, “l”);
  q2_hist_rw_a2->Draw("same");
  q2_hist_rw_a2-> SetLineColor(kBlue);
  //myLegend->AddEntry(&q2_hist_rw_a2, “a2 reweighted”, “l”);
  q2_hist_rw_a3->Draw("same");
  q2_hist_rw_a3-> SetLineColor(kGreen);
  //myLegend->AddEntry(&q2_hist_rw_a3, “a3 reweighted”, “l”);
  q2_hist_rw_a4->Draw("same");
  q2_hist_rw_a4-> SetLineColor(kMagenta);




  //myLegend->AddEntry(&q2_hist_rw_a4, “a4 reweighted”, “l”);
  //myLegend->Draw();
  //hs->Add(q2_hist_rw, "axial reweighter");
  //hs->Add(q2_hist_rw_a1, "a1 reweighter");
  //hs->Add(q2_hist_rw_a2, "a2 reweighter");
  //hs->Add(q2_hist_rw_a3, "a3 reweighter");
  //hs->Add(q2_hist_rw_a4, "a4 reweighter");
  //hs->Draw("stacked weighted histograms");
  TLegend legend(.7,.75,.89,.89);
  //TLegend *leg = new TLegend(.1,.7,.3,.9,"Reweighted  z-expansion parameters");
  legend.SetFillColor(0);
  //graph.SetFillColor(0);
  legend.AddEntry(q2_hist, "axial reweighted");
  legend.AddEntry(q2_hist_rw_a1, "a1 reweighted");
  legend.AddEntry(q2_hist_rw_a2, "a2 reweighted");
  legend.AddEntry(q2_hist_rw_a3, "a3 reweighted");
  legend.AddEntry(q2_hist_rw_a4, "a4 reweighted");
  legend.DrawClone("Sames");
  canvas->Draw();
  


  
  //std::cout << "left while loop" << std::endl;
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

  canvas->Write("/stackedhistograms_new.pdf");
  fin->Close();
  results->Close();
  //std::cout << "closed ROOT file" << std::endl;

}