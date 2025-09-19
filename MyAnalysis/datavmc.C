#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLatex.h>
#include <TCanvas.h>
//#include <TPad.h>
#include <TLegend.h>
#include <TFile.h>
#include <TString.h>
#include <TProfile.h>
#include <TFitResult.h>
#include <TH1D.h>
#include <TF1.h>
#include <TF2.h>
#include <TLine.h>
#include <vector>
#include <iostream>

#include "AtlasStyle.C"
#include "AtlasLabels.C"

bool Sherpa = true;

const int nfile = 14;
const int nhist = nfile+4;

/*TFile *f_QCD = new TFile("Xbb_OptFunc/QCD_Xbb60_455_3GeV.root", "RECREATE");
TFile *f_Z = new TFile("Xbb_OptFunc/Z_Xbb60_455_3GeV.root", "RECREATE");
TFile *f_W = new TFile("Xbb_OptFunc/W_Xbb60_455_3GeV.root", "RECREATE");
TFile *f_tt = new TFile("Xbb_OptFunc/tt_Xbb60_455_3GeV.root", "RECREATE");*/



TString fileNames[nfile] = {"700042_MC16ad.root","700040_MC16ad.root", "410471_MC16ad.root", "364703_MC16ad.root", "364704_MC16ad.root", "364705_MC16ad.root", "364706_MC16ad.root", "364707_MC16ad.root", "364708_MC16ad.root", "364709_MC16ad.root", "364710_MC16ad.root", "364711_MC16ad.root", "364712_MC16ad.root", "data1517_V3pT.root"};


  const int p_Sherpa_ZJets_r9364 = 0;
  const int p_Sherpa_WJets_r9364 = 1;
  const int p_Pythia_tt_r9364 = 2;
  const int p_Pythia_qcdjet_r9364 = 3;
  const int p_data = 13;

void drawplot(TString name, TH1D** hists, bool dology);
template <class THnD> int readplots(TFile ** filePointers,THnD ** histPointers,TString name);
template <class THnD> THnD* sumPlots(THnD ** histPointers,uint p1,int n);

