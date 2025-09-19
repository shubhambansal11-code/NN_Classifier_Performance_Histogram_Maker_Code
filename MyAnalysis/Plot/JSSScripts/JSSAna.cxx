 
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

//******************************************************************************************
//This file is used to compare the shape of 0-b tag, 1-b tag, 2-b tag substructure variables
//******************************************************************************************

void JSSAna()
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
TFile File1("JSSTest_ZSample_JSS_MOpt.root");//files including the signal JSS
TFile File2("JSSTest_QCDSample_JSS_MOpt.root");//files including the background JSS
TFile File3("JSSTest_WSample_JSS_MOpt.root");
TFile File4("JSSTest_ttSample_JSS_MOpt.root");
//TH1D* hist_bkgTH1D *hist_bkg;
 TH1D *hTau21_0b_sig=(TH1D*)File1.Get("Zcand_Tau21_0b");
TH1D *hTau21_1b60_sig=(TH1D*)File1.Get("Zcand_Tau21_1b60");
TH1D *hTau21_2b60_sig=(TH1D*)File1.Get("Zcand_Tau21_2b60");
TH1D *hTau21_1b70_sig=(TH1D*)File1.Get("Zcand_Tau21_1b70");
TH1D *hTau21_2b70_sig=(TH1D*)File1.Get("Zcand_Tau21_2b70");
TH1D *hTau21_1b77_sig=(TH1D*)File1.Get("Zcand_Tau21_1b77");
TH1D *hTau21_2b77_sig=(TH1D*)File1.Get("Zcand_Tau21_2b77");
TH1D *hTau21_1b85_sig=(TH1D*)File1.Get("Zcand_Tau21_1b85");
TH1D *hTau21_2b85_sig=(TH1D*)File1.Get("Zcand_Tau21_2b85");
TH1D *hTau32_sig=(TH1D*)File1.Get("Zcand_Tau32");
TH1D *hD2_sig=(TH1D*)File1.Get("Zcand_D2");
TH1D *hECF2_sig=(TH1D*)File1.Get("Zcand_ECF2");
TH1D *hECF3_sig=(TH1D*)File1.Get("Zcand_ECF3");
TH1D *hAngularity_sig=(TH1D*)File1.Get("Zcand_Angularity");
TH1D *hZCut23_sig=(TH1D*)File1.Get("Zcand_ZCut23");
TH1D *hZCut34_sig=(TH1D*)File1.Get("Zcand_ZCut34");
TH1D *hThrustMin_sig=(TH1D*)File1.Get("Zcand_ThrustMin");
TH1D *hFoxWolfram42_sig=(TH1D*)File1.Get("Zcand_FoxWolfram42");
TH1D *hAplanarity_sig=(TH1D*)File1.Get("Zcand_Angularity");
TH1D *hPlanarFlow_sig=(TH1D*)File1.Get("Zcand_PlanarFlow");
TH1D *hMu12_sig=(TH1D*)File1.Get("Zcand_Mu12");
TH1D *hSplit12_sig=(TH1D*)File1.Get("Zcand_Split12");

//TH1D *hTau21_bkg1=(TH1D*)File2.Get("Zcand_Tau21");
TH1D *hTau21_0b_bkg1=(TH1D*)File2.Get("Zcand_Tau21_0b");
TH1D *hTau21_1b60_bkg1=(TH1D*)File2.Get("Zcand_Tau21_1b60");
TH1D *hTau21_2b60_bkg1=(TH1D*)File2.Get("Zcand_Tau21_2b60");
TH1D *hTau21_1b70_bkg1=(TH1D*)File2.Get("Zcand_Tau21_1b70");
TH1D *hTau21_2b70_bkg1=(TH1D*)File2.Get("Zcand_Tau21_2b70");
TH1D *hTau21_1b77_bkg1=(TH1D*)File2.Get("Zcand_Tau21_1b77");
TH1D *hTau21_2b77_bkg1=(TH1D*)File2.Get("Zcand_Tau21_2b77");
TH1D *hTau21_1b85_bkg1=(TH1D*)File2.Get("Zcand_Tau21_1b85");
TH1D *hTau21_2b85_bkg1=(TH1D*)File2.Get("Zcand_Tau21_2b85");
TH1D *hTau32_bkg1=(TH1D*)File2.Get("Zcand_Tau32");
TH1D *hD2_bkg1=(TH1D*)File2.Get("Zcand_D2");
TH1D *hECF2_bkg1=(TH1D*)File2.Get("Zcand_ECF2");
TH1D *hECF3_bkg1=(TH1D*)File2.Get("Zcand_ECF3");
TH1D *hAngularity_bkg1=(TH1D*)File2.Get("Zcand_Angularity");
TH1D *hZCut23_bkg1=(TH1D*)File2.Get("Zcand_ZCut23");
TH1D *hZCut34_bkg1=(TH1D*)File2.Get("Zcand_ZCut34");
TH1D *hThrustMin_bkg1=(TH1D*)File2.Get("Zcand_ThrustMin");
TH1D *hFoxWolfram42_bkg1=(TH1D*)File2.Get("Zcand_FoxWolfram42");
TH1D *hAplanarity_bkg1=(TH1D*)File2.Get("Zcand_Angularity");
TH1D *hPlanarFlow_bkg1=(TH1D*)File2.Get("Zcand_PlanarFlow");
TH1D *hMu12_bkg1=(TH1D*)File2.Get("Zcand_Mu12");
TH1D *hSplit12_bkg1=(TH1D*)File2.Get("Zcand_Split12");

