//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr  3 17:39:23 2019 by ROOT version 6.14/08
// from TTree nominal/tree
//////////////////////////////////////////////////////////

#ifndef Nominal_h
#define Nominal_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "fatjet.h"

// Headers needed by this particular selector
#include <vector>
#include <string>
#include <map>


class Nominal : public TSelector {
public :
   TTreeReader    fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain
   std::vector<TString> systs_list;
   TString do_which_systematic;
   // Some variables are here only for MC and some for data.
   TTreeReaderValue<uint32_t> DSID = {fReader, "DSID"}; //only for MC
   //TTreeReaderValue<uint32_t> RunNumber = {fReader, "RunNumber"}; //only for data
   TTreeReaderValue<unsigned long long> EventNumber = {fReader, "EventNumber"};
   TTreeReaderValue<uint32_t> LumiBlock = {fReader, "LumiBlock"};
   TTreeReaderValue<Float_t> EventWeight = {fReader, "EventWeight"}; //only for MC
   TTreeReaderValue<Float_t> PileupWeight = {fReader, "PileupWeight"}; //only for MC
   TTreeReaderArray<char> JetIsSelected = {fReader, "JetIsSelected"};
   TTreeReaderArray<char> JetIsSelectedLoose = {fReader, "JetIsSelectedLoose"};
   TTreeReaderArray<float> JetPt = {fReader, "JetPt"};
   TTreeReaderArray<float> JetEta = {fReader, "JetEta"};
   TTreeReaderArray<float> JetPhi = {fReader, "JetPhi"};
   TTreeReaderArray<float> JetMass = {fReader, "JetMass"};
   TTreeReaderArray<char> TrackJetIsSelected = {fReader, "TrackJetIsSelected"};
   //TTreeReaderArray<int> TrackJetTruthLabelId = {fReader, "TrackJetTruthLabelId"};
   TTreeReaderArray<float> TrackJetPt = {fReader, "TrackJetPt"};
   TTreeReaderArray<float> TrackJetEta = {fReader, "TrackJetEta"};
   TTreeReaderArray<float> TrackJetPhi = {fReader, "TrackJetPhi"};
   TTreeReaderArray<float> TrackJetMass = {fReader, "TrackJetMass"};
   TTreeReaderArray<char> TrackJetPassDR = {fReader, "TrackJetPassDR"};
   TTreeReaderArray<char> ElectronIsSelected = {fReader, "ElectronIsSelected"};
   TTreeReaderArray<char> ElectronIsSelectedLoose = {fReader, "ElectronIsSelectedLoose"};
   TTreeReaderArray<float> ElectronPt = {fReader, "ElectronPt"};
   TTreeReaderArray<float> ElectronEta = {fReader, "ElectronEta"};
   TTreeReaderArray<float> ElectronPhi = {fReader, "ElectronPhi"};
   TTreeReaderArray<char> MuonIsSelected = {fReader, "MuonIsSelected"};
   TTreeReaderArray<char> MuonIsSelectedLoose = {fReader, "MuonIsSelectedLoose"};
   TTreeReaderArray<float> MuonPt = {fReader, "MuonPt"};
   TTreeReaderArray<float> MuonEta = {fReader, "MuonEta"};
   TTreeReaderArray<float> MuonPhi = {fReader, "MuonPhi"};
   TTreeReaderArray<char> LargeRJetIsSelected = {fReader, "LargeRJetIsSelected"};
   TTreeReaderArray<float> LargeRJetPt = {fReader, "LargeRJetPt"};
   TTreeReaderArray<float> LargeRJetEta = {fReader, "LargeRJetEta"};
   TTreeReaderArray<float> LargeRJetPhi = {fReader, "LargeRJetPhi"};
   TTreeReaderArray<float> LargeRJetMass = {fReader, "LargeRJetMass"};
   // TTreeReaderArray<float> LargeRJetTau1 = {fReader, "LargeRJetTau1"};
   //TTreeReaderArray<float> LargeRJetTau2 = {fReader, "LargeRJetTau2"};
   TTreeReaderArray<float> LargeRJetTau21 = {fReader, "LargeRJetTau21"};
   //TTreeReaderArray<float> LargeRJetTau3 = {fReader, "LargeRJetTau3"};
   TTreeReaderArray<float> LargeRJetECF1 = {fReader, "LargeRJetECF1"};
   TTreeReaderArray<float> LargeRJetECF2 = {fReader, "LargeRJetECF2"};
   TTreeReaderArray<float> LargeRJetECF3 = {fReader, "LargeRJetECF3"};
   TTreeReaderArray<float> LargeRJetAngularity = {fReader, "LargeRJetAngularity"};
   //TTreeReaderArray<float> LargeRJetZCut23 = {fReader, "LargeRJetZCut23"};
   //TTreeReaderArray<float> LargeRJetZCut34 = {fReader, "LargeRJetZCut34"};
   //TTreeReaderArray<float> LargeRJetFoxWolfram4 = {fReader, "LargeRJetFoxWolfram4"};
   TTreeReaderArray<float> LargeRJetFoxWolfram2 = {fReader, "LargeRJetFoxWolfram2"};
   TTreeReaderArray<float> LargeRJetThrustMin = {fReader, "LargeRJetThrustMin"};
   TTreeReaderArray<float> LargeRJetAplanarity = {fReader, "LargeRJetAplanarity"};
   TTreeReaderArray<float> LargeRJetPlanarFlow = {fReader, "LargeRJetPlanarFlow"};
   TTreeReaderArray<float> LargeRJetNtrk = {fReader, "LargeRJetNtrk"};
   TTreeReaderArray<float> LargeRJetMu12 = {fReader, "LargeRJetMu12"};
   TTreeReaderArray<float> LargeRJetSplit12 = {fReader, "LargeRJetSplit12"};
   TTreeReaderArray<float> LargeRJetXbbScoreTop = {fReader, "LargeRJetXbbScoreTop"};
   TTreeReaderArray<float> LargeRJetXbbScoreQCD = {fReader, "LargeRJetXbbScoreQCD"};
   TTreeReaderArray<float> LargeRJetXbbScoreHiggs = {fReader, "LargeRJetXbbScoreHiggs"};
   TTreeReaderArray<float> LargeRJetHbbScoreTop = {fReader, "LargeRJetHbbScoreTop"};
   TTreeReaderArray<float> LargeRJetHbbScoreQCD = {fReader, "LargeRJetHbbScoreQCD"};
   TTreeReaderArray<float> LargeRJetHbbScoreHiggs = {fReader, "LargeRJetHbbScoreHiggs"};
   //TTreeReaderArray<int> LargeRJetPassWD2 = {fReader, "LargeRJetPassWD2"};
   //TTreeReaderArray<int> LargeRJetPassWNtrk = {fReader, "LargeRJetPassWNtrk"};
   //TTreeReaderArray<int> LargeRJetPassWMassHigh = {fReader, "LargeRJetPassWMassHigh"};
   //TTreeReaderArray<int> LargeRJetPassWMassLow = {fReader, "LargeRJetPassWMassLow"};
   //TTreeReaderArray<int> LargeRJetPassWNtrkD2 = {fReader, "LargeRJetPassWNtrkD2"};
   //TTreeReaderArray<int> LargeRJetPassZD2 = {fReader, "LargeRJetPassZD2"};
   //TTreeReaderArray<int> LargeRJetPassZNtrk = {fReader, "LargeRJetPassZNtrk"};
   //TTreeReaderArray<int> LargeRJetPassZMassHigh= {fReader, "LargeRJetPassZMassHigh"};
   //TTreeReaderArray<int> LargeRJetPassZMassLow = {fReader, "LargeRJetPassZMassLow"};
   TTreeReaderArray<int> LargeRJetPassZD2_80 = {fReader, "LargeRJetPassZD2_80"};
   TTreeReaderArray<int> LargeRJetPassZNtrk_80 = {fReader, "LargeRJetPassZNtrk_80"};
   TTreeReaderArray<int> LargeRJetPassZMassHigh_80= {fReader, "LargeRJetPassZMassHigh_80"};
   TTreeReaderArray<int> LargeRJetPassZMassLow_80 = {fReader, "LargeRJetPassZMassLow_80"};
   TTreeReaderArray<int> LargeRJetTruthLabel = {fReader, "LargeRJetTruthLabel"};

