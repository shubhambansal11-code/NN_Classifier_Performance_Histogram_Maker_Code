#define Nominal_cxx
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Nominal.h"
#include <TH2.h>
#include <TH1D.h>
#include <TProfile.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
#include <stdio.h>      /* printf */
#include <TSystemDirectory.h>
#include <TSystem.h>
//************************************************************************
//This file is the main analysis code where you define  all the cuts, fill your desired histograms for both MC and data for Z->bb calibration
//************************************************************************
void Nominal::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  
  // Create all the histograms and set up features
  TString option = GetOption();
  cutflow_Vqq = makeHist("cutflow_Vqq",17,-2,15);
  cutflow_Vbb = makeHist("cutflow_Vbb",17,-2,15);
  jet_pt = makeHist("jet_pt",100,0.,3000);
  jet_mass = makeHist("jet_mass",100,0.,500);
  largeRjet_pt = makeHist("largeRjet_pt",100,200,3000);
  largeRjet_mass = makeHist("largeRjet_mass",250,0.,500);
  trackjet_pt = makeHist("trackjet_pt",100,0.,3000);
  trackjet_mass = makeHist("trackjet_mass",500,0.,500);
  muon_pt = makeHist("muon_pt",100,0.,3000);
  ntrk_hist = makeHist("ntrk",20,0.,20.);
  pTass_hist = makeHist("pT asymmetry",50,0.,1.);
  del_y = makeHist("Del y_12", 50, 0, 4.0); 

  Selected_leading_largeRjet_mass = makeHist("Selected_leading_largeRjet_mass",100,30,500);
  Selected_leading_largeRjet_pt = makeHist("Selected_leading_largeRjet_pt",14,200,3000);
  Selected_subleading_largeRjet_mass = makeHist("Selected_subleading_largeRjet_mass",100,30,500);
  Selected_subleading_largeRjet_pt = makeHist("Selected_subleading_largeRjet_pt",14,200,3000);
  Selected_largeRjet_deltaR = makeHist("Selected_largeRjet_deltaR",50,1.,6.);

  Selected_pTsymmetry_leading_largeRjet_mass = makeHist("Selected_pTsymmetry_leading_largeRjet_mass",100.,30,500);
  Selected_pTsymmetry_leading_largeRjet_pt = makeHist("Selected_pTsymmetry_leading_largeRjet_pt",14,200,3000);
  Selected_pTsymmetry_subleading_largeRjet_mass = makeHist("Selected_pTsymmetry_subleading_largeRjet_mass",100,30,500);
  Selected_pTsymmetry_subleading_largeRjet_pt = makeHist("Selected_pTsymmetry_subleading_largeRjet_pt",14,200,3000);
  Selected_pTsymmetry_largeRjet_deltaR = makeHist("Selected_pTsymmetry_largeRjet_deltaR",50,1.,6.);

  Selected_pTsymmetry_etaCut_leading_largeRjet_mass = makeHist("Selected_pTsymmetry_etaCut_leading_largeRjet_mass",100,30,500);
  Selected_pTsymmetry_etaCut_leading_largeRjet_pt = makeHist("Selected_pTsymmetry_etaCut_leading_largeRjet_pt",14,200,3000);
  Selected_pTsymmetry_etaCut_subleading_largeRjet_mass = makeHist("Selected_pTsymmetry_etaCut_subleading_largeRjet_mass",100,30,500);
  Selected_pTsymmetry_etaCut_subleading_largeRjet_pt = makeHist("Selected_pTsymmetry_etaCut_subleading_largeRjet_pt",14,200,3000);
  Selected_pTsymmetry_etaCut_largeRjet_deltaR = makeHist("Selected_pTsymmetry_etaCut_largeRjet_deltaR",500,1.,6.);
  Zcand_opt_largeRjet_mass = makeHist("Zcand_opt_largeRjet_mass",100,30,500);
  //Wtagged_smooth50_mass = makeHist("Wtagged_smooth50_mass",100,20.,500.);
  //Wtagged_smooth50_pt = makeHist("Wtagged_smooth50_pt",100,200.,3000.);

  Wtagged_smooth80_mass = makeHist("Wtagged_smooth80_mass",24,30,150);
  Wtagged_smooth80_pt = makeHist("Wtagged_smooth80_pt",14,200,3000);

  //Ztagged_smooth50_mass = makeHist("Ztagged_smooth50_mass",100,20.,500.);
  //Ztagged_smooth50_pt = makeHist("Ztagged_smooth50_pt",100,200.,3000.);

  Ztagged_smooth80_mass = makeHist("Ztagged_smooth80_mass",24,30,150);
  Ztagged_smooth80_pt = makeHist("Ztagged_smooth80_pt",14,200,3000);

  Ztagged_smooth50_mass = makeHist("Ztagged_smooth50_mass",40,50,150);
  Ztagged_smooth50_pt = makeHist("Ztagged_smooth50_pt",50,200,3000);

  Tagged_80_mass = makeHist("Tagged_80_mass",100,50,150);
  Tagged_80_pt = makeHist("Tagged_80_pt",50,200,3000);
  Tagged_80_ntrk = makeHist("Tagged_80_ntrk",20,0.,20.);
  Tagged_80_leadtrk_pt = makeHist("Tagged_80_leadtrk_pt",100,0.,500);
  Tagged_80_subtrk_pt = makeHist("Tagged_80_subtrk_pt",100,0.,300);
  Tagged_80_deltaR = makeHist("Tagged_80_deltaR",10,0.,1.);

  Tagged_50_mass = makeHist("Tagged_50_mass",100,50,150);
  Tagged_50_pt = makeHist("Tagged_50_pt",50,200,3000);
  Tagged_50_ntrk = makeHist("Tagged_50_ntrk",20,0.,20.);
  Tagged_50_leadtrk_pt = makeHist("Tagged_50_leadtrk_pt",100,0.,500);
  Tagged_50_subtrk_pt = makeHist("Tagged_50_subtrk_pt",100,0.,300);
  Tagged_50_deltaR = makeHist("Tagged_50_deltaR",10,0.,1.);

  Zcand_mass = makeHist("Zcand_mass",100,50,200);
  Zcand_inc_mass = makeHist("Zcand_inc_mass",10,0,500);
  Zcand_pre_pt = makeHist("Zcand_pre_pt",14,200,3000);
  Zcand_pt = makeHist("Zcand_pt",50,200,3000);
  Zcand_pt_D2cut = makeHist("Zcand_pt_D2cut",100,200,3000);
  Zcand_mass_D2cut = makeHist("Zcand_mass_D2cut",20,50,300);
  
  Zcand_Tau21 = makeHist("Zcand_Tau21",250, 0., 1.3);
  Zcand_Tau21_0b = makeHist("Zcand_Tau21_0b",250, 0., 1.3);
  Zcand_Tau21_1b60 = makeHist("Zcand_Tau21_1b60",250, 0., 1.3);
  Zcand_Tau21_2b60 = makeHist("Zcand_Tau21_2b60",250, 0., 1.3);
  Zcand_Tau21_1b70 = makeHist("Zcand_Tau21_1b70",250, 0., 1.3);
  Zcand_Tau21_2b70 = makeHist("Zcand_Tau21_2b70",250, 0., 1.3);
  Zcand_Tau21_1b77 = makeHist("Zcand_Tau21_1b77",250, 0., 1.3);
  Zcand_Tau21_2b77 = makeHist("Zcand_Tau21_2b77",250, 0., 1.3);
  Zcand_Tau21_1b85 = makeHist("Zcand_Tau21_1b85",250, 0., 1.3);
  Zcand_Tau21_2b85 = makeHist("Zcand_Tau21_2b85",250, 0., 1.3);

  Zcand_Tau32 = makeHist("Zcand_Tau32",250, 0., 1.3);
  Zcand_D2 = makeHist("Zcand_D2",250, 0., 20);
  Zcand_ECF3 = makeHist("Zcand_ECF3",250, 0., 2500e12);//change the binning
  Zcand_ECF2 = makeHist("Zcand_ECF2",250, 0., 1500e6);//change the binning
  Zcand_Angularity = makeHist("Zcand_Angularity", 250, 0,0.014);
  //Zcand_ZCut23 = makeHist("Zcand_ZCut23",250, 0,0.6 );
  //Zcand_ZCut34 = makeHist("Zcand_ZCut34",250, 0,0.6);
  Zcand_ThrustMin = makeHist("Zcand_ThrustMin", 250, 0,1.1 );
  //Zcand_FoxWolfram42 = makeHist("Zcand_FoxWolfram42", 250, -6,6);
  Zcand_Aplanarity = makeHist("Zcand_Aplanarity", 250, 0,0.5 );
  Zcand_PlanarFlow = makeHist("Zcand_PlanarFlow", 250, 0, 1.0);
  Zcand_Mu12 = makeHist("Zcand_Mu12", 250, 0, 1.0 );
  Zcand_Split12 = makeHist("Zcand_Split12", 250, 0,1000);
  Zcand_ntrk = makeHist("Zcand_ntrk",20,0.,20.);
  Zcand_leadtrk_pt = makeHist("Zcand_leadtrk_pt",100,0.,500);
  Zcand_subtrk_pt = makeHist("Zcand_subtrk_pt",100,0.,300);
  Zcand_h2Dpt = makeHist2("Zcand_h2Dpt", 100, 0, 500, 100, 0, 300);
  Zcand_imass_leadtrk_pt = makeHist("Zcand_imass_leadtrk_pt",100,0.,500);
  Zcand_imass_subtrk_pt = makeHist("Zcand_imass_subtrk_pt",100,0.,300);
  Zcand_deltaR = makeHist("Zcand_deltaR",10,0.,1.);
  Zcand_imass_2b_DL1r_70_mass = makeHist("Zcand_imass_2b_DL1r_70_mass",20,50,300);
  Zcand_imass_2b_DL1r_70_pt = makeHist("Zcand_imass_2b_DL1r_70_pt",100,200,3000);
  Zcand_imass_2b_DL1r_77_mass = makeHist("Zcand_imass_2b_DL1r_77_mass",20,50,300);
  Zcand_imass_2b_DL1r_77_pt = makeHist("Zcand_imass_2b_DL1r_77_pt",100,200,3000);

  Zcand_Xbb50_mass = makeHist("Zcand_Xbb50_mass",200,50,250);
  Zcand_Xbb60_mass = makeHist("Zcand_Xbb60_mass",200,50,250);
  Zcand_Xbb70_mass = makeHist("Zcand_Xbb70_mass",200,50,250);
  Zcand_Xbb80_mass = makeHist("Zcand_Xbb80_mass",200,50,250);

  Zcand_Xbb50_pT  = makeHist("Zcand_Xbb50_pT",100,200,3000);
  Zcand_Xbb60_pT  = makeHist("Zcand_Xbb60_pT",100,200,3000);
  Zcand_Xbb70_pT  = makeHist("Zcand_Xbb70_pT",100,200,3000);
  Zcand_Xbb80_pT  = makeHist("Zcand_Xbb80_pT",100,200,3000);
  //histograms without mass cut
  Zcand_Xbb50_pT_wom  = makeHist("Zcand_Xbb50_pT_wom",100,200,3000);
  Zcand_Xbb60_pT_wom  = makeHist("Zcand_Xbb60_pT_wom",100,200,3000);
  Zcand_Xbb70_pT_wom  = makeHist("Zcand_Xbb70_pT_wom",100,200,3000);
  Zcand_Xbb80_pT_wom  = makeHist("Zcand_Xbb80_pT_wom",100,200,3000);
 
  //finer binning covering pT range: 450-500, 500-600, 600-700, 700-1000
  Zcand_Xbb50_mass_pT455 = makeHist("Zcand_Xbb50_mass_pT455",100,50,150);
  Zcand_Xbb50_mass_pT56 = makeHist("Zcand_Xbb50_mass_pT56",100,50,150);
  Zcand_Xbb50_mass_pT67 = makeHist("Zcand_Xbb50_mass_pT67",100,50,150);
  Zcand_Xbb50_mass_pT78 = makeHist("Zcand_Xbb50_mass_pT78",100,50,150);
  Zcand_Xbb50_mass_pT89 = makeHist("Zcand_Xbb50_mass_pT89",100,50,150);
  Zcand_Xbb50_mass_pT910 = makeHist("Zcand_Xbb50_mass_pT910",100,50,150);
  Zcand_Xbb50_mass_pT710 = makeHist("Zcand_Xbb50_mass_pT710",100,50,150);
  
  Zcand_Xbb60_mass_pT455 = makeHist("Zcand_Xbb60_mass_pT455",100,50,150);
  Zcand_Xbb60_mass_pT56 = makeHist("Zcand_Xbb60_mass_pT56",100,50,150);
  Zcand_Xbb60_mass_pT67 = makeHist("Zcand_Xbb60_mass_pT67",100,50,150);
  Zcand_Xbb60_mass_pT78 = makeHist("Zcand_Xbb60_mass_pT78",100,50,150);
  Zcand_Xbb60_mass_pT89 = makeHist("Zcand_Xbb60_mass_pT89",100,50,150);
  Zcand_Xbb60_mass_pT910 = makeHist("Zcand_Xbb60_mass_pT910",100,50,150);
  Zcand_Xbb60_mass_pT710 = makeHist("Zcand_Xbb60_mass_pT710",100,50,150);

  Zcand_Xbb70_mass_pT455 = makeHist("Zcand_Xbb70_mass_pT455",100,50,150);
  Zcand_Xbb70_mass_pT56 = makeHist("Zcand_Xbb70_mass_pT56",100,50,150);
  Zcand_Xbb70_mass_pT67 = makeHist("Zcand_Xbb70_mass_pT67",100,50,150);
  Zcand_Xbb70_mass_pT78 = makeHist("Zcand_Xbb70_mass_pT78",100,50,150);
  Zcand_Xbb70_mass_pT89 = makeHist("Zcand_Xbb70_mass_pT89",100,50,150);
  Zcand_Xbb70_mass_pT910 = makeHist("Zcand_Xbb70_mass_pT910",100,50,150);
  Zcand_Xbb70_mass_pT710 = makeHist("Zcand_Xbb70_mass_pT710",100,50,150);

  Zcand_Xbb80_mass_pT455 = makeHist("Zcand_Xbb80_mass_pT455",100,50,150);
  Zcand_Xbb80_mass_pT56 = makeHist("Zcand_Xbb80_mass_pT56",100,50,150);
  Zcand_Xbb80_mass_pT67 = makeHist("Zcand_Xbb80_mass_pT67",100,50,150);
  Zcand_Xbb80_mass_pT78 = makeHist("Zcand_Xbb80_mass_pT78",100,50,150);
  Zcand_Xbb80_mass_pT89 = makeHist("Zcand_Xbb80_mass_pT89",100,50,150);
  Zcand_Xbb80_mass_pT910 = makeHist("Zcand_Xbb80_mass_pT910",100,50,150);
  Zcand_Xbb80_mass_pT710 = makeHist("Zcand_Xbb80_mass_pT710",100,50,150);
  
  //coarser binning covering pT range: 450-600, 600-1000
  Zcand_Xbb50_mass_pT456 = makeHist("Zcand_Xbb50_mass_pT456",100,50,150);
  Zcand_Xbb50_mass_pT610 = makeHist("Zcand_Xbb50_mass_pT610",100,50,150);
  Zcand_Xbb60_mass_pT456 = makeHist("Zcand_Xbb60_mass_pT456",100,50,150);
  Zcand_Xbb60_mass_pT610 = makeHist("Zcand_Xbb60_mass_pT610",100,50,150);
  Zcand_Xbb70_mass_pT456 = makeHist("Zcand_Xbb70_mass_pT456",100,50,150);
  Zcand_Xbb70_mass_pT610 = makeHist("Zcand_Xbb70_mass_pT610",100,50,150);
  Zcand_Xbb80_mass_pT456 = makeHist("Zcand_Xbb80_mass_pT456",100,50,150);
  Zcand_Xbb80_mass_pT610 = makeHist("Zcand_Xbb80_mass_pT610",100,50,150);

  //LargeJet categorial based splitting for 410471 i.e tt cat 1: tqqb, cat2: W from t + others from t

  //Category 1
  Zcand_Xbb50_mass_cat1 = makeHist("Zcand_Xbb50_mass_cat1",200,50,250);
  Zcand_Xbb60_mass_cat1 = makeHist("Zcand_Xbb60_mass_cat1",200,50,250);
  Zcand_Xbb70_mass_cat1 = makeHist("Zcand_Xbb70_mass_cat1",200,50,250);
  Zcand_Xbb80_mass_cat1 = makeHist("Zcand_Xbb80_mass_cat1",200,50,250);

  Zcand_Xbb50_mass_cat1_pT455 = makeHist("Zcand_Xbb50_mass_cat1_pT455",100,50,150);
  Zcand_Xbb50_mass_cat1_pT56 = makeHist("Zcand_Xbb50_mass_cat1_pT56",100,50,150);
  Zcand_Xbb50_mass_cat1_pT67 = makeHist("Zcand_Xbb50_mass_cat1_pT67",100,50,150);
  Zcand_Xbb50_mass_cat1_pT710 = makeHist("Zcand_Xbb50_mass_cat1_pT710",100,50,150);
  
  Zcand_Xbb60_mass_cat1_pT455 = makeHist("Zcand_Xbb60_mass_cat1_pT455",100,50,150);
  Zcand_Xbb60_mass_cat1_pT56 = makeHist("Zcand_Xbb60_mass_cat1_pT56",100,50,150);
  Zcand_Xbb60_mass_cat1_pT67 = makeHist("Zcand_Xbb60_mass_cat1_pT67",100,50,150);
  Zcand_Xbb60_mass_cat1_pT710 = makeHist("Zcand_Xbb60_mass_cat1_pT710",100,50,150);

  Zcand_Xbb70_mass_cat1_pT455 = makeHist("Zcand_Xbb70_mass_cat1_pT455",100,50,150);
  Zcand_Xbb70_mass_cat1_pT56 = makeHist("Zcand_Xbb70_mass_cat1_pT56",100,50,150);
  Zcand_Xbb70_mass_cat1_pT67 = makeHist("Zcand_Xbb70_mass_cat1_pT67",100,50,150);
  Zcand_Xbb70_mass_cat1_pT710 = makeHist("Zcand_Xbb70_mass_cat1_pT710",100,50,150);

  Zcand_Xbb80_mass_cat1_pT455 = makeHist("Zcand_Xbb80_mass_cat1_pT455",100,50,150);
  Zcand_Xbb80_mass_cat1_pT56 = makeHist("Zcand_Xbb80_mass_cat1_pT56",100,50,150);
  Zcand_Xbb80_mass_cat1_pT67 = makeHist("Zcand_Xbb80_mass_cat1_pT67",100,50,150);
  Zcand_Xbb80_mass_cat1_pT710 = makeHist("Zcand_Xbb80_mass_cat1_pT710",100,50,150);
  
  //coarser binning covering pT range: 450-600, 600-1000
  Zcand_Xbb50_mass_cat1_pT456 = makeHist("Zcand_Xbb50_mass_cat1_pT456",100,50,150);
  Zcand_Xbb50_mass_cat1_pT610 = makeHist("Zcand_Xbb50_mass_cat1_pT610",100,50,150);
  Zcand_Xbb60_mass_cat1_pT456 = makeHist("Zcand_Xbb60_mass_cat1_pT456",100,50,150);
  Zcand_Xbb60_mass_cat1_pT610 = makeHist("Zcand_Xbb60_mass_cat1_pT610",100,50,150);
  Zcand_Xbb70_mass_cat1_pT456 = makeHist("Zcand_Xbb70_mass_cat1_pT456",100,50,150);
  Zcand_Xbb70_mass_cat1_pT610 = makeHist("Zcand_Xbb70_mass_cat1_pT610",100,50,150);
  Zcand_Xbb80_mass_cat1_pT456 = makeHist("Zcand_Xbb80_mass_cat1_pT456",100,50,150);
  Zcand_Xbb80_mass_cat1_pT610 = makeHist("Zcand_Xbb80_mass_cat1_pT610",100,50,150);

  //Category 2
  Zcand_Xbb50_mass_cat2 = makeHist("Zcand_Xbb50_mass_cat2",200,50,250);
  Zcand_Xbb60_mass_cat2 = makeHist("Zcand_Xbb60_mass_cat2",200,50,250);
  Zcand_Xbb70_mass_cat2 = makeHist("Zcand_Xbb70_mass_cat2",200,50,250);
  Zcand_Xbb80_mass_cat2 = makeHist("Zcand_Xbb80_mass_cat2",200,50,250);

  Zcand_Xbb50_mass_cat2_pT455 = makeHist("Zcand_Xbb50_mass_cat2_pT455",100,50,150);
  Zcand_Xbb50_mass_cat2_pT56 = makeHist("Zcand_Xbb50_mass_cat2_pT56",100,50,150);
  Zcand_Xbb50_mass_cat2_pT67 = makeHist("Zcand_Xbb50_mass_cat2_pT67",100,50,150);
  Zcand_Xbb50_mass_cat2_pT710 = makeHist("Zcand_Xbb50_mass_cat2_pT710",100,50,150);
  
  Zcand_Xbb60_mass_cat2_pT455 = makeHist("Zcand_Xbb60_mass_cat2_pT455",100,50,150);
  Zcand_Xbb60_mass_cat2_pT56 = makeHist("Zcand_Xbb60_mass_cat2_pT56",100,50,150);
  Zcand_Xbb60_mass_cat2_pT67 = makeHist("Zcand_Xbb60_mass_cat2_pT67",100,50,150);
  Zcand_Xbb60_mass_cat2_pT710 = makeHist("Zcand_Xbb60_mass_cat2_pT710",100,50,150);

  Zcand_Xbb70_mass_cat2_pT455 = makeHist("Zcand_Xbb70_mass_cat2_pT455",100,50,150);
  Zcand_Xbb70_mass_cat2_pT56 = makeHist("Zcand_Xbb70_mass_cat2_pT56",100,50,150);
  Zcand_Xbb70_mass_cat2_pT67 = makeHist("Zcand_Xbb70_mass_cat2_pT67",100,50,150);
  Zcand_Xbb70_mass_cat2_pT710 = makeHist("Zcand_Xbb70_mass_cat2_pT710",100,50,150);

  Zcand_Xbb80_mass_cat2_pT455 = makeHist("Zcand_Xbb80_mass_cat2_pT455",100,50,150);
  Zcand_Xbb80_mass_cat2_pT56 = makeHist("Zcand_Xbb80_mass_cat2_pT56",100,50,150);
  Zcand_Xbb80_mass_cat2_pT67 = makeHist("Zcand_Xbb80_mass_cat2_pT67",100,50,150);
  Zcand_Xbb80_mass_cat2_pT710 = makeHist("Zcand_Xbb80_mass_cat2_pT710",100,50,150);
  
  //coarser binning covering pT range: 450-600, 600-1000
  Zcand_Xbb50_mass_cat2_pT456 = makeHist("Zcand_Xbb50_mass_cat2_pT456",100,50,150);
  Zcand_Xbb50_mass_cat2_pT610 = makeHist("Zcand_Xbb50_mass_cat2_pT610",100,50,150);
  Zcand_Xbb60_mass_cat2_pT456 = makeHist("Zcand_Xbb60_mass_cat2_pT456",100,50,150);
  Zcand_Xbb60_mass_cat2_pT610 = makeHist("Zcand_Xbb60_mass_cat2_pT610",100,50,150);
  Zcand_Xbb70_mass_cat2_pT456 = makeHist("Zcand_Xbb70_mass_cat2_pT456",100,50,150);
  Zcand_Xbb70_mass_cat2_pT610 = makeHist("Zcand_Xbb70_mass_cat2_pT610",100,50,150);
  Zcand_Xbb80_mass_cat2_pT456 = makeHist("Zcand_Xbb80_mass_cat2_pT456",100,50,150);
  Zcand_Xbb80_mass_cat2_pT610 = makeHist("Zcand_Xbb80_mass_cat2_pT610",100,50,150);

  //Category 2 W(tt)
  Zcand_Xbb50_mass_cat2_W = makeHist("Zcand_Xbb50_mass_cat2_W",200,50,250);
  Zcand_Xbb60_mass_cat2_W = makeHist("Zcand_Xbb60_mass_cat2_W",200,50,250);
  Zcand_Xbb70_mass_cat2_W = makeHist("Zcand_Xbb70_mass_cat2_W",200,50,250);
  Zcand_Xbb80_mass_cat2_W = makeHist("Zcand_Xbb80_mass_cat2_W",200,50,250);
  
  //Category 2 Others(tt)
  Zcand_Xbb50_mass_cat2_O = makeHist("Zcand_Xbb50_mass_cat2_O",200,50,250);
  Zcand_Xbb60_mass_cat2_O = makeHist("Zcand_Xbb60_mass_cat2_O",200,50,250);
  Zcand_Xbb70_mass_cat2_O = makeHist("Zcand_Xbb70_mass_cat2_O",200,50,250);
  Zcand_Xbb80_mass_cat2_O = makeHist("Zcand_Xbb80_mass_cat2_O",200,50,250);

  // for Side-bands data histograms:
  Zcand_Xbb60_mass_pT455_data = makeHist("Zcand_Xbb60_mass_pT455_data",100,50,150);
  Zcand_Xbb60_mass_pT56_data = makeHist("Zcand_Xbb60_mass_pT56_data",100,50,150);
  Zcand_Xbb60_mass_pT67_data = makeHist("Zcand_Xbb60_mass_pT67_data",100,50,150);
  Zcand_Xbb60_mass_pT78_data = makeHist("Zcand_Xbb60_mass_pT78_data",100,50,150);
  Zcand_Xbb60_mass_pT89_data = makeHist("Zcand_Xbb60_mass_pT89_data",100,50,150);
  Zcand_Xbb60_mass_pT910_data = makeHist("Zcand_Xbb60_mass_pT910_data",100,50,150);
  Zcand_Xbb60_mass_pT710_data = makeHist("Zcand_Xbb60_mass_pT710_data",100,50,150);
  
  Zcand_Xbb70_mass_pT455_data = makeHist("Zcand_Xbb70_mass_pT455_data",100,50,150);
  Zcand_Xbb70_mass_pT56_data = makeHist("Zcand_Xbb70_mass_pT56_data",100,50,150);
  Zcand_Xbb70_mass_pT67_data = makeHist("Zcand_Xbb70_mass_pT67_data",100,50,150);
  Zcand_Xbb70_mass_pT78_data = makeHist("Zcand_Xbb70_mass_pT78_data",100,50,150);
  Zcand_Xbb70_mass_pT89_data = makeHist("Zcand_Xbb70_mass_pT89_data",100,50,150);
  Zcand_Xbb70_mass_pT910_data = makeHist("Zcand_Xbb70_mass_pT910_data",100,50,150);
  Zcand_Xbb70_mass_pT710_data = makeHist("Zcand_Xbb70_mass_pT710_data",100,50,150);

  Zcand_Xbb60_mass_pT456_data = makeHist("Zcand_Xbb60_mass_pT456_data",100,50,150);
  Zcand_Xbb60_mass_pT610_data = makeHist("Zcand_Xbb60_mass_pT610_data",100,50,150);
  Zcand_Xbb70_mass_pT456_data = makeHist("Zcand_Xbb70_mass_pT456_data",100,50,150);
  Zcand_Xbb70_mass_pT610_data = makeHist("Zcand_Xbb70_mass_pT610_data",100,50,150);
  
  Zcand_Xbb60_mass_data = makeHist("Zcand_Xbb60_mass_data",100,50,150);
  Zcand_Xbb70_mass_data = makeHist("Zcand_Xbb70_mass_data",100,50,150);

  Zcand_Xbb = makeHist("Zcand_Xbb",50, -15, 15);

  Zcand_0b_DL1r_mass = makeHist("Zcand_0b_DL1r_mass",40,50,200);
  Zcand_0b_DL1r_pt = makeHist("Zcand_0b_DL1r_pt",100,200,3000);
  Zcand_0b_DL1r_leadtrk_pt = makeHist("Zcand_0b_DL1r_leadtrk_pt",100,0.,500);
  Zcand_0b_DL1r_subtrk_pt = makeHist("Zcand_0b_DL1r_subtrk_pt",100,0.,300);
  Zcand_0b_DL1r_deltaR = makeHist("Zcand_0b_DL1r_deltaR",10,0.,1.);
  
  // Histograms for 1b-DL1r 60%, 70%, 77%, 85% 
  Zcand_1b_DL1r_60_mass = makeHist("Zcand_1b_DL1r_60_mass",40,50,200);
  Zcand_1b_DL1r_60_pt = makeHist("Zcand_1b_DL1r_60_pt",100,200,3000);

  //Zcand_1b_DL1r_60_leadtrk_mass = makeHist("Zcand_1b_DL1r_60_leadtrk_mass",40,50,200);
  //Zcand_1b_DL1r_60_subtrk_mass = makeHist("Zcand_1b_DL1r_60_subtrk_mass",40,50,200);

  Zcand_1b_DL1r_70_mass = makeHist("Zcand_1b_DL1r_70_mass",40,50,200);
  Zcand_1b_DL1r_70_pt = makeHist("Zcand_1b_DL1r_70_pt",100,200,3000);

  //Zcand_1b_DL1r_70_leadtrk_mass = makeHist("Zcand_1b_DL1r_70_leadtrk_mass",40,50,200);
  //Zcand_1b_DL1r_70_subtrk_mass = makeHist("Zcand_1b_DL1r_70_subtrk_mass",40,50,200);

  Zcand_1b_DL1r_77_mass = makeHist("Zcand_1b_DL1r_77_mass",40,50,200);
  Zcand_1b_DL1r_77_pt = makeHist("Zcand_1b_DL1r_77_pt",100,200,3000);

  //Zcand_1b_DL1r_77_leadtrk_mass = makeHist("Zcand_1b_DL1r_77_leadtrk_mass",40,50,200);
  //Zcand_1b_DL1r_77_subtrk_mass = makeHist("Zcand_1b_DL1r_77_subtrk_mass",40,50,200);

  Zcand_1b_DL1r_85_mass = makeHist("Zcand_1b_DL1r_85_mass",40,50,200);
  Zcand_1b_DL1r_85_pt = makeHist("Zcand_1b_DL1r_85_pt",100,200,3000);

  //Zcand_1b_DL1r_85_leadtrk_mass = makeHist("Zcand_1b_DL1r_85_leadtrk_mass",40,50,200);
  //Zcand_1b_DL1r_85_subtrk_mass = makeHist("Zcand_1b_DL1r_85_subtrk_mass",40,50,200);
  
  // Histograms for 2b-DL1r 60%, 70%, 77%, 85% 
  Zcand_2b_DL1r_60_mass = makeHist("Zcand_2b_DL1r_60_mass",40,50,200);
  Zcand_2b_DL1r_60_pt = makeHist("Zcand_2b_DL1r_60_pt",100,200,3000);
  Zcand_2b_DL1r_70_mass = makeHist("Zcand_2b_DL1r_70_mass",40,50,200);
  Zcand_2b_DL1r_70_pt = makeHist("Zcand_2b_DL1r_70_pt",100,200,3000);
  Zcand_2b_DL1r_77_mass = makeHist("Zcand_2b_DL1r_77_mass",40,50,200);
  Zcand_2b_DL1r_77_pt = makeHist("Zcand_2b_DL1r_77_pt",100,200,3000);
  Zcand_2b_DL1r_85_mass = makeHist("Zcand_2b_DL1r_85_mass",40,50,200);
  Zcand_2b_DL1r_85_pt = makeHist("Zcand_2b_DL1r_85_pt",100,200,3000);
  
  
  //1b histograms in different pT bins: 

  Zcand_1b_DL1r_60_mass_pT455 = makeHist("Zcand_1b_DL1r_60_mass_pT455",40,50,200);
  Zcand_1b_DL1r_60_pt_pT455 = makeHist("Zcand_1b_DL1r_60_pt_pT455",100,200,3000);
  Zcand_1b_DL1r_70_mass_pT455 = makeHist("Zcand_1b_DL1r_70_mass_pT455",40,50,200);
  Zcand_1b_DL1r_70_pt_pT455 = makeHist("Zcand_1b_DL1r_70_pt_pT455",100,200,3000);
  Zcand_1b_DL1r_77_mass_pT455 = makeHist("Zcand_1b_DL1r_77_mass_pT455",40,50,200);
  Zcand_1b_DL1r_77_pt_pT455 = makeHist("Zcand_1b_DL1r_77_pt_pT455",100,200,3000);
  Zcand_1b_DL1r_85_mass_pT455 = makeHist("Zcand_1b_DL1r_85_mass_pT455",40,50,200);
  Zcand_1b_DL1r_85_pt_pT455 = makeHist("Zcand_1b_DL1r_85_pt_pT455",100,200,3000);

  Zcand_1b_DL1r_60_mass_pT56 = makeHist("Zcand_1b_DL1r_60_mass_pT56",40,50,200);
  Zcand_1b_DL1r_60_pt_pT56 = makeHist("Zcand_1b_DL1r_60_pt_pT56",100,200,3000);
  Zcand_1b_DL1r_70_mass_pT56 = makeHist("Zcand_1b_DL1r_70_mass_pT56",40,50,200);
  Zcand_1b_DL1r_70_pt_pT56 = makeHist("Zcand_1b_DL1r_70_pt_pT56",100,200,3000);
  Zcand_1b_DL1r_77_mass_pT56 = makeHist("Zcand_1b_DL1r_77_mass_pT56",40,50,200);
  Zcand_1b_DL1r_77_pt_pT56 = makeHist("Zcand_1b_DL1r_77_pt_pT56",100,200,3000);
  Zcand_1b_DL1r_85_mass_pT56 = makeHist("Zcand_1b_DL1r_85_mass_pT56",40,50,200);
  Zcand_1b_DL1r_85_pt_pT56 = makeHist("Zcand_1b_DL1r_85_pt_pT56",100,200,3000);

  Zcand_1b_DL1r_60_mass_pT67 = makeHist("Zcand_1b_DL1r_60_mass_pT67",40,50,200);
  Zcand_1b_DL1r_60_pt_pT67 = makeHist("Zcand_1b_DL1r_60_pt_pT67",100,200,3000);
  Zcand_1b_DL1r_70_mass_pT67 = makeHist("Zcand_1b_DL1r_70_mass_pT67",40,50,200);
  Zcand_1b_DL1r_70_pt_pT67 = makeHist("Zcand_1b_DL1r_70_pt_pT67",100,200,3000);
  Zcand_1b_DL1r_77_mass_pT67 = makeHist("Zcand_1b_DL1r_77_mass_pT67",40,50,200);
  Zcand_1b_DL1r_77_pt_pT67 = makeHist("Zcand_1b_DL1r_77_pt_pT67",100,200,3000);
  Zcand_1b_DL1r_85_mass_pT67 = makeHist("Zcand_1b_DL1r_85_mass_pT67",40,50,200);
  Zcand_1b_DL1r_85_pt_pT67 = makeHist("Zcand_1b_DL1r_85_pt_pT67",100,200,3000);

  Zcand_1b_DL1r_60_mass_pT710 = makeHist("Zcand_1b_DL1r_60_mass_pT710",40,50,200);
  Zcand_1b_DL1r_60_pt_pT710 = makeHist("Zcand_1b_DL1r_60_pt_pT710",100,200,3000);
  Zcand_1b_DL1r_70_mass_pT710 = makeHist("Zcand_1b_DL1r_70_mass_pT710",40,50,200);
  Zcand_1b_DL1r_70_pt_pT710 = makeHist("Zcand_1b_DL1r_70_pt_pT710",100,200,3000);
  Zcand_1b_DL1r_77_mass_pT710 = makeHist("Zcand_1b_DL1r_77_mass_pT710",40,50,200);
  Zcand_1b_DL1r_77_pt_pT710 = makeHist("Zcand_1b_DL1r_77_pt_pT710",100,200,3000);
  Zcand_1b_DL1r_85_mass_pT710 = makeHist("Zcand_1b_DL1r_85_mass_pT710",40,50,200);
  Zcand_1b_DL1r_85_pt_pT710 = makeHist("Zcand_1b_DL1r_85_pt_pT710",100,200,3000); 


  //2b histograms in different pT bins: 

  Zcand_2b_DL1r_60_mass_pT455 = makeHist("Zcand_2b_DL1r_60_mass_pT455",40,50,200);
  Zcand_2b_DL1r_60_pt_pT455 = makeHist("Zcand_2b_DL1r_60_pt_pT455",100,200,3000);
  Zcand_2b_DL1r_70_mass_pT455 = makeHist("Zcand_2b_DL1r_70_mass_pT455",40,50,200);
  Zcand_2b_DL1r_70_pt_pT455 = makeHist("Zcand_2b_DL1r_70_pt_pT455",100,200,3000);
  Zcand_2b_DL1r_77_mass_pT455 = makeHist("Zcand_2b_DL1r_77_mass_pT455",40,50,200);
  Zcand_2b_DL1r_77_pt_pT455 = makeHist("Zcand_2b_DL1r_77_pt_pT455",100,200,3000);
  Zcand_2b_DL1r_85_mass_pT455 = makeHist("Zcand_2b_DL1r_85_mass_pT455",40,50,200);
  Zcand_2b_DL1r_85_pt_pT455 = makeHist("Zcand_2b_DL1r_85_pt_pT455",100,200,3000);

  Zcand_2b_DL1r_60_mass_pT56 = makeHist("Zcand_2b_DL1r_60_mass_pT56",40,50,200);
  Zcand_2b_DL1r_60_pt_pT56 = makeHist("Zcand_2b_DL1r_60_pt_pT56",100,200,3000);
  Zcand_2b_DL1r_70_mass_pT56 = makeHist("Zcand_2b_DL1r_70_mass_pT56",40,50,200);
  Zcand_2b_DL1r_70_pt_pT56 = makeHist("Zcand_2b_DL1r_70_pt_pT56",100,200,3000);
  Zcand_2b_DL1r_77_mass_pT56 = makeHist("Zcand_2b_DL1r_77_mass_pT56",40,50,200);
  Zcand_2b_DL1r_77_pt_pT56 = makeHist("Zcand_2b_DL1r_77_pt_pT56",100,200,3000);
  Zcand_2b_DL1r_85_mass_pT56 = makeHist("Zcand_2b_DL1r_85_mass_pT56",40,50,200);
  Zcand_2b_DL1r_85_pt_pT56 = makeHist("Zcand_2b_DL1r_85_pt_pT56",100,200,3000);

  Zcand_2b_DL1r_60_mass_pT67 = makeHist("Zcand_2b_DL1r_60_mass_pT67",40,50,200);
  Zcand_2b_DL1r_60_pt_pT67 = makeHist("Zcand_2b_DL1r_60_pt_pT67",100,200,3000);
  Zcand_2b_DL1r_70_mass_pT67 = makeHist("Zcand_2b_DL1r_70_mass_pT67",40,50,200);
  Zcand_2b_DL1r_70_pt_pT67 = makeHist("Zcand_2b_DL1r_70_pt_pT67",100,200,3000);
  Zcand_2b_DL1r_77_mass_pT67 = makeHist("Zcand_2b_DL1r_77_mass_pT67",40,50,200);
  Zcand_2b_DL1r_77_pt_pT67 = makeHist("Zcand_2b_DL1r_77_pt_pT67",100,200,3000);
  Zcand_2b_DL1r_85_mass_pT67 = makeHist("Zcand_2b_DL1r_85_mass_pT67",40,50,200);
  Zcand_2b_DL1r_85_pt_pT67 = makeHist("Zcand_2b_DL1r_85_pt_pT67",100,200,3000);

  Zcand_2b_DL1r_60_mass_pT710 = makeHist("Zcand_2b_DL1r_60_mass_pT710",40,50,200);
  Zcand_2b_DL1r_60_pt_pT710 = makeHist("Zcand_2b_DL1r_60_pt_pT710",100,200,3000);
  Zcand_2b_DL1r_70_mass_pT710 = makeHist("Zcand_2b_DL1r_70_mass_pT710",40,50,200);
  Zcand_2b_DL1r_70_pt_pT710 = makeHist("Zcand_2b_DL1r_70_pt_pT710",100,200,3000);
  Zcand_2b_DL1r_77_mass_pT710 = makeHist("Zcand_2b_DL1r_77_mass_pT710",40,50,200);
  Zcand_2b_DL1r_77_pt_pT710 = makeHist("Zcand_2b_DL1r_77_pt_pT710",100,200,3000);
  Zcand_2b_DL1r_85_mass_pT710 = makeHist("Zcand_2b_DL1r_85_mass_pT710",40,50,200);
  Zcand_2b_DL1r_85_pt_pT710 = makeHist("Zcand_2b_DL1r_85_pt_pT710",100,200,3000);

  largeRjet_mass_vs_pt = makeHist2("largeRjet_mass_vs_pt",100,200,3000,150,0.,150);

  //Histograms for different trackjet flavours, for different b-tagging benchmarks, here using DL1r discriminant..
  //LL
  Zcand_LL_mass = makeHist("Zcand_LL_mass",100,50,150);
  Zcand_LL_pt = makeHist("Zcand_LL_pt",100,200,3000);
  Zcand_LB_mass = makeHist("Zcand_LB_mass",100,50,150);
  Zcand_LB_pt = makeHist("Zcand_LB_pt",100,200,3000);
  Zcand_LC_mass = makeHist("Zcand_LC_mass",100,50,150);
  Zcand_LC_pt = makeHist("Zcand_LC_pt",100,200,3000);
  Zcand_CC_mass = makeHist("Zcand_CC_mass",100,50,150);
  Zcand_CC_pt = makeHist("Zcand_CC_pt",100,200,3000);
  Zcand_CL_mass = makeHist("Zcand_CL_mass",100,50,150);
  Zcand_CL_pt = makeHist("Zcand_CL_pt",100,200,3000);
  Zcand_BB_mass = makeHist("Zcand_BB_mass",100,50,150);
  Zcand_BB_pt = makeHist("Zcand_BB_pt",100,200,3000);
  Zcand_BL_mass = makeHist("Zcand_BL_mass",100,50,150);
  Zcand_BL_pt = makeHist("Zcand_BL_pt",100,200,3000);


  Zcand_0b_LL_mass = makeHist("Zcand_0b_LL_mass",100,50,150);
  Zcand_0b_LL_pt = makeHist("Zcand_0b_LL_pt",100,200,3000);
  Zcand_1b_LL_60_mass = makeHist("Zcand_1b_LL_60_mass",100,50,150);
  Zcand_1b_LL_60_pt = makeHist("Zcand_1b_LL_60_pt",100,200,3000);
  Zcand_2b_LL_60_mass = makeHist("Zcand_2b_LL_60_mass",100,50,150);
  Zcand_2b_LL_60_pt = makeHist("Zcand_2b_LL_60_pt",100,200,3000);

  Zcand_1b_LL_70_mass = makeHist("Zcand_1b_LL_70_mass",100,50,150);
  Zcand_1b_LL_70_pt = makeHist("Zcand_1b_LL_70_pt",100,200,3000);
  Zcand_2b_LL_70_mass = makeHist("Zcand_2b_LL_70_mass",100,50,150);
  Zcand_2b_LL_70_pt = makeHist("Zcand_2b_LL_70_pt",100,200,3000);

  Zcand_1b_LL_77_mass = makeHist("Zcand_1b_LL_77_mass",100,50,150);
  Zcand_1b_LL_77_pt = makeHist("Zcand_1b_LL_77_pt",100,200,3000);
  Zcand_2b_LL_77_mass = makeHist("Zcand_2b_LL_77_mass",100,50,150);
  Zcand_2b_LL_77_pt = makeHist("Zcand_2b_LL_77_pt",100,200,3000);

  Zcand_1b_LL_85_mass = makeHist("Zcand_1b_LL_85_mass",100,50,150);
  Zcand_1b_LL_85_pt = makeHist("Zcand_1b_LL_85_pt",100,200,3000);
  Zcand_2b_LL_85_mass = makeHist("Zcand_2b_LL_85_mass",100,50,150);
  Zcand_2b_LL_85_pt = makeHist("Zcand_2b_LL_85_pt",100,200,3000);


  //LC
  Zcand_0b_LC_mass = makeHist("Zcand_0b_LC_mass",100,50,150);
  Zcand_0b_LC_pt = makeHist("Zcand_0b_LC_pt",100,200,3000);
  Zcand_1b_LC_60_mass = makeHist("Zcand_1b_LC_60_mass",100,50,150);
  Zcand_1b_LC_60_pt = makeHist("Zcand_1b_LC_60_pt",100,200,3000);
  Zcand_2b_LC_60_mass = makeHist("Zcand_2b_LC_60_mass",100,50,150);
  Zcand_2b_LC_60_pt = makeHist("Zcand_2b_LC_60_pt",100,200,3000);

  Zcand_1b_LC_70_mass = makeHist("Zcand_1b_LC_70_mass",100,50,150);
  Zcand_1b_LC_70_pt = makeHist("Zcand_1b_LC_70_pt",100,200,3000);
  Zcand_2b_LC_70_mass = makeHist("Zcand_2b_LC_70_mass",100,50,150);
  Zcand_2b_LC_70_pt = makeHist("Zcand_2b_LC_70_pt",100,200,3000);

  Zcand_1b_LC_77_mass = makeHist("Zcand_1b_LC_77_mass",100,50,150);
  Zcand_1b_LC_77_pt = makeHist("Zcand_1b_LC_77_pt",100,200,3000);
  Zcand_2b_LC_77_mass = makeHist("Zcand_2b_LC_77_mass",100,50,150);
  Zcand_2b_LC_77_pt = makeHist("Zcand_2b_LC_77_pt",100,200,3000);

  Zcand_1b_LC_85_mass = makeHist("Zcand_1b_LC_85_mass",100,50,150);
  Zcand_1b_LC_85_pt = makeHist("Zcand_1b_LC_85_pt",100,200,3000);
  Zcand_2b_LC_85_mass = makeHist("Zcand_2b_LC_85_mass",100,50,150);
  Zcand_2b_LC_85_pt = makeHist("Zcand_2b_LC_85_pt",100,200,3000);


  //LB
  Zcand_0b_LB_mass = makeHist("Zcand_0b_LB_mass",100,50,150);
  Zcand_0b_LB_pt = makeHist("Zcand_0b_LB_pt",100,200,3000);
  Zcand_1b_LB_60_mass = makeHist("Zcand_1b_LB_60_mass",100,50,150);
  Zcand_1b_LB_60_pt = makeHist("Zcand_1b_LB_60_pt",100,200,3000);
  Zcand_2b_LB_60_mass = makeHist("Zcand_2b_LB_60_mass",100,50,150);
  Zcand_2b_LB_60_pt = makeHist("Zcand_2b_LB_60_pt",100,200,3000);

  Zcand_1b_LB_70_mass = makeHist("Zcand_1b_LB_70_mass",100,50,150);
  Zcand_1b_LB_70_pt = makeHist("Zcand_1b_LB_70_pt",100,200,3000);
  Zcand_2b_LB_70_mass = makeHist("Zcand_2b_LB_70_mass",100,50,150);
  Zcand_2b_LB_70_pt = makeHist("Zcand_2b_LB_70_pt",100,200,3000);

  Zcand_1b_LB_77_mass = makeHist("Zcand_1b_LB_77_mass",100,50,150);
  Zcand_1b_LB_77_pt = makeHist("Zcand_1b_LB_77_pt",100,200,3000);
  Zcand_2b_LB_77_mass = makeHist("Zcand_2b_LB_77_mass",100,50,150);
  Zcand_2b_LB_77_pt = makeHist("Zcand_2b_LB_77_pt",100,200,3000);

  Zcand_1b_LB_85_mass = makeHist("Zcand_1b_LB_85_mass",100,50,150);
  Zcand_1b_LB_85_pt = makeHist("Zcand_1b_LB_85_pt",100,200,3000);
  Zcand_2b_LB_85_mass = makeHist("Zcand_2b_LB_85_mass",100,50,150);
  Zcand_2b_LB_85_pt = makeHist("Zcand_2b_LB_85_pt",100,200,3000);


   //CC
  Zcand_0b_CC_mass = makeHist("Zcand_0b_CC_mass",100,50,150);
  Zcand_0b_CC_pt = makeHist("Zcand_0b_CC_pt",100,200,3000);
  Zcand_1b_CC_60_mass = makeHist("Zcand_1b_CC_60_mass",100,50,150);
  Zcand_1b_CC_60_pt = makeHist("Zcand_1b_CC_60_pt",100,200,3000);
  Zcand_2b_CC_60_mass = makeHist("Zcand_2b_CC_60_mass",100,50,150);
  Zcand_2b_CC_60_pt = makeHist("Zcand_2b_CC_60_pt",100,200,3000);

  Zcand_1b_CC_70_mass = makeHist("Zcand_1b_CC_70_mass",100,50,150);
  Zcand_1b_CC_70_pt = makeHist("Zcand_1b_CC_70_pt",100,200,3000);
  Zcand_2b_CC_70_mass = makeHist("Zcand_2b_CC_70_mass",100,50,150);
  Zcand_2b_CC_70_pt = makeHist("Zcand_2b_CC_70_pt",100,200,3000);

  Zcand_1b_CC_77_mass = makeHist("Zcand_1b_CC_77_mass",100,50,150);
  Zcand_1b_CC_77_pt = makeHist("Zcand_1b_CC_77_pt",100,200,3000);
  Zcand_2b_CC_77_mass = makeHist("Zcand_2b_CC_77_mass",100,50,150);
  Zcand_2b_CC_77_pt = makeHist("Zcand_2b_CC_77_pt",100,200,3000);

  Zcand_1b_CC_85_mass = makeHist("Zcand_1b_CC_85_mass",100,50,150);
  Zcand_1b_CC_85_pt = makeHist("Zcand_1b_CC_85_pt",100,200,3000);
  Zcand_2b_CC_85_mass = makeHist("Zcand_2b_CC_85_mass",100,50,150);
  Zcand_2b_CC_85_pt = makeHist("Zcand_2b_CC_85_pt",100,200,3000);

  //CL
  Zcand_0b_CL_mass = makeHist("Zcand_0b_CL_mass",100,50,150);
  Zcand_0b_CL_pt = makeHist("Zcand_0b_CL_pt",100,200,3000);
  Zcand_1b_CL_60_mass = makeHist("Zcand_1b_CL_60_mass",100,50,150);
  Zcand_1b_CL_60_pt = makeHist("Zcand_1b_CL_60_pt",100,200,3000);
  Zcand_2b_CL_60_mass = makeHist("Zcand_2b_CL_60_mass",100,50,150);
  Zcand_2b_CL_60_pt = makeHist("Zcand_2b_CL_60_pt",100,200,3000);

  Zcand_1b_CL_70_mass = makeHist("Zcand_1b_CL_70_mass",100,50,150);
  Zcand_1b_CL_70_pt = makeHist("Zcand_1b_CL_70_pt",100,200,3000);
  Zcand_2b_CL_70_mass = makeHist("Zcand_2b_CL_70_mass",100,50,150);
  Zcand_2b_CL_70_pt = makeHist("Zcand_2b_CL_70_pt",100,200,3000);

  Zcand_1b_CL_77_mass = makeHist("Zcand_1b_CL_77_mass",100,50,150);
  Zcand_1b_CL_77_pt = makeHist("Zcand_1b_CL_77_pt",100,200,3000);
  Zcand_2b_CL_77_mass = makeHist("Zcand_2b_CL_77_mass",100,50,150);
  Zcand_2b_CL_77_pt = makeHist("Zcand_2b_CL_77_pt",100,200,3000);

  Zcand_1b_CL_85_mass = makeHist("Zcand_1b_CL_85_mass",100,50,150);
  Zcand_1b_CL_85_pt = makeHist("Zcand_1b_CL_85_pt",100,200,3000);
  Zcand_2b_CL_85_mass = makeHist("Zcand_2b_CL_85_mass",100,50,150);
  Zcand_2b_CL_85_pt = makeHist("Zcand_2b_CL_85_pt",100,200,3000);

  //BL
  Zcand_0b_BL_mass = makeHist("Zcand_0b_BL_mass",100,50,150);
  Zcand_0b_BL_pt = makeHist("Zcand_0b_BL_pt",100,200,3000);
  Zcand_1b_BL_60_mass = makeHist("Zcand_1b_BL_60_mass",100,50,150);
  Zcand_1b_BL_60_pt = makeHist("Zcand_1b_BL_60_pt",100,200,3000);
  Zcand_2b_BL_60_mass = makeHist("Zcand_2b_BL_60_mass",100,50,150);
  Zcand_2b_BL_60_pt = makeHist("Zcand_2b_BL_60_pt",100,200,3000);

  Zcand_1b_BL_70_mass = makeHist("Zcand_1b_BL_70_mass",100,50,150);
  Zcand_1b_BL_70_pt = makeHist("Zcand_1b_BL_70_pt",100,200,3000);
  Zcand_2b_BL_70_mass = makeHist("Zcand_2b_BL_70_mass",100,50,150);
  Zcand_2b_BL_70_pt = makeHist("Zcand_2b_BL_70_pt",100,200,3000);

  Zcand_1b_BL_77_mass = makeHist("Zcand_1b_BL_77_mass",100,50,150);
  Zcand_1b_BL_77_pt = makeHist("Zcand_1b_BL_77_pt",100,200,3000);
  Zcand_2b_BL_77_mass = makeHist("Zcand_2b_BL_77_mass",100,50,150);
  Zcand_2b_BL_77_pt = makeHist("Zcand_2b_BL_77_pt",100,200,3000);

  Zcand_1b_BL_85_mass = makeHist("Zcand_1b_BL_85_mass",100,50,150);
  Zcand_1b_BL_85_pt = makeHist("Zcand_1b_BL_85_pt",100,200,3000);
  Zcand_2b_BL_85_mass = makeHist("Zcand_2b_BL_85_mass",100,50,150);
  Zcand_2b_BL_85_pt = makeHist("Zcand_2b_BL_85_pt",100,200,3000);

  //Zcand_BB_mass = makeHist("Zcand_BB_mass",40,50e3,150e3);
  //Zcand_BB_pt = makeHist("Zcand_BB_pt",100,200e3,3000e3);

 //BB
  Zcand_0b_BB_mass = makeHist("Zcand_0b_BB_mass",10,50,150);
  Zcand_0b_BB_pt = makeHist("Zcand_0b_BB_pt",100,200,3000);
  Zcand_1b_BB_60_mass = makeHist("Zcand_1b_BB_60_mass",100,50,150);
  Zcand_1b_BB_60_pt = makeHist("Zcand_1b_BB_60_pt",100,200,3000);
  Zcand_2b_BB_60_mass = makeHist("Zcand_2b_BB_60_mass",100,50,150);
  Zcand_2b_BB_60_pt = makeHist("Zcand_2b_BB_60_pt",100,200,3000);

  Zcand_1b_BB_70_mass = makeHist("Zcand_1b_BB_70_mass",100,50,150);
  Zcand_1b_BB_70_pt = makeHist("Zcand_1b_BB_70_pt",100,200,3000);
  Zcand_2b_BB_70_mass = makeHist("Zcand_2b_BB_70_mass",100,50,150);
  Zcand_2b_BB_70_pt = makeHist("Zcand_2b_BB_70_pt",100,200,3000);

  Zcand_1b_BB_77_mass = makeHist("Zcand_1b_BB_77_mass",100,50,150);
  Zcand_1b_BB_77_pt = makeHist("Zcand_1b_BB_77_pt",100,200,3000);
  Zcand_2b_BB_77_mass = makeHist("Zcand_2b_BB_77_mass",100,50,150);
  Zcand_2b_BB_77_pt = makeHist("Zcand_2b_BB_77_pt",100,200,3000);

  Zcand_1b_BB_85_mass = makeHist("Zcand_1b_BB_85_mass",100,50,150);
  Zcand_1b_BB_85_pt = makeHist("Zcand_1b_BB_85_pt",100,200,3000);
  Zcand_2b_BB_85_mass = makeHist("Zcand_2b_BB_85_mass",100,50,150);
  Zcand_2b_BB_85_pt = makeHist("Zcand_2b_BB_85_pt",100,200,3000);
  
  //***These are definitions for combination cuts for the substructure analysis (to aim for event selection optimisation, 
  //(uncomment only if needed for further crosschecks, since we use baseline selction now)***

  /*Zcand_mass_TminPFlow = makeHist("Zcand_mass_TminPFlow",20,50e3,300e3);
  Zcand_pt_TminPFlow = makeHist("Zcand_pt_TminPFlow",100,200e3,3000e3);
  Zcand_mass_TminTau21 = makeHist("Zcand_mass_TminTau21",20,50e3,300e3);
  Zcand_pt_TminTau21 = makeHist("Zcand_pt_TminTau21",100,200e3,3000e3);
  Zcand_mass_PFlowTau21 = makeHist("Zcand_mass_PFlowTau21",20,50e3,300e3);
  Zcand_pt_PFlowTau21 = makeHist("Zcand_pt_PFlowTau21",100,200e3,3000e3);
  Zcand_mass_All3    =  makeHist("Zcand_mass_All3"   ,20,50e3,300e3);
  Zcand_pt_All3    = makeHist("Zcand_pt_All3   ",100,200e3,3000e3);*/

  /*Zcand_pt_Tau2140cut = makeHist("Zcand_pt_Tau2140cut",100,200e3,3000e3);
  Zcand_pt_Tau2135cut = makeHist("Zcand_pt_Tau2135cut",100,200e3,3000e3);
  Zcand_pt_Tau2145cut = makeHist("Zcand_pt_Tau2145cut",100,200e3,3000e3);
  Zcand_mass_Tau21cut = makeHist("Zcand_mass_Tau21cut",20,50e3,300e3);
  Zcand_pt_Tmin25cut = makeHist("Zcand_pt_Tmin25cut",100,200e3,3000e3);
  Zcand_pt_Tmin30cut = makeHist("Zcand_pt_Tmin30cut",100,200e3,3000e3);
  Zcand_pt_Tmin35cut = makeHist("Zcand_pt_Tmin35cut",100,200e3,3000e3);
  Zcand_mass_Tmincut =  makeHist("Zcand_mass_Tmincut",20,50e3,300e3);
  Zcand_pt_Mu12cut = makeHist("Zcand_pt_Mu12cut",100,200e3,3000e3);
  Zcand_mass_Mu12cut = makeHist("Zcand_mass_Mu12cut",20,50e3,300e3);
  Zcand_pt_PFlow32cut = makeHist("Zcand_pt_PFlow32cut",100,200e3,3000e3);
  Zcand_pt_PFlow34cut = makeHist("Zcand_pt_PFlow34cut",100,200e3,3000e3);
  Zcand_pt_PFlow36cut = makeHist("Zcand_pt_PFlow36cut",100,200e3,3000e3);*/
  
}

