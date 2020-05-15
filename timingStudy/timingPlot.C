#include <TROOT.h>
#include <TStyle.h>
#include <TH1F.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveStats.h>
#include <TEfficiency.h>
#include <TGraphAsymmErrors.h>
#include <iostream>
#include <TLatex.h>
#include <TGaxis.h>

//int colors[] = {kBlack, kRed+2, kOrange+2, kGreen+2, kCyan+2, kBlue+2, kViolet+2};
//int colors[] = {kBlack, kBlue+2,  kRed+2, kOrange+2, kGreen+2, kCyan+2, kViolet+2};
//int colors[] = {kBlack,  kRed+2, kOrange+2, kGreen+2, kCyan+2, kMagenta+2, kViolet+2, kBlue+2};
//int colors[] = {kBlack, kRed+2, kOrange+2, kYellow+2, kGreen+2, kCyan+2, kBlue+2, kViolet+2, kMagenta+2};
//int colors[] = {kBlack, kCyan+2, kOrange+2, kRed+2, kYellow+2, kGreen+2, kBlue+2, kViolet+2, kMagenta+2};
//int colors[] = {kBlack, kOrange+2, kCyan+2, kRed+2, kYellow+2, kGreen+2, kBlue+2, kViolet+2, kMagenta+2};
//int colors[] = {kBlack, kRed+2, kBlue+2, kOrange+2, kCyan+2, kYellow+2, kGreen+2, kViolet+2, kMagenta+2};
int colors[] = {kBlack, kOrange+2, kCyan+2, kGreen+2, kRed+2, kViolet+2, kBlue+2, kMagenta+2, kGreen};

TString HLTpath;
TString HLTpath2;
TString hEventsName;
TString hPathName;
TString hModulesName;
TString hModulesName2;
TString hModulesDir;

std::vector<TString> filename;
std::vector<TString> label;
std::vector<TString> sel;

double NEVENTS;

void drawText(TString textString, double xmin, double ymin, double textSize) {
  TLatex* text=new TLatex(xmin, ymin, textString);
  text->SetNDC();
  text->SetTextSize(textSize);
  text->Draw();
}


void drawCMS() {
  TLatex* text=new TLatex(0.18, 0.95, "CMS Data, 2012, #sqrt{s}=8 TeV, Preliminary");
  text->SetNDC();
  text->SetTextSize(0.045);
  text->Draw();
}


void drawPU(int pu = 40) {
  TLatex* text=new TLatex(0.08, 0.9, Form("<PU> ~ %d",pu));
  text->SetNDC();
  text->SetTextSize(0.04);
  text->Draw();

  TLatex* text1=new TLatex(0.085, 0.8, "25ns");
  text1->SetNDC();
  text1->SetTextSize(0.04);
  text1->Draw();
}


void drawCMSsimulation() {
  TLatex* text=new TLatex(0.18, 0.95, "CMS Simulation Private, 2023, #sqrt{s}=14 TeV, Preliminary");
  text->SetNDC();
  text->SetTextSize(0.045);
  text->Draw();
}

void init() {

  gStyle->SetOptTitle(0); 

  filename.clear();
  label.clear();
  sel.clear();

  
  TString processName = "TIMING";
  HLTpath = "MC_Tracking_v2";

  hEventsName   = "/DQMData/Run 1/HLT/Run summary/TimerService/event time_thread";
  hPathName     = "/DQMData/Run 1/HLT/Run summary/TimerService/process "+processName+" paths/path "+HLTpath+"/path time_thread";
  hModulesName  = "/DQMData/Run 1/HLT/Run summary/TimerService/process "+processName+" paths/path "+HLTpath+"/module_time_thread_average";


  NEVENTS = 1000.;

//  filename.push_back("DQM_V0001_R000000001__HLT__FastTimerService__All_PU0_1k_16core.root");
//  filename.push_back("DQM_V0001_R000000001__HLT__FastTimerService__All_PU200_1k_16core.root");

  filename.push_back("DQM_v2_timing.root");
  filename.push_back("DQM_11_timing.root");  
  label.push_back("PU: 0");
  label.push_back("PU: 200");
  sel.push_back("PU: 0");
  sel.push_back("PU: 200");

 //=============================================

  gROOT ->Reset();
  
  //=========  settings ====================
  gROOT->SetStyle("Plain");


}