   //TTreeReaderArray<int> LargeRJetPassWD2_50 = {fReader, "LargeRJetPassWD2_50"};
   //TTreeReaderArray<int> LargeRJetPassWNtrk_50 = {fReader, "LargeRJetPassWNtrk_50"};
   //TTreeReaderArray<int> LargeRJetPassWMassHigh_50 = {fReader, "LargeRJetPassWMassHigh_50"};
   //TTreeReaderArray<int> LargeRJetPassWMassLow_50 = {fReader, "LargeRJetPassWMassLow_50"};
   //TTreeReaderArray<int> LargeRJetPassWNtrkD2_50 = {fReader, "LargeRJetPassWNtrkD2_50"};
   TTreeReaderArray<int> LargeRJetPassZD2_50 = {fReader, "LargeRJetPassZD2_50"};
   TTreeReaderArray<int> LargeRJetPassZNtrk_50 = {fReader, "LargeRJetPassZNtrk_50"};
   TTreeReaderArray<int> LargeRJetPassZMassHigh_50= {fReader, "LargeRJetPassZMassHigh_50"};
   TTreeReaderArray<int> LargeRJetPassZMassLow_50 = {fReader, "LargeRJetPassZMassLow_50"};
   //TTreeReaderArray<int> LargeRJetPassWD2_80 = {fReader, "LargeRJetPassWD2_80"};
   //TTreeReaderArray<int> LargeRJetPassWNtrk_80 = {fReader, "LargeRJetPassWNtrk_80"};
   //TTreeReaderArray<int> LargeRJetPassWMassHigh_80 = {fReader, "LargeRJetPassWMassHigh_80"};
   //TTreeReaderArray<int> LargeRJetPassWMassLow_80 = {fReader, "LargeRJetPassWMassLow_80"};
   //TTreeReaderArray<int> LargeRJetPassWNtrkD2_80 = {fReader, "LargeRJetPassWNtrkD2_80"};
   //TTreeReaderArray<int> LargeRJetPassZD2_80 = {fReader, "LargeRJetPassZD2_80"};
   //TTreeReaderArray<int> LargeRJetPassZNtrk_80 = {fReader, "LargeRJetPassZNtrk_80"};
   //TTreeReaderArray<int> LargeRJetPassZMassHigh_80= {fReader, "LargeRJetPassZMassHigh_80"};
   //TTreeReaderArray<int> LargeRJetPassZMassLow_80 = {fReader, "LargeRJetPassZMassLow_80"};
   