void datavmc() {
  //declaring all the histograms here.......
  TH1D* Zcand_mass[nhist];
  TH1D* Zcand_pt[nhist];
  TH1D* Selected_pTsymmetry_etaCut_leading_largeRjet_mass[nhist];
  TH1D* Zcand_Xbb[nhist];
  TH1D* Zcand_Xbb50_mass[nhist];
  TH1D* Zcand_Xbb60_mass[nhist];
  TH1D* Zcand_Xbb70_mass[nhist];
  TH1D* Zcand_Xbb80_mass[nhist];

  TH1D* Zcand_Xbb50_pT[nhist];
  TH1D* Zcand_Xbb60_pT[nhist];
  TH1D* Zcand_Xbb70_pT[nhist];
  TH1D* Zcand_Xbb80_pT[nhist];
  
  TH1D* Tagged_50_mass[nhist];
  TH1D* Tagged_50_pt[nhist];
  TH1D* Tagged_80_mass[nhist];
  TH1D* Tagged_80_pt[nhist];
  //TH1D* Zcand_Zwin_mass[nhist];
  //TH1D* Zcand_Zwin_pt[nhist];
   TH1D* Zcand_Xbb50_mass_pT56[nhist];
   TH1D* Zcand_Xbb50_mass_pT67[nhist];
   TH1D* Zcand_Xbb50_mass_pT710[nhist];

   TH1D* Zcand_Xbb60_mass_pT455[nhist];
   TH1D* Zcand_Xbb60_mass_pT56[nhist];
   TH1D* Zcand_Xbb60_mass_pT67[nhist];
   TH1D* Zcand_Xbb60_mass_pT710[nhist];

   TH1D* Zcand_Xbb60_mass_pT455_data[nhist];
   TH1D* Zcand_Xbb60_mass_pT56_data[nhist];
   TH1D* Zcand_Xbb60_mass_pT67_data[nhist];
   TH1D* Zcand_Xbb60_mass_pT710_data[nhist];
   
   TH1D* Zcand_Xbb70_mass_pT455[nhist];
   TH1D* Zcand_Xbb70_mass_pT56[nhist];
   TH1D* Zcand_Xbb70_mass_pT67[nhist];
   TH1D* Zcand_Xbb70_mass_pT710[nhist];

   TH1D* Zcand_Xbb60_mass_pT456[nhist];
   TH1D* Zcand_Xbb60_mass_pT610[nhist];
   
   TH1D* Zcand_Xbb70_mass_pT456[nhist];
   TH1D* Zcand_Xbb70_mass_pT610[nhist];

   TH1D* Zcand_Xbb60_mass_cat1_pT456[nhist];
   TH1D* Zcand_Xbb60_mass_cat1_pT610[nhist];
   TH1D* Zcand_Xbb70_mass_cat1_pT456[nhist];
   TH1D* Zcand_Xbb70_mass_cat1_pT610[nhist];

   TH1D* Zcand_Xbb50_mass_pT456[nhist];
   TH1D* Zcand_Xbb50_mass_pT610[nhist];

   TH1D* Zcand_Xbb50_mass_cat1[nhist];
   TH1D* Zcand_Xbb50_mass_cat2[nhist];

   TH1D* Zcand_Xbb50_mass_cat1_pT456[nhist];
   TH1D* Zcand_Xbb50_mass_cat1_pT610[nhist];
   TH1D* Zcand_Xbb50_mass_cat2_pT456[nhist];
   TH1D* Zcand_Xbb50_mass_cat2_pT610[nhist];

   TH1D* Zcand_Xbb60_mass_cat2_pT456[nhist];
   TH1D* Zcand_Xbb60_mass_cat2_pT610[nhist];
   TH1D* Zcand_Xbb70_mass_cat2_pT456[nhist];
   TH1D* Zcand_Xbb70_mass_cat2_pT610[nhist];

   TH1D* Zcand_Xbb60_mass_cat1[nhist];
   TH1D* Zcand_Xbb60_mass_cat2[nhist];
   TH1D* Zcand_Xbb70_mass_cat1[nhist];
   TH1D* Zcand_Xbb70_mass_cat2[nhist];

   TH1D* Zcand_Xbb60_mass_cat2_W[nhist];
   TH1D* Zcand_Xbb60_mass_cat2_O[nhist];
   TH1D* Zcand_Xbb70_mass_cat2_W[nhist];
   TH1D* Zcand_Xbb70_mass_cat2_O[nhist];

  
  TH1D * Zcand_1b_DL1r_60_mass[nhist];
  TH1D * Zcand_1b_DL1r_60_pt[nhist];
  TH1D * Zcand_2b_DL1r_60_mass[nhist];
  TH1D * Zcand_2b_DL1r_60_pt[nhist];

  TH1D * Zcand_1b_DL1r_70_mass[nhist];
  TH1D * Zcand_1b_DL1r_70_pt[nhist];
  TH1D * Zcand_2b_DL1r_70_mass[nhist];
  TH1D * Zcand_2b_DL1r_70_pt[nhist];

  TH1D * Zcand_1b_DL1r_77_mass[nhist];
  TH1D * Zcand_1b_DL1r_77_pt[nhist];
  TH1D * Zcand_2b_DL1r_77_mass[nhist];
  TH1D * Zcand_2b_DL1r_77_pt[nhist];

  TH1D * Zcand_1b_DL1r_85_mass[nhist];
  TH1D * Zcand_1b_DL1r_85_pt[nhist];
  TH1D * Zcand_2b_DL1r_85_mass[nhist];
  TH1D * Zcand_2b_DL1r_85_pt[nhist];
  

  SetAtlasStyle();

  //TString dir = "/afs/cern.ch/work/s/shbansal/QT_2020/qt-2019-2020/run/output_JSSInc_mc16_150/";
  //TString dir = "/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_t7Xbb_0408/output_Xbb_funcOpt_1206/";
  TString dir = "/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_t7XbbDL1r_2010/";
  TFile * filePointers[nfile];
  
  for (int i=0;i<nfile;++i) {
    filePointers[i] = TFile::Open(dir+fileNames[i]);
    if (!filePointers[i]) {
      std::cout<<"File "<<dir+fileNames[i]<<" could not be opened"<<std::endl;
    } // end if
  } // end for

  std::cout<<"All files have been opened. Beginning to read plots."<<std::endl;
  
  // readplots(filePointers,Zcand_2b_DL1r_70_mass,"Zcand_2b_DL1r_70_mass");
  //readplots(filePointers,Zcand_0b_DL1r_mass,"Zcand_0b_DL1r_mass");
  //readplots(filePointers,Zcand_1b_DL1r_77_mass,"Zcand_1b_DL1r_77_mass");
  // readplots(filePointers,Zcand_0b_DL1r_mass,"Zcand_0b_DL1r_mass");
  // readplots(filePointers,jet_mass,"jet_mass");
  // readplots(filePointers,jet_pt,"jet_pt");
  // readplots(filePointers,photon_pt,"photon_pt");
  // readplots(filePointers,photon_OR_pt,"photon_OR_pt");
  // readplots(filePointers,largeRjet_mass,"largeRjet_mass");
  // readplots(filePointers,largeRjet_pt,"largeRjet_pt");
  // readplots(filePointers,deltaR_OR,"deltaR_OR");
  //readplots(filePointers,Zcand_2b_DL1r_77_mass,"Zcand_2b_DL1r_77_mass");
  //readplots(filePointers,Zcand_Xbb,"Zcand_Xbb");
  readplots(filePointers,Selected_pTsymmetry_etaCut_leading_largeRjet_mass,"Selected_pTsymmetry_etaCut_leading_largeRjet_mass");
  readplots(filePointers,Zcand_mass,"Zcand_mass");
  readplots(filePointers,Zcand_Xbb,"Zcand_Xbb");
  readplots(filePointers,Tagged_50_mass,"Tagged_50_mass");
  readplots(filePointers,Tagged_80_mass,"Tagged_80_mass");
  readplots(filePointers,Zcand_Xbb50_mass,"Zcand_Xbb50_mass");
  readplots(filePointers,Zcand_Xbb60_mass,"Zcand_Xbb60_mass");
  readplots(filePointers,Zcand_Xbb70_mass,"Zcand_Xbb70_mass");
  readplots(filePointers,Zcand_Xbb80_mass,"Zcand_Xbb80_mass"); 
  readplots(filePointers,Zcand_Xbb50_pT,"Zcand_Xbb50_pT");
  readplots(filePointers,Zcand_Xbb60_pT,"Zcand_Xbb60_pT");
  readplots(filePointers,Zcand_Xbb70_pT,"Zcand_Xbb70_pT");
  readplots(filePointers,Zcand_Xbb80_pT,"Zcand_Xbb80_pT");
  readplots(filePointers,Zcand_Xbb50_pT,"Zcand_Xbb50_pT");
  readplots(filePointers,Zcand_Xbb60_pT,"Zcand_Xbb60_pT");
  readplots(filePointers,Zcand_Xbb70_pT,"Zcand_Xbb70_pT");
  readplots(filePointers,Zcand_Xbb80_pT,"Zcand_Xbb80_pT");
  //readplots(filePointers,Zcand_Xbb70_mass,"Zcand_Xbb70_mass");
  //readplots(filePointers,Zcand_Xbb70_mass_cat2_O,"Zcand_Xbb70_mass_cat2_O");
  //readplots(filePointers,Zcand_Xbb60_mass_cat2,"Zcand_Xbb60_mass_cat2");
  //readplots(filePointers,Zcand_Xbb70_mass,"Zcand_Xbb70_mass");
  //readplots(filePointers,Zcand_2b_DL1r_60_mass,"Zcand_2b_DL1r_60_mass");
  //readplots(filePointers,Zcand_Xbb70_mass_cat2_pT456,"Zcand_Xbb70_mass_cat2_pT456");
  //readplots(filePointers,Zcand_Xbb70_mass_cat2,"Zcand_Xbb70_mass_cat2");
  //readplots(filePointers,Zcand_Xbb70_mass_pT610,"Zcand_Xbb70_mass_pT610");
  //readplots(filePointers,Zcand_Xbb50_mass_cat1_pT610,"Zcand_Xbb50_mass_cat1_pT610");
  //readplots(filePointers,Zcand_Xbb60_mass_pT710,"Zcand_Xbb60_mass_pT710");
  //readplots(filePointers,Zcand_Xbb60_mass_pT455,"Zcand_Xbb60_mass_pT455");

  readplots(filePointers,Zcand_Xbb60_mass_pT56,"Zcand_Xbb60_mass_pT56");
  readplots(filePointers,Zcand_Xbb60_mass_pT67,"Zcand_Xbb60_mass_pT67"); 
  readplots(filePointers,Zcand_Xbb60_mass_pT710,"Zcand_Xbb60_mass_pT710");
  readplots(filePointers,Zcand_Xbb60_mass_pT455,"Zcand_Xbb60_mass_pT455");
  readplots(filePointers,Zcand_Xbb60_mass_pT456,"Zcand_Xbb60_mass_pT456"); 
  readplots(filePointers,Zcand_Xbb60_mass_pT610,"Zcand_Xbb60_mass_pT610");

  readplots(filePointers,Zcand_Xbb70_mass_pT56,"Zcand_Xbb70_mass_pT56");
  readplots(filePointers,Zcand_Xbb70_mass_pT67,"Zcand_Xbb70_mass_pT67"); 
  readplots(filePointers,Zcand_Xbb70_mass_pT710,"Zcand_Xbb70_mass_pT710");
  readplots(filePointers,Zcand_Xbb70_mass_pT455,"Zcand_Xbb70_mass_pT455");
  readplots(filePointers,Zcand_Xbb70_mass_pT456,"Zcand_Xbb70_mass_pT456"); 
  readplots(filePointers,Zcand_Xbb70_mass_pT610,"Zcand_Xbb70_mass_pT610");

  //readplots(filePointers,Zcand_Xbb60_mass_pT67_data,"Zcand_Xbb60_mass_pT67_data");
  //readplots(filePointers,Zcand_Xbb50_mass_pT67,"Zcand_Xbb50_mass_pT67");
  //readplots(filePointers,Zcand_Xbb50_mass_pT710,"Zcand_Xbb50_mass_pT710");  
  /*readplots(filePointers,Zcand_Xbb70_mass_pT56,"Zcand_Xbb70_mass_pT56");
  readplots(filePointers,Zcand_Xbb70_mass_pT67,"Zcand_Xbb70_mass_pT67");
  readplots(filePointers,Zcand_Xbb70_mass_pT710,"Zcand_Xbb70_mass_pT710");*/
  
  /*readplots(filePointers,Zcand_mass,"Zcand_mass");
  readplots(filePointers,Zcand_pt,"Zcand_pt");*/
  
  /*readplots(filePointers,pTasymmetry, "pT asymmetry");
  readplots(filePointers, Dely_12, "Del y_12");  
  readplots(filePointers,Zcand_0b_DL1r_mass,"Zcand_0b_DL1r_mass");
  readplots(filePointers,Zcand_0b_DL1r_pt,"Zcand_0b_DL1r_pt");*/

  /*readplots(filePointers,Zcand_1b_DL1r_60_mass,"Zcand_1b_DL1r_60_mass");
  //readplots(filePointers,Zcand_1b_DL1r_60_pt,"Zcand_1b_DL1r_60_pt");
  readplots(filePointers,Zcand_2b_DL1r_60_mass,"Zcand_2b_DL1r_60_mass");
  //readplots(filePointers,Zcand_2b_DL1r_60_pt,"Zcand_2b_DL1r_60_pt");
    
  readplots(filePointers,Zcand_1b_DL1r_70_mass,"Zcand_1b_DL1r_70_mass");
  //readplots(filePointers,Zcand_1b_DL1r_70_pt,"Zcand_1b_DL1r_70_pt");
  readplots(filePointers,Zcand_2b_DL1r_70_mass,"Zcand_2b_DL1r_70_mass");
  //readplots(filePointers,Zcand_2b_DL1r_70_pt,"Zcand_2b_DL1r_70_pt");

  readplots(filePointers,Zcand_1b_DL1r_77_mass,"Zcand_1b_DL1r_77_mass");
  //readplots(filePointers,Zcand_1b_DL1r_77_pt,"Zcand_1b_DL1r_77_pt");
  readplots(filePointers,Zcand_2b_DL1r_77_mass,"Zcand_2b_DL1r_77_mass");
  //readplots(filePointers,Zcand_2b_DL1r_77_pt,"Zcand_2b_DL1r_77_pt");

  readplots(filePointers,Zcand_1b_DL1r_85_mass,"Zcand_1b_DL1r_85_mass");
  //readplots(filePointers,Zcand_1b_DL1r_85_pt,"Zcand_1b_DL1r_85_pt");
  readplots(filePointers,Zcand_2b_DL1r_85_mass,"Zcand_2b_DL1r_85_mass");
  //readplots(filePointers,Zcand_2b_DL1r_85_pt,"Zcand_2b_DL1r_85_pt");*/

  /*readplots(filePointers,Zcand_Tau21_0b,"Zcand_Tau21_0b");
   readplots(filePointers,Zcand_Tau21_1b60,"Zcand_Tau21_1b60");
   readplots(filePointers,Zcand_Tau21_2b60,"Zcand_Tau21_2b60");
   readplots(filePointers,Zcand_Tau21_1b70,"Zcand_Tau21_1b70");
   readplots(filePointers,Zcand_Tau21_2b70,"Zcand_Tau21_2b70");
   readplots(filePointers,Zcand_Tau21_1b77,"Zcand_Tau21_1b77");
   readplots(filePointers,Zcand_Tau21_2b77,"Zcand_Tau21_2b77");
   readplots(filePointers,Zcand_Tau21_1b85,"Zcand_Tau21_1b85");
   readplots(filePointers,Zcand_Tau21_2b85,"Zcand_Tau21_2b85");*/

  /*readplots(filePointers,Selected_leading_largeRjet_mass_vs_tau21 ,"Selected_leading_largeRjet_mass_vs_tau21");
   readplots(filePointers,Selected_leading_largeRjet_pt_vs_tau21 ,"Selected_leading_largeRjet_pt_vs_tau21");
   readplots(filePointers,Selected_leading_largeRjet_ljetpt_vs_tau21 ,"Selected_leading_largeRjet_ljetpt_vs_tau21");
   readplots(filePointers,Selected_leading_largeRjet_sljetpt_vs_tau21 ,"Selected_leading_largeRjet_sljetpt_vs_tau21");*/

  std::cout<<"All plots have been read. Beginning to draw plots."<<std::endl;
  
  //drawplot("Zcand_Xbb60_mass_pT455",Zcand_Xbb60_mass_pT455, false);
  //drawplot("Zcand_mass",Zcand_mass,false);
  //drawplot("Zcand_pt",Zcand_pt,true);
  
  //drawplot("Zcand_Tau21",Zcand_Tau21,false);
  
  drawplot("pT asymmetry", pTasymmetry, false);
  drawplot("Del y_12", Dely_12, false); 
  
  drawplot("Zcand_0b_DL1r_mass",Zcand_0b_DL1r_mass, false);
  drawplot("Zcand_0b_DL1r_pt",Zcand_0b_DL1r_pt, true);
  //drawplot("Selected_pTsymmetry_etaCut_leading_largeRjet_mass", Selected_pTsymmetry_etaCut_leading_largeRjet_mass,true);
  //drawplot("Zcand_mass", Zcand_mass,false);
  //drawplot("Zcand_Xbb60_mass",Zcand_Xbb60_mass ,false);
  //drawplot("Zcand_Xbb",Zcand_Xbb ,true);
  drawplot("Zcand_Xbb50_mass",Zcand_Xbb50_mass ,false);
  drawplot("Zcand_Xbb60_mass",Zcand_Xbb60_mass ,false);
  drawplot("Tagged_50_mass",Tagged_50_mass ,false);
  drawplot("Tagged_80_mass",Tagged_80_mass ,false);
  drawplot("Zcand_Xbb70_mass",Zcand_Xbb70_mass ,false);
  drawplot("Zcand_Xbb80_mass",Zcand_Xbb80_mass ,false);
  drawplot("Zcand_Xbb50_pT",Zcand_Xbb50_pT ,false);
  drawplot("Zcand_Xbb60_pT",Zcand_Xbb60_pT ,false);
  drawplot("Zcand_Xbb70_pT",Zcand_Xbb70_pT ,false);
  drawplot("Zcand_Xbb80_pT",Zcand_Xbb80_pT ,false);

  drawplot("Zcand_Xbb50_pT",Zcand_Xbb50_pT ,true);
  drawplot("Zcand_Xbb60_pT",Zcand_Xbb60_pT ,true);
  drawplot("Zcand_Xbb70_pT",Zcand_Xbb70_pT ,true);
  drawplot("Zcand_Xbb80_pT",Zcand_Xbb80_pT ,true);

  /*drawplot("Zcand_Xbb50_pT_wom",Zcand_Xbb50_pT_wom ,true);
  drawplot("Zcand_Xbb60_pT_wom",Zcand_Xbb60_pT_wom ,true);
  drawplot("Zcand_Xbb70_pT_wom",Zcand_Xbb70_pT_wom ,true);
  drawplot("Zcand_Xbb80_pT_wom",Zcand_Xbb80_pT_wom ,true);*/
  //***
  /*drawplot("Zcand_Xbb50_mass_pT56",Zcand_Xbb50_mass_pT56, false);
  drawplot("Zcand_Xbb50_mass_pT67",Zcand_Xbb50_mass_pT67, false);
  drawplot("Zcand_Xbb50_mass_pT710",Zcand_Xbb50_mass_pT710, false);*/


  /*drawplot("Zcand_Xbb60_mass_pT455",Zcand_Xbb60_mass_pT455, false);
  drawplot("Zcand_Xbb60_mass_pT56",Zcand_Xbb60_mass_pT56, false);
  drawplot("Zcand_Xbb60_mass_pT67",Zcand_Xbb60_mass_pT67, false);
  drawplot("Zcand_Xbb60_mass_pT710",Zcand_Xbb60_mass_pT710, false);
  drawplot("Zcand_Xbb60_mass_pT456",Zcand_Xbb60_mass_pT456, false);
  drawplot("Zcand_Xbb60_mass_pT610",Zcand_Xbb60_mass_pT610, false);

  drawplot("Zcand_Xbb70_mass_pT455",Zcand_Xbb70_mass_pT455, false);
  drawplot("Zcand_Xbb70_mass_pT56",Zcand_Xbb70_mass_pT56, false);
  drawplot("Zcand_Xbb70_mass_pT67",Zcand_Xbb70_mass_pT67, false);
  drawplot("Zcand_Xbb70_mass_pT710",Zcand_Xbb70_mass_pT710, false);
  drawplot("Zcand_Xbb70_mass_pT456",Zcand_Xbb70_mass_pT456, false);
  drawplot("Zcand_Xbb70_mass_pT610",Zcand_Xbb70_mass_pT610, false);*/
  

  /*drawplot("Zcand_1b_DL1r_60_mass",Zcand_1b_DL1r_60_mass, false);
  //drawplot("Zcand_1b_DL1r_60_pt",Zcand_1b_DL1r_60_pt, true);
  drawplot("Zcand_2b_DL1r_60_mass",Zcand_2b_DL1r_60_mass, false);
  //drawplot("Zcand_2b_DL1r_60_pt",Zcand_2b_DL1r_60_pt, true);
  
  drawplot("Zcand_1b_DL1r_70_mass",Zcand_1b_DL1r_70_mass, false);
  //rawplot("Zcand_1b_DL1r_70_pt",Zcand_1b_DL1r_70_pt, true);
  drawplot("Zcand_2b_DL1r_70_mass",Zcand_2b_DL1r_70_mass, false);
  //drawplot("Zcand_2b_DL1r_70_pt",Zcand_2b_DL1r_70_pt, true);

  drawplot("Zcand_1b_DL1r_77_mass",Zcand_1b_DL1r_77_mass, false);
  //drawplot("Zcand_1b_DL1r_77_pt",Zcand_1b_DL1r_77_pt, true);
  drawplot("Zcand_2b_DL1r_77_mass",Zcand_2b_DL1r_77_mass, false);
  //drawplot("Zcand_2b_DL1r_77_pt",Zcand_2b_DL1r_77_pt, true);

  drawplot("Zcand_1b_DL1r_85_mass",Zcand_1b_DL1r_85_mass, false);
  //drawplot("Zcand_1b_DL1r_85_pt",Zcand_1b_DL1r_85_pt, true);
  drawplot("Zcand_2b_DL1r_85_mass",Zcand_2b_DL1r_85_mass, false);
  //drawplot("Zcand_2b_DL1r_85_pt",Zcand_2b_DL1r_85_pt, true);*/
  
  
   drawplot("Zcand_Tau21_0b",Zcand_Tau21_0b, false);
   drawplot("Zcand_Tau21_1b60",Zcand_Tau21_1b60, false);
   drawplot("Zcand_Tau21_2b60",Zcand_Tau21_2b60, false);
   //drawplot("Zcand_mass_Tmincut",Zcand_mass_Tmincut, true);
   drawplot("Zcand_Tau21_1b70",Zcand_Tau21_1b70, false);
   drawplot("Zcand_Tau21_2b70",Zcand_Tau21_2b70, false);
   drawplot("Zcand_Tau21_1b77",Zcand_Tau21_1b77, false);
   drawplot("Zcand_Tau21_2b77",Zcand_Tau21_2b77, false);
   drawplot("Zcand_Tau21_1b85",Zcand_Tau21_1b85, false);
   drawplot("Zcand_Tau21_2b85",Zcand_Tau21_2b85, false);
  

  std::cout<<"All plots have been drawn."<<std::endl;


} // end datavmc()

