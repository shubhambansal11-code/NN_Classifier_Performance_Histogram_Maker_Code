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
//***********************************************************************************
//This file is used to calculate the flavour fraction (for truth studies for QCD dijets)
//***********************************************************************************

void Truth()
{

    std::shared_ptr<TCanvas> canv(new TCanvas("canv","",500,500));
    canv.get()->cd(); 
    std::shared_ptr<TPad> pad1(new TPad("pad1","pad1",0.007,0.,1,1));
    pad1.get()->SetLeftMargin(0.15);
    pad1.get()->SetBottomMargin(0.15);
    pad1.get()->Draw();
    
    TFile File1("TruthTest_ZSample_MC16ad_DL1r_Ztagger_MuL.root");//files including the signal JSS
    //TFile File1("/afs/cern.ch/work/s/shbansal/QT_2020/qt-2019-2020/run/output_JSSInc_mc16a_150/Truthtest.root");

//TH1D* hist_bkgTH1D *hist_bkg;
    /*TH1D *hZcand_2b_mass=(TH1D*)File1.Get("Tagged_80_pt");
 TH1D *hZcand_2b_LL_mass=(TH1D*)File1.Get("Tagged_80_LL_pt");
 TH1D *hZcand_2b_LC_mass=(TH1D*)File1.Get("Tagged_80_LC_pt");
 TH1D *hZcand_2b_LB_mass=(TH1D*)File1.Get("Tagged_80_LB_pt");
 TH1D *hZcand_2b_CC_mass=(TH1D*)File1.Get("Tagged_80_CC_pt");
 TH1D *hZcand_2b_CL_mass=(TH1D*)File1.Get("Tagged_80_CL_pt");
 TH1D *hZcand_2b_BB_mass=(TH1D*)File1.Get("Tagged_80_BB_pt");
 TH1D *hZcand_2b_BL_mass=(TH1D*)File1.Get("Tagged_80_BL_pt");*/

 TH1D *hZcand_2b_mass=(TH1D*)File1.Get("Tagged_80_2b_DL1r_85_pt");
 TH1D *hZcand_2b_LL_mass=(TH1D*)File1.Get("Tagged_80_2b_LL_85_pt");
 TH1D *hZcand_2b_LC_mass=(TH1D*)File1.Get("Tagged_80_2b_LC_85_pt");
 TH1D *hZcand_2b_LB_mass=(TH1D*)File1.Get("Tagged_80_2b_LB_85_pt");
 TH1D *hZcand_2b_CC_mass=(TH1D*)File1.Get("Tagged_80_2b_CC_85_pt");
 TH1D *hZcand_2b_CL_mass=(TH1D*)File1.Get("Tagged_80_2b_CL_85_pt");
 TH1D *hZcand_2b_BB_mass=(TH1D*)File1.Get("Tagged_80_2b_BB_85_pt");
 TH1D *hZcand_2b_BL_mass=(TH1D*)File1.Get("Tagged_80_2b_BL_85_pt");
 

TH1D *hist_com=(TH1D*)hZcand_2b_mass->Clone();
TH1D *hist_LL=(TH1D*)hZcand_2b_LL_mass->Clone();
TH1D *hist_LC=(TH1D*)hZcand_2b_LC_mass->Clone();
TH1D *hist_LB=(TH1D*)hZcand_2b_LB_mass->Clone();
TH1D *hist_CC=(TH1D*)hZcand_2b_CC_mass->Clone();
TH1D *hist_CL=(TH1D*)hZcand_2b_CL_mass->Clone();
TH1D *hist_BB=(TH1D*)hZcand_2b_BB_mass->Clone();
TH1D *hist_BL=(TH1D*)hZcand_2b_BL_mass->Clone();

 double sum_com, sum_LL, sum_LC, sum_LB, sum_CC, sum_CL, sum_BB, sum_BL;
 sum_com = hist_com->Integral();
   sum_LL = hist_LL->Integral();
 sum_LC =  hist_LC->Integral();
 sum_LB =  hist_LB->Integral();
 sum_BB =   hist_BB->Integral();
 sum_CC =   hist_CC->Integral();
 sum_BL =  hist_BL->Integral();
 sum_CL =  hist_CL->Integral();
 std::cout<<"LL frac"<<"" << sum_LL/ sum_com <<std::endl;
 std::cout<<"LC frac"<<"" << sum_LC/ sum_com <<std::endl;
 std::cout<<"LB frac"<<"" << sum_LB/ sum_com <<std::endl;
 std::cout<<"CC frac"<<"" << sum_CC/ sum_com <<std::endl;
 std::cout<<"CL frac"<<"" << sum_CL/ sum_com <<std::endl;
 std::cout<<"BB frac"<<"" << sum_BB/ sum_com <<std::endl;
 std::cout<<"BL frac"<<"" << sum_BL/ sum_com <<std::endl;


std::cout<<"LL/BB frac"<<"" << sum_LL/ sum_BB <<std::endl;
 std::cout<<"LC/BB frac"<<"" << sum_LC/ sum_BB <<std::endl;
 std::cout<<"LB/BB frac"<<"" << sum_LB/ sum_BB <<std::endl;
 std::cout<<"CC/BB frac"<<"" << sum_CC/ sum_BB <<std::endl;
 std::cout<<"CL/BB frac"<<"" << sum_CL/ sum_BB <<std::endl;
 std::cout<<"BB/BB frac"<<"" << sum_BB/ sum_BB <<std::endl;
 std::cout<<"BL/BB frac"<<"" << sum_BL/ sum_BB <<std::endl;




   //sum_LL =
 
         pad1->cd();
         hist_com->Scale(1.0 / hist_com->Integral());         
	 hist_LL->Scale(1.0 / hist_LL->Integral());
	 hist_LC->Scale(1.0 / hist_LC->Integral());
         hist_LB->Scale(1.0 / hist_LB->Integral());
         hist_CC->Scale(1.0 / hist_CC->Integral());
         hist_CL->Scale(1.0 / hist_CL->Integral());
         hist_BB->Scale(1.0 / hist_BB->Integral());
         hist_BL->Scale(1.0 / hist_BL->Integral());
            
         //hist_com->Rebin();
         hist_LL->Rebin();
         hist_LC->Rebin();
         hist_LB->Rebin();
         hist_CC->Rebin();
         hist_CL->Rebin();
         hist_BB->Rebin();
         hist_BL->Rebin();

         hist_LL->SetLineColor(kYellow);
         hist_LL->SetLineWidth(2);
         hist_LC->SetLineColor(kOrange);
	 hist_LC->SetLineWidth(2);
         hist_LB->SetLineColor(kMagenta);
         hist_LB->SetLineWidth(2);
         hist_CC->SetLineColor(kGreen);
	 hist_CC->SetLineWidth(2);
         hist_CL->SetLineColor(kRed);
         hist_CL->SetLineWidth(2);
         hist_BB->SetLineColor(kBlue);
	 hist_BB->SetLineWidth(2);
         hist_BL->SetLineColor(kViolet);
	 hist_BL->SetLineWidth(2);


         hist_LL->SetStats(0);
	 hist_LL->Draw("HISTO");
         hist_LC->Draw("HISTO SAME");
         hist_LB->Draw("HISTO SAME");
	 hist_CC->Draw("HISTO SAME");
         hist_CL->Draw("HISTO SAME");
         hist_BB->Draw("HISTO SAME");
         hist_BL->Draw("HISTO SAME");
         //hist_bkg->SetTitle("");
    
   //h1->SetLabelSize(0.005,"X");
        hist_LL->SetYTitle("#bf{Normalised to Unity}");
   //h1->SetMarkerStyle(20);
  //h_Num_2p->SetLineColor(kBlue);
        hist_LL->SetTitleOffset(0.92,"t");
        hist_LL->SetTitleSize(0.07,"t");
  //h_Num_2p->SetLabelSize(0.055, "Y");
  //pad2->cd();
  //h_Sig_2p->SetXTitle("#bf{large-R jet FoxW_{42}}");
       hist_LL->SetXTitle("#bf{Zcand mass}");
       hist_LL->SetTitleSize(0.07,"t");
  //leg->AddEntry(h_Num_2p,"pythia8 MC","epl");
  
  //h_Num_2p->SetMinimum(0);
  
  
  //h_Num_2p->Draw("C");

// the line belows can be changed to modify the user-range for y-axis and the x-axis.
  hist_LL->GetYaxis()->SetRangeUser(0, hist_LL->GetMaximum()*1.7);
  //h_Sig_2p->GetXaxis()->SetLimits(-6.0, 6.0);
  //
  //h1->GetXaxis()->SetLimits(0.20, 1.3);
  //h_Bkg_2p->GetXaxis()->SetLimits(0.20, 1.3);
  //h1->GetXaxis()->SetLimits(0.02, 0.6);
  //h1->GetXaxis()->SetLimits(0.15, 1.5);
  //h1->GetXaxis()->SetLimits(0.5, 20);
  //h_Sig_2p->GetXaxis()->SetLimits(-1.0, 1.0);
    TLegend *leg=new TLegend(0.65,0.90,0.90,0.80);
   //TLegend *leg=new TLegend(0.1,0.80,0.45,0.90);
  //auto legend = new TLegend(0.1,0.7,0.48,0.9);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
    
    leg->AddEntry(hist_LL,"LL","l");
    leg->AddEntry(hist_LC,"LC","l");
    leg->AddEntry(hist_LB,"LB","l");
    leg->AddEntry(hist_CC,"CC","l");
    leg->AddEntry(hist_CL,"CL","l");
    leg->AddEntry(hist_BB,"BB","l");
    leg->AddEntry(hist_BL,"BL","l");
    
   //pad1->cd();
    TLatex *tex0 = new TLatex();
  float lx ; float ly;
  lx=0.11;
  ly=0.85;
  tex0= new TLatex(lx,ly,"");
  tex0->SetNDC();
  tex0->SetTextSize(0.045*1.5);
  tex0->SetTextColor(1);
  tex0->SetTextFont(42);

  TLatex *tex1= new TLatex();
  lx=0.11;
  ly=0.82;
  tex1= new TLatex(lx,ly,""); 
  tex1->SetNDC();
  tex1->SetTextSize(0.025*1.2);
  tex1->SetTextColor(1);
  tex1->SetTextFont(42);

  TLatex *tex2= new TLatex();
  lx=0.35;
  ly=0.75;
  //tex2= new TLatex(lx,ly,"");
  tex2= new TLatex(lx,ly,"#bf{Untagged}");
  tex2->SetNDC();
  tex2->SetTextSize(0.025*1.5);
  tex2->SetTextColor(1);
  tex2->SetTextFont(42);

  TLatex *tex3= new TLatex();
  lx=0.33;
  ly=0.70;
  tex3= new TLatex(lx,ly,"#bf{anti-k_{t}LC topo trimmed Large-R jet}");
  tex3->SetNDC();
  tex3->SetTextSize(0.025*1.5);
  tex3->SetTextColor(1);
  tex3->SetTextFont(42);

  TLatex *tex4= new TLatex();
  lx=0.33;
  ly=0.66;
  tex4= new TLatex(lx,ly,"#bf{VR Track jet}");
  tex4->SetNDC();
  tex4->SetTextSize(0.025*1.5);
  tex4->SetTextColor(1);
  tex4->SetTextFont(42);

  //pad1->cd();
  tex0->Draw("same");
  tex1->Draw("same");
  tex2->Draw("same");
  //tex3->Draw("same");
  //tex4->Draw("same");

  leg->Draw();
  TString name;
  name= TString("Flavour_0b_50Sig_MC16ad_Ztagger.pdf");
  canv->SaveAs(name.Data());
  delete leg;

}