//TH1D *hTau21_bkg2=(TH1D*)File3.Get("Zcand_Tau21");
TH1D *hTau21_0b_bkg2=(TH1D*)File3.Get("Zcand_Tau21_0b");
TH1D *hTau21_1b60_bkg2=(TH1D*)File3.Get("Zcand_Tau21_1b60");
TH1D *hTau21_2b60_bkg2=(TH1D*)File3.Get("Zcand_Tau21_2b60");
TH1D *hTau21_1b70_bkg2=(TH1D*)File3.Get("Zcand_Tau21_1b70");
TH1D *hTau21_2b70_bkg2=(TH1D*)File3.Get("Zcand_Tau21_2b70");
TH1D *hTau21_1b77_bkg2=(TH1D*)File3.Get("Zcand_Tau21_1b77");
TH1D *hTau21_2b77_bkg2=(TH1D*)File3.Get("Zcand_Tau21_2b77");
TH1D *hTau21_1b85_bkg2=(TH1D*)File3.Get("Zcand_Tau21_1b85");
TH1D *hTau21_2b85_bkg2=(TH1D*)File3.Get("Zcand_Tau21_2b85");
TH1D *hTau32_bkg2=(TH1D*)File3.Get("Zcand_Tau32");
TH1D *hD2_bkg2=(TH1D*)File3.Get("Zcand_D2");
TH1D *hECF2_bkg2=(TH1D*)File3.Get("Zcand_ECF2");
TH1D *hECF3_bkg2=(TH1D*)File3.Get("Zcand_ECF3");
TH1D *hAngularity_bkg2=(TH1D*)File3.Get("Zcand_Angularity");
TH1D *hZCut23_bkg2=(TH1D*)File3.Get("Zcand_ZCut23");
TH1D *hZCut34_bkg2=(TH1D*)File3.Get("Zcand_ZCut34");
TH1D *hThrustMin_bkg2=(TH1D*)File3.Get("Zcand_ThrustMin");
TH1D *hFoxWolfram42_bkg2=(TH1D*)File3.Get("Zcand_FoxWolfram42");
TH1D *hAplanarity_bkg2=(TH1D*)File3.Get("Zcand_Angularity");
TH1D *hPlanarFlow_bkg2=(TH1D*)File3.Get("Zcand_PlanarFlow");
TH1D *hMu12_bkg2=(TH1D*)File3.Get("Zcand_Mu12");
TH1D *hSplit12_bkg2=(TH1D*)File3.Get("Zcand_Split12");

//TH1D *hTau21_bkg3=(TH1D*)File4.Get("Zcand_Tau21");
TH1D *hTau21_0b_bkg3=(TH1D*)File4.Get("Zcand_Tau21_0b");
TH1D *hTau21_1b60_bkg3=(TH1D*)File4.Get("Zcand_Tau21_1b60");
TH1D *hTau21_2b60_bkg3=(TH1D*)File4.Get("Zcand_Tau21_2b60");
TH1D *hTau21_1b70_bkg3=(TH1D*)File4.Get("Zcand_Tau21_1b70");
TH1D *hTau21_2b70_bkg3=(TH1D*)File4.Get("Zcand_Tau21_2b70");
TH1D *hTau21_1b77_bkg3=(TH1D*)File4.Get("Zcand_Tau21_1b77");
TH1D *hTau21_2b77_bkg3=(TH1D*)File4.Get("Zcand_Tau21_2b77");
TH1D *hTau21_1b85_bkg3=(TH1D*)File4.Get("Zcand_Tau21_1b85");
TH1D *hTau21_2b85_bkg3=(TH1D*)File4.Get("Zcand_Tau21_2b85");
TH1D *hTau32_bkg3=(TH1D*)File4.Get("Zcand_Tau32");
TH1D *hD2_bkg3=(TH1D*)File4.Get("Zcand_D2");
TH1D *hECF2_bkg3=(TH1D*)File4.Get("Zcand_ECF2");
TH1D *hECF3_bkg3=(TH1D*)File4.Get("Zcand_ECF3");
TH1D *hAngularity_bkg3=(TH1D*)File4.Get("Zcand_Angularity");
TH1D *hZCut23_bkg3=(TH1D*)File4.Get("Zcand_ZCut23");
TH1D *hZCut34_bkg3=(TH1D*)File4.Get("Zcand_ZCut34");
TH1D *hThrustMin_bkg3=(TH1D*)File4.Get("Zcand_ThrustMin");
TH1D *hFoxWolfram42_bkg3=(TH1D*)File4.Get("Zcand_FoxWolfram42");
TH1D *hAplanarity_bkg3=(TH1D*)File4.Get("Zcand_Angularity");
TH1D *hPlanarFlow_bkg3=(TH1D*)File4.Get("Zcand_PlanarFlow");
TH1D *hMu12_bkg3=(TH1D*)File4.Get("Zcand_Mu12");
TH1D *hSplit12_bkg3=(TH1D*)File4.Get("Zcand_Split12");