   TTreeReaderArray<std::vector<unsigned long>> LargeRJetAssociatedTrackJet = {fReader, "LargeRJetAssociatedTrackJet"};
   TTreeReaderValue<Bool_t> Analysis = {fReader, "Analysis"};
   //   TTreeReaderArray<char> JetIsBTagged_DL1rmu_FixedCutBEff_60 = {fReader, "JetIsBTagged_DL1rmu_FixedCutBEff_60"};
   /*TTreeReaderArray<char> JetIsBTagged_DL1_FixedCutBEff_60 = {fReader, "JetIsBTagged_DL1_FixedCutBEff_60"};
   TTreeReaderArray<char> JetIsBTagged_DL1_FixedCutBEff_70 = {fReader, "JetIsBTagged_DL1_FixedCutBEff_70"};
   TTreeReaderArray<char> JetIsBTagged_DL1_FixedCutBEff_77 = {fReader, "JetIsBTagged_DL1_FixedCutBEff_77"};
   TTreeReaderArray<char> JetIsBTagged_DL1_FixedCutBEff_85 = {fReader, "JetIsBTagged_DL1_FixedCutBEff_85"};*/
   /* TTreeReaderArray<char> JetIsBTagged_DL1rmu_FixedCutBEff_70 = {fReader, "JetIsBTagged_DL1rmu_FixedCutBEff_70"};
   TTreeReaderArray<char> JetIsBTagged_DL1rmu_FixedCutBEff_77 = {fReader, "JetIsBTagged_DL1rmu_FixedCutBEff_77"};
   TTreeReaderArray<char> JetIsBTagged_DL1rmu_FixedCutBEff_85 = {fReader, "JetIsBTagged_DL1rmu_FixedCutBEff_85"};
   TTreeReaderArray<char> JetIsBTagged_DL1r_FixedCutBEff_60 = {fReader, "JetIsBTagged_DL1r_FixedCutBEff_60"};
   TTreeReaderArray<char> JetIsBTagged_DL1r_FixedCutBEff_70 = {fReader, "JetIsBTagged_DL1r_FixedCutBEff_70"};
   TTreeReaderArray<char> JetIsBTagged_DL1r_FixedCutBEff_77 = {fReader, "JetIsBTagged_DL1r_FixedCutBEff_77"};
   TTreeReaderArray<char> JetIsBTagged_DL1r_FixedCutBEff_85 = {fReader, "JetIsBTagged_DL1r_FixedCutBEff_85"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1rmu_FixedCutBEff_60 = {fReader, "TrackJetIsBTagged_DL1rmu_FixedCutBEff_60"}; */
   /* TTreeReaderArray<char> TrackJetIsBTagged_DL1_FixedCutBEff_60 = {fReader, "TrackJetIsBTagged_DL1_FixedCutBEff_60"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1_FixedCutBEff_70 = {fReader, "TrackJetIsBTagged_DL1_FixedCutBEff_70"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1_FixedCutBEff_77 = {fReader, "TrackJetIsBTagged_DL1_FixedCutBEff_77"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1_FixedCutBEff_85 = {fReader, "TrackJetIsBTagged_DL1_FixedCutBEff_85"};*/
   /*TTreeReaderArray<char> TrackJetIsBTagged_DL1rmu_FixedCutBEff_70 = {fReader, "TrackJetIsBTagged_DL1rmu_FixedCutBEff_70"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1rmu_FixedCutBEff_77 = {fReader, "TrackJetIsBTagged_DL1rmu_FixedCutBEff_77"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1rmu_FixedCutBEff_85 = {fReader, "TrackJetIsBTagged_DL1rmu_FixedCutBEff_85"};*/
   TTreeReaderArray<char> TrackJetIsBTagged_DL1r_FixedCutBEff_60 = {fReader, "TrackJetIsBTagged_DL1r_FixedCutBEff_60"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1r_FixedCutBEff_70 = {fReader, "TrackJetIsBTagged_DL1r_FixedCutBEff_70"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1r_FixedCutBEff_77 = {fReader, "TrackJetIsBTagged_DL1r_FixedCutBEff_77"};
   TTreeReaderArray<char> TrackJetIsBTagged_DL1r_FixedCutBEff_85 = {fReader, "TrackJetIsBTagged_DL1r_FixedCutBEff_85"};
   
   float mc_weighted;
   float dsid_weights;

   // TH1D * selection;
   TH1D * cutflow_Vqq;
   TH1D * cutflow_Vbb;
   TH1D * jet_pt;
   TH1D * jet_mass;
   TH1D * largeRjet_pt;
   TH1D * largeRjet_mass;
   TH1D * Zcand_Tau21;
   TH1D * Zcand_Tau21_0b;

   TH1D * Zcand_Xbb50_pT;
   TH1D * Zcand_Xbb60_pT;
   TH1D * Zcand_Xbb70_pT;
   TH1D * Zcand_Xbb80_pT;

   TH1D * Zcand_Xbb50_pT_wom;
   TH1D * Zcand_Xbb60_pT_wom;
   TH1D * Zcand_Xbb70_pT_wom;
   TH1D * Zcand_Xbb80_pT_wom;

   TH1D * Zcand_Tau21_1b60;
   TH1D * Zcand_Tau21_2b60;
   TH1D * Zcand_Tau21_1b70;
   TH1D * Zcand_Tau21_2b70;
   TH1D * Zcand_Tau21_1b77;
   TH1D * Zcand_Tau21_2b77;
   TH1D * Zcand_Tau21_1b85;
   TH1D * Zcand_Tau21_2b85;
   TH1D * Zcand_Tau32;
   TH1D * Zcand_D2;
   TH1D * Zcand_ECF3;
   TH1D * Zcand_ECF2;
   TH1D * Zcand_Angularity;
   TH1D * Zcand_ZCut23;
   TH1D * Zcand_ZCut34;
   TH1D * Zcand_ThrustMin;
   TH1D * Zcand_FoxWolfram42;
   TH1D * Zcand_Aplanarity;
   TH1D * Zcand_PlanarFlow;
   TH1D * Zcand_Mu12;
   TH1D * Zcand_Split12;
   TH1D * trackjet_pt;
   TH1D * Zcand_Xbb;
   /*TH1D * trackjet_pt_0tag;
   TH1D * trackjet_pt_MV260;
   TH1D * trackjet_pt_MV270;
   TH1D * trackjet_pt_MV277;
   TH1D * trackjet_pt_MV285;*/
   TH1D * trackjet_mass;
   TH1D * muon_pt;
   TH1D * ntrk_hist;
   TH1D * pTass_hist;
   TH1D * del_y;

   TH1D * Selected_leading_largeRjet_pt;   
   TH1D * Selected_leading_largeRjet_mass;
   TH1D * Selected_subleading_largeRjet_pt;
   TH1D * Selected_subleading_largeRjet_mass;
   TH1D * Selected_largeRjet_deltaR;

   TH1D * Selected_pTsymmetry_leading_largeRjet_pt;
   TH1D * Selected_pTsymmetry_leading_largeRjet_mass;
   TH1D * Selected_pTsymmetry_subleading_largeRjet_pt;
   TH1D * Selected_pTsymmetry_subleading_largeRjet_mass;
   TH1D * Selected_pTsymmetry_largeRjet_deltaR;

   TH1D * Selected_pTsymmetry_etaCut_leading_largeRjet_pt;
   TH1D * Selected_pTsymmetry_etaCut_leading_largeRjet_mass;
   TH1D * Selected_pTsymmetry_etaCut_subleading_largeRjet_pt;
   TH1D * Selected_pTsymmetry_etaCut_subleading_largeRjet_mass;
   TH1D * Selected_pTsymmetry_etaCut_largeRjet_deltaR;

   TH1D * Wtagged_smooth50_mass;
   TH1D * Wtagged_smooth50_pt;
   TH1D * Wtagged_smooth80_mass;
   TH1D * Wtagged_smooth80_pt;

   TH1D * Ztagged_smooth50_mass;
   TH1D * Ztagged_smooth50_pt;
   TH1D * Ztagged_smooth80_mass;
   TH1D * Ztagged_smooth80_pt;

   TH1D * Tagged_50_mass;
   TH1D * Tagged_50_pt;
   TH1D * Tagged_50_ntrk;
   TH1D * Tagged_50_leadtrk_pt;
   TH1D * Tagged_50_subtrk_pt;
   TH1D * Tagged_50_deltaR;

   TH1D * Tagged_80_mass;
   TH1D * Tagged_80_pt;
   TH1D * Tagged_80_ntrk;
   TH1D * Tagged_80_leadtrk_pt;
   TH1D * Tagged_80_subtrk_pt;
   TH1D * Tagged_80_deltaR;

   TH1D * Tagged_mass;
   TH1D * Tagged_pt;
   TH1D * Tagged_ntrk;
   TH1D * Tagged_leadtrk_pt;
   TH1D * Tagged_subtrk_pt;
   TH1D * Tagged_deltaR;
   
   TH1D * Zcand_ntrk;   
   TH1D * Zcand_mass;
   TH1D * Zcand_inc_mass;
   TH1D * Zcand_pt_D2cut;
   TH1D * Zcand_mass_D2cut;
   TH1D * Zcand_pt_Tau2135cut;
   TH1D * Zcand_pt_Tau2140cut;
   TH1D * Zcand_pt_Tau2145cut;
   TH1D * Zcand_mass_Tau21cut;
   TH1D * Zcand_pt_Tmin25cut;
   TH1D * Zcand_pt_Tmin30cut;
   TH1D * Zcand_pt_Tmin35cut;
   TH1D * Zcand_mass_Tmincut;
   TH1D * Zcand_mass_TminPFlow;
   TH1D * Zcand_pt_TminPFlow;
   TH1D * Zcand_mass_TminTau21;
   TH1D * Zcand_pt_TminTau21;
   TH1D * Zcand_mass_PFlowTau21;
   TH1D * Zcand_pt_PFlowTau21;
   TH1D * Zcand_mass_All3;
   TH1D * Zcand_pt_All3;
   TH1D * Zcand_pt;
   TH1D * Zcand_pre_pt;
   TH1D * Zcand_pt_Mu12cut;
   TH1D * Zcand_mass_Mu12cut;
   TH1D * Zcand_pt_PFlow32cut;
   TH1D * Zcand_pt_PFlow34cut;
   TH1D * Zcand_pt_PFlow36cut;
   TH1D * Zcand_mass_PFlowcut;
   TH1D * Zcand_leadtrk_pt;
   TH1D * pTassy;
   TH1D * rapid;
   TH1D * Zcand_subtrk_pt;
   TH1D * Zcand_imass_leadtrk_pt;
   TH1D * Zcand_imass_subtrk_pt;
   TH1D * Zcand_deltaR;
   TH1D * Zcand_opt_largeRjet_mass;
   
   TH1D * Zcand_imass_2b_DL1r_70_mass;
   TH1D * Zcand_imass_2b_DL1r_70_pt;
   
   TH1D * Zcand_imass_2b_DL1r_77_mass;
   TH1D * Zcand_imass_2b_DL1r_77_pt;
   TH1D * Zcand_0b_DL1r_mass;
   TH1D * Zcand_0b_DL1r_pt;
   TH1D * Zcand_0b_DL1r_leadtrk_pt;
   TH1D * Zcand_0b_DL1r_subtrk_pt;
   TH1D * Zcand_0b_DL1r_deltaR;

   TH1D * Zcand_Xbb50_mass;
   TH1D * Zcand_Xbb60_mass;
   TH1D * Zcand_Xbb70_mass;
   TH1D * Zcand_Xbb80_mass;
   
   
   
   TH1D * Zcand_Xbb50_mass_pT455;
   TH1D * Zcand_Xbb50_mass_pT56;
   TH1D * Zcand_Xbb50_mass_pT67;
   TH1D * Zcand_Xbb50_mass_pT78;
   TH1D * Zcand_Xbb50_mass_pT89;
   TH1D * Zcand_Xbb50_mass_pT910;
   TH1D * Zcand_Xbb50_mass_pT710;
   
   TH1D * Zcand_Xbb60_mass_pT455;
   TH1D * Zcand_Xbb60_mass_pT56;
   TH1D * Zcand_Xbb60_mass_pT67;
   TH1D * Zcand_Xbb60_mass_pT78;
   TH1D * Zcand_Xbb60_mass_pT89;
   TH1D * Zcand_Xbb60_mass_pT910;
   TH1D * Zcand_Xbb60_mass_pT710;
   
   TH1D * Zcand_Xbb70_mass_pT455;
   TH1D * Zcand_Xbb70_mass_pT56;
   TH1D * Zcand_Xbb70_mass_pT67;
   TH1D * Zcand_Xbb70_mass_pT78;
   TH1D * Zcand_Xbb70_mass_pT89;
   TH1D * Zcand_Xbb70_mass_pT910;
   TH1D * Zcand_Xbb70_mass_pT710;
   
   TH1D * Zcand_Xbb80_mass_pT455;
   TH1D * Zcand_Xbb80_mass_pT56;
   TH1D * Zcand_Xbb80_mass_pT67;
   TH1D * Zcand_Xbb80_mass_pT78;
   TH1D * Zcand_Xbb80_mass_pT89;
   TH1D * Zcand_Xbb80_mass_pT910;
   TH1D * Zcand_Xbb80_mass_pT710;

   TH1D * Zcand_Xbb50_mass_pT456;
   TH1D * Zcand_Xbb50_mass_pT610;

   TH1D * Zcand_Xbb60_mass_pT456;
   TH1D * Zcand_Xbb60_mass_pT610;

   TH1D * Zcand_Xbb70_mass_pT456;
   TH1D * Zcand_Xbb70_mass_pT610;

   TH1D * Zcand_Xbb80_mass_pT456;
   TH1D * Zcand_Xbb80_mass_pT610;

   //category 1 for top tqqb
   TH1D * Zcand_Xbb50_mass_cat1;
   TH1D * Zcand_Xbb60_mass_cat1;
   TH1D * Zcand_Xbb70_mass_cat1;
   TH1D * Zcand_Xbb80_mass_cat1;

   TH1D * Zcand_Xbb50_mass_cat1_pT455;
   TH1D * Zcand_Xbb50_mass_cat1_pT56;
   TH1D * Zcand_Xbb50_mass_cat1_pT67;
   TH1D * Zcand_Xbb50_mass_cat1_pT710;
   
   TH1D * Zcand_Xbb60_mass_cat1_pT455;
   TH1D * Zcand_Xbb60_mass_cat1_pT56;
   TH1D * Zcand_Xbb60_mass_cat1_pT67;
   TH1D * Zcand_Xbb60_mass_cat1_pT710;
   
   TH1D * Zcand_Xbb70_mass_cat1_pT455;
   TH1D * Zcand_Xbb70_mass_cat1_pT56;
   TH1D * Zcand_Xbb70_mass_cat1_pT67;
   TH1D * Zcand_Xbb70_mass_cat1_pT710;
   
   TH1D * Zcand_Xbb80_mass_cat1_pT455;
   TH1D * Zcand_Xbb80_mass_cat1_pT56;
   TH1D * Zcand_Xbb80_mass_cat1_pT67;
   TH1D * Zcand_Xbb80_mass_cat1_pT710;

   TH1D * Zcand_Xbb50_mass_cat1_pT456;
   TH1D * Zcand_Xbb50_mass_cat1_pT610;

   TH1D * Zcand_Xbb60_mass_cat1_pT456;
   TH1D * Zcand_Xbb60_mass_cat1_pT610;

   TH1D * Zcand_Xbb70_mass_cat1_pT456;
   TH1D * Zcand_Xbb70_mass_cat1_pT610;

   TH1D * Zcand_Xbb80_mass_cat1_pT456;
   TH1D * Zcand_Xbb80_mass_cat1_pT610;
   
   //category 2 for w from t + others from top
   TH1D * Zcand_Xbb50_mass_cat2;
   TH1D * Zcand_Xbb60_mass_cat2;
   TH1D * Zcand_Xbb70_mass_cat2;
   TH1D * Zcand_Xbb80_mass_cat2;

   TH1D * Zcand_Xbb50_mass_cat2_pT455;
   TH1D * Zcand_Xbb50_mass_cat2_pT56;
   TH1D * Zcand_Xbb50_mass_cat2_pT67;
   TH1D * Zcand_Xbb50_mass_cat2_pT710;
   
   TH1D * Zcand_Xbb60_mass_cat2_pT455;
   TH1D * Zcand_Xbb60_mass_cat2_pT56;
   TH1D * Zcand_Xbb60_mass_cat2_pT67;
   TH1D * Zcand_Xbb60_mass_cat2_pT710;
   
   TH1D * Zcand_Xbb70_mass_cat2_pT455;
   TH1D * Zcand_Xbb70_mass_cat2_pT56;
   TH1D * Zcand_Xbb70_mass_cat2_pT67;
   TH1D * Zcand_Xbb70_mass_cat2_pT710;
   
   TH1D * Zcand_Xbb80_mass_cat2_pT455;
   TH1D * Zcand_Xbb80_mass_cat2_pT56;
   TH1D * Zcand_Xbb80_mass_cat2_pT67;
   TH1D * Zcand_Xbb80_mass_cat2_pT710;

   TH1D * Zcand_Xbb50_mass_cat2_pT456;
   TH1D * Zcand_Xbb50_mass_cat2_pT610;

   TH1D * Zcand_Xbb60_mass_cat2_pT456;
   TH1D * Zcand_Xbb60_mass_cat2_pT610;

   TH1D * Zcand_Xbb70_mass_cat2_pT456;
   TH1D * Zcand_Xbb70_mass_cat2_pT610;

   TH1D * Zcand_Xbb80_mass_cat2_pT456;
   TH1D * Zcand_Xbb80_mass_cat2_pT610;

   
   TH1D * Zcand_Xbb50_mass_cat2_W;
   TH1D * Zcand_Xbb60_mass_cat2_W;
   TH1D * Zcand_Xbb70_mass_cat2_W;
   TH1D * Zcand_Xbb80_mass_cat2_W;

   TH1D * Zcand_Xbb50_mass_cat2_O;
   TH1D * Zcand_Xbb60_mass_cat2_O;
   TH1D * Zcand_Xbb70_mass_cat2_O;
   TH1D * Zcand_Xbb80_mass_cat2_O;

   TH1D * Zcand_Xbb60_mass_pT455_data;
   TH1D * Zcand_Xbb60_mass_pT56_data;
   TH1D * Zcand_Xbb60_mass_pT67_data;
   TH1D * Zcand_Xbb60_mass_pT78_data;
   TH1D * Zcand_Xbb60_mass_pT89_data;
   TH1D * Zcand_Xbb60_mass_pT910_data;
   TH1D * Zcand_Xbb60_mass_pT710_data;

   TH1D * Zcand_Xbb70_mass_pT455_data;
   TH1D * Zcand_Xbb70_mass_pT56_data;
   TH1D * Zcand_Xbb70_mass_pT67_data;
   TH1D * Zcand_Xbb70_mass_pT78_data;
   TH1D * Zcand_Xbb70_mass_pT89_data;
   TH1D * Zcand_Xbb70_mass_pT910_data;
   TH1D * Zcand_Xbb70_mass_pT710_data;


   TH1D * Zcand_Xbb60_mass_pT456_data;
   TH1D * Zcand_Xbb60_mass_pT610_data;

   TH1D * Zcand_Xbb70_mass_pT456_data;
   TH1D * Zcand_Xbb70_mass_pT610_data;

   TH1D * Zcand_Xbb60_mass_data;
   TH1D * Zcand_Xbb70_mass_data;
   
   TH1D * Zcand_1b_DL1r_60_mass;
   TH1D * Zcand_1b_DL1r_60_pt;
   
   TH1D * Zcand_1b_DL1r_60_leadtrk_mass;
   TH1D * Zcand_1b_DL1r_60_subtrk_mass;

   TH1D * Zcand_1b_DL1r_70_leadtrk_mass;
   TH1D * Zcand_1b_DL1r_70_subtrk_mass;

   TH1D * Zcand_1b_DL1r_77_leadtrk_mass;
   TH1D * Zcand_1b_DL1r_77_subtrk_mass;

   TH1D * Zcand_1b_DL1r_85_leadtrk_mass;
   TH1D * Zcand_1b_DL1r_85_subtrk_mass;

   /*TH1D * Zcand_2b_DL1r_60_mass;
   TH1D * Zcand_2b_DL1r_60_pt;
   TH1D * Zcand_2b_DL1r_70_mass;
   TH1D * Zcand_2b_DL1r_70_pt;
   TH1D * Zcand_2b_DL1r_77_mass;
   TH1D * Zcand_2b_DL1r_77_pt;
   TH1D * Zcand_2b_DL1r_85_mass;
   TH1D * Zcand_2b_DL1r_85_pt;*/

   TH1D * Zcand_1b_DL1r_60_mass_pT455;
   TH1D * Zcand_1b_DL1r_60_pt_pT455;
   TH1D * Zcand_1b_DL1r_70_mass_pT455;
   TH1D * Zcand_1b_DL1r_70_pt_pT455;
   TH1D * Zcand_1b_DL1r_77_mass_pT455;
   TH1D * Zcand_1b_DL1r_77_pt_pT455;
   TH1D * Zcand_1b_DL1r_85_mass_pT455;
   TH1D * Zcand_1b_DL1r_85_pt_pT455;
    
   TH1D * Zcand_1b_DL1r_60_mass_pT56;
   TH1D * Zcand_1b_DL1r_60_pt_pT56;
   TH1D * Zcand_1b_DL1r_70_mass_pT56;
   TH1D * Zcand_1b_DL1r_70_pt_pT56;
   TH1D * Zcand_1b_DL1r_77_mass_pT56;
   TH1D * Zcand_1b_DL1r_77_pt_pT56;
   TH1D * Zcand_1b_DL1r_85_mass_pT56;
   TH1D * Zcand_1b_DL1r_85_pt_pT56; 

   TH1D * Zcand_1b_DL1r_60_mass_pT67;
   TH1D * Zcand_1b_DL1r_60_pt_pT67;
   TH1D * Zcand_1b_DL1r_70_mass_pT67;
   TH1D * Zcand_1b_DL1r_70_pt_pT67;
   TH1D * Zcand_1b_DL1r_77_mass_pT67;
   TH1D * Zcand_1b_DL1r_77_pt_pT67;
   TH1D * Zcand_1b_DL1r_85_mass_pT67;
   TH1D * Zcand_1b_DL1r_85_pt_pT67;

   TH1D * Zcand_1b_DL1r_60_mass_pT710;
   TH1D * Zcand_1b_DL1r_60_pt_pT710;
   TH1D * Zcand_1b_DL1r_70_mass_pT710;
   TH1D * Zcand_1b_DL1r_70_pt_pT710;
   TH1D * Zcand_1b_DL1r_77_mass_pT710;
   TH1D * Zcand_1b_DL1r_77_pt_pT710;
   TH1D * Zcand_1b_DL1r_85_mass_pT710;
   TH1D * Zcand_1b_DL1r_85_pt_pT710;


   TH1D * Zcand_2b_DL1r_60_mass_pT455;
   TH1D * Zcand_2b_DL1r_60_pt_pT455;
   TH1D * Zcand_2b_DL1r_70_mass_pT455;
   TH1D * Zcand_2b_DL1r_70_pt_pT455;
   TH1D * Zcand_2b_DL1r_77_mass_pT455;
   TH1D * Zcand_2b_DL1r_77_pt_pT455;
   TH1D * Zcand_2b_DL1r_85_mass_pT455;
   TH1D * Zcand_2b_DL1r_85_pt_pT455;

   TH1D * Zcand_2b_DL1r_60_mass_pT56;
   TH1D * Zcand_2b_DL1r_60_pt_pT56;
   TH1D * Zcand_2b_DL1r_70_mass_pT56;
   TH1D * Zcand_2b_DL1r_70_pt_pT56;
   TH1D * Zcand_2b_DL1r_77_mass_pT56;
   TH1D * Zcand_2b_DL1r_77_pt_pT56;
   TH1D * Zcand_2b_DL1r_85_mass_pT56;
   TH1D * Zcand_2b_DL1r_85_pt_pT56;

   TH1D * Zcand_2b_DL1r_60_mass_pT67;
   TH1D * Zcand_2b_DL1r_60_pt_pT67;
   TH1D * Zcand_2b_DL1r_70_mass_pT67;
   TH1D * Zcand_2b_DL1r_70_pt_pT67;
   TH1D * Zcand_2b_DL1r_77_mass_pT67;
   TH1D * Zcand_2b_DL1r_77_pt_pT67;
   TH1D * Zcand_2b_DL1r_85_mass_pT67;
   TH1D * Zcand_2b_DL1r_85_pt_pT67;

   TH1D * Zcand_2b_DL1r_60_mass_pT710;
   TH1D * Zcand_2b_DL1r_60_pt_pT710;
   TH1D * Zcand_2b_DL1r_70_mass_pT710;
   TH1D * Zcand_2b_DL1r_70_pt_pT710;
   TH1D * Zcand_2b_DL1r_77_mass_pT710;
   TH1D * Zcand_2b_DL1r_77_pt_pT710;
   TH1D * Zcand_2b_DL1r_85_mass_pT710;
   TH1D * Zcand_2b_DL1r_85_pt_pT710;


   TH1D * Zcand_1b_DL1r_60_leadtrk_pt;
   TH1D * Zcand_1b_DL1r_60_subtrk_pt;
   TH1D * Zcand_1b_DL1r_60_deltaR;

   TH1D * Zcand_2b_DL1r_60_mass;
   TH1D * Zcand_2b_DL1r_60_pt;
   TH1D * Zcand_2b_DL1r_60_leadtrk_pt;
   TH1D * Zcand_2b_DL1r_60_subtrk_pt;
   TH1D * Zcand_2b_DL1r_60_deltaR;

   TH1D * Zcand_1b_DL1r_70_mass;
   TH1D * Zcand_1b_DL1r_70_pt;
   TH1D * Zcand_1b_DL1r_70_leadtrk_pt;
   TH1D * Zcand_1b_DL1r_70_subtrk_pt;
   TH1D * Zcand_1b_DL1r_70_deltaR;
   
   TH1D * Zcand_2b_DL1r_70_mass;
   TH1D * Zcand_2b_DL1r_70_pt;
   TH1D * Zcand_2b_DL1r_70_leadtrk_pt;
   TH1D * Zcand_2b_DL1r_70_subtrk_pt;
   TH1D * Zcand_2b_DL1r_70_deltaR;

   TH1D * Zcand_1b_DL1r_77_mass;
   TH1D * Zcand_1b_DL1r_77_pt;
   TH1D * Zcand_1b_DL1r_77_leadtrk_pt;
   TH1D * Zcand_1b_DL1r_77_subtrk_pt;
   TH1D * Zcand_1b_DL1r_77_deltaR;

   TH1D * Zcand_2b_DL1r_77_mass;
   TH1D * Zcand_2b_DL1r_77_pt;
   TH1D * Zcand_2b_DL1r_77_leadtrk_pt;
   TH1D * Zcand_2b_DL1r_77_subtrk_pt;
   TH1D * Zcand_2b_DL1r_77_deltaR;

   TH1D * Zcand_1b_DL1r_85_mass;
   TH1D * Zcand_1b_DL1r_85_pt;
   TH1D * Zcand_1b_DL1r_85_leadtrk_pt;
   TH1D * Zcand_1b_DL1r_85_subtrk_pt;
   TH1D * Zcand_1b_DL1r_85_deltaR;

   TH1D * Zcand_2b_DL1r_85_mass;
   TH1D * Zcand_2b_DL1r_85_pt;
   TH1D * Zcand_2b_DL1r_85_leadtrk_pt;
   TH1D * Zcand_2b_DL1r_85_subtrk_pt;
   TH1D * Zcand_2b_DL1r_85_deltaR;

   TH1D *  Zcand_0b_LL_mass;
   TH1D *  Zcand_0b_LL_pt;
   TH1D *  Zcand_1b_LL_60_mass;
   TH1D *  Zcand_1b_LL_60_pt;
   TH1D *  Zcand_2b_LL_60_mass;
   TH1D *  Zcand_2b_LL_60_pt;
  
   TH1D *  Zcand_1b_LL_70_mass;
   TH1D *  Zcand_1b_LL_70_pt;
   TH1D *  Zcand_2b_LL_70_mass;
   TH1D *  Zcand_2b_LL_70_pt;

   TH1D *  Zcand_1b_LL_77_mass;
   TH1D *  Zcand_1b_LL_77_pt;
   TH1D *  Zcand_2b_LL_77_mass;
   TH1D *  Zcand_2b_LL_77_pt;

   TH1D *  Zcand_1b_LL_85_mass;
   TH1D *  Zcand_1b_LL_85_pt;
   TH1D *  Zcand_2b_LL_85_mass;
   TH1D *  Zcand_2b_LL_85_pt;
 
   TH1D *  Zcand_0b_LC_mass;
   TH1D *  Zcand_0b_LC_pt;
   TH1D *  Zcand_1b_LC_60_mass;
   TH1D *  Zcand_1b_LC_60_pt;
   TH1D *  Zcand_2b_LC_60_mass;
   TH1D *  Zcand_2b_LC_60_pt;
  
   TH1D *  Zcand_1b_LC_70_mass;
   TH1D *  Zcand_1b_LC_70_pt;
   TH1D *  Zcand_2b_LC_70_mass;
   TH1D *  Zcand_2b_LC_70_pt;

   TH1D *  Zcand_1b_LC_77_mass;
   TH1D *  Zcand_1b_LC_77_pt;
   TH1D *  Zcand_2b_LC_77_mass;
   TH1D *  Zcand_2b_LC_77_pt;

   TH1D *  Zcand_1b_LC_85_mass;
   TH1D *  Zcand_1b_LC_85_pt;
   TH1D *  Zcand_2b_LC_85_mass;
   TH1D *  Zcand_2b_LC_85_pt;



   TH1D *  Zcand_0b_LB_mass;
   TH1D *  Zcand_0b_LB_pt;
   TH1D *  Zcand_1b_LB_60_mass;
   TH1D *  Zcand_1b_LB_60_pt;
   TH1D *  Zcand_2b_LB_60_mass;
   TH1D *  Zcand_2b_LB_60_pt;
  
   TH1D *  Zcand_1b_LB_70_mass;
   TH1D *  Zcand_1b_LB_70_pt;
   TH1D *  Zcand_2b_LB_70_mass;
   TH1D *  Zcand_2b_LB_70_pt;

   TH1D *  Zcand_1b_LB_77_mass;
   TH1D *  Zcand_1b_LB_77_pt;
   TH1D *  Zcand_2b_LB_77_mass;
   TH1D *  Zcand_2b_LB_77_pt;

   TH1D *  Zcand_1b_LB_85_mass;
   TH1D *  Zcand_1b_LB_85_pt;
   TH1D *  Zcand_2b_LB_85_mass;
   TH1D *  Zcand_2b_LB_85_pt;

   TH1D *  Zcand_0b_CC_mass;
   TH1D *  Zcand_0b_CC_pt;
   TH1D *  Zcand_1b_CC_60_mass;
   TH1D *  Zcand_1b_CC_60_pt;
   TH1D *  Zcand_2b_CC_60_mass;
   TH1D *  Zcand_2b_CC_60_pt;
  
   TH1D *  Zcand_1b_CC_70_mass;
   TH1D *  Zcand_1b_CC_70_pt;
   TH1D *  Zcand_2b_CC_70_mass;
   TH1D *  Zcand_2b_CC_70_pt;

   TH1D *  Zcand_1b_CC_77_mass;
   TH1D *  Zcand_1b_CC_77_pt;
   TH1D *  Zcand_2b_CC_77_mass;
   TH1D *  Zcand_2b_CC_77_pt;

   TH1D *  Zcand_1b_CC_85_mass;
   TH1D *  Zcand_1b_CC_85_pt;
   TH1D *  Zcand_2b_CC_85_mass;
   TH1D *  Zcand_2b_CC_85_pt;

   TH1D *  Zcand_0b_CL_mass;
   TH1D *  Zcand_0b_CL_pt;
   TH1D *  Zcand_1b_CL_60_mass;
   TH1D *  Zcand_1b_CL_60_pt;
   TH1D *  Zcand_2b_CL_60_mass;
   TH1D *  Zcand_2b_CL_60_pt;
  
   TH1D *  Zcand_1b_CL_70_mass;
   TH1D *  Zcand_1b_CL_70_pt;
   TH1D *  Zcand_2b_CL_70_mass;
   TH1D *  Zcand_2b_CL_70_pt;

   TH1D *  Zcand_1b_CL_77_mass;
   TH1D *  Zcand_1b_CL_77_pt;
   TH1D *  Zcand_2b_CL_77_mass;
   TH1D *  Zcand_2b_CL_77_pt;

   TH1D *  Zcand_1b_CL_85_mass;
   TH1D *  Zcand_1b_CL_85_pt;
   TH1D *  Zcand_2b_CL_85_mass;
   TH1D *  Zcand_2b_CL_85_pt;

   TH1D *  Zcand_0b_BL_mass;
   TH1D *  Zcand_0b_BL_pt;
   TH1D *  Zcand_1b_BL_60_mass;
   TH1D *  Zcand_1b_BL_60_pt;
   TH1D *  Zcand_2b_BL_60_mass;
   TH1D *  Zcand_2b_BL_60_pt;
  
   TH1D *  Zcand_1b_BL_70_mass;
   TH1D *  Zcand_1b_BL_70_pt;
   TH1D *  Zcand_2b_BL_70_mass;
   TH1D *  Zcand_2b_BL_70_pt;

   TH1D *  Zcand_1b_BL_77_mass;
   TH1D *  Zcand_1b_BL_77_pt;
   TH1D *  Zcand_2b_BL_77_mass;
   TH1D *  Zcand_2b_BL_77_pt;

   TH1D *  Zcand_1b_BL_85_mass;
   TH1D *  Zcand_1b_BL_85_pt;
   TH1D *  Zcand_2b_BL_85_mass;
   TH1D *  Zcand_2b_BL_85_pt;

   TH1D *  Zcand_BB_mass;
   TH1D *  Zcand_BB_pt;
   TH1D *  Zcand_BL_mass;
   TH1D *  Zcand_BL_pt;
   TH1D *  Zcand_CC_mass;
   TH1D *  Zcand_CC_pt;
   TH1D *  Zcand_CL_mass;
   TH1D *  Zcand_CL_pt;
   TH1D *  Zcand_LL_mass;
   TH1D *  Zcand_LL_pt;
   TH1D *  Zcand_LC_mass;
   TH1D *  Zcand_LC_pt;
   TH1D *  Zcand_LB_mass;
   TH1D *  Zcand_LB_pt;

   TH1D *  Zcand_0b_BB_mass;
   TH1D *  Zcand_0b_BB_pt;
   TH1D *  Zcand_1b_BB_60_mass;
   TH1D *  Zcand_1b_BB_60_pt;
   TH1D *  Zcand_2b_BB_60_mass;
   TH1D *  Zcand_2b_BB_60_pt;
  
   TH1D *  Zcand_1b_BB_70_mass;
   TH1D *  Zcand_1b_BB_70_pt;
   TH1D *  Zcand_2b_BB_70_mass;
   TH1D *  Zcand_2b_BB_70_pt;

   TH1D *  Zcand_1b_BB_77_mass;
   TH1D *  Zcand_1b_BB_77_pt;
   TH1D *  Zcand_2b_BB_77_mass;
   TH1D *  Zcand_2b_BB_77_pt;

   TH1D *  Zcand_1b_BB_85_mass;
   TH1D *  Zcand_1b_BB_85_pt;
   TH1D *  Zcand_2b_BB_85_mass;
   TH1D *  Zcand_2b_BB_85_pt;

   std::vector<TH1*> histlist;
   //TH2D
   TH2D * largeRjet_mass_vs_pt;
   TH2D * Zcand_h2Dpt;
   TH2D * Selected_leading_largeRjet_mass_vs_pt;
   TH2D * Selected_leading_largeRjet_pt_vs_tau21;
   TH2D * Selected_leading_largeRjet_mass_vs_tau21;
   TH2D * Selected_leading_largeRjet_ljetpt_vs_tau21;
   TH2D * Selected_leading_largeRjet_sljetpt_vs_tau21;

   std::vector<TH2*> histlist2;

   Nominal(TTree * /*tree*/ =0) { }
   virtual ~Nominal() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   //virtual void    Terminate(TH1D * h_stat[16],TString mc_filename);
   virtual void    Terminate(TString mc_filename);
   TH1D * makeHist(TString name,int nbins,double x1,double x2);
   TH2D * makeHist2(TString name, int xnbins, double x1, double x2, int ynbins, double y1, double y2);
   void FatToTrackLinks(std::vector<fatjet> & largeRjets,std::vector<trackjet> & trackjets, int & nlargeRjets);
   void EraseUnselectedFatjets(std::vector<fatjet> & largeRjets);
   ClassDef(Nominal,0);

};

#endif

#ifdef Nominal_cxx
void Nominal::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
   fReader.SetTree(tree);
}

Bool_t Nominal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef Nominal_cxx