void Nominal::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

Bool_t Nominal::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   //std::cout<<"Passed 01"<<std::endl;
   fReader.SetEntry(entry);  
   float totalWeight = 1; //declaration 
   float xs = 0;
   float filteff = 0;
   bool WqqSamples = 0;
   bool ZqqSamples = 0; //for data do this as equal to 1 
   bool ttbarSamples = 0;
   bool QCDSamples = 0;
   bool isZTag = 0;
   bool isWTag = 1;
    //Total Weight definition for Monte Carlo
   if((*DSID) >=364702 && (*DSID) <= 364713){
     totalWeight = ((*EventWeight)*(*PileupWeight)*mc_weighted/dsid_weights)*36.1*0.90*1000000; }
   else{
       totalWeight = ((*EventWeight)*(*PileupWeight)*mc_weighted/dsid_weights)*36.1*1000000; }


   //For running over data, just uncomment the above lines. 


   std::cout<<mc_weighted<<std::endl;
   std::cout<<dsid_weights<<std::endl;
 
   std::cout<<"totalWeight: " << totalWeight <<std::endl;
   std::vector<fatjet> largeRjets;
   std::vector<trackjet> trackjets;
   std::vector<muon> muons; 
   int njets = JetIsSelected.GetSize();   
   int nlargeRjets = LargeRJetIsSelected.GetSize();
   int ntrackjets = TrackJetIsSelected.GetSize();
   int nmuons = MuonIsSelected.GetSize();
   int nmuonsLoose = MuonIsSelectedLoose.GetSize();
   int nelectrons = ElectronIsSelected.GetSize();
   std::cout<<"number of muons = "<<nmuons<<std::endl;
   std::cout<<"number of loose muons = "<<nmuonsLoose<<std::endl;
   std::cout<<"number of electrons = "<<nelectrons<<std::endl;
   //std::cout<<"Passed 2"<<std::endl;
   cutflow_Vqq->Fill(-1.5,totalWeight);
   cutflow_Vbb->Fill(-1.5,totalWeight);
     for (int i=0;i<nlargeRjets; ++i) { 
       fatjet temp;
       temp.SetPtEtaPhiM(LargeRJetPt[i],LargeRJetEta[i],LargeRJetPhi[i],LargeRJetMass[i]);
       temp.isPassNtrk_80 = LargeRJetPassZNtrk_80[i];
       temp.isPassD2_80 = LargeRJetPassZD2_80[i];
       temp.isTagged_80 = LargeRJetPassZD2_80[i] && LargeRJetPassZNtrk_80[i];
       temp.isPassNtrk_50 = LargeRJetPassZNtrk_50[i];
       temp.isPassD2_50 = LargeRJetPassZD2_50[i];
       temp.isTagged_50 = LargeRJetPassZD2_50[i] && LargeRJetPassZNtrk_50[i];
       temp.isXbbTagged = log(LargeRJetHbbScoreHiggs[i]/(0.75*LargeRJetHbbScoreQCD[i]+0.25*LargeRJetHbbScoreTop[i]));
       temp.isFatJetLabel = LargeRJetTruthLabel[i];
       temp.isNtrk = LargeRJetNtrk[i];

       //***The below structure fills in the information for substructure analysis
       //(uncomment only if needed for further crosschecks, since we use baseline selection now)***

       //temp.isPassNtrk = LargeRJetPassWNtrk[i];
       //temp.isPassD2 = LargeRJetPassWD2[i];
       //temp.isTagged = LargeRJetPassWD2[i] && LargeRJetPassWNtrk[i] && LargeRJetPassWMassHigh[i] && LargeRJetPassWMassLow[i];
       //temp.PassD2 = LargeRJetECF3[i]*pow(LargeRJetECF1[i]/LargeRJetECF2[i], 3);
       //temp.PassMu12 = LargeRJetMu12[i];
       // temp.PassTau21 = LargeRJetTau21[i];
       //temp.PassTmin = LargeRJetThrustMin[i];
       //temp.PassPFlow = LargeRJetPlanarFlow[i];
       //temp.PassPt = LargeRJetPt[i];
       /*largeRjet_Tau21->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       largeRjet_Tau32->Fill(LargeRJetTau3[i]/LargeRJetTau2[i], totalWeight);
       largeRjet_ECF3->Fill(LargeRJetECF3[i], totalWeight);
       largeRjet_ECF2->Fill(LargeRJetECF2[i], totalWeight);
       largeRjet_Angularity->Fill(LargeRJetAngularity[i], totalWeight);
       largeRjet_ZCut23->Fill(LargeRJetZCut23[i], totalWeight);
       largeRjet_ZCut34->Fill(LargeRJetZCut34[i], totalWeight);
       largeRjet_ThrustMin->Fill(LargeRJetThrustMin[i], totalWeight);
       largeRjet_FoxWolfram42->Fill(LargeRJetFoxWolfram4[i]/LargeRJetFoxWolfram2[i], totalWeight);
       largeRjet_Aplanarity->Fill(LargeRJetAplanarity[i], totalWeight);
       largeRjet_PlanarFlow->Fill(LargeRJetPlanarFlow[i], totalWeight);
       largeRjet_Mu12->Fill(LargeRJetMu12[i], totalWeight);
       largeRjet_Split12->Fill(LargeRJetSplit12[i], totalWeight);*/
       largeRjets.push_back(temp);
       largeRjet_pt->Fill(LargeRJetPt[i],totalWeight);
       largeRjet_mass->Fill(LargeRJetMass[i],totalWeight);
     } // Close for (int i=0;i<nlargeRjets;++i)
     // }
   for (int i=0;i<ntrackjets;++i) {  
     trackjet temp; 
     temp.SetPtEtaPhiM(TrackJetPt[i],TrackJetEta[i],TrackJetPhi[i],TrackJetMass[i]);
     temp.TrackJetIsBTagged_DL1r_FixedCutBEff_85 = TrackJetIsBTagged_DL1r_FixedCutBEff_85[i];
     temp.TrackJetIsBTagged_DL1r_FixedCutBEff_77 = TrackJetIsBTagged_DL1r_FixedCutBEff_77[i];
     temp.TrackJetIsBTagged_DL1r_FixedCutBEff_70 = TrackJetIsBTagged_DL1r_FixedCutBEff_70[i];
     temp.TrackJetIsBTagged_DL1r_FixedCutBEff_60 = TrackJetIsBTagged_DL1r_FixedCutBEff_60[i];
     trackjets.push_back(temp);
     
      
     trackjet_pt->Fill(TrackJetPt[i],totalWeight);
     trackjet_mass->Fill(TrackJetMass[i],totalWeight);
   } // Close for (int i=0;i<ntrackjets;++i)
  
   for (int i=0;i<nmuons;++i) {
     if (MuonIsSelectedLoose[i] == true) continue;
     muon temp;
     temp.SetPtEtaPhiM(MuonPt[i],MuonEta[i],MuonPhi[i],0.1056);
     muons.push_back(temp);
     muon_pt->Fill(MuonPt[i],totalWeight);
   } // Close for (int i=0;i<nmuons;++i)
   //   std::cout<<"vector of muons made"<<std::endl;
   
   FatToTrackLinks(largeRjets,trackjets,nlargeRjets);
   EraseUnselectedFatjets(largeRjets);
   //***muon-in-jet correction*** (not considering as of now)
   //fatjet *largeRjet = 0;
   //for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj) {
   //  fatjet & largeR = (*lrj);
   //  largeRjet = &largeR;
   //  for (int i = 0; i < largeRjet->GetNumMuonVectors();++i) {
   //    muon * MuonInJet = largeRjet->GetMuonVetctor(i);
   for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj) {
     fatjet & largeR = (*lrj);
     ntrk_hist->Fill(largeR.GetNumTrackVectors(),totalWeight);
   }
   
   fatjet * Tagged_80 = 0;
   fatjet * Tagged_50 = 0;
   fatjet * Zcand = 0;
   fatjet * leading_lrj = 0;
   fatjet * sub_leading_lrj = 0;

   
   double highestPt = 0;
   double secondPt = 0;
  
   if(nlargeRjets > 1) {
     cutflow_Vqq->Fill(-0.5,totalWeight);
     cutflow_Vbb->Fill(-0.5,totalWeight);

     //Process events with at least 2 largeRjets;
     //The event is selected;
   // The Selected has the highest pt..

  highestPt = 450;
  //***Find the leading large-R jet***
  for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj) {
     fatjet & largeR = (*lrj);
     if (largeR.isCand() && largeR.Pt() > highestPt) {
       leading_lrj = &largeR;
       highestPt = leading_lrj->Pt();
     } //close largeR.Pt() > highestPt
     else continue;
  } //close for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj)

  //Selected_leading_largeRjet_pt->Fill(leading_lrj->Pt(),totalWeight);
  //Selected_leading_largeRjet_mass->Fill(leading_lrj->M(),totalWeight);
   //std::cout << "highest Pt: " << leadinglrj->Pt() << "MeV" << std::endl;

  // ***find sub-leading lrj***
  //secondPt = 0;
  for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj) {
    fatjet & largeR = (*lrj);
    if (largeR.isCand() && largeR.Pt() < highestPt) {
      if (largeR.Pt() > secondPt) {
	sub_leading_lrj = &largeR;
	secondPt = sub_leading_lrj->Pt();
      } // Close if (largeR.Pt() > secondPt)
      else continue;
   } // Close if (largeR.Pt() < highestPt)
   else continue;
 }// Close for (auto lrj = largeRjets.begin();lrj != largeRjets.end();++lrj)
  
  if(leading_lrj != 0 && sub_leading_lrj != 0 ){
  
    cutflow_Vqq->Fill(0.5,totalWeight);
    cutflow_Vbb->Fill(0.5,totalWeight);
    Selected_leading_largeRjet_pt->Fill(leading_lrj->Pt(),totalWeight);
    Selected_leading_largeRjet_mass->Fill(leading_lrj->M(),totalWeight);
    // Selected_leading_largeRjet_mass_vs_pt->Fill(leading_lrj->Pt(),leading_lrj->M(),totalWeight);
  double lrj_deltaR = leading_lrj->DeltaR(*sub_leading_lrj);
  Selected_subleading_largeRjet_pt->Fill(sub_leading_lrj->Pt(),totalWeight);
  Selected_subleading_largeRjet_mass->Fill(sub_leading_lrj->M(),totalWeight);
  Selected_largeRjet_deltaR->Fill(lrj_deltaR,totalWeight); 
  double symmetry = (leading_lrj->Pt() - sub_leading_lrj->Pt())/(leading_lrj->Pt() + sub_leading_lrj->Pt());
  double etaCut = abs(leading_lrj->Eta() - sub_leading_lrj->Eta());
  pTass_hist->Fill(symmetry, totalWeight);
  del_y->Fill(etaCut, totalWeight);  
  if( symmetry < 0.15){ //pT asymmetry cut 
     cutflow_Vqq->Fill(1.5,totalWeight);
    cutflow_Vbb->Fill(1.5,totalWeight);
    Selected_pTsymmetry_leading_largeRjet_pt->Fill(leading_lrj->Pt(),totalWeight);
    Selected_pTsymmetry_leading_largeRjet_mass->Fill(leading_lrj->M(),totalWeight);
    Selected_pTsymmetry_subleading_largeRjet_pt->Fill(sub_leading_lrj->Pt(),totalWeight);
    Selected_pTsymmetry_subleading_largeRjet_mass->Fill(sub_leading_lrj->M(),totalWeight);
    Selected_pTsymmetry_largeRjet_deltaR->Fill(lrj_deltaR,totalWeight);
    
    
    if( etaCut < 1.2){ //eta cut
      cutflow_Vqq->Fill(2.5,totalWeight);
      cutflow_Vbb->Fill(2.5,totalWeight);
      Selected_pTsymmetry_etaCut_leading_largeRjet_pt->Fill(leading_lrj->Pt(),totalWeight);
      Selected_pTsymmetry_etaCut_leading_largeRjet_mass->Fill(leading_lrj->M(),totalWeight);
      Selected_pTsymmetry_etaCut_subleading_largeRjet_pt->Fill(sub_leading_lrj->Pt(),totalWeight);
      Selected_pTsymmetry_etaCut_subleading_largeRjet_mass->Fill(sub_leading_lrj->M(),totalWeight);
      Selected_pTsymmetry_etaCut_largeRjet_deltaR->Fill(lrj_deltaR,totalWeight);
    

 

      if( leading_lrj->isTagged_50 && !sub_leading_lrj->isPassD2_50) { 
    Tagged_50 = leading_lrj;
      
   }
   else if(sub_leading_lrj->isTagged_50 && !leading_lrj->isPassD2_50) {
     Tagged_50 = sub_leading_lrj;
     
   }
  if( leading_lrj->isTagged_80 && !sub_leading_lrj->isPassD2_80) { 
    Tagged_80 = leading_lrj;
      
   }
   else if(sub_leading_lrj->isTagged_80 && !leading_lrj->isPassD2_80 ) {
     Tagged_80 = sub_leading_lrj;
     
   }
   //Boosted Boson Tagging histograms (for the pre-tagged investigation scenario)
   if (Tagged_50 != 0 && Tagged_50->M() > 50 && Tagged_50->Pt() > 450 && Tagged_50->Pt() < 3000 && (Tagged_50->Eta() < 2. && Tagged_50->Eta() > -2.)) { 
     Tagged_50_ntrk->Fill(Tagged_50->GetNumTrackVectors(),totalWeight);
     trackjet * leadingtrk_50 = 0;
     trackjet * secondtrk_50 = 0;
     double highestPt_50 = 0;
     double secondPt_50 = 0;
     if(Tagged_50->GetNumTrackVectors() > 1){
     for (int i=0;i<Tagged_50->GetNumTrackVectors();++i) {
       trackjet * trk_50 = Tagged_50->GetTrackVector(i);
       if (trk_50->Pt() > highestPt_50) {
         
	    secondPt_50 = highestPt_50;
	    secondtrk_50 = leadingtrk_50;
	    leadingtrk_50 = trk_50;
	    highestPt_50 = trk_50->Pt();
       } else if (trk_50->Pt() > secondPt_50) {
	    secondtrk_50 = trk_50;
	    secondPt_50 = trk_50->Pt();
       } else continue;
       }
   double deltaR_50 = leadingtrk_50->DeltaR(*secondtrk_50);
   cutflow_Vqq->Fill(3.5,totalWeight);
   Tagged_50_mass->Fill(Tagged_50->M(),totalWeight);
   Tagged_50_pt->Fill(Tagged_50->Pt(),totalWeight);
   Tagged_50_leadtrk_pt->Fill(leadingtrk_50->Pt(),totalWeight);
   Tagged_50_subtrk_pt->Fill(secondtrk_50->Pt(),totalWeight);
   Tagged_50_deltaR->Fill(deltaR_50,totalWeight);
     }
   }
   
   if (Tagged_80 != 0 && Tagged_80->M() > 50 && Tagged_80->Pt() > 450 && Tagged_80->Pt() < 3000  && (Tagged_80->Eta() < 2. && Tagged_80->Eta() > -2.)) { 
     Tagged_80_ntrk->Fill(Tagged_80->GetNumTrackVectors(),totalWeight);
     trackjet * leadingtrk_80 = 0;
     trackjet * secondtrk_80 = 0;
     double highestPt_80 = 0;
     double secondPt_80 = 0;
     if(Tagged_80->GetNumTrackVectors() > 1){
     for (int i=0;i<Tagged_80->GetNumTrackVectors();++i) {
       trackjet * trk_80 = Tagged_80->GetTrackVector(i);
       if (trk_80->Pt() > highestPt_80) {
	 secondPt_80 = highestPt_80;
	 secondtrk_80 = leadingtrk_80;
	 leadingtrk_80 = trk_80;
	 highestPt_80 = trk_80->Pt();
       } else if (trk_80->Pt() > secondPt_80) {
	 secondtrk_80 = trk_80;
	 secondPt_80 = trk_80->Pt();
       } else continue;
       }
   double deltaR_80 = leadingtrk_80->DeltaR(*secondtrk_80);
   cutflow_Vqq->Fill(3.5,totalWeight);
   Tagged_80_mass->Fill(Tagged_80->M(),totalWeight);
   Tagged_80_pt->Fill(Tagged_80->Pt(),totalWeight);
   Tagged_80_leadtrk_pt->Fill(leadingtrk_80->Pt(),totalWeight);
   Tagged_80_subtrk_pt->Fill(secondtrk_80->Pt(),totalWeight);
   Tagged_80_deltaR->Fill(deltaR_80,totalWeight);
     }
   }
   //} //end if(leading_lrj != 0 && sub_leading_lrj !=0)

   //***Substructure analysis based stuff
   //uncomment only if needed as now we are using the baseline selection***
  /*
   trackjet * Zcand_imass_leadingtrk = 0;
     trackjet * Zcand_imass_secondtrk = 0;
     double Zcand_imass_highestPt = 0;
     double Zcand_imass_secondPt = 0;
     if(leading_lrj->PassMu12 < 0.32)
       { Zcand_pt_Mu12cut->Fill(leading_lrj->Pt(),totalWeight);
       }
     if(leading_lrj->PassD2 < 1.50)
       { Zcand_pt_D2cut->Fill(leading_lrj->Pt(),totalWeight);
       }
     if(leading_lrj->PassPFlow < 0.40)
       { Zcand_pt_PFlowcut->Fill(leading_lrj->Pt(),totalWeight);
       }
      if(leading_lrj->PassTmin < 0.32 )
       { 
         Zcand_pt_Tmincut->Fill(leading_lrj->Pt(),totalWeight);
       }
      if(leading_lrj->PassTau21 < 0.43)
	   {
        Zcand_pt_Tau21cut->Fill(leading_lrj->Pt(),totalWeight);
	   }
      if(leading_lrj->PassTmin < 0.32 && leading_lrj->PassTau21 < 0.43)
       {
	 Zcand_pt_TminTau21->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_TminTau21->Fill(leading_lrj->M(),totalWeight);  
       }
      if(leading_lrj->PassPFlow < 0.40 && leading_lrj->PassTmin < 0.32)
       {
	 Zcand_pt_TminPFlow->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_TminPFlow->Fill(leading_lrj->M(),totalWeight);
       }*/
  ///if(leading_lrj->PassTmin < 0.32)
  ///{ 
         //Zcand_pt_Tmincut->Fill(leading_lrj->Pt(),totalWeight);
	 //if(leading_lrj->PassTau21 < 0.43)
      //{
  ///Zcand_pt_PFlowTau21->Fill(leading_lrj->Pt(),totalWeight);
  
   //****************************************************
   //Selecting a Z candidate
   //*************************************************
   if(leading_lrj->isCand() && leading_lrj->GetNumTrackVectors() > 1){ 
     if(leading_lrj->Pt() >=450 && leading_lrj->Pt() <1000){
       /*
       //This part of code is to incorporate the jet substructure cuts as well
       if(leading_lrj->M() > 50 ) {
         if(leading_lrj->PassPFlow < 0.34 && leading_lrj->PassTau21 < 0.40)
       {
	 Zcand_pt_PFlowTau21->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_PFlowTau21->Fill(leading_lrj->M(),totalWeight);
         
       }
     if(leading_lrj->PassTau21 < 0.40 && leading_lrj->PassTmin < 0.30 )
       {
	 Zcand_pt_TminTau21->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_TminTau21->Fill(leading_lrj->M(),totalWeight);
       }
     if(leading_lrj->PassPFlow < 0.34 && leading_lrj->PassTmin < 0.30)
       {
	 Zcand_pt_TminPFlow->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_TminPFlow->Fill(leading_lrj->M(),totalWeight);
       }
     if(leading_lrj->PassPFlow < 0.34 && leading_lrj->PassTmin < 0.30 && leading_lrj->PassTau21 < 0.40)
       {
	 Zcand_pt_All3->Fill(leading_lrj->Pt(),totalWeight);
         Zcand_mass_All3->Fill(leading_lrj->M(),totalWeight);
       }
     }*/
    Zcand_opt_largeRjet_mass->Fill(leading_lrj->M(),totalWeight);
	 if(leading_lrj->M() > 50 ) {
	  
	 Zcand = leading_lrj;
	 } //Get a Z candidate
	 //}
   }
   }
   //}
   // }


   //***************SUBSTRUCTURE BUSINESS********************************
   /*for (int i=0;i<nlargeRjets; ++i) { 
    fatjet temp2;
    temp2.SetPtEtaPhiM(LargeRJetPt[i],LargeRJetEta[i],LargeRJetPhi[i],LargeRJetMass[i]);
    if (Zcand != 0 && temp2.Pt() == Zcand->Pt() && temp2.M() == Zcand->M() &&  temp2.Eta() == Zcand->Eta() && temp2.Phi() == Zcand->Phi())
      //if()
         {
     Zcand_Tau21->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     //Zcand_Tau32->Fill(LargeRJetTau3[i]/LargeRJetTau2[i], totalWeight);
     Zcand_D2->Fill(LargeRJetECF3[i]*pow(LargeRJetECF1[i]/LargeRJetECF2[i], 3), totalWeight);
     Zcand_ECF2->Fill(LargeRJetECF2[i], totalWeight);
     Zcand_ECF3->Fill(LargeRJetECF3[i], totalWeight);
     Zcand_Angularity->Fill(LargeRJetAngularity[i], totalWeight);
     Zcand_ZCut23->Fill(LargeRJetZCut23[i], totalWeight);
     Zcand_ZCut34->Fill(LargeRJetZCut34[i], totalWeight);
     Zcand_ThrustMin->Fill(LargeRJetThrustMin[i], totalWeight);
     Zcand_FoxWolfram42->Fill(LargeRJetFoxWolfram4[i]/LargeRJetFoxWolfram2[i], totalWeight);
     Zcand_Aplanarity->Fill(LargeRJetAplanarity[i], totalWeight);
     Zcand_PlanarFlow->Fill(LargeRJetPlanarFlow[i], totalWeight);
     Zcand_Mu12->Fill(LargeRJetMu12[i], totalWeight);
     Zcand_Split12->Fill(LargeRJetSplit12[i], totalWeight);  
     if (Zcand->GetBStatus() == 1) {
       Zcand_Tau21_0b->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 2) {
       Zcand_Tau21_1b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 3) {
       Zcand_Tau21_1b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 4) {
       Zcand_Tau21_1b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b70->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 5) {
       Zcand_Tau21_1b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b70->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       /* if(Zcand->Pt() >=200e3 && Zcand->Pt() <=600e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.057);}
       else if(Zcand->Pt() >=600e3 && Zcand->Pt() <=1000e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.099);}
       else if(Zcand->Pt() >=1000e3 && Zcand->Pt() <=1400e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.096);}
       else if(Zcand->Pt() >=1400e3 && Zcand->Pt() <=1800e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.044);}
       else if(Zcand->Pt() >=1800e3 && Zcand->Pt() <=2200e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.119);}
       else if(Zcand->Pt() >=2200e3 && Zcand->Pt() <=2600e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.399);}
       else if(Zcand->Pt() >=2600e3 && Zcand->Pt() <=3000e3)
	 {
	   Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.089);}
       else{
           Zcand_Tau21_1b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       }*/
        
   /* }
    if (Zcand->GetBStatus() == 6) {
       Zcand_Tau21_2b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 7) {
       Zcand_Tau21_2b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 8) {
       Zcand_Tau21_2b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b70->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
     }
     if (Zcand->GetBStatus() == 9) {
       Zcand_Tau21_2b85->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b77->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b70->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);*/
       //Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       /*if(Zcand->Pt() >=200e3 && Zcand->Pt() <=600e3)
	 {
	   Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*0.980);}
       else if(Zcand->Pt() >=600e3 && Zcand->Pt() <=1000e3)
	 {
	   Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.023);}
       else if(Zcand->Pt() >=1000e3 && Zcand->Pt() <=1400e3)
	 {
	   Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*0.938);}
       else if(Zcand->Pt() >=1400e3 && Zcand->Pt() <=1800e3)
	 {
	   Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*0.668);}
       else if(Zcand->Pt() >=1800e3 && Zcand->Pt() <=2200e3)
	 {
	   Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight*1.079);}
       else{
           Zcand_Tau21_2b60->Fill(LargeRJetTau2[i]/LargeRJetTau1[i], totalWeight);
       }
                
	 
   }
	 }
   }*/
    /*
    if(Zcand != 0 && Zcand->PassMu12 < 0.315)
       { Zcand_pt_Mu12cut->Fill(Zcand->Pt(),totalWeight);
       }
     if(Zcand != 0 && Zcand->PassD2 < 1.50)
       { Zcand_pt_D2cut->Fill(Zcand->Pt(),totalWeight);
       }
     if(Zcand != 0 && Zcand->PassPFlow < 0.32)
       { Zcand_pt_PFlow32cut->Fill(Zcand->Pt(),totalWeight);
       }
     if(Zcand != 0 && Zcand->PassPFlow < 0.34)
       { Zcand_pt_PFlow34cut->Fill(Zcand->Pt(),totalWeight);
       }
     if(Zcand != 0 && Zcand->PassPFlow < 0.36)
       { Zcand_pt_PFlow36cut->Fill(Zcand->Pt(),totalWeight);
       }
      if(Zcand != 0 && Zcand->PassTmin < 0.25 )
       { 
         Zcand_pt_Tmin25cut->Fill(Zcand->Pt(),totalWeight);
       }
      if(Zcand != 0 && Zcand->PassTmin < 0.30 )
       { 
         Zcand_pt_Tmin30cut->Fill(Zcand->Pt(),totalWeight);
       }
      if(Zcand != 0 && Zcand->PassTmin < 0.35 )
       { 
         Zcand_pt_Tmin35cut->Fill(Zcand->Pt(),totalWeight);
       }

       if(Zcand != 0 && Zcand->PassTau21 < 0.35)
	   {
        Zcand_pt_Tau2135cut->Fill(Zcand->Pt(),totalWeight);
	   }
      if(Zcand != 0 && Zcand->PassTau21 < 0.40)
	   {
        Zcand_pt_Tau2140cut->Fill(Zcand->Pt(),totalWeight);
	   }
      if(Zcand != 0 && Zcand->PassTau21 < 0.45)
	   {
        Zcand_pt_Tau2145cut->Fill(Zcand->Pt(),totalWeight);
	   }
      
      if(Zcand != 0 && Zcand->PassTmin < 0.30 && Zcand->PassTau21 < 0.40)
       {
	 Zcand_pt_TminTau21->Fill(Zcand->Pt(),totalWeight);
         //Zcand_mass_TminTau21->Fill(Zcand->M(),totalWeight);  
       }
      if(Zcand != 0 && Zcand->PassPFlow < 0.34 && Zcand->PassTmin < 0.30)
       {
	 Zcand_pt_TminPFlow->Fill(Zcand->Pt(),totalWeight);
         //Zcand_mass_TminPFlow->Fill(Zcand->M(),totalWeight);
       }
      if(Zcand != 0 && Zcand->PassPFlow < 0.34 && Zcand->PassTau21 < 0.40)
       {
	 Zcand_pt_PFlowTau21->Fill(Zcand->Pt(),totalWeight);
         //Zcand_mass_TminTau21->Fill(Zcand->M(),totalWeight);  
       }
       */  

   if (Zcand != 0) { // Definitely got a Zcand and it has highest pT
     cutflow_Vbb->Fill(3.5,totalWeight);
     Zcand_mass->Fill(Zcand->M(),totalWeight);
     Zcand_pt->Fill(Zcand->Pt(),totalWeight);
     Zcand_ntrk->Fill(Zcand->GetNumTrackVectors(),totalWeight);
     trackjet * Zcand_leadingtrk = 0;
     trackjet * Zcand_secondtrk = 0;
     double Zcand_highestPt = 0;
     double Zcand_secondPt = 0;
     int idx_leadtrk=0;
     int idx_subltrk=0;
     //std::cout<<"NumTrackVectors: " << Selected->GetNumTrackVectors() <<std::endl;
     for (int i=0;i<Zcand->GetNumTrackVectors();++i) {
       trackjet * Zcand_trk = Zcand->GetTrackVector(i);
       if (Zcand_trk->Pt() > Zcand_highestPt) {
         Zcand_secondPt = Zcand_highestPt;
         Zcand_secondtrk = Zcand_leadingtrk;
         Zcand_leadingtrk = Zcand_trk;
         Zcand_highestPt = Zcand_trk->Pt();
         idx_leadtrk = i;
       } else if (Zcand_trk->Pt() > Zcand_secondPt) {
         Zcand_secondtrk = Zcand_trk;
         Zcand_secondPt = Zcand_trk->Pt();
         idx_subltrk = i;
       } else continue;
       Zcand_leadtrk_pt->Fill(Zcand_highestPt,totalWeight);
       Zcand_subtrk_pt->Fill(Zcand_secondPt,totalWeight);
       Zcand_h2Dpt->Fill(Zcand_highestPt,Zcand_secondPt, totalWeight);
     }
     double Zcand_deltaR = Zcand_leadingtrk->DeltaR(*Zcand_secondtrk);
     //std::cout << "Jet Status: " << Zcand->GetBStatus() << std::endl;
   if(Zcand->GettrkJetBStatus()==1 && totalWeight >0){
     Zcand_LL_mass->Fill(Zcand->M(),totalWeight);
     Zcand_LL_pt->Fill(Zcand->Pt(),totalWeight);
   }
   if(Zcand->GettrkJetBStatus()==2 && totalWeight >0){
     Zcand_LC_mass->Fill(Zcand->M(),totalWeight);
     Zcand_LC_pt->Fill(Zcand->Pt(),totalWeight);
   }
   if(Zcand->GettrkJetBStatus()==3 && totalWeight >0){
     Zcand_LB_mass->Fill(Zcand->M(),totalWeight);
     Zcand_LB_pt->Fill(Zcand->Pt(),totalWeight);
   }
    if(Zcand->GettrkJetBStatus()==4 && totalWeight >0){
      Zcand_CC_mass->Fill(Zcand->M(),totalWeight);
      Zcand_CC_pt->Fill(Zcand->Pt(),totalWeight);
   } 
   if(Zcand->GettrkJetBStatus()==5 && totalWeight >0){
      Zcand_CL_mass->Fill(Zcand->M(),totalWeight);
      Zcand_CL_pt->Fill(Zcand->Pt(),totalWeight);
   }
  if(Zcand->GettrkJetBStatus()==6 && totalWeight >0){
     Zcand_BL_mass->Fill(Zcand->M(),totalWeight);
     Zcand_BL_pt->Fill(Zcand->Pt(),totalWeight);
   }   
  if(Zcand->GettrkJetBStatus()==7 && totalWeight >0){
     Zcand_BB_mass->Fill(Zcand->M(),totalWeight);
     Zcand_BB_pt->Fill(Zcand->Pt(),totalWeight);
   }
   //1b, 2b DL1r histogram filling and Flavour Fraction histogramming:
   
   if (Zcand->GetBStatus() == 1 && totalWeight >0) {
     //std::cout<<"0 btags"<<std::endl;
     cutflow_Vbb->Fill(4.5,totalWeight);
     Zcand_0b_DL1r_mass->Fill(Zcand->M(),totalWeight);
     Zcand_0b_DL1r_pt->Fill(Zcand->Pt(),totalWeight);
     Zcand_0b_DL1r_leadtrk_pt->Fill(Zcand_leadingtrk->Pt(),totalWeight);
     Zcand_0b_DL1r_subtrk_pt->Fill(Zcand_secondtrk->Pt(),totalWeight);
     Zcand_0b_DL1r_deltaR->Fill(Zcand_deltaR,totalWeight);
     
     if(Zcand->GettrkJetBStatus()==1 && totalWeight >0){ 

      Zcand_0b_LL_mass->Fill(Zcand->M(),totalWeight);
      Zcand_0b_LL_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()==2 && totalWeight >0){ 
       
       Zcand_0b_LC_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_LC_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 

      else if(Zcand->GettrkJetBStatus()==3 && totalWeight >0){ 
       
       Zcand_0b_LB_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_LB_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()==4 && totalWeight >0){ 
       
       Zcand_0b_CC_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_CC_pt->Fill(Zcand->Pt(),totalWeight);
    
   }

     else if(Zcand->GettrkJetBStatus()==5 && totalWeight >0){ 
       
       Zcand_0b_CL_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_CL_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
   
     else if(Zcand->GettrkJetBStatus()==7 && totalWeight >0){ 
       
       Zcand_0b_BB_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_BB_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 

     else if(Zcand->GettrkJetBStatus()==6 && totalWeight >0){ 
       
       Zcand_0b_BL_mass->Fill(Zcand->M(),totalWeight);
       Zcand_0b_BL_pt->Fill(Zcand->Pt(),totalWeight);
    
   }    
     
    
     
   } // Close (Zcand->GetBStatus() == 1)
  
   //***Filling in histograms for truth labelling studies***
   // Find Zcand with 1 btag DL1r 85% WP

   else if (Zcand->GetBStatus() == 2 && totalWeight >0) {
     //      std::cout<<"1 btag"<<std::endl;
     cutflow_Vbb->Fill(11.5,totalWeight);
     Zcand_1b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
      if(Zcand->GettrkJetBStatus()==1){ 

        Zcand_1b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()==2 && totalWeight >0){ 
         
         Zcand_1b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   } 

      else if(Zcand->GettrkJetBStatus()==3 && totalWeight >0){ 
       
         Zcand_1b_LB_85_mass->Fill(Zcand->M(),totalWeight);
         Zcand_1b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus() == 4 && totalWeight >0){ 
        
          Zcand_1b_CC_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_1b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);   
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
          Zcand_1b_CL_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_1b_CL_85_pt->Fill(Zcand->Pt(),totalWeight); 
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
          Zcand_1b_BB_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_1b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
          Zcand_1b_BL_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_1b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
    
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl
   } // Close if (Zcand->GetBStatus() == 2)
   
   // Find Zcand with 1 btag DL1r 77% WP  
   else if (Zcand->GetBStatus() == 3 && totalWeight >0) {
     //      std::cout<<"1 btag"<<std::endl;
    
     cutflow_Vbb->Fill(7.5,totalWeight);
     Zcand_1b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);
     

     cutflow_Vbb->Fill(11.5,totalWeight);
     Zcand_1b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
     
   if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_1b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
        Zcand_1b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
       
        Zcand_1b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus() == 4 && totalWeight >0){ 
        
     Zcand_1b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
  
   }
     
     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
     Zcand_1b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_1b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
     Zcand_1b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_1b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_85_pt->Fill(Zcand->Pt(),totalWeight);
   }
    
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 3)

   // Find Zcand with 1 btag DL1r 70% WP
   
   else if (Zcand->GetBStatus() == 4 && totalWeight >0) {
     //      std::cout<<"1 btag"<<std::endl;
     cutflow_Vbb->Fill(7.5,totalWeight);
     Zcand_1b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_DL1r_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_70_pt->Fill(Zcand->Pt(),totalWeight);

     cutflow_Vbb->Fill(11.5,totalWeight);
     Zcand_1b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
     if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_1b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
        
     Zcand_1b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
       
     Zcand_1b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()== 4 && totalWeight >0){ 
        
     Zcand_1b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
     Zcand_1b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);  
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_1b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
     Zcand_1b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
    
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 4)
   
   // Find Zcand with 1 btag DL1r 60% WP
   else if (Zcand->GetBStatus() == 5 && totalWeight >0) {
           cutflow_Vbb->Fill(5.5,totalWeight);
     //      std::cout<<"1 btag"<<std::endl;
     Zcand_1b_DL1r_60_pt->Fill(Zcand->Pt(),totalWeight);
     Zcand_1b_DL1r_60_mass->Fill(Zcand->M(),totalWeight);
     
    
     Zcand_1b_DL1r_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_70_pt->Fill(Zcand->Pt(),totalWeight);
     
    
     cutflow_Vbb->Fill(7.5,totalWeight);   
     Zcand_1b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);
     

     cutflow_Vbb->Fill(11.5,totalWeight);
     Zcand_1b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     

     
     if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_1b_LL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_60_pt->Fill(Zcand->Pt(),totalWeight); 

     Zcand_1b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
     Zcand_1b_LC_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_60_pt->Fill(Zcand->Pt(),totalWeight);  
 
     Zcand_1b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
     
     Zcand_1b_LB_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()== 4 && totalWeight >0){ 
        
      Zcand_1b_CC_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_60_pt->Fill(Zcand->Pt(),totalWeight); 
     Zcand_1b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
     
     Zcand_1b_CL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);  
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_1b_BB_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
     
     Zcand_1b_BL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_1b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_1b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
     
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 5)
   
   // Find Zcand with 2 btags at 85% WP
   
   else if (Zcand->GetBStatus() == 6 && totalWeight >0) {
     //    std::cout<<"2 btag"<<std::endl;
     cutflow_Vbb->Fill(13.5,totalWeight);
    
     Zcand_2b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
      if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

        Zcand_2b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
         Zcand_2b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
       
         Zcand_2b_LB_85_mass->Fill(Zcand->M(),totalWeight);
         Zcand_2b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()== 4 && totalWeight >0){ 
        
          Zcand_2b_CC_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_2b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);   
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
          Zcand_2b_CL_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_2b_CL_85_pt->Fill(Zcand->Pt(),totalWeight); 
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
          Zcand_2b_BB_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_2b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
          Zcand_2b_BL_85_mass->Fill(Zcand->M(),totalWeight);
          Zcand_2b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 6) 

   // Find Zcand with 2 btags at 77% WP

   else if (Zcand->GetBStatus() == 7 && totalWeight >0) {
       cutflow_Vbb->Fill(8.5,totalWeight);
     //std::cout<<"2 btag"<<std::endl;
     Zcand_2b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     cutflow_Vbb->Fill(13.5,totalWeight);
     Zcand_2b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
      if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_2b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
        Zcand_2b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
       
        Zcand_2b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()== 4 && totalWeight >0){ 
        
     Zcand_2b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
     Zcand_2b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_2b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
     Zcand_2b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);
     
     Zcand_2b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_85_pt->Fill(Zcand->Pt(),totalWeight);
   }
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 7)    

   // Find Zcand with 2 btags at 70% WP
   
   else if (Zcand->GetBStatus() == 8 && totalWeight >0) {
     //    std::cout<<"2 btag"<<std::endl;
     cutflow_Vbb->Fill(8.5,totalWeight);
     Zcand_2b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);
    
     Zcand_2b_DL1r_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_70_pt->Fill(Zcand->Pt(),totalWeight);
     
     cutflow_Vbb->Fill(13.5,totalWeight);
     Zcand_2b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
      if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_2b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
        
     Zcand_2b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
       
     Zcand_2b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus()== 4 && totalWeight >0){ 
        
     Zcand_2b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
       
     Zcand_2b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);  
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_2b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
       
     Zcand_2b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;
   } // Close if (Zcand->GetBStatus() == 4)
  
   // Find Zcand with 2 btags at 60% WP
   else if (Zcand->GetBStatus() == 9 && totalWeight >0) {
   
     cutflow_Vbb->Fill(6.5,totalWeight);
     Zcand_2b_DL1r_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_60_pt->Fill(Zcand->Pt(),totalWeight);

     cutflow_Vbb->Fill(8.5,totalWeight);
     Zcand_2b_DL1r_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_DL1r_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_70_pt->Fill(Zcand->Pt(),totalWeight);

     cutflow_Vbb->Fill(13.5,totalWeight);
     Zcand_2b_DL1r_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_DL1r_85_pt->Fill(Zcand->Pt(),totalWeight);
     
      if(Zcand->GettrkJetBStatus()== 1 && totalWeight >0){ 

     Zcand_2b_LL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_60_pt->Fill(Zcand->Pt(),totalWeight); 

     Zcand_2b_LL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LL_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   }
      else if(Zcand->GettrkJetBStatus()== 2 && totalWeight >0){ 
         
     Zcand_2b_LC_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_60_pt->Fill(Zcand->Pt(),totalWeight);  
 
     Zcand_2b_LC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LC_85_pt->Fill(Zcand->Pt(),totalWeight);
   } 

      else if(Zcand->GettrkJetBStatus()== 3 && totalWeight >0){ 
     
     Zcand_2b_LB_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_LB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_LB_85_pt->Fill(Zcand->Pt(),totalWeight);
    
   } 
      else if(Zcand->GettrkJetBStatus() == 4 && totalWeight >0){ 
        
      Zcand_2b_CC_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_60_pt->Fill(Zcand->Pt(),totalWeight); 
     Zcand_2b_CC_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CC_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CC_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CC_85_pt->Fill(Zcand->Pt(),totalWeight);
      
   }

     else if(Zcand->GettrkJetBStatus()== 5 && totalWeight >0){ 
     
     Zcand_2b_CL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_CL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_CL_85_pt->Fill(Zcand->Pt(),totalWeight);  
    
   }   
     else if(Zcand->GettrkJetBStatus()== 7 && totalWeight >0){ 
       
     Zcand_2b_BB_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BB_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BB_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BB_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BB_85_pt->Fill(Zcand->Pt(),totalWeight);
         
    
   } 
     else if(Zcand->GettrkJetBStatus()== 6 && totalWeight >0){ 
     
     Zcand_2b_BL_60_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_60_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BL_77_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_77_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BL_70_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_70_pt->Fill(Zcand->Pt(),totalWeight);

     Zcand_2b_BL_85_mass->Fill(Zcand->M(),totalWeight);
     Zcand_2b_BL_85_pt->Fill(Zcand->Pt(),totalWeight); 
   }
     //std::cout << "leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_leadtrk]<< std::endl;
     //std::cout << "Sub-leading Trackjet Flavour" <<TrackJetTruthLabelId[idx_subltrk]<< std::endl;   

   } 

  //Xbb Histogram Filling for all pT bins and inclusive as well...
  
  Zcand_Xbb->Fill(Zcand->isXbbTagged, totalWeight);
  if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass->Fill(Zcand->M(),totalWeight);  
     Zcand_Xbb50_pT->Fill(Zcand->Pt(),totalWeight); 
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass->Fill(Zcand->M(),totalWeight);
    Zcand_Xbb60_pT->Fill(Zcand->Pt(),totalWeight); 
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb60_mass_data->Fill(Zcand->M(),totalWeight);
       
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass->Fill(Zcand->M(),totalWeight);
    Zcand_Xbb70_pT->Fill(Zcand->Pt(),totalWeight); 
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_data->Fill(Zcand->M(),totalWeight);
      }
    
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass->Fill(Zcand->M(),totalWeight);
     Zcand_Xbb80_pT->Fill(Zcand->Pt(),totalWeight); 
     
  }


  if(Zcand->Pt()>=450 && Zcand->Pt()<500)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT455->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT455->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT455_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb60_mass_pT455_data->Fill(Zcand->M(),totalWeight);
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT455->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT455_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT455_data->Fill(Zcand->M(),totalWeight);
      }
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT455->Fill(Zcand->M(),totalWeight);   
  }

   }

  if(Zcand->Pt()>=500 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT56->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT56->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT56_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb60_mass_pT56_data->Fill(Zcand->M(),totalWeight);
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT56->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT56_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT56_data->Fill(Zcand->M(),totalWeight);
      }
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT56->Fill(Zcand->M(),totalWeight);   
  }

   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<700)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT67->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT67->Fill(Zcand->M(),totalWeight);
    
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT67_data->Fill(Zcand->M(),0);
        
       }
      else
      {
       Zcand_Xbb60_mass_pT67_data->Fill(Zcand->M(),totalWeight);
       
      }
    
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT67->Fill(Zcand->M(),totalWeight);
    
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT67_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT67_data->Fill(Zcand->M(),totalWeight);
      }
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT67->Fill(Zcand->M(),totalWeight);   
  }

   } 


   if(Zcand->Pt()>=700 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT710->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT710->Fill(Zcand->M(),totalWeight);
    
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT710_data->Fill(Zcand->M(),0);       
       }
      else
      {
       Zcand_Xbb60_mass_pT710_data->Fill(Zcand->M(),totalWeight);
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT710->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT710_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT710_data->Fill(Zcand->M(),totalWeight);
      }
    
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT710->Fill(Zcand->M(),totalWeight);   
  }

   }
   
   //Xbb histogram filling for coarser binning
   if(Zcand->Pt()>=450 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT456->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT456->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT456_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb60_mass_pT456_data->Fill(Zcand->M(),totalWeight);
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT456->Fill(Zcand->M(),totalWeight);
    
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT456_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT456_data->Fill(Zcand->M(),totalWeight);
      }
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT456->Fill(Zcand->M(),totalWeight);   
  }
   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_pT610->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_pT610->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb60_mass_pT610_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb60_mass_pT610_data->Fill(Zcand->M(),totalWeight);
      }
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_pT610->Fill(Zcand->M(),totalWeight);
    if(Zcand->M()>70 && Zcand->M()<110)
       {
        Zcand_Xbb70_mass_pT610_data->Fill(Zcand->M(),0);
       }
      else
      {
       Zcand_Xbb70_mass_pT610_data->Fill(Zcand->M(),totalWeight);
      }
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_pT610->Fill(Zcand->M(),totalWeight); 
  }
   }
   //***THIS PART IS ONLY FOR tt MC***
   
   if((*DSID) == 410471 && Zcand->isFatJetLabel == 1) {
   // category 1 definition for top 
     Zcand_Xbb->Fill(Zcand->isXbbTagged, totalWeight);
  if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1->Fill(Zcand->M(),totalWeight);    
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1->Fill(Zcand->M(),totalWeight);  
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1->Fill(Zcand->M(),totalWeight);
     
  }

  if(Zcand->Pt()>=450 && Zcand->Pt()<500)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT455->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT455->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT455->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT455->Fill(Zcand->M(),totalWeight);   
  }

   }

  if(Zcand->Pt()>=500 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT56->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT56->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT56->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT56->Fill(Zcand->M(),totalWeight);   
  }

   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<700)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT67->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT67->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT67->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT67->Fill(Zcand->M(),totalWeight);   
  }

   }

   

   if(Zcand->Pt()>=700 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT710->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT710->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT710->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT710->Fill(Zcand->M(),totalWeight);   
  }

   }
   
   //Xbb histogram filling for coarser binning

   if(Zcand->Pt()>=450 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT456->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT456->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT456->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT456->Fill(Zcand->M(),totalWeight);   
  }
   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat1_pT610->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat1_pT610->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat1_pT610->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat1_pT610->Fill(Zcand->M(),totalWeight); 
  }
   }//category 1 for top braces close
   }
    
   if((*DSID) == 410471 && (Zcand->isFatJetLabel == 4 || Zcand->isFatJetLabel == 5) ) // category 2 definition for top 
   {
     Zcand_Xbb->Fill(Zcand->isXbbTagged, totalWeight);
  if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2->Fill(Zcand->M(),totalWeight);
     
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2->Fill(Zcand->M(),totalWeight);
     
  }

  if(Zcand->Pt()>=450 && Zcand->Pt()<500)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT455->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT455->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT455->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT455->Fill(Zcand->M(),totalWeight);   
  }

   }

  if(Zcand->Pt()>=500 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT56->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT56->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT56->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT56->Fill(Zcand->M(),totalWeight);   
  }

   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<700)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT67->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT67->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT67->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT67->Fill(Zcand->M(),totalWeight);   
  }

   }

   if(Zcand->Pt()>=700 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT710->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT710->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT710->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT710->Fill(Zcand->M(),totalWeight);   
  }

   }
    
   //Xbb histogram filling for coarser binning

   if(Zcand->Pt()>=450 && Zcand->Pt()<600)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT456->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT456->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT456->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT456->Fill(Zcand->M(),totalWeight);   
  }
   }

   if(Zcand->Pt()>=600 && Zcand->Pt()<1000)
   {
    if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_pT610->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_pT610->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_pT610->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_pT610->Fill(Zcand->M(),totalWeight); 
  }
   }
   
   }//category 2 for top braces close
   if((*DSID) == 410471 && Zcand->isFatJetLabel == 4 ) // category 2 definition for top (W)
   {
     Zcand_Xbb->Fill(Zcand->isXbbTagged, totalWeight);
  if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_W->Fill(Zcand->M(),totalWeight);
     
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_W->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_W->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_W->Fill(Zcand->M(),totalWeight);
     
  }  
   }

   if((*DSID) == 410471 && Zcand->isFatJetLabel == 5 ) // category 2 definition for top (others)
   {
     Zcand_Xbb->Fill(Zcand->isXbbTagged, totalWeight);
  if(Zcand->isXbbTagged >3.13 && totalWeight >0){
     Zcand_Xbb50_mass_cat2_O->Fill(Zcand->M(),totalWeight);
     
  }
  if(Zcand->isXbbTagged >2.55 && totalWeight >0){
    Zcand_Xbb60_mass_cat2_O->Fill(Zcand->M(),totalWeight);
  }
   if(Zcand->isXbbTagged >1.92 && totalWeight >0){
    Zcand_Xbb70_mass_cat2_O->Fill(Zcand->M(),totalWeight);
  }
  if(Zcand->isXbbTagged >1.20 && totalWeight >0){
     Zcand_Xbb80_mass_cat2_O->Fill(Zcand->M(),totalWeight);
     
  }  
   }
   
   } // Close if (Zcand != 0)

   } // Close if (Pt symmetry)
   ////////////////////////////////////////////////////
   //end Zbb
   
   } // Close if (Eta cut)
   } //Close if leading !=0 && sub_leading !=0 
   // std::cout<<"End of Process"<<std::endl;
  
   ///////////////////////////////////////////////////////////////////////////////
   } //Close if (nlargeRjet > 1)
   /////////////////////////////////////////////////////////////////////////////
   fReader.SetEntry(entry);
   return kTRUE;
} // Close Nominal