TH1D *hist_sig0=(TH1D*)hTau21_0b_sig->Clone();
TH1D *hist_bkg0=(TH1D*)hTau21_0b_bkg1->Clone();
TH1D *hist_bkg20=(TH1D*)hTau21_0b_bkg2->Clone();
TH1D *hist_bkg30=(TH1D*)hTau21_0b_bkg3->Clone();

TH1D *hist_sigb=(TH1D*)hTau21_1b85_sig->Clone();
TH1D *hist_bkgb=(TH1D*)hTau21_1b85_bkg1->Clone();
TH1D *hist_bkg2b=(TH1D*)hTau21_1b85_bkg2->Clone();
TH1D *hist_bkg3b=(TH1D*)hTau21_1b85_bkg3->Clone();

TH1D *hist_sigbb=(TH1D*)hTau21_2b85_sig->Clone();
TH1D *hist_bkgbb=(TH1D*)hTau21_2b85_bkg1->Clone();
TH1D *hist_bkg2bb=(TH1D*)hTau21_2b85_bkg2->Clone();
TH1D *hist_bkg3bb=(TH1D*)hTau21_2b85_bkg3->Clone();
 
  hist_bkg0->Add(hist_bkg20);
  hist_bkg0->Add(hist_bkg30);

  hist_bkgb->Add(hist_bkg2b);
  hist_bkgb->Add(hist_bkg3b);

  hist_bkgbb->Add(hist_bkg2bb);
  hist_bkgbb->Add(hist_bkg3bb);
  /*double sum_sig=0;
  double sum_bkg=0;
  double sens=0;
  int bmin_sig=hist_sig->GetXaxis()->FindBin(0.0);
  int bmax_sig=hist_sig->GetXaxis()->FindBin(1.65);
  int bmin_bkg=hist_bkg->GetXaxis()->FindBin(0.0);
  int bmax_bkg=hist_bkg->GetXaxis()->FindBin(1.65);
  sum_sig=hist_sig->Integral(bmin_sig, bmax_sig);
  sum_bkg=hist_bkg->Integral(bmin_bkg, bmax_bkg);
  std::cout<<sum_sig<<std::endl;
  std::cout<<sum_bkg<<std::endl;
  sens=sqrt(2*((sum_sig+sum_bkg)*log(1+(sum_sig/sum_bkg))-sum_sig));
  std::cout<<"Sensitivity for D2"<<""<<sens<<std::endl;
  
}*/

         pad1->cd();
         hist_sig0->Scale(1.0 / hist_sig0->Integral());
	 
         
	 hist_bkg0->Scale(1.0 / hist_bkg0->Integral());
	 //hist_bkg->Rebin();
	 
        

         hist_sigb->Scale(1.0 / hist_sigb->Integral());
	 //hist_sigb->Rebin();
         
         //hist_bkg->Add(hist_bkg2);
         //hist_bkg->Add(hist_bkg3);
	 hist_bkgb->Scale(1.0 / hist_bkgb->Integral());
         hist_sigbb->Scale(1.0 / hist_sigbb->Integral());
	 //hist_sigb->Rebin();
         
         //hist_bkg->Add(hist_bkg2);
         //hist_bkg->Add(hist_bkg3);
	 hist_bkgbb->Scale(1.0 / hist_bkgbb->Integral());
	 //hist_bkgb->Rebin();
	 /*double sum_sig=0;
        double sum_bkg=0;
        double sum_sigb=0;
        double sum_bkgb=0;
	int bmin_sig=hist_sig->GetXaxis()->FindBin(0.0);
        int bmax_sig=hist_sig->GetXaxis()->FindBin(0.40);
        int bmin_bkg=hist_bkg->GetXaxis()->FindBin(0.0);
        int bmax_bkg=hist_bkg->GetXaxis()->FindBin(0.40);
        sum_sig=hist_sig->Integral(bmin_sig, bmax_sig);
        sum_bkg=hist_bkg->Integral(bmin_bkg, bmax_bkg);
        std::cout<<"Tau21 contribution for 1b 60 sig"<< sum_sig <<std::endl;
        std::cout<<"Tau21 contribution for 1b 60 bkg"<< sum_bkg <<std::endl;

        int bmin_sigb=hist_sigb->GetXaxis()->FindBin(0.0);
        int bmax_sigb=hist_sigb->GetXaxis()->FindBin(0.40);
        int bmin_bkgb=hist_bkgb->GetXaxis()->FindBin(0.0);
        int bmax_bkgb=hist_bkgb->GetXaxis()->FindBin(0.40);
        sum_sigb=hist_sigb->Integral(bmin_sigb, bmax_sigb);
        sum_bkgb=hist_bkgb->Integral(bmin_bkgb, bmax_bkgb);
        std::cout<<"Tau21 contribution for 2b 60 sig"<< sum_sigb <<std::endl;
        std::cout<<"Tau21 contribution for 2b 60 bkg"<< sum_bkgb <<std::endl;*/
        
         hist_sig0->Rebin();
         hist_bkg0->Rebin();
         hist_sigb->Rebin();
         hist_bkgb->Rebin();
         hist_sigbb->Rebin();
         hist_bkgbb->Rebin();
         hist_sig0->SetLineColor(kGreen);
         hist_sig0->SetLineWidth(2);
         hist_bkg0->SetLineColor(kOrange);
	 hist_bkg0->SetLineWidth(2);
         hist_sigb->SetLineColor(kMagenta);
         hist_sigb->SetLineWidth(2);
         hist_bkgb->SetLineColor(kYellow);
	 hist_bkgb->SetLineWidth(2);
         hist_sigbb->SetLineColor(kBlue);
         hist_sigbb->SetLineWidth(2);
         hist_bkgbb->SetLineColor(kRed);
	 hist_bkgbb->SetLineWidth(2);


         hist_sig0->SetStats(0);
	 hist_sig0->Draw("HISTO");
         hist_sigb->Draw("HISTO SAME");
         hist_sigbb->Draw("HISTO SAME");
	 hist_bkg0->Draw("HISTO SAME");
         hist_bkgb->Draw("HISTO SAME");
         hist_bkgbb->Draw("HISTO SAME");
         //hist_bkg->SetTitle("");
    
   //h1->SetLabelSize(0.005,"X");
        hist_sig0->SetYTitle("#bf{Normalised to Unity}");
   //h1->SetMarkerStyle(20);
  //h_Num_2p->SetLineColor(kBlue);
        hist_sig0->SetTitleOffset(0.92,"t");
        hist_sig0->SetTitleSize(0.07,"t");
  //h_Num_2p->SetLabelSize(0.055, "Y");
  //pad2->cd();
  //h_Sig_2p->SetXTitle("#bf{large-R jet FoxW_{42}}");
       hist_sig0->SetXTitle("#bf{#tau_{21}}");
       hist_sig0->SetTitleSize(0.07,"t");
  //leg->AddEntry(h_Num_2p,"pythia8 MC","epl");
  
  //h_Num_2p->SetMinimum(0);
  
  
  //h_Num_2p->Draw("C");

// the line belows can be changed to modify the user-range for y-axis and the x-axis.
  hist_sig0->GetYaxis()->SetRangeUser(0, hist_sig0->GetMaximum()*1.7);
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
    
    leg->AddEntry(hist_sig0,"Zqq 0b","l");
    leg->AddEntry(hist_bkg0,"Total Bkg 0b","l");
    leg->AddEntry(hist_sigb,"Zqq 1b 85","l");
    leg->AddEntry(hist_bkgb,"Total Bkg 1b 85","l");
    leg->AddEntry(hist_sigbb,"Zqq 2b 85","l");
    leg->AddEntry(hist_bkgbb,"Total Bkg 2b 85","l");
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
  tex2= new TLatex(lx,ly,"#bf{}");
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
  tex3->Draw("same");
  tex4->Draw("same");

  leg->Draw();
  TString name;
  name= TString("tau21_85WP.pdf");
  canv->SaveAs(name.Data());
  delete leg;

}