void module(TString module) {

  init();

  std::vector<TH1F*> h;

  std::cout << "nFiles: " << filename.size() << std::endl;
  for ( size_t i=0; i<filename.size(); i++ ) {
    TH1F* histo = NULL;
    TFile* f = new TFile(filename[i]);
    if (f == NULL) continue;
    
    histo = (TH1F*)f->Get(hModulesDir+"/"+module);
    histo->SetName("events_"+sel[i]);
    histo->SetLineColor(colors[i]);
    histo->SetLineWidth(3);
    histo->GetXaxis()->SetTitle("processing time [ms]");
    h.push_back(histo);
 }

 TString options = "histo";
 double startingX = 0.75;
 double startingY = 0.80;
 
 TCanvas * can = new TCanvas(module,module,1800,900);
 can->cd();
 gStyle->SetOptStat(112220);
 // gStyle->SetPadGridX(kTRUE);
 // gStyle->SetPadGridY(kTRUE);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.1);
 gPad->SetLogy();
 options = "histo";
 startingX = 0.75;
 startingY = 0.80;
 
 TLegend* legEvents = new TLegend(0.45,0.55,0.70,0.85);
 legEvents->SetFillColor(0);
 legEvents->SetLineColor(0);
 
 for ( size_t i=0; i<h.size(); i++ ) {
   if (i!=0) options = "histosames";
   //   h[i]->GetXaxis()->SetRangeUser(0.,1000.);
   h[i]->Draw(options);

   gPad->Update();
   TPaveStats* st = (TPaveStats*) h[i]->GetListOfFunctions()->FindObject("stats");
   st->SetX1NDC(startingX);
   st->SetX2NDC(startingX+0.20);
   st->SetY1NDC(startingY);
   st->SetY2NDC(startingY+0.15);
   st->SetTextColor(colors[i]);
   st->SetLineColor(colors[i]);
   st->SetLineWidth(2);
   gPad->Update();

   startingY = startingY-0.15;

   legEvents->AddEntry(h[i],label[i],"l");
 }
 legEvents->Draw("same");

 can->SaveAs(module+".png");
 can->SaveAs(module+".pdf");

}

void iter0() {
  module("");
  module("");
  module("");
  module("");
  module("");
  module("");
  module("");
}

void iter1() {
  module(""); 
  module(""); 
  module(""); 
  module(""); 
  module(""); 
  module(""); 
}

void iter2() {
  module(""); 
  module(""); 
  module(""); 
  module(""); 
}