void Nominal::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}


void Nominal::Terminate(TString mc_filename)
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  
  TFile *f = new TFile(mc_filename+".root","RECREATE");

  /*if (h_stat[0]) {
    for (int i=0;i<8;++i) {
      h_stat[i]->Write();
    }
    }*/
  
  for (uint i=0;i<histlist.size();++i) {
    (histlist.at(i))->Write();
    delete histlist.at(i);
  }
  for (uint i=0;i<histlist2.size();++i) {
    (histlist2.at(i))->Write();
    delete histlist2.at(i);
  }
  f->Close();
}


TH1D * Nominal::makeHist(TString name,int nbins,double x1, double x2) {
  TH1D * hist = new TH1D(name,name,nbins,x1,x2);
  hist->Sumw2();
  histlist.push_back(hist);
  return hist;
}

TH2D * Nominal::makeHist2(TString name,int xnbins,double x1, double x2, int ynbins, double y1, double y2) {
  TH2D * hist2 = new TH2D(name,name,xnbins,x1,x2,ynbins,y1,y2);
  hist2->Sumw2();
  histlist2.push_back(hist2);
  return hist2;
}

void Nominal::FatToTrackLinks(std::vector<fatjet> & largeRjets,std::vector<trackjet> & trackjets,int & nlargeRjets){
  //  std::cout<<"Creating links between fatjet and trackjets."<<std::endl;
  for (int i=0;i<nlargeRjets;++i) {
    //    std::cout<<"i= "<<i<<std::endl;
    fatjet & fj = largeRjets[i];
    //    std::cout<<"We have largeRjet "<<i<<std::endl;
    std::vector<unsigned long> tjvector = LargeRJetAssociatedTrackJet[i];
    //    std::cout<<"We have the vector of trackjets."<<std::endl;

    for (auto tj=tjvector.begin();tj!=tjvector.end();++tj) { 
      trackjet & tjassociated = trackjets[*tj];
      if (TrackJetIsSelected[*tj] == false) continue;
      else if (TrackJetPassDR[*tj] == false) continue;
      (fj).AddTrackJetPointer(&(tjassociated));
    }
  }
  //  std::cout<<"Exiting for loop."<<std::endl;
}

