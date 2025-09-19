#include "TFile.h"
#include "TTree.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "TList.h"
#include "TLegend.h"
#include "TColor.h"
#include "TDatime.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TLine.h"
#include "THStack.h"
#include "TStyle.h"
#include "math.h"
#include "TROOT.h"
#include "TGaxis.h"
#include "TVector.h"
#include "TMatrix.h"
#include "TMatrixFUtils.h"
#include <TMatrixDSymEigen.h>
#include <TMatrixDSym.h>
#include <TVectorD.h>
#include "TH1D.h"
#include "TH2D.h"

//**********************************************************************************************
//This file is used to calculate significance gained  with JSS over the baseline selection criteria in the
//0-b, 1-b and 2-b tag region...
//**********************************************************************************************

void Cut_Significance()
{

    std::shared_ptr<TCanvas> canv(new TCanvas("canv","",500,500));
    canv.get()->cd(); 
    std::shared_ptr<TPad> pad1(new TPad("pad1","pad1",0.007,0.,1,1));
    pad1.get()->SetLeftMargin(0.15);
    pad1.get()->SetBottomMargin(0.15);
    pad1.get()->Draw();
    
    /*TFile File1("JSSAna_ZSample.root");//files including the signal JSS
TFile File2("JSSAna_QCD.root");//files including the background JSS
TFile File3("JSSAna_WSample.root");
TFile File4("JSSAna_tt.root");*/
    /*TFile File1("JSSTest_ZSample_JSS_MC16d_Nominal.root");//files including the signal JSS
TFile File2("JSSTest_QCDSample_JSS_MC16d_Nominal.root");//files including the background JSS
TFile File3("JSSTest_WSample_JSS_MC16d_Nominal.root");
TFile File4("JSSTest_ttSample_JSS_MC16d_Nominal.root");*/

    /* TFile File1("Z_2b_Sign_p4128_L80.root");
TFile File2("QCD_2b_Sign_p4128_L80.root");
TFile File3("W_2b_Sign_p4128_L80.root");
TFile File4("tt_2b_Sign_p4128_L80.root");*/

TFile File1("Z_Ztagger_Sig_L80.root");
TFile File2("QCD_Ztagger_Sig_L80.root");
TFile File3("W_Ztagger_Sig_L80.root");
TFile File4("tt_Ztagger_Sig_L80.root");

/*
TH1D *hZcand_omass_sig=(TH1D*)File1.Get("Zcand_opt_largeRjet_mass");
TH1D *hZcand_omass_bkg1=(TH1D*)File2.Get("Zcand_opt_largeRjet_mass");
TH1D *hZcand_omass_bkg2=(TH1D*)File3.Get("Zcand_opt_largeRjet_mass");
TH1D *hZcand_omass_bkg3=(TH1D*)File4.Get("Zcand_opt_largeRjet_mass");*/

/*
int bmin=hZcand_omass_sig->GetXaxis()->FindBin(50e3);
 int bmax=0;
  double sum_sig=0;
  double sum_W=0;
  double sum_QCD=0;
  double sum_tt=0;
  double sign_comp=0;
 for(unsigned int i=60e3; i<=150e3; i=i+5e3)
   {
   bmax = hZcand_omass_sig->GetXaxis()->FindBin(i);
   sum_sig=hZcand_omass_sig->Integral(bmin, bmax);
   sum_W= hZcand_omass_bkg2->Integral(bmin, bmax);
   sum_QCD=hZcand_omass_bkg1->Integral(bmin, bmax);
   sum_tt=hZcand_omass_bkg3->Integral(bmin, bmax);
   sign_comp=sqrt(2*((sum_sig+sum_tt+sum_QCD+sum_W)*log(1+(sum_sig/(sum_QCD+sum_W+sum_tt)))-sum_sig));
   std::cout<<"Sensitivity for comp bkg for"<<i<<"bin"<<""<<sign_comp<<std::endl;
   std::cout<<"Signal for"<<i<<"bin"<<""<<sum_sig<<std::endl;
   std::cout<<"Bkg compos QCD for"<<i<<"bin"<<""<<sum_QCD<<std::endl;
   std::cout<<"Bkg compos tt for"<<i<<"bin"<<""<<sum_tt<<std::endl;
   std::cout<<"Bkg compos W for"<<i<<"bin"<<""<<sum_W<<std::endl;
    std::cout<<"Total bkg sum"<<i<<"bin"<<""<<sum_W+sum_QCD+sum_tt<<std::endl;
   std::cout<<"           "<<std::endl;
   }

*/



//TH1D* hist_bkgTH1D *hist_bkg;

/*
TH1D *hLeadingjetpTeta_sig=(TH1D*)File1.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_sig=(TH1D*)File1.Get("Zcand_pt");
TH1D *hZcandD2_sig=(TH1D*)File1.Get("Zcand_pt_D2cut");
TH1D *hZcandPflow32_sig=(TH1D*)File1.Get("Zcand_pt_PFlow32cut");
TH1D *hZcandTau2135_sig=(TH1D*)File1.Get("Zcand_pt_Tau2135cut");
TH1D *hZcandTmin25_sig=(TH1D*)File1.Get("Zcand_pt_Tmin25cut");
TH1D *hZcandPflow34_sig=(TH1D*)File1.Get("Zcand_pt_PFlow34cut");
TH1D *hZcandTau2140_sig=(TH1D*)File1.Get("Zcand_pt_Tau2140cut");
TH1D *hZcandTmin30_sig=(TH1D*)File1.Get("Zcand_pt_Tmin30cut");
TH1D *hZcandPflow36_sig=(TH1D*)File1.Get("Zcand_pt_PFlow36cut");
TH1D *hZcandTau2145_sig=(TH1D*)File1.Get("Zcand_pt_Tau2145cut");
TH1D *hZcandTmin35_sig=(TH1D*)File1.Get("Zcand_pt_Tmin35cut");
TH1D *hZcandMu12_sig=(TH1D*)File1.Get("Zcand_pt_Mu12cut");
TH1D *hZcandTminPFlow_sig=(TH1D*)File1.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_sig=(TH1D*)File1.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_sig=(TH1D*)File1.Get("Zcand_pt_PFlowTau21");

TH1D *hLeadingjetpTeta_bkg1=(TH1D*)File2.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg1=(TH1D*)File2.Get("Zcand_pt");
TH1D *hZcandD2_bkg1=(TH1D*)File2.Get("Zcand_pt_D2cut");
TH1D *hZcandTau2135_bkg1=(TH1D*)File2.Get("Zcand_pt_Tau2135cut");
TH1D *hZcandTmin25_bkg1=(TH1D*)File2.Get("Zcand_pt_Tmin25cut");
TH1D *hZcandPflow34_bkg1=(TH1D*)File2.Get("Zcand_pt_PFlow34cut");
TH1D *hZcandTau2140_bkg1=(TH1D*)File2.Get("Zcand_pt_Tau2140cut");
TH1D *hZcandTmin30_bkg1=(TH1D*)File2.Get("Zcand_pt_Tmin30cut");
TH1D *hZcandPflow36_bkg1=(TH1D*)File2.Get("Zcand_pt_PFlow36cut");
TH1D *hZcandTau2145_bkg1=(TH1D*)File2.Get("Zcand_pt_Tau2145cut");
TH1D *hZcandTmin35_bkg1=(TH1D*)File2.Get("Zcand_pt_Tmin35cut");
TH1D *hZcandMu12_bkg1=(TH1D*)File2.Get("Zcand_pt_Mu12cut");
TH1D *hZcandTminPFlow_bkg1=(TH1D*)File2.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg1=(TH1D*)File2.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg1=(TH1D*)File2.Get("Zcand_pt_PFlowTau21");

TH1D *hLeadingjetpTeta_bkg2=(TH1D*)File3.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg2=(TH1D*)File3.Get("Zcand_pt");
TH1D *hZcandD2_bkg2=(TH1D*)File3.Get("Zcand_pt_D2cut");
TH1D *hZcandTau2135_bkg2=(TH1D*)File3.Get("Zcand_pt_Tau2135cut");
TH1D *hZcandTmin25_bkg2=(TH1D*)File3.Get("Zcand_pt_Tmin25cut");
TH1D *hZcandPflow34_bkg2=(TH1D*)File3.Get("Zcand_pt_PFlow34cut");
TH1D *hZcandTau2140_bkg2=(TH1D*)File3.Get("Zcand_pt_Tau2140cut");
TH1D *hZcandTmin30_bkg2=(TH1D*)File3.Get("Zcand_pt_Tmin30cut");
TH1D *hZcandPflow36_bkg2=(TH1D*)File3.Get("Zcand_pt_PFlow36cut");
TH1D *hZcandTau2145_bkg2=(TH1D*)File3.Get("Zcand_pt_Tau2145cut");
TH1D *hZcandTmin35_bkg2=(TH1D*)File3.Get("Zcand_pt_Tmin35cut");
TH1D *hZcandMu12_bkg2=(TH1D*)File3.Get("Zcand_pt_Mu12cut");
TH1D *hZcandTminPFlow_bkg2=(TH1D*)File3.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg2=(TH1D*)File3.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg2=(TH1D*)File3.Get("Zcand_pt_PFlowTau21");

TH1D *hLeadingjetpTeta_bkg3=(TH1D*)File4.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg3=(TH1D*)File4.Get("Zcand_pt");
TH1D *hZcandD2_bkg3=(TH1D*)File4.Get("Zcand_pt_D2cut");
TH1D *hZcandTau2135_bkg3=(TH1D*)File4.Get("Zcand_pt_Tau2135cut");
TH1D *hZcandTmin25_bkg3=(TH1D*)File4.Get("Zcand_pt_Tmin25cut");
TH1D *hZcandPflow34_bkg3=(TH1D*)File4.Get("Zcand_pt_PFlow34cut");
TH1D *hZcandTau2140_bkg3=(TH1D*)File4.Get("Zcand_pt_Tau2140cut");
TH1D *hZcandTmin30_bkg3=(TH1D*)File4.Get("Zcand_pt_Tmin30cut");
TH1D *hZcandPflow36_bkg3=(TH1D*)File4.Get("Zcand_pt_PFlow36cut");
TH1D *hZcandTau2145_bkg3=(TH1D*)File4.Get("Zcand_pt_Tau2145cut");
TH1D *hZcandTmin35_bkg3=(TH1D*)File4.Get("Zcand_pt_Tmin35cut");
TH1D *hZcandMu12_bkg3=(TH1D*)File4.Get("Zcand_pt_Mu12cut");
TH1D *hZcandTminPFlow_bkg3=(TH1D*)File4.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg3=(TH1D*)File4.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg3=(TH1D*)File4.Get("Zcand_pt_PFlowTau21");


TH1D *hist_sig=(TH1D*)hZcandTmin35_sig->Clone();
TH1D *hist_bkg=(TH1D*)hZcandTmin35_bkg1->Clone();
TH1D *hist_bkg2=(TH1D*)hZcandTmin35_bkg2->Clone();
 TH1D *hist_bkg3=(TH1D*)hZcandTmin35_bkg3->Clone();

  double sum_sig=0;
  double sum_W=0;
  double sum_QCD=0;
  double sum_tt=0;

  double sign=0;
  double sign_W=0;
  double sign_QCD=0;
  double sign_tt=0;
  double sign_comp=0;
  sum_sig=hist_sig->Integral();
  sum_QCD=hist_bkg->Integral();
  sum_W=hist_bkg2->Integral();
  sum_tt=hist_bkg3->Integral();
  std::cout<<sum_sig<<std::endl;
  std::cout<<sum_W<<std::endl;
   std::cout<<sum_QCD<<std::endl;
  std::cout<<sum_tt<<std::endl; 
  std::cout<<sum_tt+sum_W+sum_QCD<<std::endl;
  sign_W=sqrt(2*((sum_sig+sum_W)*log(1+(sum_sig/sum_W))-sum_sig));
  std::cout<<"Sensitivity for W bkg"<<""<<sign_W<<std::endl;
  sign_QCD=sqrt(2*((sum_sig+sum_QCD)*log(1+(sum_sig/sum_QCD))-sum_sig));
  std::cout<<"Sensitivity for QCD bkg"<<""<<sign_QCD<<std::endl;
  sign_tt=sqrt(2*((sum_sig+sum_tt)*log(1+(sum_sig/sum_tt))-sum_sig));
  std::cout<<"Sensitivity for tt bkg"<<""<<sign_tt<<std::endl;
  sign_comp=sqrt(2*((sum_sig+sum_tt+sum_QCD+sum_W)*log(1+(sum_sig/(sum_QCD+sum_W+sum_tt)))-sum_sig));
  std::cout<<"Sensitivity for comp bkg"<<""<<sign_comp<<std::endl;

*/


//TH1D *hLeadingjetpTeta_sig=(TH1D*)File1.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");

//TH1D *hZcand0b_sig=(TH1D*)File1.Get("Tagged_50_0b_DL1r_mass");
TH1D *hZcand0b_sig=(TH1D*)File1.Get("Tagged_80_mass");
TH1D *hZcand1b60_sig=(TH1D*)File1.Get("Tagged_50_1b_DL1r_85_mass");
TH1D *hZcand2b60_sig=(TH1D*)File1.Get("Tagged_50_2b_DL1r_85_mass");
TH1D *hZcand1b70_sig=(TH1D*)File1.Get("Tagged_80_1b_DL1r_77_mass");
TH1D *hZcand2b70_sig=(TH1D*)File1.Get("Tagged_80_2b_DL1r_77_mass");
TH1D *hZcand1b77_sig=(TH1D*)File1.Get("Tagged_80_1b_DL1r_85_mass");
TH1D *hZcand2b77_sig=(TH1D*)File1.Get("Tagged_80_2b_DL1r_85_mass");

//TH1D *hZcand0b_sig=(TH1D*)File1.Get("Zcand_0b_DL1r_mass");
/*TH1D *hZcand0b_sig=(TH1D*)File1.Get("Zcand_mass");
TH1D *hZcand1b60_sig=(TH1D*)File1.Get("Zcand_1b_DL1r_60_mass");
TH1D *hZcand2b60_sig=(TH1D*)File1.Get("Zcand_2b_DL1r_60_mass");
TH1D *hZcand1b70_sig=(TH1D*)File1.Get("Zcand_1b_DL1r_70_mass");
TH1D *hZcand2b70_sig=(TH1D*)File1.Get("Zcand_2b_DL1r_70_mass");
TH1D *hZcand1b77_sig=(TH1D*)File1.Get("Zcand_1b_DL1r_77_mass");
TH1D *hZcand2b77_sig=(TH1D*)File1.Get("Zcand_2b_DL1r_77_mass");*/
/*TH1D *hZcand1b85_sig=(TH1D*)File1.Get("Zcand_1b_DL1r_85_pt");
TH1D *hZcand2b85_sig=(TH1D*)File1.Get("Zcand_2b_DL1r_85_pt");*/

//TH1D *hLeadingjetpTeta_bkg1=(TH1D*)File2.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
//TH1D *hZcand0b_bkg1=(TH1D*)File2.Get("Tagged_50_0b_DL1r_mass");
TH1D *hZcand0b_bkg1=(TH1D*)File2.Get("Tagged_80_mass");
TH1D *hZcand1b60_bkg1=(TH1D*)File2.Get("Tagged_50_1b_DL1r_85_mass");
TH1D *hZcand2b60_bkg1=(TH1D*)File2.Get("Tagged_50_2b_DL1r_85_mass");
TH1D *hZcand1b70_bkg1=(TH1D*)File2.Get("Tagged_80_1b_DL1r_77_mass");
TH1D *hZcand2b70_bkg1=(TH1D*)File2.Get("Tagged_80_2b_DL1r_77_mass");
TH1D *hZcand1b77_bkg1=(TH1D*)File2.Get("Tagged_80_1b_DL1r_85_mass");
TH1D *hZcand2b77_bkg1=(TH1D*)File2.Get("Tagged_80_2b_DL1r_85_mass");
/*TH1D *hZcand1b85_bkg1=(TH1D*)File2.Get("Zcand_1b_DL1r_85_pt");
TH1D *hZcand2b85_bkg1=(TH1D*)File2.Get("Zcand_2b_DL1r_85_pt");*/

//TH1D *hZcand0b_bkg1=(TH1D*)File2.Get("Zcand_0b_DL1r_mass");
/*TH1D *hZcand0b_bkg1=(TH1D*)File2.Get("Zcand_mass");
TH1D *hZcand1b60_bkg1=(TH1D*)File2.Get("Zcand_1b_DL1r_60_mass");
TH1D *hZcand2b60_bkg1=(TH1D*)File2.Get("Zcand_2b_DL1r_60_mass");
TH1D *hZcand1b70_bkg1=(TH1D*)File2.Get("Zcand_1b_DL1r_70_mass");
TH1D *hZcand2b70_bkg1=(TH1D*)File2.Get("Zcand_2b_DL1r_70_mass");
TH1D *hZcand1b77_bkg1=(TH1D*)File2.Get("Zcand_1b_DL1r_77_mass");
TH1D *hZcand2b77_bkg1=(TH1D*)File2.Get("Zcand_2b_DL1r_77_mass");*/

//TH1D *hLeadingjetpTeta_bkg2=(TH1D*)File3.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");

//TH1D *hZcand0b_bkg2=(TH1D*)File3.Get("Tagged_50_0b_DL1r_mass");
TH1D *hZcand0b_bkg2=(TH1D*)File3.Get("Tagged_80_mass");
TH1D *hZcand1b60_bkg2=(TH1D*)File3.Get("Tagged_50_1b_DL1r_85_mass");
TH1D *hZcand2b60_bkg2=(TH1D*)File3.Get("Tagged_50_2b_DL1r_85_mass");
TH1D *hZcand1b70_bkg2=(TH1D*)File3.Get("Tagged_80_1b_DL1r_77_mass");
TH1D *hZcand2b70_bkg2=(TH1D*)File3.Get("Tagged_80_2b_DL1r_77_mass");
TH1D *hZcand1b77_bkg2=(TH1D*)File3.Get("Tagged_80_1b_DL1r_85_mass");
TH1D *hZcand2b77_bkg2=(TH1D*)File3.Get("Tagged_80_2b_DL1r_85_mass");

//TH1D *hZcand0b_bkg2=(TH1D*)File3.Get("Zcand_0b_DL1r_mass");
/*TH1D *hZcand0b_bkg2=(TH1D*)File3.Get("Zcand_mass");
TH1D *hZcand1b60_bkg2=(TH1D*)File3.Get("Zcand_1b_DL1r_60_mass");
TH1D *hZcand2b60_bkg2=(TH1D*)File3.Get("Zcand_2b_DL1r_60_mass");
TH1D *hZcand1b70_bkg2=(TH1D*)File3.Get("Zcand_1b_DL1r_70_mass");
TH1D *hZcand2b70_bkg2=(TH1D*)File3.Get("Zcand_2b_DL1r_70_mass");
TH1D *hZcand1b77_bkg2=(TH1D*)File3.Get("Zcand_1b_DL1r_77_mass");
TH1D *hZcand2b77_bkg2=(TH1D*)File3.Get("Zcand_2b_DL1r_77_mass");*/


/*TH1D *hZcand1b85_bkg2=(TH1D*)File3.Get("Zcand_1b_DL1r_85_pt");
TH1D *hZcand2b85_bkg2=(TH1D*)File3.Get("Zcand_2b_DL1r_85_pt");*/

//TH1D *hLeadingjetpTeta_bkg3=(TH1D*)File4.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");

//TH1D *hZcand0b_bkg3=(TH1D*)File4.Get("Tagged_50_0b_DL1r_mass");
TH1D *hZcand0b_bkg3=(TH1D*)File4.Get("Tagged_80_mass");
TH1D *hZcand1b60_bkg3=(TH1D*)File4.Get("Tagged_50_1b_DL1r_85_mass");
TH1D *hZcand2b60_bkg3=(TH1D*)File4.Get("Tagged_50_2b_DL1r_85_mass");
TH1D *hZcand1b70_bkg3=(TH1D*)File4.Get("Tagged_80_1b_DL1r_77_mass");
TH1D *hZcand2b70_bkg3=(TH1D*)File4.Get("Tagged_80_2b_DL1r_77_mass");
TH1D *hZcand1b77_bkg3=(TH1D*)File4.Get("Tagged_80_1b_DL1r_85_mass");
TH1D *hZcand2b77_bkg3=(TH1D*)File4.Get("Tagged_80_2b_DL1r_85_mass");

//TH1D *hZcand0b_bkg3=(TH1D*)File4.Get("Zcand_0b_DL1r_mass");
/*TH1D *hZcand0b_bkg3=(TH1D*)File4.Get("Zcand_mass");
TH1D *hZcand1b60_bkg3=(TH1D*)File4.Get("Zcand_1b_DL1r_60_mass");
TH1D *hZcand2b60_bkg3=(TH1D*)File4.Get("Zcand_2b_DL1r_60_mass");
TH1D *hZcand1b70_bkg3=(TH1D*)File4.Get("Zcand_1b_DL1r_70_mass");
TH1D *hZcand2b70_bkg3=(TH1D*)File4.Get("Zcand_2b_DL1r_70_mass");
TH1D *hZcand1b77_bkg3=(TH1D*)File4.Get("Zcand_1b_DL1r_77_mass");
TH1D *hZcand2b77_bkg3=(TH1D*)File4.Get("Zcand_2b_DL1r_77_mass");*/

/*TH1D *hZcand1b85_bkg3=(TH1D*)File4.Get("Zcand_1b_DL1r_85_pt");
TH1D *hZcand2b85_bkg3=(TH1D*)File4.Get("Zcand_2b_DL1r_85_pt");*/

TH1D *hist_0sig=(TH1D*)hZcand0b_sig->Clone();
TH1D *hist_0bkg=(TH1D*)hZcand0b_bkg1->Clone();
TH1D *hist_0bkg2=(TH1D*)hZcand0b_bkg2->Clone();
TH1D *hist_0bkg3=(TH1D*)hZcand0b_bkg3->Clone();

TH1D *hist_1b60sig=(TH1D*)hZcand1b60_sig->Clone();
TH1D *hist_1b60bkg=(TH1D*)hZcand1b60_bkg1->Clone();
TH1D *hist_1b60bkg2=(TH1D*)hZcand1b60_bkg2->Clone();
TH1D *hist_1b60bkg3=(TH1D*)hZcand1b60_bkg3->Clone();

TH1D *hist_2b60sig=(TH1D*)hZcand2b60_sig->Clone();
TH1D *hist_2b60bkg=(TH1D*)hZcand2b60_bkg1->Clone();
TH1D *hist_2b60bkg2=(TH1D*)hZcand2b60_bkg2->Clone();
TH1D *hist_2b60bkg3=(TH1D*)hZcand2b60_bkg3->Clone();

TH1D *hist_1b70sig=(TH1D*)hZcand1b70_sig->Clone();
TH1D *hist_1b70bkg=(TH1D*)hZcand1b70_bkg1->Clone();
TH1D *hist_1b70bkg2=(TH1D*)hZcand1b70_bkg2->Clone();
TH1D *hist_1b70bkg3=(TH1D*)hZcand1b70_bkg3->Clone();

TH1D *hist_2b70sig=(TH1D*)hZcand2b70_sig->Clone();
TH1D *hist_2b70bkg=(TH1D*)hZcand2b70_bkg1->Clone();
TH1D *hist_2b70bkg2=(TH1D*)hZcand2b70_bkg2->Clone();
TH1D *hist_2b70bkg3=(TH1D*)hZcand2b70_bkg3->Clone();

TH1D *hist_2b77sig=(TH1D*)hZcand2b77_sig->Clone();
TH1D *hist_2b77bkg=(TH1D*)hZcand2b77_bkg1->Clone();
TH1D *hist_2b77bkg2=(TH1D*)hZcand2b77_bkg2->Clone();
TH1D *hist_2b77bkg3=(TH1D*)hZcand2b77_bkg3->Clone();

TH1D *hist_1b77sig=(TH1D*)hZcand1b77_sig->Clone();
TH1D *hist_1b77bkg=(TH1D*)hZcand1b77_bkg1->Clone();
TH1D *hist_1b77bkg2=(TH1D*)hZcand1b77_bkg2->Clone();
TH1D *hist_1b77bkg3=(TH1D*)hZcand1b77_bkg3->Clone();

/*TH1D *hist_2b85sig=(TH1D*)hZcand2b85_sig->Clone();
TH1D *hist_2b85bkg=(TH1D*)hZcand2b85_bkg1->Clone();
TH1D *hist_2b85bkg2=(TH1D*)hZcand2b85_bkg2->Clone();
TH1D *hist_2b85bkg3=(TH1D*)hZcand2b85_bkg3->Clone();*/

/*TH1D *hist_1b85sig=(TH1D*)hZcand1b85_sig->Clone();
TH1D *hist_1b85bkg=(TH1D*)hZcand1b85_bkg1->Clone();
TH1D *hist_1b85bkg2=(TH1D*)hZcand1b85_bkg2->Clone();
TH1D *hist_1b85bkg3=(TH1D*)hZcand1b85_bkg3->Clone();*/


  double sum_0sig=0;
  double sum_0W=0;
  double sum_0QCD=0;
  double sum_0tt=0;
  double sum_0comp=0;

  double sign_0=0;
  double sign_0W=0;
  double sign_0QCD=0;
  double sign_0tt=0;
  double sign_0comp=0;
  sum_0sig=hist_0sig->Integral();
  sum_0QCD=hist_0bkg->Integral();
  sum_0W=hist_0bkg2->Integral();
  sum_0tt=hist_0bkg3->Integral();
  sum_0comp= sum_0QCD+sum_0W+sum_0tt;
  std::cout<<"Signal for Zqq:"<<sum_0sig<<std::endl;
  std::cout<<"Total Bkg:"<<sum_0comp<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sign_0W=sqrt(2*((sum_0sig+sum_0W)*log(1+(sum_0sig/sum_0W))-sum_0sig));
  std::cout<<"Significance for 0b W bkg"<<""<<sign_0W<<std::endl;
  sign_0QCD=sqrt(2*((sum_0sig+sum_0QCD)*log(1+(sum_0sig/sum_0QCD))-sum_0sig));
  std::cout<<"Significance for 0b QCD bkg"<<""<<sign_0QCD<<std::endl;
  sign_0tt=sqrt(2*((sum_0sig+sum_0tt)*log(1+(sum_0sig/sum_0tt))-sum_0sig));
  std::cout<<"Sensitivity for 0b tt bkg"<<""<<sign_0tt<<std::endl;
  sign_0comp=sqrt(2*((sum_0sig+sum_0comp)*log(1+(sum_0sig/sum_0comp))-sum_0sig));
  std::cout<<"Sensitivity for total bkg"<<""<<sign_0comp<<std::endl;
  
  //-----------------------------------------
  //1b-60
   double sum_1b60sig=0;
  double sum_1b60W=0;
  double sum_1b60QCD=0;
  double sum_1b60tt=0;
  double sum_1b60comp=0;

  double sign_1b60=0;
  double sign_1b60W=0;
  double sign_1b60QCD=0;
  double sign_1b60tt=0;
  double sign_1b60comp=0;
  sum_1b60sig=hist_1b60sig->Integral();
  sum_1b60QCD=hist_1b60bkg->Integral();
  sum_1b60W=hist_1b60bkg2->Integral();
  sum_1b60tt=hist_1b60bkg3->Integral();
  sum_1b60comp= sum_1b60QCD+sum_1b60W+sum_1b60tt;
 std::cout<<"Signal for 1b 60 Zqq:"<<sum_1b60sig<<std::endl;
  std::cout<<"Total 1b 60 Bkg:"<<sum_1b60comp<<std::endl;
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sign_1b60W=sqrt(2*((sum_1b60sig+sum_1b60W)*log(1+(sum_1b60sig/sum_1b60W))-sum_1b60sig));
  std::cout<<"Significance for 1b 60 W bkg"<<""<<sign_1b60W<<std::endl;
  sign_1b60QCD=sqrt(2*((sum_1b60sig+sum_1b60QCD)*log(1+(sum_1b60sig/sum_1b60QCD))-sum_1b60sig));
  std::cout<<"Significance for 1b 60 QCD bkg"<<""<<sign_1b60QCD<<std::endl;
  sign_1b60tt=sqrt(2*((sum_1b60sig+sum_1b60tt)*log(1+(sum_1b60sig/sum_1b60tt))-sum_1b60sig));
  std::cout<<"Sensitivity for 1b 60  tt bkg"<<""<<sign_1b60tt<<std::endl;
  sign_1b60comp=sqrt(2*((sum_1b60sig+sum_1b60comp)*log(1+(sum_1b60sig/sum_1b60comp))-sum_1b60sig));
  std::cout<<"Sensitivity for 1b comp  bkg"<<""<<sign_1b60comp<<std::endl;  

  //-----------------------------------------
  //2b-60
   double sum_2b60sig=0;
  double sum_2b60W=0;
  double sum_2b60QCD=0;
  double sum_2b60tt=0;
  double sum_2b60comp=0;

  double sign_2b60=0;
  double sign_2b60W=0;
  double sign_2b60QCD=0;
  double sign_2b60tt=0;
  double sign_2b60comp=0;
  sum_2b60sig=hist_2b60sig->Integral();
  sum_2b60QCD=hist_2b60bkg->Integral();
  sum_2b60W=hist_2b60bkg2->Integral();
  sum_2b60tt=hist_2b60bkg3->Integral();
  sum_2b60comp=sum_2b60QCD+sum_2b60W+sum_2b60tt;
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
 std::cout<<"Signal for 2b 60 Zqq:"<<sum_2b60sig<<std::endl;
  std::cout<<"Total 2b 60 Bkg:"<<sum_2b60comp<<std::endl;
  sign_2b60W=sqrt(2*((sum_2b60sig+sum_2b60W)*log(1+(sum_2b60sig/sum_2b60W))-sum_2b60sig));
  std::cout<<"Significance for 2b 60 W bkg"<<""<<sign_2b60W<<std::endl;
  sign_2b60QCD=sqrt(2*((sum_2b60sig+sum_2b60QCD)*log(1+(sum_2b60sig/sum_2b60QCD))-sum_2b60sig));
  std::cout<<"Significance for 2b 60 QCD bkg"<<""<<sign_2b60QCD<<std::endl;
  sign_2b60tt=sqrt(2*((sum_2b60sig+sum_2b60tt)*log(1+(sum_2b60sig/sum_2b60tt))-sum_2b60sig));
  std::cout<<"Sensitivity for 2b 60  tt bkg"<<""<<sign_2b60tt<<std::endl;
  sign_2b60comp=sqrt(2*((sum_2b60sig+sum_2b60comp)*log(1+(sum_2b60sig/sum_2b60comp))-sum_2b60sig));
  std::cout<<"Sensitivity for 2b 60  comp bkg"<<""<<sign_2b60comp<<std::endl;

  //-----------------------------------------
  //1b-70
   double sum_1b70sig=0;
  double sum_1b70W=0;
  double sum_1b70QCD=0;
  double sum_1b70tt=0;
  double sum_1b70comp=0;

  double sign_1b70=0;
  double sign_1b70W=0;
  double sign_1b70QCD=0;
  double sign_1b70tt=0;
  double sign_1b70comp=0;
  sum_1b70sig=hist_1b70sig->Integral();
  sum_1b70QCD=hist_1b70bkg->Integral();
  sum_1b70W=hist_1b70bkg2->Integral();
  sum_1b70tt=hist_1b70bkg3->Integral();
  sum_1b70comp=sum_1b70QCD+sum_1b70W+sum_1b70tt;
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
   std::cout<<"Signal for 1b 70 Zqq:"<<sum_1b70sig<<std::endl;
  std::cout<<"Total 1b 70 Bkg:"<<sum_1b70comp<<std::endl;
  sign_1b70W=sqrt(2*((sum_1b70sig+sum_1b70W)*log(1+(sum_1b70sig/sum_1b70W))-sum_1b70sig));
  std::cout<<"Significance for 1b 70 W bkg"<<""<<sign_1b70W<<std::endl;
  sign_1b70QCD=sqrt(2*((sum_1b70sig+sum_1b70QCD)*log(1+(sum_1b70sig/sum_1b70QCD))-sum_1b70sig));
  std::cout<<"Significance for 1b 70 QCD bkg"<<""<<sign_1b70QCD<<std::endl;
  sign_1b70tt=sqrt(2*((sum_1b70sig+sum_1b70tt)*log(1+(sum_1b70sig/sum_1b70tt))-sum_1b70sig));
  std::cout<<"Sensitivity for 1b 70  tt bkg"<<""<<sign_1b70tt<<std::endl;
  sign_1b70comp=sqrt(2*((sum_1b70sig+sum_1b70comp)*log(1+(sum_1b70sig/sum_1b70comp))-sum_1b70sig));
  std::cout<<"Sensitivity for 1b 70  comp bkg"<<""<<sign_1b70comp<<std::endl;
  //-----------------------------------------
  //2b-70
   double sum_2b70sig=0;
  double sum_2b70W=0;
  double sum_2b70QCD=0;
  double sum_2b70tt=0;
 double sum_2b70comp=0;

  double sign_2b70=0;
  double sign_2b70W=0;
  double sign_2b70QCD=0;
  double sign_2b70tt=0;
  double sign_2b70comp=0;
  sum_2b70sig=hist_2b70sig->Integral();
  sum_2b70QCD=hist_2b70bkg->Integral();
  sum_2b70W=hist_2b70bkg2->Integral();
  sum_2b70tt=hist_2b70bkg3->Integral();
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sum_2b70comp=sum_2b70W+sum_2b70QCD+sum_2b70tt;
  std::cout<<"Signal for 2b 70 Zqq:"<<sum_2b70sig<<std::endl;
  std::cout<<"Total 2b 70 Bkg:"<<sum_2b70comp<<std::endl;
  sign_2b70W=sqrt(2*((sum_2b70sig+sum_2b70W)*log(1+(sum_2b70sig/sum_2b70W))-sum_2b70sig));
  std::cout<<"Significance for 2b 70 W bkg"<<""<<sign_2b70W<<std::endl;
  sign_2b70QCD=sqrt(2*((sum_2b70sig+sum_2b70QCD)*log(1+(sum_2b70sig/sum_2b70QCD))-sum_2b70sig));
  std::cout<<"Significance for 2b 70 QCD bkg"<<""<<sign_2b70QCD<<std::endl;
  sign_2b70tt=sqrt(2*((sum_2b70sig+sum_2b70tt)*log(1+(sum_2b70sig/sum_2b70tt))-sum_2b70sig));
  std::cout<<"Sensitivity for 2b 70  tt bkg"<<""<<sign_2b70tt<<std::endl;
  sign_2b70comp=sqrt(2*((sum_2b70sig+sum_2b70comp)*log(1+(sum_2b70sig/sum_2b70comp))-sum_2b70sig));
  std::cout<<"Sensitivity for 2b 70  comp bkg"<<""<<sign_2b70comp<<std::endl;

  //-----------------------------------------
  //1b-77
   double sum_1b77sig=0;
  double sum_1b77W=0;
  double sum_1b77QCD=0;
  double sum_1b77tt=0;
  double sum_1b77comp=0;
 
  double sign_1b77=0;
  double sign_1b77W=0;
  double sign_1b77QCD=0;
  double sign_1b77tt=0;
  double sign_1b77comp=0;
  sum_1b77sig=hist_1b77sig->Integral();
  sum_1b77QCD=hist_1b77bkg->Integral();
  sum_1b77W=hist_1b77bkg2->Integral();
  sum_1b77tt=hist_1b77bkg3->Integral();
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sum_1b77comp=sum_1b77QCD+sum_1b77W+sum_1b77tt;
  std::cout<<"Signal for 1b 77 Zqq:"<<sum_1b77sig<<std::endl;
  std::cout<<"Total 1b 77 Bkg:"<<sum_1b77comp<<std::endl;
  sign_1b77W=sqrt(2*((sum_1b77sig+sum_1b77W)*log(1+(sum_1b77sig/sum_1b77W))-sum_1b77sig));
  std::cout<<"Significance for 1b 77 W bkg"<<""<<sign_1b77W<<std::endl;
  sign_1b77QCD=sqrt(2*((sum_1b77sig+sum_1b77QCD)*log(1+(sum_1b77sig/sum_1b77QCD))-sum_1b77sig));
  std::cout<<"Significance for 1b 77 QCD bkg"<<""<<sign_1b77QCD<<std::endl;
  sign_1b77tt=sqrt(2*((sum_1b77sig+sum_1b77tt)*log(1+(sum_1b77sig/sum_1b77tt))-sum_1b77sig));
  std::cout<<"Sensitivity for 1b 77  tt bkg"<<""<<sign_1b77tt<<std::endl;
  sign_1b77comp=sqrt(2*((sum_1b77sig+sum_1b77comp)*log(1+(sum_1b77sig/sum_1b77comp))-sum_1b77sig));
  std::cout<<"Sensitivity for 1b 77  tt comp"<<""<<sign_1b77comp<<std::endl;

  //-----------------------------------------
  //2b-77
   double sum_2b77sig=0;
  double sum_2b77W=0;
  double sum_2b77QCD=0;
  double sum_2b77tt=0;
  double sum_2b77comp=0;  

  double sign_2b77=0;
  double sign_2b77W=0;
  double sign_2b77QCD=0;
  double sign_2b77tt=0;
  double sign_2b77comp=0;
  sum_2b77sig=hist_2b77sig->Integral();
  sum_2b77QCD=hist_2b77bkg->Integral();
  sum_2b77W=hist_2b77bkg2->Integral();
  sum_2b77tt=hist_2b77bkg3->Integral();
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sum_2b77comp=sum_2b77W+sum_2b77QCD+sum_2b77tt;
  std::cout<<"Signal for 2b 77 Zqq:"<<sum_2b77sig<<std::endl;
  std::cout<<"Total 2b 77 Bkg:"<<sum_2b77comp<<std::endl;
  sign_2b77W=sqrt(2*((sum_2b77sig+sum_2b77W)*log(1+(sum_2b77sig/sum_2b77W))-sum_2b77sig));
  std::cout<<"Significance for 2b 77 W bkg"<<""<<sign_2b77W<<std::endl;
  sign_2b77QCD=sqrt(2*((sum_2b77sig+sum_2b77QCD)*log(1+(sum_2b77sig/sum_2b77QCD))-sum_2b77sig));
  std::cout<<"Significance for 2b 77 QCD bkg"<<""<<sign_2b77QCD<<std::endl;
  sign_2b77tt=sqrt(2*((sum_2b77sig+sum_2b77tt)*log(1+(sum_2b77sig/sum_2b77tt))-sum_2b77sig));
  std::cout<<"Sensitivity for 2b 77  tt bkg"<<""<<sign_2b77tt<<std::endl;
  sign_2b77comp=sqrt(2*((sum_2b77sig+sum_2b77comp)*log(1+(sum_2b77sig/sum_2b77comp))-sum_2b77sig));
  std::cout<<"Sensitivity for 2b 77 comp"<<""<<sign_2b77comp<<std::endl;

   //-----------------------------------------
  //1b-85
  /*   double sum_1b85sig=0;
  double sum_1b85W=0;
  double sum_1b85QCD=0;
  double sum_1b85tt=0;
 double sum_1b85comp=0;

  double sign_1b85=0;
  double sign_1b85W=0;
  double sign_1b85QCD=0;
  double sign_1b85tt=0;
 double sign_1b85comp=0;
  sum_1b85sig=hist_1b85sig->Integral();
  sum_1b85QCD=hist_1b85bkg->Integral();
  sum_1b85W=hist_1b85bkg2->Integral();
  sum_1b85tt=hist_1b85bkg3->Integral();
  sum_1b85comp=sum_1b85QCD+sum_1b85W+sum_1b85tt;
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
   std::cout<<"Signal for 1b 85 Zqq:"<<sum_1b85sig<<std::endl;
  std::cout<<"Total 1b 85 Bkg:"<<sum_1b85comp<<std::endl;
  sign_1b85W=sqrt(2*((sum_1b85sig+sum_1b85W)*log(1+(sum_1b85sig/sum_1b85W))-sum_1b85sig));
  std::cout<<"Significance for 1b 85 W bkg"<<""<<sign_1b85W<<std::endl;
  sign_1b85QCD=sqrt(2*((sum_1b85sig+sum_1b85QCD)*log(1+(sum_1b85sig/sum_1b85QCD))-sum_1b85sig));
  std::cout<<"Significance for 1b 85 QCD bkg"<<""<<sign_1b85QCD<<std::endl;
  sign_1b85tt=sqrt(2*((sum_1b85sig+sum_1b85tt)*log(1+(sum_1b85sig/sum_1b85tt))-sum_1b85sig));
  std::cout<<"Sensitivity for 1b 85  tt bkg"<<""<<sign_1b85tt<<std::endl;
 sign_1b85comp=sqrt(2*((sum_1b85sig+sum_1b85comp)*log(1+(sum_1b85sig/sum_1b85comp))-sum_1b85sig));
  std::cout<<"Sensitivity for 1b 85 comp"<<""<<sign_1b85comp<<std::endl;
  //-----------------------------------------
  //2b-85
   double sum_2b85sig=0;
  double sum_2b85W=0;
  double sum_2b85QCD=0;
  double sum_2b85tt=0;
   double sum_2b85comp=0; 

  double sign_2b85=0;
  double sign_2b85W=0;
  double sign_2b85QCD=0;
  double sign_2b85tt=0;
 double sign_2b85comp=0;
  sum_2b85sig=hist_2b85sig->Integral();
  sum_2b85QCD=hist_2b85bkg->Integral();
  sum_2b85W=hist_2b85bkg2->Integral();
  sum_2b85tt=hist_2b85bkg3->Integral();
  //std::cout<<sum_sig<<std::endl;
  //std::cout<<sum_W<<std::endl;
  //std::cout<<sum_QCD<<std::endl;
  //std::cout<<sum_tt<<std::endl; 
  sum_2b85comp= sum_2b85QCD+sum_2b85W+sum_2b85tt;
  std::cout<<"Signal for 2b 85 Zqq:"<<sum_2b85sig<<std::endl;
  std::cout<<"Total 2b 85 Bkg:"<<sum_2b85comp<<std::endl;
  sign_2b85W=sqrt(2*((sum_2b85sig+sum_2b85W)*log(1+(sum_2b85sig/sum_2b85W))-sum_2b85sig));
  std::cout<<"Significance for 2b 85 W bkg"<<""<<sign_2b85W<<std::endl;
  sign_2b85QCD=sqrt(2*((sum_2b85sig+sum_2b85QCD)*log(1+(sum_2b85sig/sum_2b85QCD))-sum_2b85sig));
  std::cout<<"Significance for 2b 85 QCD bkg"<<""<<sign_2b85QCD<<std::endl;
  sign_2b85tt=sqrt(2*((sum_2b85sig+sum_2b85tt)*log(1+(sum_2b85sig/sum_2b85tt))-sum_2b85sig));
  std::cout<<"Sensitivity for 2b 85  tt bkg"<<""<<sign_2b85tt<<std::endl;
  sign_2b85comp=sqrt(2*((sum_2b85sig+sum_2b85comp)*log(1+(sum_2b85sig/sum_2b85comp))-sum_2b85sig));
  std::cout<<"Sensitivity for 2b 85 comp"<<""<<sign_2b85comp<<std::endl;
*/



    /*TFile File1("JSSTest_ZSample.root");//files including the signal JSS
TFile File2("JSSTest_QCDSample.root");//files including the background JSS
TFile File3("JSSTest_WSample.root");
TFile File4("JSSTest_ttSample.root");
//TH1D* hist_bkgTH1D *hist_bkg;
TH1D *hLeadingjetpTeta_sig=(TH1D*)File1.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_sig=(TH1D*)File1.Get("Zcand_pt");
TH1D *hZcandTminPFlow_sig=(TH1D*)File1.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_sig=(TH1D*)File1.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_sig=(TH1D*)File1.Get("Zcand_pt_PFlowTau21");
TH1D *hZcandAll3_sig=(TH1D*)File1.Get("Zcand_pt_All3");
//TH1D *hZcandAll3_sig=(TH1D*)File1.Get("Zcand_pt_All3");

TH1D *hLeadingjetpTeta_bkg1=(TH1D*)File2.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg1=(TH1D*)File2.Get("Zcand_pt");
TH1D *hZcandTminPFlow_bkg1=(TH1D*)File2.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg1=(TH1D*)File2.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg1=(TH1D*)File2.Get("Zcand_pt_PFlowTau21");
TH1D *hZcandAll3_bkg1=(TH1D*)File2.Get("Zcand_pt_All3");
//TH1D *hZcandMu12_bkg1=(TH1D*)File2.Get("Zcand_pt_Mu12cut");

TH1D *hLeadingjetpTeta_bkg2=(TH1D*)File3.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg2=(TH1D*)File3.Get("Zcand_pt");
TH1D *hZcandTminPFlow_bkg2=(TH1D*)File3.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg2=(TH1D*)File3.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg2=(TH1D*)File3.Get("Zcand_pt_PFlowTau21");
TH1D *hZcandAll3_bkg2=(TH1D*)File3.Get("Zcand_pt_All3");

TH1D *hLeadingjetpTeta_bkg3=(TH1D*)File4.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_pt");
TH1D *hZcand_bkg3=(TH1D*)File4.Get("Zcand_pt");
TH1D *hZcandTminPFlow_bkg3=(TH1D*)File4.Get("Zcand_pt_TminPFlow");
TH1D *hZcandTminTau21_bkg3=(TH1D*)File4.Get("Zcand_pt_TminTau21");
TH1D *hZcandPFlowTau21_bkg3=(TH1D*)File4.Get("Zcand_pt_PFlowTau21");
TH1D *hZcandAll3_bkg3=(TH1D*)File4.Get("Zcand_pt_All3");


TH1D *hist_sig=(TH1D*)hZcandAll3_sig->Clone();
TH1D *hist_bkg=(TH1D*)hZcandAll3_bkg1->Clone();
TH1D *hist_bkg2=(TH1D*)hZcandAll3_bkg2->Clone();
 TH1D *hist_bkg3=(TH1D*)hZcandAll3_bkg3->Clone();*/
 
//hist_bkg->Add(hist_bkg2);
//hist_bkg->Add(hist_bkg3);
 /*
  double sum_sig=0;
  double sum_W=0;
  double sum_QCD=0;
  double sum_tt=0;

  double sign=0;
  double sign_W=0;
  double sign_QCD=0;
  double sign_tt=0;
  sum_sig=hist_sig->Integral();
  sum_QCD=hist_bkg->Integral();
  sum_W=hist_bkg2->Integral();
  sum_tt=hist_bkg3->Integral();
  std::cout<<sum_sig<<std::endl;
  std::cout<<sum_W<<std::endl;
   std::cout<<sum_QCD<<std::endl;
  std::cout<<sum_tt<<std::endl; 
  sign_W=sqrt(2*((sum_sig+sum_W)*log(1+(sum_sig/sum_W))-sum_sig));
  std::cout<<"Sensitivity for W bkg"<<""<<sign_W<<std::endl;
  sign_QCD=sqrt(2*((sum_sig+sum_QCD)*log(1+(sum_sig/sum_QCD))-sum_sig));
  std::cout<<"Sensitivity for QCD bkg"<<""<<sign_QCD<<std::endl;
  sign_tt=sqrt(2*((sum_sig+sum_tt)*log(1+(sum_sig/sum_tt))-sum_sig));
  std::cout<<"Sensitivity for tt bkg"<<""<<sign_tt<<std::endl;
  */
  



}