void trackingByModule(TString last = "GeneralTracks") 
{

  init();

 std::vector<TH1F*> hModules;

 std::cout << "nFiles: " << filename.size() << std::endl;
 double hModules_ymax = 0.;
 for ( size_t i=0; i<filename.size(); i++ ) {
   TH1F* histo = NULL;
   TFile* f = new TFile(filename[i]);
   if (f == NULL) continue;

   TString hname = hModulesName;
   histo = (TH1F*)f->Get(hname);
     
   std::cout << "hModulesName: " << hModulesName << std::endl;
   if (histo==NULL) continue;
   histo->SetName("modules_"+sel[i]);
   histo->SetLineColor(colors[i]);
   histo->SetLineWidth(3);
   histo->SetFillColor(colors[i]);
   if (i==0)
     histo->SetFillStyle(0);
   else
     histo->SetFillStyle(3001);
   histo->GetYaxis()->SetTitle("average processing time [ms]");
   histo->GetYaxis()->SetNdivisions(305);
   histo->GetYaxis()->SetLabelSize(0.05);   
   histo->GetYaxis()->SetLabelOffset(0.008);   
   histo->GetYaxis()->SetTitleOffset(0.65);   
   histo->GetYaxis()->SetTitleSize(0.05);
   histo->GetXaxis()->SetTitle("HLT modules");
   //   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleSize(0.08);
   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleOffset(.5);
   histo->GetYaxis()->SetLabelSize(.04);
   //double integral = histo->Integral(71.,98.);
   //   histo->Scale(1000./integral);
   
   hModules.push_back(histo);

   double max = histo->GetMaximum();
   hModules_ymax = (max > hModules_ymax ? max : hModules_ymax);

 }

 TString options = "";
 double startingX = 0.75;
 double startingY = 0.80;

 size_t nbins = hModules[0]->GetNbinsX();
 double xmin = -1.;
 double xmax = hModules[0]->GetXaxis()->GetXmax();
 for (size_t i=0; i<nbins; i++) {
   TString ilabel = hModules[0]->GetXaxis()->GetBinLabel(i);
   if (xmin < 0) // if it hasn't been assigned and = -1
     if ( ilabel.Contains("nitialStepSeedLayers")  ){
       xmin = hModules[0]->GetXaxis()->GetBinCenter(i);//(i-1);
  
       }	

   if ( ilabel.Contains(last) ) {
     xmax = hModules[0]->GetXaxis()->GetBinCenter(i);
   }
  }

 TCanvas * canModules = new TCanvas("canModules","canModules",1800,900);
 TGaxis::SetMaxDigits(3);
 canModules->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.07);

 // TGaxis::SetMaxDigits(3);

 // TPad* pad1 = new TPad("pad1","Ratios",0.,0.7,1.0,1.0);
 // pad1->SetBottomMargin(0);
 // pad1->Draw();
 // TPad* pad2 = new TPad("pad2","Histos",0.,0.0,1.0,0.7);
 // pad2->SetBottomMargin(0.25);
 // pad2->SetTopMargin(0);
 // pad2->Draw();


 // pad2->cd();
 options = "histo";
 TLegend* legModules = new TLegend(0.50,0.60,0.65,0.90);
 legModules->SetTextSize(0.05);
 legModules->SetFillColor(0);
 legModules->SetLineColor(0);

 for ( size_t i=0; i<hModules.size(); i++ ) {
   if (i!=0) options = "histosame";
   hModules[i]->GetXaxis()->SetRangeUser(xmin,xmax);
   double all = 0.;
   double tot = 0.;
   for (size_t ibin=1; ibin<=hModules[0]->GetXaxis()->GetXmax(); ibin++) {
     all += hModules[i]->GetBinContent(ibin);
     TString ilabel = hModules[i]->GetXaxis()->GetBinLabel(ibin-1);
     //std::cout << "all modules: " << ilabel << std::endl;
   }
   for (size_t ibin=1; ibin<=hModules[0]->GetXaxis()->GetXmax(); ibin++) {
     if (ibin >= xmin and ibin <= xmax) {
       TString ilabel = hModules[i]->GetXaxis()->GetBinLabel(ibin-1);
       if ( ilabel.Contains("GeneralTracks") ) break;
       tot += hModules[i]->GetBinContent(ibin);
       //std::cout << ilabel << std::endl;
     }
   }
   std::cout << label[i] << " --> " << tot << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   std::cout << label[i] << " --> " << tot/NEVENTS << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   hModules[i]->GetYaxis()->SetRangeUser(0.,hModules_ymax*1.1);
   //   hModules[i]->GetXaxis()->SetTitleSize(0.08);
   //   hModules[i]->GetXaxis()->SetLabelOffset(10.);
   //   hModules[i]->GetXaxis()->SetTitleOffset(.5);
   //   hModules[i]->GetYaxis()->SetNdivisions(305);
   //   hModules[i]->GetYaxis()->SetTitleSize(0.05);
   //   hModules[i]->GetYaxis()->SetTitleOffset(0.6);
   //   hModules[i]->GetYaxis()->SetLabelOffset(0.005);
   //   hModules[i]->GetYaxis()->SetLabelSize(.04);
   
   hModules[i]->Draw(options);
   legModules->AddEntry(hModules[i],label[i],"f");
 }
 hModules[0]->Draw("histosame");
 legModules->Draw("same");

 // drawText("pixelTracks",0.10,0.95,0.04);
 // drawText("iter0",      0.23,0.86,0.04);
 // drawText("iter1",      0.48,0.35,0.04);
 // drawText("iter2",      0.81,0.76,0.04);
 // drawText("iter3",      0.70,0.23,0.04);
 // drawText("iter4",      0.88,0.38,0.04);

 /*
 pad1->cd();
 const TArrayD* bins = hModules[0]->GetXaxis()->GetXbins();
 double ymin_ratio =  0.01;
 double ymax_ratio =  5.;
 options = "AP";
 std::cout << "hModules: " << hModules.size() << std::endl;
 for (size_t i=1; i<hModules.size(); i++) {
   if (i!=1) options = "Psame";
   std::cout << "ratio wrt " << sel[i] << std::endl;
   TEfficiency* ratio = new TEfficiency("ratio_"+sel[i],"ratio_"+sel[i],nbins,bins->GetArray());
   ratio->SetTotalHistogram(*hModules[0],"f");
   ratio->SetPassedHistogram(*hModules[i],"f");
   ratio->SetStatisticOption(TEfficiency::kFWilson);
   ratio->Draw(options);

   pad1->Update();

   ratio->SetLineColor(colors[i]);
   ratio->SetMarkerColor(colors[i]);
   ratio->SetMarkerStyle(20);
   ratio->SetMarkerSize(1);
   ratio->GetPaintedGraph()->GetXaxis()->SetLimits(xmin,xmax);
   ratio->GetPaintedGraph()->SetMinimum( ymin_ratio);
   ratio->GetPaintedGraph()->SetMaximum( ymax_ratio);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitle("ratio");
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.1);
   ratio->GetPaintedGraph()->GetYaxis()->SetNdivisions(305);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.3);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelOffset(0.01);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelSize(.08);
 }
 */
 drawCMSsimulation();
 
 canModules->SaveAs("tracking_by_modules_"+last+".png");
 canModules->SaveAs("tracking_by_modules_"+last+".pdf");

}