void Nominal::EraseUnselectedFatjets(std::vector<fatjet> & largeRjets) {
  for (uint i=0;i<largeRjets.size();++i) {
    if (LargeRJetIsSelected[i] == false) {
      largeRjets.erase(largeRjets.begin()+i);
    }
    else continue;
  }
}
    
std::pair<std::map<std::string, double>, bool> GetMCWeightMap() {
  std::map<std::string, double> MCWeightMap;
  bool Success;
  PyObject *pName;
  PyObject *pModule;
  PyObject *pFunc;

  PyObject *pDict;

  Py_Initialize();
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\".\")");
  pName = PyString_FromString("read_json");
  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (pModule != nullptr) {
    pFunc = PyObject_GetAttrString(pModule,"read_file");

    if (pFunc && PyCallable_Check(pFunc)) {
      pDict = PyObject_CallObject(pFunc, nullptr);
      if (pDict != nullptr) {
	PyObject *pKeys = PyDict_Keys(pDict);
	PyObject *pValues = PyDict_Values(pDict);
	for (Py_ssize_t i = 0; i < PyDict_Size(pDict); ++i) { 
	  auto pair = std::make_pair(std::string(PyString_AsString(PyList_GetItem(pKeys, i))), PyFloat_AsDouble(PyList_GetItem(pValues, i)));
	  MCWeightMap.insert( pair );
	}
	Success = true;
	Py_DECREF(pDict);
      }
      else {
	Py_DECREF(pFunc);
	Py_DECREF(pModule);
	PyErr_Print();
	fprintf(stderr,"Call failed\n");
	Success = false;
	return std::make_pair(MCWeightMap,Success);
      }
    }
    else {
      if (PyErr_Occurred())
	PyErr_Print();
      fprintf(stderr,"Cannot find function \"%s\"\n", "read_file");
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
  }
  else {
    PyErr_Print();
    fprintf(stderr, "Failed to load \"%s\"\n", "read_json");
    Success = false;
    return std::make_pair(MCWeightMap,Success);
  }
  Py_Finalize();
  Success = true;
  for (auto const& pair: MCWeightMap) {
     std::cout<<"{" <<(pair.first) << ":"<<(pair.second)<<"}"<<std::endl;
   }

  return std::make_pair(MCWeightMap,Success);
}	    