void drawplot(TString name,TH1D** hists, bool dology) {

  //TCanvas * canv = new TCanvas("can "+name,"can "+name,800,600);
  //canv->SetRightMargin(0.1);
  //canv->SetLeftMargin(0.15);
  std::shared_ptr<TCanvas> canv(new TCanvas("can"+name,"can"+name, 800, 800));
  canv->SetRightMargin(0.08);
  canv->SetLeftMargin(0.15);
  
  canv.get()->cd();
  std::shared_ptr<TPad> pad1(new TPad("pad1","pad1",0,0.35,1,1));
  pad1.get()->SetLeftMargin(0.15);
  pad1.get()->SetBottomMargin(0.);
   pad1.get()->SetRightMargin(0.08);
  pad1.get()->Draw();
  pad1.get()->SetTicks();
  if (dology) pad1->SetLogy();
  canv->cd();
  
  std::shared_ptr<TPad> pad2 = std::shared_ptr<TPad>(new TPad("pad2","pad2",0,0.0,1,0.35));
  pad2.get()->SetLeftMargin(0.15);
   pad2.get()->SetRightMargin(0.08);
  pad2->SetTopMargin(0.0);
  pad2->SetBottomMargin(0.35);
  
  pad2.get()->Draw();
  pad2.get()->SetTicks();
  
  TLegend * leg = new TLegend(0.7,0.72,0.8,0.92);
  leg->SetTextFont(42);
  leg->SetTextSize(0.025);
  leg->SetBorderSize(0);
  leg->SetMargin(0.25);

  //double delx = 0.115*696*gPad->GetWh()/(472*gPad->GetWw());
  double_t x = 0.17;
  double_t y = 0.89;
  TLatex * l = new TLatex(x,y,"ATLAS Internal");
  l->SetNDC();
  l->SetTextFont(72);
  l->SetTextColor(1);
  
  /*
  TLatex * p = new TLatex(x+delx,y,"work-in-progress");
  p->SetNDC();
  p->SetTextFont(42);
  p->SetTextColor(1);
  */
  TLatex * r = new TLatex(x,0.85,"#sqrt{s} = 13 TeV, 80.4 fb^{-1}");
  r->SetNDC();
  r->SetTextFont(42);
  r->SetTextColor(1);
  r->SetTextSize(0.04);
  
  TLatex * X50 = new TLatex(x,0.70,"DXbb Tagger 50%");
  X50->SetNDC();
  X50->SetTextFont(42);
  X50->SetTextColor(1);
  X50->SetTextSize(0.04);

  TLatex * X60 = new TLatex(x,0.70,"DXbb Tagger 60%");
  X60->SetNDC();
  X60->SetTextFont(42);
  X60->SetTextColor(1);
  X60->SetTextSize(0.04);

  TLatex * X70 = new TLatex(x,0.70,"DXbb Tagger 70%");
  X70->SetNDC();
  X70->SetTextFont(42);
  X70->SetTextColor(1);
  X70->SetTextSize(0.04);

  TLatex * X80 = new TLatex(x,0.70,"DXbb Tagger 80%");
  X80->SetNDC();
  X80->SetTextFont(42);
  X80->SetTextColor(1);
  X80->SetTextSize(0.04);
  
  TLatex * p = new TLatex(x,0.82,"M > 50 GeV");
  p->SetNDC();
  p->SetTextFont(42);
  p->SetTextColor(1);
  p->SetTextSize(0.04);

  TLatex * n = new TLatex(x,0.78," 450 GeV <= p_{T}(J) < 1000 GeV");
  n->SetNDC();
  n->SetTextFont(42);
  n->SetTextColor(1);
  n->SetTextSize(0.04);

  TLatex * s = new TLatex(x,0.73,"At least 2 ghost-associated VR track jets");
  s->SetNDC();
  s->SetTextFont(42);
  s->SetTextColor(1);
  s->SetTextSize(0.04);

  TLatex * aTwo = new TLatex(x,0.71,"Two b-tags, DL1r, 60% WP");
  aTwo->SetNDC();
  aTwo->SetTextFont(42);
  aTwo->SetTextColor(1);
  aTwo->SetTextSize(0.04);
  TLatex * bTwo = new TLatex(x,0.71,"Two b-tags, DL1r, 70% WP");
  bTwo->SetNDC();
  bTwo->SetTextFont(42);
  bTwo->SetTextColor(1);
  bTwo->SetTextSize(0.04);
  TLatex * cTwo = new TLatex(x,0.71,"Two b-tags, DL1r, 77% WP");
  cTwo->SetNDC();
  cTwo->SetTextFont(42);
  cTwo->SetTextColor(1);
  cTwo->SetTextSize(0.04);

  TLatex * dTwo = new TLatex(x,0.71,"Two b-tags, DL1r, 85% WP");
  dTwo->SetNDC();
  dTwo->SetTextFont(42);
  dTwo->SetTextColor(1);
  dTwo->SetTextSize(0.04);

  TLatex * aOne = new TLatex(x,0.71,"One b-tag, DL1r, 60% WP");
  aOne->SetNDC();
  aOne->SetTextFont(42);
  aOne->SetTextColor(1);
  aOne->SetTextSize(0.04);

  TLatex * bOne = new TLatex(x,0.71,"One b-tag, DL1r, 70% WP");
  bOne->SetNDC();
  bOne->SetTextFont(42);
  bOne->SetTextColor(1);
  bOne->SetTextSize(0.04);

  TLatex * cOne = new TLatex(x,0.71,"One b-tag, DL1r, 77% WP");
  cOne->SetNDC();
  cOne->SetTextFont(42);
  cOne->SetTextColor(1);
  cOne->SetTextSize(0.04);

  TLatex * dOne = new TLatex(x,0.71,"One b-tag, DL1r, 85% WP");
  dOne->SetNDC();
  dOne->SetTextFont(42);
  dOne->SetTextColor(1);
  dOne->SetTextSize(0.04);

  TLatex * v = new TLatex(x,0.71,"Untagged");
  v->SetNDC();
  v->SetTextFont(42);
  v->SetTextColor(1);
  v->SetTextSize(0.04);

  TLatex * b = new TLatex(x,0.71," b-tag veto region, DL1r");
  b->SetNDC();
  b->SetTextFont(42);
  b->SetTextColor(1);
  b->SetTextSize(0.04);

  //hists[nfile+3]->Add(hists[nfile+4]);
  //hists[nfile+3]->Add(hists[nfile+5]);

  THStack * data_v_mc_stacked = new THStack();
  int cols[4] = {kBlue, kGreen+2 ,kViolet-3, kRed-3};
  TString types[4] = {"Sherpa2.2.8 Z+Jet","Sherpa2.2.8 W+Jet","Pythia8+Powheg tt","Pythia8 QCD dijets"};
  int col=0;
  double y1 = 1E30;
  double y2 = -1E30;
  //double lumi = 80.4*1000000; // in nb
  
  //for(int i=0;i<nfile;++i){ //taken from hist adding class
  //hists[i]->Scale(lumi);
  //}

  for (int i=0;i<4;++i) {
    //if (Sherpa==true && i==0) continue;
    //if (Sherpa==true && i==1) continue;
    //if (Sherpa==false && i==2) continue;
    //if (Sherpa==false && i==3) continue; 
    if (hists[nfile+i]->GetMinimum() < y1) y1 = hists[nfile+i]->GetMinimum();
    //if (name.Contains("mass") && (name.Contains("2b_DL1r_60") || name.Contains("2b_DL1r_70") || name.Contains("2b_DL1r_77") || name.Contains("2b_DL1r_85")))
    if (name.Contains("pt"))
    { if (hists[nfile+i]->GetMaximum() > y2) y2 = hists[nfile+i]->GetMaximum();}
    else{ 
      if (hists[nfile+i]->GetMaximum() > y2) y2 = hists[nfile+i]->GetMaximum()+(hists[nfile+i]->GetMaximum())*0.8;
      }
   if (dology) {
         y2 = hists[nfile+i]->GetMaximum()+(hists[nfile+i]->GetMaximum())*100;
   }

   
    //if (hists[nfile+i]->GetMaximum() > y2) y2 = hists[nfile+i]->GetMaximum();
  }
  
  if (dology) {
    if (y1<0.01) y1 = 0.1;
    y2 = y2 * 1.5;
    if (y1 <= 0) y1 = 1E-10;
  }

  
  /*if (dology) {
    //if (y1<0.01) y1 = 0.1;
    y2 = y2 * 100;
    if (y1 <= 0) y1 = 1E-02;
  }*/
  TH1D * full_mc = (TH1D*)hists[nfile+3]->Clone();
  for (int i=3;i>=0;--i) {
    //if (Sherpa==true && i==0) continue;
    //if (Sherpa==true && i==1) continue;
    //if (Sherpa==false && i==2) continue;
    //if (Sherpa==false && i==3) continue;
    
    col=cols[i];
    hists[nfile+i]->SetFillColor(col); //changing it temporarily (only remove this line for drawing Xbb discriminant)
    hists[nfile+i]->SetLineColor(col);
    hists[nfile+i]->GetXaxis()->SetTickLength(0);
    hists[nfile+i]->GetXaxis()->SetLabelOffset(999);
    leg->AddEntry(hists[nfile+i],types[i],"f");
    if (hists[nfile+i] != 0)
      { 
       data_v_mc_stacked->Add(hists[nfile+i]);
        //full_mc->Add(hists[nfile+i]);
      }
    if (hists[nfile+i] != 0 && (i==2 || i== 1 || i==0))
      { 
        full_mc->Add(hists[nfile+i]);
      }
  }
   
  data_v_mc_stacked->SetMinimum(y1);
  data_v_mc_stacked->SetMaximum(y2);

  //Lines required for drawing Xbb discriminant only
  /*full_mc->SetLineColor(kMagenta);
  full_mc->SetMinimum(y1);
  full_mc->SetMaximum(y2);*/
  
  hists[nfile+4]->SetMarkerStyle(20);
  hists[nfile+4]->SetMarkerColor(1);
  
  leg->AddEntry(hists[nfile+4],"Data","epl");
  //pad1->cd();
  hists[nfile+4]->SetTitleOffset(0.9,"Y");
  hists[nfile+4]->SetTitleSize(0.07,"Y");
  hists[nfile+4]->SetLabelSize(0.055, "Y");
  
  hists[nfile+4]->SetMinimum(y1);
  hists[nfile+4]->SetMinimum(y2);
  pad1->cd();
  
  data_v_mc_stacked->Draw("hist");

  data_v_mc_stacked->GetHistogram()->GetXaxis()->SetTickLength(0);
  data_v_mc_stacked->GetHistogram()->GetXaxis()->SetLabelOffset(999);

  //Lines required for drawing Xbb discriminant only 
  /*full_mc->Draw("hist");

  full_mc->GetXaxis()->SetTickLength(0);
  full_mc->GetXaxis()->SetLabelOffset(999);
  hists[nfile]->Draw("hist same");
  hists[nfile+1]->Draw("hist same");
  hists[nfile+2]->Draw("hist same");
  hists[nfile+3]->Draw("hist same");*/
  
  //hists[nfile+4]->SetLabelSize(0,"X");
  
  hists[nfile+4]->Draw("same");
  hists[nfile+4]->GetXaxis()->SetTickLength(0);
  hists[nfile+4]->GetXaxis()->SetLabelOffset(999);
  canv->cd();
 //ratio
  TH1D *h_ratio=(TH1D*)hists[nfile+4]->Clone();
  h_ratio->Divide(full_mc);
  h_ratio->SetMinimum();

  h_ratio->SetTitle("");
  h_ratio->SetMarkerStyle(20);
  h_ratio->SetYTitle("Data/MC");

  
 /* if (name.Contains("pT")) {
    data_v_mc_stacked->GetXaxis()->SetRangeUser(200, 1000);
    data_v_mc_stacked->GetXaxis()->SetTitle("P_{T} / GeV");
  }*/
  /*
  if (name.Contains("mass") && name.Contains("Zcand")) {
    data_v_mc_stacked->GetXaxis()->SetRangeUser(40e3,150e3);
    data_v_mc_stacked->GetXaxis()->SetTitle("Mass / MeV");
  }
  */
  
  

  /*
  if ((name.Contains("2b_DL1r_70") || name.Contains("2b_DL1r_77") || name.Contains("2b_DL1r_85")) && name.Contains("mass")) {
    h_ratio->GetXaxis()->SetRangeUser(50e3,150e3);
    h_ratio->GetYaxis()->SetRangeUser(y1, y2/10);
    h_ratio->GetXaxis()->SetTitle("Mass / MeV");
  }

  if (name.Contains("2b_DL1r_60") && name.Contains("mass")) {
    h_ratio->GetXaxis()->SetRangeUser(50e3,150e3);
    h_ratio->GetYaxis()->SetRangeUser(y1, y2/1.39*100000000);
    h_ratio->GetXaxis()->SetTitle("Mass / MeV");
  }
  */
  
  
  /*if (name.Contains("Zcand_mass")) {
    h_ratio->GetXaxis()->SetRangeUser(50e3,150e3);
    h_ratio->GetXaxis()->SetTitle("Mass / MeV");
    }*/
   
  pad2->SetGrid();
  pad2->cd();
  h_ratio->GetYaxis()->SetRangeUser(0.4,1.6);
  h_ratio->SetLabelSize(0.102,"X");
  
  h_ratio->SetLabelSize(0.102,"Y");
  
  h_ratio->SetTitleSize(0.12,"X");
  h_ratio->SetTitleSize(0.12,"Y");
  h_ratio->SetTitleOffset(0.48,"Y");
  h_ratio->SetTitleOffset(1.2,"X");
  h_ratio->GetYaxis()->SetNdivisions(505);
  h_ratio->Draw("EP");  
  h_ratio->SetTickLength(0.01,"X"); //0.05
  h_ratio->SetLabelOffset(0.01,"X"); //0.02
if (name.Contains("pT")) {
    h_ratio->GetXaxis()->SetRangeUser(200, 1000);
    h_ratio->GetXaxis()->SetTitle("P_{T} / GeV");
  }
if (name.Contains("pT asymmetry")) {
  h_ratio->GetXaxis()->SetRangeUser(0,1);
    h_ratio->GetXaxis()->SetTitle("P_{T} asymmetry");
  } 
if (name.Contains("Del y_12")) {
  h_ratio->GetXaxis()->SetRangeUser(0,4);
    h_ratio->GetXaxis()->SetTitle("Del y_{12}");
  } 

  if (name.Contains("mass")) {
    h_ratio->GetXaxis()->SetRangeUser(50,200);
    h_ratio->GetXaxis()->SetTitle("Mass / GeV");
  }

   if (name.Contains("Tau21")) {
     h_ratio->GetXaxis()->SetRangeUser(0,1.0);
    h_ratio->GetXaxis()->SetTitle("#tau_{21}");
  }
  if (name == "Zcand_Xbb") {
     //h_ratio->GetXaxis()->SetRangeUser(0,1.0);
    h_ratio->GetXaxis()->SetTitle("Xbb Discriminant");
  }
  pad1->cd();
  
  
  data_v_mc_stacked->GetYaxis()->SetTitle("Events/ 5 GeV");
  //full_mc->GetYaxis()->SetTitle("Events");
  
  if (leg)   leg->Draw();
  
  l->Draw();
  //p->Draw();
  r->Draw();
  n->Draw();
  s->Draw();
  if(name.Contains("Zcand_Xbb50_pT"))p->Draw();
  if(name.Contains("Zcand_Xbb60_pT"))p->Draw();
  if(name.Contains("Zcand_Xbb70_pT"))p->Draw();
  if(name.Contains("Zcand_Xbb80_pT"))p->Draw();
  if(name == "Zcand_Xbb")p->Draw();
  if (name.Contains("Zcand_mass")) v->Draw();
  //if (name.Contains("Zcand_pt")) v->Draw();
  if (name.Contains("0b_DL1r")) b->Draw();
  if (name.Contains("2b_DL1r_60" )) aTwo->Draw();
  if (name.Contains("2b_DL1r_70" )) bTwo->Draw();
  if (name.Contains("2b_DL1r_77" )) cTwo->Draw();
  if (name.Contains("2b_DL1r_85" )) dTwo->Draw();

  if (name.Contains("1b_DL1r_60" )) aOne->Draw();
  if (name.Contains("1b_DL1r_70" )) bOne->Draw();
  if (name.Contains("1b_DL1r_77" )) cOne->Draw();
  if (name.Contains("1b_DL1r_85" )) dOne->Draw();
  
  if (name.Contains("Xbb50" )) X50->Draw();
  if (name.Contains("Xbb60" )) X60->Draw();
  if (name.Contains("Xbb70" )) X70->Draw();
  if (name.Contains("Xbb80" )) X80->Draw();
  
  if (Sherpa) 
    {if (name.Contains("pT asymmetry"))
	{ canv->SaveAs("Nominal_pTassy_data_v_mc_sherpa.pdf");}
     if (name.Contains("Del y_12"))
	{ canv->SaveAs("Nominal_dely12_data_v_mc_sherpa.pdf");}
      else{
	canv->SaveAs("XbbDL1rTagger_1611/Nominal_"+name+"_data_v_mc_sherpa_p4128_228_80fb.pdf");}}
  if (! Sherpa) canv->SaveAs("XbbDL1rTagger_1611/Nominal_"+name+"_data_v_mc_madgraph_p4128_228_80fb.pdf");
  
  return;
}