void trackingByStep(TString step = "hltPhase2InitialStep") 
{

  init();

 std::vector<TH1F*> hModules;

 std::cout << "nFiles: " << filename.size() << std::endl;
 double hModules_ymax = 0.;
 for ( size_t i=0; i<filename.size(); i++ ) {
   TH1F* histo = NULL;
   TFile* f = new TFile(filename[i]);
   if (f == NULL) continue;

   TString hname = hModulesName;
   histo = (TH1F*)f->Get(hname);
     
   std::cout << "hModulesName: " << hModulesName << std::endl;
   if (histo==NULL) continue;
   histo->SetName("modules_"+sel[i]);
   histo->SetLineColor(colors[i]);
   histo->SetLineWidth(3);
   histo->SetFillColor(colors[i]);
   if (i==0)
     histo->SetFillStyle(0);
   else
     histo->SetFillStyle(3001);
   histo->GetYaxis()->SetTitle("average processing time [ms]");
   histo->GetYaxis()->SetNdivisions(305);
   histo->GetYaxis()->SetLabelSize(0.05);   
   histo->GetYaxis()->SetLabelOffset(0.008);   
   histo->GetYaxis()->SetTitleOffset(0.65);   
   histo->GetYaxis()->SetTitleSize(0.05);
   histo->GetXaxis()->SetTitle("HLT modules");
   //   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleSize(0.08);
   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleOffset(.5);
   histo->GetYaxis()->SetLabelSize(.04);
   //double integral = histo->Integral(71.,98.);
   //   histo->Scale(1000./integral);
   
   hModules.push_back(histo);

   double max = histo->GetMaximum();
   hModules_ymax = (max > hModules_ymax ? max : hModules_ymax);

 }

 TString options = "";
 double startingX = 0.75;
 double startingY = 0.80;

 size_t nbins = hModules[0]->GetNbinsX();
 double xmin = -1.;
 double xmax = hModules[0]->GetXaxis()->GetXmax();
 size_t nFILES = filename.size();
 double tot[nFILES];
 for (size_t i=0; i<nFILES; i++)
   tot[i] = 0.;
 TString last = "hltPhase2GeneralTracks"; //"earlyGeneralTracks"; #v1
 for (size_t i=0; i<nbins; i++) {
   TString ilabel = hModules[0]->GetXaxis()->GetBinLabel(i);
   //   std::cout << "ilabel: " << ilabel << " " << (ilabel.Contains(step) ? "OK" : "KO") << " " << hModules[0]->GetBinContent(i) << std::endl;
   //   std::cout << "ilabel: " << ilabel << " " << (ilabel.Contains(step) ? "OK" : "KO") << " " << hModules[1]->GetBinContent(i) << std::endl;
   if (ilabel.Contains(step)) 
     for (size_t j=0; j< nFILES; j++)
       tot[j] += hModules[j]->GetBinContent(i);
   if (xmin < 0)
     if ( ilabel.Contains(step) )
       xmin = hModules[0]->GetXaxis()->GetBinCenter(i-1);

   if ( ilabel.Contains(step) and ilabel.Contains("Selection") ) {
     xmax = hModules[0]->GetXaxis()->GetBinCenter(i);
   }
 }
 for (size_t i=0; i<nFILES; i++)
   std::cout << "step: " << step << " " << tot[i] << " ms" << std::endl;


 TCanvas * canModules = new TCanvas("canModules","canModules",1800,900);
 TGaxis::SetMaxDigits(3);
 canModules->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.07);

 // TGaxis::SetMaxDigits(3);

 TPad* pad1 = new TPad("pad1","Ratios",0.,0.7,1.0,1.0);
 pad1->SetBottomMargin(0);
 pad1->Draw();
 TPad* pad2 = new TPad("pad2","Histos",0.,0.0,1.0,0.7);
 pad2->SetBottomMargin(0.25);
 pad2->SetTopMargin(0);
 pad2->Draw();


 pad2->cd();
 options = "histo";
 TLegend* legModules = new TLegend(0.50,0.60,0.65,0.90);
 legModules->SetTextSize(0.05);
 legModules->SetFillColor(0);
 legModules->SetLineColor(0);

 for ( size_t i=0; i<hModules.size(); i++ ) {
   if (i!=0) options = "histosame";
   hModules[i]->GetXaxis()->SetRangeUser(xmin,xmax);
   double all = 0.;
   double tot = 0.;
   for (size_t ibin=1; ibin<=hModules[0]->GetXaxis()->GetXmax(); ibin++)
     all += hModules[i]->GetBinContent(ibin);
   for (size_t ibin=1; ibin<=hModules[0]->GetXaxis()->GetXmax(); ibin++) {
     if (ibin >= xmin and ibin <= xmax) {
       TString ilabel = hModules[0]->GetXaxis()->GetBinLabel(i-1);
       if ( ilabel.Contains("hltPhase2GeneralTracks") ) break; //v1
       tot += hModules[i]->GetBinContent(ibin);
     }
   }
   std::cout << label[i] << " --> " << tot << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   std::cout << label[i] << " --> " << tot/NEVENTS << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   hModules[i]->GetYaxis()->SetRangeUser(0.,hModules_ymax*1.1);
   //   hModules[i]->GetXaxis()->SetTitleSize(0.08);
   //   hModules[i]->GetXaxis()->SetLabelOffset(10.);
   //   hModules[i]->GetXaxis()->SetTitleOffset(.5);
   //   hModules[i]->GetYaxis()->SetNdivisions(305);
   //   hModules[i]->GetYaxis()->SetTitleSize(0.05);
   //   hModules[i]->GetYaxis()->SetTitleOffset(0.6);
   //   hModules[i]->GetYaxis()->SetLabelOffset(0.005);
   //   hModules[i]->GetYaxis()->SetLabelSize(.04);
   
   hModules[i]->Draw(options);
   legModules->AddEntry(hModules[i],label[i],"f");
 }
 hModules[0]->Draw("histosame");
 legModules->Draw("same");

 // drawText("pixelTracks",0.10,0.95,0.04);
 // drawText("iter0",      0.23,0.86,0.04);
 // drawText("iter1",      0.48,0.35,0.04);
 // drawText("iter2",      0.81,0.76,0.04);
 // drawText("iter3",      0.70,0.23,0.04);
 // drawText("iter4",      0.88,0.38,0.04);

 pad1->cd();
 const TArrayD* bins = hModules[0]->GetXaxis()->GetXbins();
 double ymin_ratio =  0.01;
 double ymax_ratio =  200.;
 options = "AP";
 std::cout << "hModules: " << hModules.size() << std::endl;
 auto binsArray = bins->GetArray();
 for (size_t i=1; i<hModules.size(); i++) {
   if (i!=1) options = "Psame";
   std::cout << "ratio wrt " << sel[i] << std::endl;
   TEfficiency* ratio = new TEfficiency("ratio_"+sel[i],"ratio_"+sel[i],nbins,bins->GetArray());
   ratio->SetTotalHistogram(*hModules[0],"f");
   ratio->SetPassedHistogram(*hModules[i],"f");
   ratio->SetStatisticOption(TEfficiency::kFWilson);
   //   TH1F* ratio = (TH1F*)hModules[i]->Clone("ratio_"+sel[i]);
   //   ratio->Divide(hModules[0]);
   ratio->Draw(options);

   pad1->Update();

   ratio->SetLineColor(colors[i]);
   ratio->SetMarkerColor(colors[i]);
   ratio->SetMarkerStyle(20);
   ratio->SetMarkerSize(1);

   ratio->GetPaintedGraph()->GetXaxis()->SetLimits(xmin,xmax);
   ratio->GetPaintedGraph()->SetMinimum( ymin_ratio);
   ratio->GetPaintedGraph()->SetMaximum( ymax_ratio);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitle("ratio");
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.1);
   ratio->GetPaintedGraph()->GetYaxis()->SetNdivisions(305);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.3);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelOffset(0.01);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelSize(.08);
   /*
   ratio->GetXaxis()->SetLimits(xmin,xmax);
   //   ratio->SetMinimum( ymin_ratio);
   //   ratio->SetMaximum( ymax_ratio);
   ratio->GetYaxis()->SetTitle("ratio");
   //   ratio->GetYaxis()->SetTitleSize(0.1);
   //   ratio->GetYaxis()->SetNdivisions(305);
   //   ratio->GetYaxis()->SetTitleOffset(0.3);
   //   ratio->GetYaxis()->SetLabelOffset(0.01);
   //   ratio->GetYaxis()->SetLabelSize(.08);
   */


 }
 drawCMSsimulation();
 
 canModules->SaveAs("tracking_by_modules_"+step+".png");
 canModules->SaveAs("tracking_by_modules_"+step+".pdf");

}