std::vector<TString> list_files(const char *dirname="C:/root/folder/", const char *ext=".root") {
  std::vector<TString> result;
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext)) {
	std::cout << "list_files: " <<fname.Data() << std::endl;
	result.push_back(fname);
      }
    }
  }
  return result;
}

TChain* CreateSingleChain(TString whichsystematic, TString path){
  std::vector<TString> list = list_files(path);
  TChain* syst_chain = new TChain(whichsystematic);
  std::cout<<"AddFilesToChain: Found "<<list.size()<<" files"<<std::endl;
  for (uint i=0;i<list.size();++i) {
    std::cout<<"AddFilesToChain: Adding "<<path+list[i]<< " to chain: " << whichsystematic << std::endl;
    syst_chain->Add(path+list[i]);
  }
  syst_chain->Lookup(true);
  return syst_chain;
}

std::vector<TChain*> CreateSystChains(std::vector<TString> Chainnames, TString path){
  std::vector<TChain*> chains;
  std::cout << "Do systematics !!!!!" << std::endl;
  for (uint i = 0; i<Chainnames.size(); ++i){
     std::cout << "Systematic: " << Chainnames[i] << std::endl;
  } 
  std::vector<TString> list = list_files(path);
  std::cout<<"AddFilesToChain: Found "<<list.size()<<" files"<<std::endl;  
  for (uint i = 0; i<Chainnames.size(); ++i){
    chains.push_back(new TChain(Chainnames[i]));
    for (uint j=0;j<list.size();++j) {
      std::cout<<"AddFilesToChain: Adding "<<path+list[j]<< " to chain: " << Chainnames[i] << std::endl;
      chains[i]->Add(path+list[j]);
    }
  }
  for (uint i = 0; i<Chainnames.size(); ++i){
    chains[i]->Lookup(true);
  }
 return chains;
}


