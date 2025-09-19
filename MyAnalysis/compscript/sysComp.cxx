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

void sysComp()
{

    std::shared_ptr<TCanvas> canv(new TCanvas("canv","",800,800));
    canv->SetRightMargin(0.08);
    canv->SetLeftMargin(0.15);
    canv.get()->cd(); 

    std::shared_ptr<TPad> pad1(new TPad("pad1","pad1",0,0.35,1,1));
    pad1.get()->SetLeftMargin(0.15);
    pad1.get()->SetBottomMargin(0.);
    pad1.get()->SetRightMargin(0.08);
    pad1.get()->Draw();
    pad1.get()->SetTicks();
    
   std::shared_ptr<TPad> pad2 = std::shared_ptr<TPad>(new TPad("pad2","pad2",0,0.0,1,0.35));
   pad2.get()->SetLeftMargin(0.15);
   pad2.get()->SetRightMargin(0.08);
   pad2->SetTopMargin(0.0);
   pad2->SetBottomMargin(0.35);
   pad2.get()->Draw();
   pad2.get()->SetTicks();
   TString base = "/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_t7Xbb_0408/";
   //TString SysBase = "CategoryReduction_JET_MassRes_";
   TString SysBase = "CategoryReduction_JET_SingleParticle_";
   //TString SysBase = "CategoryReduction_JET_EffectiveNP_R10_";
   //TString SysBase = "CategoryReduction_JET_EtaIntercalibration_";
   //TString SysBase = "CategoryReduction_JET_Flavor_";
   //TString SysBase = "CategoryReduction_JET_CombMass_";
   //TString SysBase = "CategoryReduction_JET_LargeR_";
   //TString JMS_UP[6]={"Baseline__1up","Modelling__1up","TotalStat__1up","Tracking1__1up","Tracking2__1up","Tracking3__1up"};
   //TString JMS_DOWN[6]={"Baseline__1down","Modelling__1down","TotalStat__1down","Tracking1__1down","Tracking2__1down","Tracking3__1down"};
   TString JMS_UP[3]={"HighPt__1up"};
   TString JMS_DOWN[3]={"HighPt__1down"};
   // TString JMS_UP[3]={"Hbb_comb__1up","Top_comb__1up","WZ_comb__1up"};
   //TString JMS_DOWN[3]={"Hbb_comb__1down","Top_comb__1down","WZ_comb__1down"};
   //TString JMS_DOWN[16]={"Detector1__1down","Detector2__1down","Mixed1__1down", "Mixed2__1down", "Mixed3__1down", "Mixed4__1down", "Modelling2__1down", "Modelling3__1down", "Modelling1__1down", "Modelling4__1down", "Statistical1__1down", "Statistical2__1down", "Statistical3__1down", "Statistical4__1down", "Statistical5__1down", "Statistical6__1down"};
   //TString JMS_UP[16]={"Detector1__1up","Detector2__1up","Mixed1__1up", "Mixed2__1up", "Mixed3__1up", "Mixed4__1up", "Modelling2__1up", "Modelling3__1up", "Modelling1__1up", "Modelling4__1up", "Statistical1__1up", "Statistical2__1up", "Statistical3__1up", "Statistical4__1up", "Statistical5__1up", "Statistical6__1up"};
   //TString JMS_DOWN[3]={"Modelling__1down","NonClosure_2018data__1down","R10_TotalStat__1down"};
   //TString JMS_UP[3]={"Modelling__1up","NonClosure_2018data__1up","R10_TotalStat__1up"};
   //TString JMS_DOWN[2]={"Composition__1down", "Response__1down"};
   //TString JMS_UP[2]={"Composition__1up", "Response__1up"};
   //TString JMS_DOWN[2]={"TopologyUncertainty_V__1down", "TopologyUncertainty_top__1down"};
   //TString JMS_UP[2]={"TopologyUncertainty_V__1up", "TopologyUncertainty_top__1up"};
   //TFile File_UP0(base+"700041_MC16a_"+JMS_UP[0]+"_"+JMS_UP[0]+".root");
   //TFile File_UP0(base+"700041_MC16a_CategoryReduction_JET_CombMass_Tracking__1up.root");
   //TH1F *h_sys_up0=(TH1F*)File_UP0.Get("Zcand_mass");
   TFile File_Nominal(base+"410471_MC16a_nominal_nominal.root");
   TH1F *h_nom=(TH1F*)File_Nominal.Get("Zcand_Xbb50_mass");
   for (int i=0; i<1;i++)
     {
       TFile File1(base+"410471_MC16a_"+SysBase+JMS_UP[i]+"_"+SysBase+JMS_UP[i]+".root");
       TH1F *h_sys_up0= (TH1F*)File1.Get("Zcand_Xbb50_mass");
       //// h_sys_up0->Add(h_sys_up);
     

   // TFile File_DOWN0(base+"700041_MC16a_"+JMS_DOWN[0]+"_"+JMS_DOWN[0]+".root");
   //TFile File_DOWN0(base+"700041_MC16a_CategoryReduction_JET_CombMass_Tracking__1down.root");
   //TH1F *h_sys_down0=(TH1F*)File_DOWN0.Get("Zcand_mass");
    
       TFile File2(base+"410471_MC16a_"+SysBase+JMS_DOWN[i]+"_"+SysBase+JMS_DOWN[i]+".root");
       TH1F *h_sys_down0= (TH1F*)File2.Get("Zcand_Xbb50_mass");
       // h_sys_down0->Add(h_sys_down);
       
   
   TH1F *h_ratio_UP=(TH1F*)h_sys_up0->Clone();
   TH1F *h_ratio_DOWN=(TH1F*)h_sys_down0->Clone();
   h_ratio_UP->Divide(h_nom);
   h_ratio_DOWN->Divide(h_nom);
   h_nom->SetLineColor(kBlack);
   h_nom->SetLineWidth(2);
   h_sys_up0->SetLineColor(kBlue);
   h_sys_up0->SetLineWidth(2);
   h_sys_down0->SetLineColor(kRed);
   h_sys_down0->SetLineWidth(2);
   h_nom->SetTitle("");
   h_nom->SetYTitle("#bf{Entries}");
   h_nom->SetTitleOffset(0.92,"t");
   h_nom->SetTitleSize(0.07,"t");
   h_nom->GetXaxis()->SetTickLength(0);
   // h_nom->SetMaximum(1800);
   h_ratio_UP->SetMinimum();
   h_ratio_UP->SetTitle("");
   h_ratio_UP->SetLineColor(kBlue);
   h_ratio_UP->SetMarkerStyle(20);
   h_ratio_DOWN->SetLineColor(kRed);
   h_ratio_DOWN->SetMarkerStyle(20);
   h_ratio_UP->SetYTitle("Sys/Nominal");
   h_ratio_UP->SetXTitle("Zcand mass [GeV]");
	 /* hist_sigb->SetLineColor(kMagenta);
         hist_sigb->SetLineWidth(2);
         hist_bkgb->SetLineColor(kYellow);
	 hist_bkgb->SetLineWidth(2);
         hist_sigbb->SetLineColor(kBlue);
         hist_sigbb->SetLineWidth(2);
         hist_bkgbb->SetLineColor(kRed);
	 hist_bkgbb->SetLineWidth(2);*/

         pad1->cd();
         h_nom->SetStats(0);
	 h_nom->Draw("HISTO ");
	 h_sys_up0->Draw("HISTO SAME");
	 h_sys_down0->Draw("HISTO SAME");
         
	 //h_sys_down0->Draw("HISTO SAME");

         pad2->SetGrid();
         pad2->cd();
	 h_ratio_UP->GetYaxis()->SetRangeUser(0,2);
	 h_ratio_UP->SetStats(0);
         h_ratio_UP->SetLabelSize(0.062,"X");
         h_ratio_UP->SetLabelSize(0.062,"Y");
         h_ratio_UP->SetTitleSize(0.062,"X");
         h_ratio_UP->SetTitleSize(0.062,"Y");
         h_ratio_UP->SetTitleOffset(0.48,"Y");
         h_ratio_UP->SetTitleOffset(1.2,"X");
         h_ratio_UP->GetYaxis()->SetNdivisions(505);
	 h_ratio_UP->SetTickLength(0.01,"X"); //0.05
         h_ratio_UP->SetLabelOffset(0.01,"X");
	 //h_ratio_UP->GetYaxis()->SetMaximum(h_ratio_UP->GetMaximum());
         h_ratio_UP->Draw("EP");  
	 h_ratio_DOWN->Draw("EP SAME");
         //htt_nonallhad->Draw("HISTO SAME");
         /*hist_sigbb->Draw("HISTO SAME");
	 hist_bkg0->Draw("HISTO SAME");
         hist_bkgb->Draw("HISTO SAME");
         hist_bkgbb->Draw("HISTO SAME");*/
         //hist_bkg->SetTitle("");
    
   //h1->SetLabelSize(0.005,"X");
	 //	 htt_allhad->SetYTitle("#bf{Events}");
	 //htt_allhad->SetYTitle("#bf{Normalised Entries}");
   //h1->SetMarkerStyle(20);
  //h_Num_2p->SetLineColor(kBlue);
        
  //h_Num_2p->SetLabelSize(0.055, "Y");
  //pad2->cd();
  //h_Sig_2p->SetXTitle("#bf{large-R jet FoxW_{42}}");
	 // htt_allhad->SetXTitle("#bf{Leading large-R jet mass}");
	 //htt_allhad->SetTitleSize(0.07,"t");
  //leg->AddEntry(h_Num_2p,"pythia8 MC","epl");
  
  //h_Num_2p->SetMinimum(0);
  
  
  //h_Num_2p->Draw("C");

// the line belows can be changed to modify the user-range for y-axis and the x-axis.
       // htt_allhad->GetYaxis()->SetRangeUser(0, htt_allhad->GetMaximum()*1.7);
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
    
    leg->AddEntry(h_sys_up0,"JsinglePart "+JMS_UP[i],"l");
    leg->AddEntry(h_sys_down0,"JsinglePart"+JMS_DOWN[i],"l");
    leg->AddEntry(h_nom,"Nominal","l");
    /* leg->AddEntry(hist_sigb,"Zqq 1b 85","l");
    leg->AddEntry(hist_bkgb,"Total Bkg 1b 85","l");
    leg->AddEntry(hist_sigbb,"Zqq 2b 85","l");
    leg->AddEntry(hist_bkgbb,"Total Bkg 2b 85","l");*/
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
  lx=0.60;
  ly=0.75;
  //tex2= new TLatex(lx,ly,"");
  tex2= new TLatex(lx,ly,"#bf{tt all-had sample}");
  tex2->SetNDC();
  tex2->SetTextSize(0.025*1.5);
  tex2->SetTextColor(1);
  tex2->SetTextFont(42);

  TLatex *tex3= new TLatex();
  lx=0.60;
  ly=0.70;
  tex3= new TLatex(lx,ly,"#bf{anti-k_{t}LC topo trimmed Large-R jet}");
  tex3->SetNDC();
  tex3->SetTextSize(0.025);
  tex3->SetTextColor(1);
  tex3->SetTextFont(42);

  TLatex *tex4= new TLatex();
  lx=0.60;
  ly=0.66;
  // tex4= new TLatex(lx,ly,"#bf{atleast 2 VR Track jet, 140 fb-1}");
  tex4= new TLatex(lx,ly,"#bf{pT>450 GeV,M>50 GeV,>=2 VR trk-jet}");
  tex4->SetNDC();
  tex4->SetTextSize(0.025);
  tex4->SetTextColor(1);
  tex4->SetTextFont(42);

  TLatex *tex5= new TLatex();
  lx=0.60;
  ly=0.62;
  // tex4= new TLatex(lx,ly,"#bf{atleast 2 VR Track jet, 140 fb-1}");
  tex4= new TLatex(lx,ly,"#bf{Xbb 50% WP}");
  tex4->SetNDC();
  tex4->SetTextSize(0.025);
  tex4->SetTextColor(1);
  tex4->SetTextFont(42);

  pad1->cd();
  tex0->Draw("same");
  tex1->Draw("same");
  tex2->Draw("same");
  tex3->Draw("same");
  tex4->Draw("same");

  leg->Draw();
  TString name;
  name= TString("Xbb_50_tt_JSP_"+JMS_UP[i]+".pdf");
  canv->SaveAs(name.Data());
  delete leg;
     }

}