void trackingBySteps() {
  trackingByStep("hltPhase2InitialStep");
  trackingByStep("hltPhase2HighPtTripletStep");
  //trackingByStep("lowPtQuadStep");
  //trackingByStep("lowPtTripletStep");
  //trackingByStep("detachedQuadStep");
  //trackingByStep("pixelPairStep");
  //trackingByStep("OutIn");
  //trackingByStep("InOut");
}


void pathByModule() 
{

  init();

 std::vector<TH1F*> hModules;

 std::cout << "nFiles: " << filename.size() << std::endl;
 double hModules_ymax = 0.;
 for ( size_t i=0; i<filename.size(); i++ ) {
   TH1F* histo = NULL;
   TFile* f = new TFile(filename[i]);
   if (f == NULL) continue;

   TString hname = hModulesName;
   histo = (TH1F*)f->Get(hname);
     
   std::cout << "hModulesName: " << hModulesName << std::endl;
   if (histo==NULL) continue;
   histo->SetName("modules_"+sel[i]);
   histo->SetLineColor(colors[i]);
   histo->SetLineWidth(3);
   histo->SetFillColor(colors[i]);
   if (i==0)
     histo->SetFillStyle(0);
   else
     histo->SetFillStyle(3001);
   histo->GetYaxis()->SetTitle("average processing time [ms]");
   histo->GetYaxis()->SetNdivisions(305);
   histo->GetYaxis()->SetLabelSize(0.05);   
   histo->GetYaxis()->SetLabelOffset(0.008);   
   histo->GetYaxis()->SetTitleOffset(0.65);   
   histo->GetYaxis()->SetTitleSize(0.05);
   histo->GetXaxis()->SetTitle("HLT modules");
   //   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleSize(0.08);
   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleOffset(.5);
   histo->GetYaxis()->SetLabelSize(.04);
   //double integral = histo->Integral(71.,98.);
   //   histo->Scale(1000./integral);
   
   hModules.push_back(histo);

   double max = histo->GetMaximum();
   hModules_ymax = (max > hModules_ymax ? max : hModules_ymax);

 }

 TString options = "";
 double startingX = 0.75;
 double startingY = 0.80;

 size_t nbins = hModules[0]->GetNbinsX();
 double xmin = -1.;
 double xmax = hModules[0]->GetXaxis()->GetXmax();

 TCanvas * canModules = new TCanvas("canModules","canModules",1800,900);
 TGaxis::SetMaxDigits(3);
 canModules->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.07);

 // TGaxis::SetMaxDigits(3);

 // TPad* pad1 = new TPad("pad1","Ratios",0.,0.7,1.0,1.0);
 // pad1->SetBottomMargin(0);
 // pad1->Draw();
 // TPad* pad2 = new TPad("pad2","Histos",0.,0.0,1.0,0.7);
 // pad2->SetBottomMargin(0.25);
 // pad2->SetTopMargin(0);
 // pad2->Draw();


 // pad2->cd();
 options = "histo";
 TLegend* legModules = new TLegend(0.50,0.60,0.65,0.90);
 legModules->SetTextSize(0.05);
 legModules->SetFillColor(0);
 legModules->SetLineColor(0);

 for ( size_t i=0; i<hModules.size(); i++ ) {
   if (i!=0) options = "histosame";
   hModules[i]->GetXaxis()->SetRangeUser(xmin,xmax);
   double all = 0.;
   double tot = 0.;
   for (size_t ibin=1; ibin<=hModules[0]->GetXaxis()->GetXmax(); ibin++) {
     all += hModules[i]->GetBinContent(ibin);
     if (ibin >= xmin and ibin <= xmax)
       tot += hModules[i]->GetBinContent(ibin);
   }
   std::cout << label[i] << " --> " << tot << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   std::cout << label[i] << " --> " << tot/NEVENTS << " ms [ " << (tot/all)*100 << " ]" << std::endl;
   hModules[i]->GetYaxis()->SetRangeUser(0.,hModules_ymax*1.1);
   //   hModules[i]->GetXaxis()->SetTitleSize(0.08);
   //   hModules[i]->GetXaxis()->SetLabelOffset(10.);
   //   hModules[i]->GetXaxis()->SetTitleOffset(.5);
   //   hModules[i]->GetYaxis()->SetNdivisions(305);
   //   hModules[i]->GetYaxis()->SetTitleSize(0.05);
   //   hModules[i]->GetYaxis()->SetTitleOffset(0.6);
   //   hModules[i]->GetYaxis()->SetLabelOffset(0.005);
   //   hModules[i]->GetYaxis()->SetLabelSize(.04);
   
   hModules[i]->Draw(options);
   legModules->AddEntry(hModules[i],label[i],"f");
 }
 hModules[0]->Draw("histosame");
 legModules->Draw("same");

 // drawText("pixelTracks",0.10,0.95,0.04);
 // drawText("iter0",      0.23,0.86,0.04);
 // drawText("iter1",      0.48,0.35,0.04);
 // drawText("iter2",      0.81,0.76,0.04);
 // drawText("iter3",      0.70,0.23,0.04);
 // drawText("iter4",      0.88,0.38,0.04);

 /*
 pad1->cd();
 const TArrayD* bins = hModules[0]->GetXaxis()->GetXbins();
 double ymin_ratio =  0.01;
 double ymax_ratio =  5.;
 options = "AP";
 std::cout << "hModules: " << hModules.size() << std::endl;
 for (size_t i=1; i<hModules.size(); i++) {
   if (i!=1) options = "Psame";
   std::cout << "ratio wrt " << sel[i] << std::endl;
   TEfficiency* ratio = new TEfficiency("ratio_"+sel[i],"ratio_"+sel[i],nbins,bins->GetArray());
   ratio->SetTotalHistogram(*hModules[0],"f");
   ratio->SetPassedHistogram(*hModules[i],"f");
   ratio->SetStatisticOption(TEfficiency::kFWilson);
   ratio->Draw(options);

   pad1->Update();

   ratio->SetLineColor(colors[i]);
   ratio->SetMarkerColor(colors[i]);
   ratio->SetMarkerStyle(20);
   ratio->SetMarkerSize(1);
   ratio->GetPaintedGraph()->GetXaxis()->SetLimits(xmin,xmax);
   ratio->GetPaintedGraph()->SetMinimum( ymin_ratio);
   ratio->GetPaintedGraph()->SetMaximum( ymax_ratio);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitle("ratio");
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.1);
   ratio->GetPaintedGraph()->GetYaxis()->SetNdivisions(305);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.3);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelOffset(0.01);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelSize(.08);
 }
 */
 drawCMSsimulation();
 
 canModules->SaveAs("path_by_modules.png");
 canModules->SaveAs("path_by_modules.pdf");

}
 