void dogen(TString path,TString fname, TString fwhichsystematics) {
  Nominal * selector = new Nominal();
  TChain * chain_syst = CreateSingleChain(fwhichsystematics,path);
  TChain * chain_nominal = CreateSingleChain("nominal",path);
  TChain * chain_2 = CreateSingleChain("sumWeights",path);

  std::vector<TString> systs;
  std::ifstream systs_list_file("systematics-list.txt");
  std::string line;
  if (systs_list_file.is_open())
    {
      while ( getline (systs_list_file,line) )
	{
	  systs.push_back(line);
	}
      systs_list_file.close();
    }

  else std::cout << "Unable to open file" << std::endl;

  if(fwhichsystematics != "nominal"){
    chain_syst->AddFriend("nominal");
  }
      
  TString mc_filename = path;
  TString deriv_tag = ".deriv.DAOD_JETM6";
  TString Event_tag = ".e4692_s3126_";
  TString Sub_compaign = "r9364_";
  TString ptag = "p4128";

  if(mc_filename.Contains("mc16a")) Sub_compaign = "r9364_";
  if(mc_filename.Contains("mc16d")) Sub_compaign = "r10201_";
  if(mc_filename.Contains("mc16e")) Sub_compaign = "r10724_";

  if (mc_filename.Contains("364375")) mc_filename = "mc16_13TeV.364375.Sherpa_225_NNPDF30NNLO_Zqq_PTV280_500";
  if (mc_filename.Contains("364376")) mc_filename = "mc16_13TeV.364376.Sherpa_225_NNPDF30NNLO_Zqq_PTV500_1000";
  if (mc_filename.Contains("364377")) mc_filename = "mc16_13TeV.364377.Sherpa_225_NNPDF30NNLO_Zqq_PTV1000_E_CMS";
  if (mc_filename.Contains("364378")) mc_filename = "mc16_13TeV.364378.Sherpa_225_NNPDF30NNLO_Wqq_PTV280_500";
  if (mc_filename.Contains("364379")) mc_filename = "mc16_13TeV.364379.Sherpa_225_NNPDF30NNLO_Wqq_PTV500_1000";
  if (mc_filename.Contains("364380")) mc_filename = "mc16_13TeV.364380.Sherpa_225_NNPDF30NNLO_Wqq_PTV1000_E_CMS";
  if (mc_filename.Contains("364700")) mc_filename = "mc16_13TeV.364700.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ0WithSW";
  if (mc_filename.Contains("364701"))mc_filename = "mc16_13TeV.364701.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ1WithSW";
  if (mc_filename.Contains("364702"))mc_filename = "mc16_13TeV.364702.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2WithSW";
  if (mc_filename.Contains("364703"))mc_filename = "mc16_13TeV.364703.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ3WithSW";
  if (mc_filename.Contains("364704"))mc_filename = "mc16_13TeV.364704.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ4WithSW";
  if (mc_filename.Contains("364705"))mc_filename = "mc16_13TeV.364705.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ5WithSW";
  if (mc_filename.Contains("364706"))mc_filename = "mc16_13TeV.364706.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ6WithSW";
  if (mc_filename.Contains("364707"))mc_filename = "mc16_13TeV.364707.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ7WithSW";
  if (mc_filename.Contains("364708"))mc_filename = "mc16_13TeV.364708.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ8WithSW";
  if (mc_filename.Contains("364709"))mc_filename = "mc16_13TeV.364709.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ9WithSW";
  if (mc_filename.Contains("364710"))mc_filename = "mc16_13TeV.364710.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ10WithSW";
  if (mc_filename.Contains("364711"))mc_filename = "mc16_13TeV.364711.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ11WithSW";
  if (mc_filename.Contains("364712"))mc_filename = "mc16_13TeV.364712.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ12WithSW";
  if (mc_filename.Contains("410471"))mc_filename = "mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad";
  if (mc_filename.Contains("410466"))mc_filename = "mc16_13TeV.410466.aMcAtNloPy8EvtGen_MEN30NLO_A14N23LO_ttbar_noShWe_AllHadronic";
  if (mc_filename.Contains("700040"))mc_filename = "mc16_13TeV.700040.Sh_228_Wqq_ptW_200_ECMS_EnhpTV";
  if (mc_filename.Contains("700041"))mc_filename = "mc16_13TeV.700041.Sh_228_Zqq_ptZ_200_ECMS_EnhpTV";
  if (mc_filename.Contains("700042"))mc_filename = "mc16_13TeV.700042.Sh_228_Zbb_ptZ_200_ECMS_EnhpTV";
  if (mc_filename.Contains("700043"))mc_filename = "mc16_13TeV.700043.Sh_228_Wqq_ptZ_200_ECMS_EnhpTV_LundHad";
  if (mc_filename.Contains("700044"))mc_filename = "mc16_13TeV.700044.Sh_228_Zqq_ptZ_200_ECMS_EnhpTV_LundHad";
  if (mc_filename.Contains("700045"))mc_filename = "mc16_13TeV.700045.Sh_228_Zbb_ptZ_200_ECMS_EnhpTV_LundHad";
  if (mc_filename.Contains("800600"))mc_filename = "mc16_13TeV.800600.Py8EG_A14_NNPDF23LO_jetjet_JZ4WithSW_FJ350";
  if (mc_filename.Contains("800601"))mc_filename = "mc16_13TeV.800601.Py8EG_A14_NNPDF23LO_jetjet_JZ5WithSW_FJ350";

  //if(mc_filename.Contains("Wqq") || mc_filename.Contains("Zqq")) Event_tag = ".e7048_s3126_";
  if(mc_filename.Contains("Sherpa_225")) Event_tag = ".e7048_s3126_";
  if(mc_filename.Contains("Sh_228")) Event_tag = ".e7947_s3126_";
  if(mc_filename.Contains("800600")) Event_tag = ".e8187_s3126_";
  if(mc_filename.Contains("800601")) Event_tag = ".e8187_s3126_";
  if(mc_filename.Contains("jetjet")) Event_tag = ".e7142_s3126_";
  if(mc_filename.Contains("ttbar")) Event_tag = ".e6337_s3126_";
  if(mc_filename.Contains("ttbar_noShWe")) Event_tag = ".e6762_s3126_";
  
  mc_filename = mc_filename + deriv_tag +  Event_tag + Sub_compaign + ptag;
  
  std::map<std::string, double> weight_map = (GetMCWeightMap()).first;
  for (auto const& pair: weight_map) {
    std::cout<<"{" <<(pair.first) << ":"<<(pair.second)<<"}"<<std::endl;
   }
   for (auto iter = weight_map.begin(); iter != weight_map.end(); ++iter) {
    if (iter->first == mc_filename) {
      selector->mc_weighted = iter->second;
    }
   }
   std::cout<<mc_filename<< " : "<< "mc_weighted"<< " : " << selector->mc_weighted<<std::endl;

  TTreeReader sumWeightsReader;
  sumWeightsReader.SetTree(chain_2);
  TTreeReaderValue<Float_t> totalEventsWeighted = {sumWeightsReader,"totalEventsWeighted"};
  
  selector->Init(chain_syst);
  selector->Begin(0);
  selector->Notify();

  std::cout<<"dogen: Will use "<<chain_syst->GetEntries()<<" entries"<<std::endl;

  std::cout << "sumweights entries : " << chain_2->GetEntries() << std::endl; 
  for (int i=0; i<chain_2->GetEntries();++i) {
    sumWeightsReader.SetEntry(i);
    selector->dsid_weights+=*totalEventsWeighted;
   }
   std::cout<<"dsid_weights : " << selector->dsid_weights<<std::endl;

   selector->do_which_systematic = fwhichsystematics;

  for (int i=0;i<chain_syst->GetEntries();++i) {
     selector->Process(i);
  }
  std::cout<<"Process finished"<<std::endl;
  selector->Terminate(mc_filename+fwhichsystematics);

  std::cout<<"Will execute Exec(mv mc_filename.root "<< fname+ "_"+fwhichsystematics << ".root"")";
  gSystem->Exec("mv "+mc_filename+fwhichsystematics+".root "+fname+"_"+fwhichsystematics+".root");
  
  selector->Delete();
}


