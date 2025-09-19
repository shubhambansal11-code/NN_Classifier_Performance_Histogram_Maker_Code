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

//***************************************************************************************************************************
//This file is used to compare the double b-tagging efficiency with and without the Jet substructure cut as a function of pT
//***************************************************************************************************************************

void JSSEff(){

   /*
  long total_sample_entries=0;

  TSystemDirectory dir(in_dir, in_dir);
  TList *files = dir.GetListOfFiles();
  if (files) {

    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();

      if (!(file->IsDirectory())) {
	
	TString filename=TString(in_dir)+"/"+fname;

	TFile *infile=TFile::Open(filename.Data(),"READ");

	TTree* tree=(TTree*) infile->Get("FlavourTagging_Nominal");

	  long nentries=tree->GetEntriesFast();

	  total_sample_entries+=nentries;

	  //	  std::cout<<"Tree has "<<nentries<<" entries "<<std::endl;

	  infile->Close();
	

      }
    }
  }
  */

  TString var="fjpt";

  std::shared_ptr<TCanvas> canv(new TCanvas("canv","",500,500));
  canv.get()->cd();
  //std::shared_ptr<TPad> pad1(new TPad("pad1","pad1",0,0.25,1,1));
  //pad1.get()->SetLeftMargin(0.15);
  //pad1.get()->SetBottomMargin(1.0);
  //pad1.get()->Draw();
  //pad1.get()->SetTicks();
  //canv->cd();
  //std::shared_ptr<TPad> pad2 = std::shared_ptr<TPad>(new TPad("pad2","pad2",0,0.0,1,0.35));
  //pad2.get()->SetLeftMargin(0.15);
  //pad2->SetTopMargin(0.0);
  //pad2->SetBottomMargin(0.35);
  //pad2.get()->Draw();
  //pad2.get()->SetTicks();

  //std::vector<int> color={kBlue+1,kAzure-4,kCyan+3,kGreen-9,kOrange};

  //std::vector<float> fj_bins=[[500]]; //put in the fat jet bins manually in a vector form.

  //std::cout<<"Bins for variable:"<<var<<std::endl;
  //for(auto &el : fj_bins) std::cout<<el<<std::endl;

  //std::vector<TString> regions=m_config->GetAllRegions();
  //std::vector<float> fj_bins{{500e3,600e3,700e3,800e3,900e3,1000e3,1100e3,1200e3,1300e3,1400e3,1500e3,1600e3}};
  std::vector<float> fj_bins{{500e3,700e3,900e3,1100e3,1300e3,1500e3,1700e3, 1900e3}};
  //std::vector<float> fj_bins{{200e3, 600e3,1000e3,1400e3,1800e3,2200e3}};
  //std::vector<float> fj_bins{{500e3,700e3,900e3,1100e3,1300e3,1500e3,1700e3}};
  //std::vector<float> fj_bins{{500e3,900e3,1300e3,1700e3,2100e3}};
  //std::vector<std::array<float, 6>> fj_bins;
  //std::vector<std::array<float, 6>>::iterator it = fj_bins.begin();
  //fj_bins.insert(it, fatjetArray);
  
  //Define 2 new histograms, one for the numerator and the other for the denominator
  //TFile File("/cephfs/user/s6subans/gbbCalibration2016_2prong/190603_v00-02-00_MC_Comp_Eff_MuF.root");   //change the file name
  //TFile File_Nom("/cephfs/user/s6subans/gbbCalibration2016_2prong/190607_v00-02-00_MC_Comp_EffAll_SBtag_MuFat1tjNoMuSel.root");
  int n_bins=fj_bins.size()-1;
  //double total_errors_up[n_bins],total_errors_down[n_bins], total_errsquare_up[n_bins],total_errsquare_down[n_bins], total_errsquare_up_JER[n_bins], total_errsquare_down_JER[n_bins], x_values[n_bins],y_values[n_bins],x_error_up[n_bins],x_error_down[n_bins];
  TFile File_woJSS("TruthTest_ZSample_MC16_woJSS_2904.root");
  TFile File_wJSS("TruthTest_ZSample_MC16_wJSS_2904.root");

  TH1D *h_NumwoJSS=(TH1D*)File_woJSS.Get("Zcand_2b_BB_85_pt"); //change the name of the histograms 
  TH1D *h_Den=(TH1D*)File_woJSS.Get("Zcand_BB_pt"); //change the name of the histograms
   TH1D *h_Den2=(TH1D*)File_wJSS.Get("Zcand_BB_pt");
  TH1D *h_NumwJSS=(TH1D*)File_wJSS.Get("Zcand_2b_BB_85_pt"); //change the name of the histograms 
 
  TH1D* h_Num_woJSS, *h_Den_cl,*h_Den_cl2, *h_Num_wJSS;
   
  TH1D* help;

  double d_fj_bins[fj_bins.size()];

  for(int i_b=0; i_b<fj_bins.size(); i_b++) d_fj_bins[i_b]=(double)fj_bins[i_b]; 
  TH1D *help_rebinned=new TH1D("help_rebinned","",fj_bins.size()-1,&(fj_bins[0]));
  help=(TH1D*)h_NumwoJSS->Clone();
  help_rebinned=(TH1D*)help->Rebin((int)fj_bins.size()-1,"help_rebinned",d_fj_bins);     
   h_Num_woJSS=(TH1D*)help_rebinned->Clone();

  help=(TH1D*)h_NumwJSS->Clone();
  help_rebinned=(TH1D*)help->Rebin((int)fj_bins.size()-1,"help_rebinned",d_fj_bins);     
   h_Num_wJSS=(TH1D*)help_rebinned->Clone();

  help=(TH1D*)h_Den->Clone();
  help_rebinned=(TH1D*)help->Rebin((int)fj_bins.size()-1,"help_rebinned",d_fj_bins);     
   h_Den_cl=(TH1D*)help_rebinned->Clone();

  help=(TH1D*)h_Den2->Clone();
  help_rebinned=(TH1D*)help->Rebin((int)fj_bins.size()-1,"help_rebinned",d_fj_bins);     
   h_Den_cl2=(TH1D*)help_rebinned->Clone();
  	
   // h_Den_cl=(TH1D*)h_Den->Clone();
   // h_Den_cl2=(TH1D*)h_Den2->Clone();
   //h_Num_wJSS=(TH1D*)h_NumwJSS->Clone();
 
  //prepare Legend                                                                                                                                                                                                             
  TLegend *leg=new TLegend(0.45,0.85,0.75,0.80);
  //auto legend = new TLegend(0.1,0.7,0.48,0.9);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  
  //calculate eff
  h_Num_woJSS->Divide(h_Den_cl);
  h_Num_woJSS->SetStats(0);
  h_Num_wJSS->Divide(h_Den_cl2);
  

  h_Num_woJSS->SetTitle("");
  h_Num_woJSS->SetYTitle("#bf{Double b-tagging efficiency in Z(->bb)}");
 // h_Num_2p->SetYTitle("#bf{Single b-tagging efficiency}");
  h_Num_woJSS->SetMarkerStyle(20);
  h_Num_woJSS->SetLineColor(kBlue);
  h_Num_woJSS->SetLineWidth(-802);
  h_Num_woJSS->SetTitleOffset(0.65,"t");
  h_Num_woJSS->SetTitleSize(0.005,"t");
  h_Num_woJSS->SetXTitle("#bf{large-R jet p_{T} [MeV]}");
  h_Num_woJSS->SetTitleSize(0.07,"t");
 
  h_Num_woJSS->Draw("PFC");
  h_Num_woJSS->GetYaxis()->SetRangeUser(0.001,h_Num_woJSS->GetMaximum()*1.8);
  //h_Num_woJSS->GetXaxis()->SetLimits(500,1000);
  
  h_Num_wJSS->SetMarkerStyle(20);
  h_Num_wJSS->SetLineColor(kBlack);
  h_Num_wJSS->SetLineWidth(-802);
  h_Num_wJSS->Draw("same");



  leg->AddEntry(h_Num_woJSS,"w/o #tau_{21} cut","l");
    leg->AddEntry(h_Num_wJSS,"w #tau_{21} cut","l");
  TLatex *tex00 = new TLatex();
  double lx ; double ly;
  lx=0.20;
  ly=0.73;
  tex00= new TLatex(lx,ly,"#bf{#it{ATLAS}} work-in-progress");
  tex00->SetNDC();
  tex00->SetTextSize(0.025*1.2);
  tex00->SetTextColor(1);
  tex00->SetTextFont(42);

  TLatex *tex0 = new TLatex();
  lx=0.20;
  ly=0.70;
  tex0= new TLatex(lx,ly,"#bf{Simulation}");
  tex0->SetNDC();
  tex0->SetTextSize(0.025*1.2);
  tex0->SetTextColor(1);
  tex0->SetTextFont(42);

  TLatex *tex1= new TLatex();
  lx=0.20;
  ly=0.67;
  tex1= new TLatex(lx,ly,"#bf{#sqrt{s}=13 TeV, R=1.0 large R-jet, VR track jets}"); 
  tex1->SetNDC();
  tex1->SetTextSize(0.025*1.2);
  tex1->SetTextColor(1);
  tex1->SetTextFont(42);

  TLatex *tex2= new TLatex();
  lx=0.20;
  ly=0.63;
  //tex2= new TLatex(lx,ly,"");
  //tex2= new TLatex(lx,ly,"#bf{Single b-tagging (70% WP) on #mu-jet}");
  tex2= new TLatex(lx,ly,"#bf{Double b-tagging (85% WP)}");
  tex2->SetNDC();
  tex2->SetTextSize(0.025*1.2);
  tex2->SetTextColor(1);
  tex2->SetTextFont(42);

  TLatex *tex3= new TLatex();
  lx=0.20;
  ly=0.60;
  tex3= new TLatex(lx,ly,"#bf{Jet Substructure Cut}");
  tex3->SetNDC();
  tex3->SetTextSize(0.025*1.2);
  tex3->SetTextColor(1);
  tex3->SetTextFont(42);

  //pad1->cd();
  // tex00->Draw("same");
  //tex0->Draw("same");
  tex1->Draw("same");
  tex2->Draw("same");
  //tex3->Draw("same");

  leg->Draw();

  TString name;
  name= TString("EFFZbb_85_2904_M150.pdf");
  
  canv->SaveAs(name.Data());

  delete leg;


  //std::cout<<"Sample has "<<total_sample_entries<<" entries "<<std::endl;

}