void trackingHLTtotal(int path = 1) 
{

  init();

 std::vector<TH1F*> hModules;

 std::cout << "nFiles: " << filename.size() << std::endl;
 double hModules_ymax = 0.;
 for ( size_t i=0; i<filename.size(); i++ ) {
   TH1F* histo = NULL;
   TFile* f = new TFile(filename[i]);
   if (f == NULL) continue;

   TString hname = hModulesName; //( path == 1 ? hModulesName : hModulesName2 );
   histo = (TH1F*)f->Get(hname);
     
   std::cout << "hModulesName: " << hModulesName << std::endl;
   if (histo==NULL) continue;
   histo->SetName("modules_"+sel[i]);
   histo->SetLineColor(colors[i]);
   histo->SetLineWidth(3);
   histo->SetFillColor(colors[i]);
   if (i==0)
     histo->SetFillStyle(0);
   else
     histo->SetFillStyle(3001);
   histo->GetYaxis()->SetTitle("number of events");
   histo->GetYaxis()->SetNdivisions(305);
   histo->GetYaxis()->SetLabelSize(0.05);   
   histo->GetYaxis()->SetLabelOffset(0.008);   
   histo->GetYaxis()->SetTitleOffset(0.65);   
   histo->GetYaxis()->SetTitleSize(0.05);
   histo->GetXaxis()->SetTitle("total time per event [ms]");
   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleSize(0.08);
   histo->GetXaxis()->SetLabelOffset(10.);
   histo->GetXaxis()->SetTitleOffset(.5);
   histo->GetYaxis()->SetLabelSize(.04);
   //double integral = histo->Integral(71.,98.);
   //   histo->Scale(1000./integral);
   
   hModules.push_back(histo);

   double maxTot = histo->GetMaximum();
   hModules_ymax = (maxTot > hModules_ymax ? maxTot : hModules_ymax);

 }

 TString options = "";
 double startingX = 0.75;
 double startingY = 0.80;

 size_t nbinsTot = hModules[0]->GetNbinsX();
 double xminTot = -1.;
 double xmaxTot = hModules[0]->GetXaxis()->GetXmax();
 for (size_t i=0; i<nbinsTot; i++) {
   TString ilabel = hModules[0]->GetXaxis()->GetBinLabel(i);
   if (xminTot < 0)
     if ( ilabel.Contains("hltPhase2PixelTracks") or ilabel.Contains("PixelTracks") )
       xminTot = hModules[0]->GetXaxis()->GetBinCenter(i-1);
   
   if (ilabel.Contains("iter") or ilabel.Contains("Iter")) {
     xmaxTot = hModules[0]->GetXaxis()->GetBinCenter(i);
   }
  }

 TCanvas * canModulesTot = new TCanvas("canModulesTot","canModulesTot",1800,900);
 TGaxis::SetMaxDigits(3);
 canModulesTot->cd();
 gStyle->SetOptStat(112220);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.1);
 options = "";
 startingX = 0.75;
 startingY = 0.80;

 // TGaxis::SetMaxDigits(3);

 // TPad* pad1Tot = new TPad("pad1Tot","Ratios",0.,0.7,1.0,1.0);
 // pad1Tot->SetBottomMargin(0);
 // pad1Tot->Draw();
 // TPad* pad2Tot = new TPad("pad2Tot","Histos",0.,0.0,1.0,0.7);
 // pad2Tot->SetBottomMargin(0.25);
 // pad2Tot->SetTopMargin(0);
 // pad2Tot->Draw();


 // pad2Tot->cd();
 options = "histo";
 TLegend* legModulesTot = new TLegend(0.35,0.55,0.60,0.85);
 legModulesTot->SetTextSize(0.03);
 legModulesTot->SetFillColor(0);
 legModulesTot->SetLineColor(0);

 for ( size_t i=0; i<hModules.size(); i++ ) {
   if (i!=0) options = "histosames";
   double tot = 0.;
   for (size_t ibin=xminTot; ibin<=xmaxTot; ibin++) {
     tot += hModules[i]->GetBinContent(ibin);
     TString ilabel = hModules[i]->GetXaxis()->GetBinLabel(ibin);
     if (ilabel.Contains("ixelTrack"))
       std::cout << ilabel << " " << hModules[i]->GetBinContent(ibin);
   }

   std::cout << label[i] << " --> " << tot << " ms" << std::endl;
   std::cout << label[i] << " --> " << tot/NEVENTS << " ms" << std::endl;
   hModules[i]->GetXaxis()->SetRangeUser(xminTot,xmaxTot);
   hModules[i]->GetYaxis()->SetRangeUser(0.,hModules_ymax*1.1);
   //   hModules[i]->GetXaxis()->SetTitleSize(0.08);
   //   hModules[i]->GetXaxis()->SetLabelOffset(10.);
   //   hModules[i]->GetXaxis()->SetTitleOffset(.5);
   //   hModules[i]->GetYaxis()->SetNdivisions(305);
   //   hModules[i]->GetYaxis()->SetTitleSize(0.05);
   //   hModules[i]->GetYaxis()->SetTitleOffset(0.6);
   //   hModules[i]->GetYaxis()->SetLabelOffset(0.005);
   //   hModules[i]->GetYaxis()->SetLabelSize(.04);
   
   hModules[i]->Draw(options);
   gPad->Update();
   TPaveStats* st = (TPaveStats*) hModules[i]->GetListOfFunctions()->FindObject("stats");
   st->SetX1NDC(startingX);
   st->SetX2NDC(startingX+0.20);
   st->SetY1NDC(startingY);
   st->SetY2NDC(startingY+0.15);
   st->SetTextColor(colors[i]);
   st->SetLineColor(colors[i]);
   st->SetLineWidth(2);
   gPad->Update();

   startingY = startingY-0.15;

   legModulesTot->AddEntry(hModules[i],label[i],"f");
 }
 hModules[0]->Draw("histosame");
 legModulesTot->Draw("same");

 drawCMSsimulation();
 
 canModulesTot->SaveAs("pathTotal.png");
 canModulesTot->SaveAs("pathTotal.pdf");

}