int main(int argc, char **argv) {
  if (argc < 5) {
    std::cout<<"main called with only "<<argc<<" arguments; quit"<<std::endl;
    return 1;
  }
  std::cout<<"Passed 1"<<std::endl;
  TString opdir = argv[1];
  TString infile = argv[2];
  TString outfile = argv[3];
  
  TString whichsystematic = argv[4];
  
  TString base = "/afs/cern.ch/work/s/shbansal/QT_2020/qt-2019-2020/";
  if (argc > 4) base = argv[5];

  std::cout<<"Nominal: opdir "<<opdir<<std::endl;
  std::cout<<"Nominal: infile "<<infile<<std::endl;
  std::cout<<"Nominal: outfile "<<outfile<<std::endl;
  std::cout<<"Nominal: base "<<base<<std::endl;
  std::cout<<"Systematic: " << whichsystematic <<std::endl;
  std::cout<<"Passed 2"<<std::endl;
  if (!gSystem->Exec("ls "+opdir)) {
    std::cout<<"pathname " <<opdir<<" exists"<<std::endl;
  } else {
    std::cout<<"pathname "<<opdir<<" does not exist. It will be made"<<std::endl;
    gSystem->Exec("mkdir "+opdir);
  }
  std::cout<<"Passed 3"<<std::endl;
  dogen(base+infile+"/",opdir+"/"+outfile,whichsystematic);
  return 0;
}