template <class THnD> int readplots(TFile ** filePointers,THnD ** histPointers,TString name) {
  int trouble = 0;
  std::cout<<"readplots is called for name="<<name<<std::endl;
  for (int i=0;i<nfile;++i) {
    histPointers[i] = 0;
    if (!filePointers[i]) {
      trouble++;
      continue;
    }
    filePointers[i]->cd();

    histPointers[i] = (THnD*)gROOT->FindObject(name);
    if (histPointers[i] == 0 ) {
      trouble++;
    } else {
      if (name.Contains("mass")) histPointers[i]->GetXaxis()->SetTitle("m_{J} [MeV]");
      if (name.Contains("pt") && !name.Contains("ratio")) histPointers[i]->GetXaxis()->SetTitle("p_{T} [MeV]");

    } // end else
  } // end for 

  if (trouble > 0) std::cout<<"readplots failed to find "<<trouble<<" from "<<nfile<<" for "<<name<<std::endl;

  histPointers[p_data]->Rebin(1);
 
  /*histPointers[nfile] =  sumPlots(histPointers,p_Mad_Wqqgam_r10201,10);
  histPointers[nfile+1] = sumPlots(histPointers,p_Mad_Zqqgam_r10201,10);
  histPointers[nfile+2] = sumPlots(histPointers,p_Sherpa_Wqqgam_r10201,10);
  histPointers[nfile+3] = sumPlots(histPointers,p_Sherpa_Zqqgam_r10201,10);
  histPointers[nfile+4] = sumPlots(histPointers,p_SinglePhoton_BFilter_r10201,14);
  histPointers[nfile+5] = sumPlots(histPointers,p_SinglePhoton_CFilterBVeto_r10201,14);
  histPointers[nfile+6] = sumPlots(histPointers,p_SinglePhoton_CVetoBVeto_r10201,14);
  histPointers[nfile+7] = (THnD*)histPointers[p_data]->Clone();*/

  histPointers[nfile] =  sumPlots(histPointers,p_Sherpa_ZJets_r9364,1);
  histPointers[nfile+1] = sumPlots(histPointers,p_Sherpa_WJets_r9364,1);
  histPointers[nfile+2] = sumPlots(histPointers,p_Pythia_tt_r9364,1);
  histPointers[nfile+3] = sumPlots(histPointers,p_Pythia_qcdjet_r9364,10);
  histPointers[nfile+4] = (THnD*)histPointers[p_data]->Clone();
  /*THnD * temp = (THnD*)histPointers[p_data]->Clone();
  f_data->cd();
  temp->SetName("data");
  temp->Write(); */
  return trouble;
}