void allTrackingHLTrun() 
{

  init();

 std::vector<TH1F*> hModules;

 std::cout << "nFiles: " << filename.size() << std::endl;
 double hModules_ymax = 0.;
 for ( size_t i=0; i<filename.size(); i++ ) {
   TH1F* histo = NULL;
   TFile* f = new TFile(filename[i]);
   if (f == NULL) continue;

   TString hname = hModulesName;
   histo = (TH1F*)f->Get(hname);
   if (histo==NULL) continue;
   histo->SetName("modules_"+sel[i]);
   histo->SetLineColor(colors[i]);
   histo->SetLineWidth(3);
   histo->SetFillColor(colors[i]);
   if (i==0)
     histo->SetFillStyle(0);
   else
     histo->SetFillStyle(3001);
   histo->GetYaxis()->SetTitle("total processing time [ms]");
   histo->GetYaxis()->SetNdivisions(305);
   histo->GetYaxis()->SetLabelSize(0.05);   
   histo->GetYaxis()->SetLabelOffset(0.008);   
   histo->GetYaxis()->SetTitleOffset(0.65);   
   histo->GetYaxis()->SetTitleSize(0.05);
   histo->GetXaxis()->SetTitle("");
   //   histo->GetXaxis()->SetLabelOffset(10.);
   //   histo->GetXaxis()->SetTitleSize(0.08);
   //   histo->GetXaxis()->SetLabelOffset(10.);
   //   histo->GetXaxis()->SetTitleOffset(.5);
   histo->GetYaxis()->SetLabelSize(.04);
   //double integral = histo->Integral(71.,98.);
   //   histo->Scale(1000./integral);
   hModules.push_back(histo);
   
   double maxRun = histo->GetMaximum();
   hModules_ymax = (maxRun > hModules_ymax ? maxRun : hModules_ymax);

 }

 TString options = "";
 double startingX = 0.75;
 double startingY = 0.80;

 size_t nbinsRun = hModules[0]->GetNbinsX();
 double xminRun = -1.;
 double xmaxRun = hModules[0]->GetXaxis()->GetXmax();

 TCanvas * canModulesRun = new TCanvas("canModulesRun","canModulesRun",1800,900);
 TGaxis::SetMaxDigits(3);
 canModulesRun->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPadRightMargin(0.07);
 gStyle->SetPadLeftMargin(0.07);

 options = "histo";
 TLegend* legModulesRun = new TLegend(0.49,0.60,0.65,0.85);
 legModulesRun->SetTextSize(0.04);
 legModulesRun->SetFillColor(0);
 legModulesRun->SetLineColor(0);
 
 for ( size_t i=0; i<hModules.size(); i++ ) {
   if (i!=0) options = "histosame";
   hModules[i]->GetYaxis()->SetRangeUser(0.,hModules_ymax*1.1);

   hModules[i]->Draw(options);
   legModulesRun->AddEntry(hModules[i],label[i],"f");
 }
 hModules[0]->Draw("histosame");
 legModulesRun->Draw("same");

// drawText("pixelTracks",   0.11,0.85,0.04);
// drawText("iter0",         0.28,0.32,0.04);
// drawText("iter1",         0.48,0.48,0.04);
// drawText("iter2",         0.76,0.38,0.04);
 // drawText("pixelRecovery", 0.78,0.43,0.04);
 // drawText("iter3",      0.70,0.23,0.04);
 // drawText("iter4",      0.88,0.38,0.04);

 // drawPU();

 /*
 pad1->cd();
 const TArrayD* binsRun = hModules[0]->GetXaxis()->GetXbins();
 double yminRun_ratio =  0.01;
 double ymaxRun_ratio =  2.;
 options = "AP";
 std::cout << "hModules: " << hModules.size() << std::endl;
 for (size_t i=1; i<hModules.size(); i++) {
   if (i!=1) options = "Psame";
   std::cout << "ratio wrt " << sel[i] << std::endl;
   TEfficiency* ratio = new TEfficiency("ratio_"+sel[i],"ratio_"+sel[i],nbinsRun,binsRun->GetArray());
   ratio->SetTotalHistogram(*hModules[0],"f");
   ratio->SetPassedHistogram(*hModules[i],"f");
   ratio->SetStatisticOption(TEfficiency::kFWilson);
   ratio->Draw(options);

   pad2->Update();

   ratio->SetLineColor(colors[i]);
   ratio->SetMarkerColor(colors[i]);
   ratio->SetMarkerStyle(20);
   ratio->SetMarkerSize(1.3);
   ratio->GetPaintedGraph()->GetXaxis()->SetLimits(xminRun,xmaxRun);
   ratio->GetPaintedGraph()->SetMinimum( yminRun_ratio);
   ratio->GetPaintedGraph()->SetMaximum( ymaxRun_ratio);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitle("ratio");
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.15);
   ratio->GetPaintedGraph()->GetYaxis()->SetNdivisions(305);
   ratio->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.2);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelOffset(0.01);
   ratio->GetPaintedGraph()->GetYaxis()->SetLabelSize(.1);

   TLine* line = new TLine(70.,1.,124.,1.);
   line->SetLineColor(kGray);
   line->SetLineWidth(3);
   line->Draw("same");
 }
 */

 drawCMSsimulation();

 canModulesRun->SaveAs("allTrackingHLTrun.png");
 //canModulesRun->SaveAs("allTrackingHLTrun.pdf");

}


void timingPlot() {
  trackingByModule("GeneralTracks");
  pathByModule();
}
