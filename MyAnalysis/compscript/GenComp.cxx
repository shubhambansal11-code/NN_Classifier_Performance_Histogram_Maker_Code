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

void GenComp()
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
    TString base = "/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_mock/";
TFile File1(base+"700043_MC16a_nominal_nominal.root");//files including the signal JSS
TFile File2(base+"700044_MC16a_nominal_nominal.root");//files including the background JSS
TFile File3(base+"700040_MC16a_nominal_nominal.root");//files including the signal JSS
TFile File4(base+"700041_MC16a_nominal_nominal.root");//files including the background JSS
//TH1D* hist_bkgTH1D *hist_bkg;
//TH1F *htt_allhad=(TH1F*)File1.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_mass");
//TH1F *htt_nonallhad=(TH1F*)File2.Get("Selected_pTsymmetry_etaCut_leading_largeRjet_mass");
TH1F *h_Wsys=(TH1F*)File1.Get("Tagged_50_mass");
TH1F *h_Zsys=(TH1F*)File2.Get("Tagged_50_mass");
TH1F *h_Wnom=(TH1F*)File3.Get("Tagged_50_mass");
TH1F *h_Znom=(TH1F*)File4.Get("Tagged_50_mass");
//TH1F *htt_allhad=(TH1F*)htt_allhad_0->Clone();
	 h_Wsys->Divide(h_Zsys);
	 h_Wnom->Divide(h_Znom);
	 TH1F *h_ratio=(TH1F*)h_Wsys->Clone();    
         h_ratio->Divide(h_Wnom);
         //h_Wsys->Scale(1/(h_Wsys->Integral()));
	 //h_Wnom->Scale(1/(h_Wnom->Integral()));
         h_Wsys->SetLineColor(kRed);
         h_Wsys->SetLineWidth(2);
         h_Wnom->SetLineColor(kBlue);
	 h_Wnom->SetLineWidth(2);
	 h_Wsys->SetTitle("");
         h_Wsys->SetYTitle("#bf{Entries}");
         h_Wsys->SetTitleOffset(0.92,"t");
         h_Wsys->SetTitleSize(0.07,"t");
	 h_Wsys->GetXaxis()->SetTickLength(0);
	 h_ratio->SetMinimum();
	 h_ratio->SetTitle("");
	 h_ratio->SetLineColor(kBlack);
         h_ratio->SetMarkerStyle(20);
         h_ratio->SetYTitle("(W_{sys}/Z_{sys})/(W_{nom}/Z_{nom})");
         h_ratio->SetXTitle("Tagged_50 mass [GeV]");
	 /* hist_sigb->SetLineColor(kMagenta);
         hist_sigb->SetLineWidth(2);
         hist_bkgb->SetLineColor(kYellow);
	 hist_bkgb->SetLineWidth(2);
         hist_sigbb->SetLineColor(kBlue);
         hist_sigbb->SetLineWidth(2);
         hist_bkgbb->SetLineColor(kRed);
	 hist_bkgbb->SetLineWidth(2);*/

         pad1->cd();
         h_Wsys->SetStats(0);
	 h_Wsys->Draw("HISTO");
         h_Wnom->Draw("HISTO SAME");

         pad2->SetGrid();
         pad2->cd();
	 //h_ratio->GetYaxis()->SetRangeUser(0,7);
	 h_ratio->SetStats(0);
         h_ratio->SetLabelSize(0.062,"X");
         h_ratio->SetLabelSize(0.062,"Y");
         h_ratio->SetTitleSize(0.062,"X");
         h_ratio->SetTitleSize(0.062,"Y");
         h_ratio->SetTitleOffset(0.48,"Y");
         h_ratio->SetTitleOffset(1.2,"X");
         h_ratio->GetYaxis()->SetNdivisions(505);
         h_ratio->Draw("EP");  
         h_ratio->SetTickLength(0.01,"X"); //0.05
         h_ratio->SetLabelOffset(0.01,"X");
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
    
    leg->AddEntry(h_Wsys,"Sherpa 2.2.8-Lund","l");
    leg->AddEntry(h_Wnom,"Sherpa 2.2.8","l");
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
  tex2= new TLatex(lx,ly,"#bf{Wqq/Zqq sample}");
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
  lx=0.52;
  ly=0.66;
  // tex4= new TLatex(lx,ly,"#bf{atleast 2 VR Track jet, 140 fb-1}");
  tex4= new TLatex(lx,ly,"#bf{pT>450 GeV,M>50 GeV,>=2 VR trk-jet,w/ D_{2},N_{trk} tagger}");
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
  name= TString("Tagged50_WoverZ_228-8-Lund.pdf");
  canv->SaveAs(name.Data());
  delete leg;

}