template <class THnD> THnD* sumPlots(THnD ** histPointers,uint p1,int n) {
  THnD* result = 0;
  for (int in=0;in<n;++in) {
    TString name = histPointers[p1]->GetName();
    // double scale = 44.3*1000000; // lumi in nb so can normalise to cross section
    //if(p1>=3 && p1<=12)
    //{  histPointers[p1]->Scale(1.0);
    //} 
    //histPointers[p1]->Scale(scale);
    histPointers[p1]->Rebin(1);
    //if(name == "Zcand_2b_DL1r_60_mass")
    //{
    THnD * temp = (THnD*)histPointers[p1]->Clone();
    if (result == 0) {
      result = temp;
    } else {
      result->Add(temp);
    }       
    p1++;
    //}
  }
  std::cout<<"sumPlots done for all"<<std::endl;
  
  //For filling in the templates for the fit
  /*if(p1==3)
    {
    f_Z2b60->cd();
    result->SetName("Zqq");
  result->Write();
  }
  
  if(p1==6)
    {
    f_W2b60->cd();
    result->SetName("Wqq");
  result->Write();
  }
  
  if(p1==7)
    {
    f_tt2b60->cd();
    result->SetName("ttbar");
  result->Write();
  }
  */
  /*if(p1==17)
    {
    f_QCD2b60->cd();
    result->SetName("data");
  result->Write();
  }*/
  return result;
}
