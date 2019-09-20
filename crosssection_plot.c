#include <TCanvas.h>
#include <TFile.h>
void crosssection_plot()
{
	THStack *hs = new THStack("hs","");

	TH1F* h1 = new TH1F("hist1","C_{g}=1",4,0,8);
	h1 -> GetXaxis() -> SetLabelSize(0.8);
	h1 -> SetBinContent(1,7375);
	h1 -> GetXaxis() -> SetBinLabel(1,"gg->ALP->gg");
	h1 -> SetBinContent(2,3.242e-07);
	h1 -> GetXaxis() -> SetBinLabel(2,"gg->ALP->uu");
	h1 -> SetBinContent(3,1.026e-08);
	h1 -> GetXaxis() -> SetBinLabel(3,"uu->ALP->gg");
	h1 -> SetBinContent(4,7.586e-19);
	h1 -> GetXaxis() -> SetBinLabel(4,"uu->ALP->uu");
	h1 -> SetFillColor(kRed);
        hs -> Add(h1);

	TH1F* h2 = new TH1F("hist2","C_{g}=#frac{1}{4#pi}",4,0,8);
        h2 -> SetBinContent(1,0.2975);
        h2 -> SetBinContent(2,2.05e-09);
        h2 -> SetBinContent(3,6.507e-11);
        h2 -> SetBinContent(4,0);
	h2 -> SetFillColor(kBlue);
        hs -> Add(h2);
	
	TCanvas *c1 = new TCanvas;
        c1 -> SetLogy();

	hs -> Draw("nostackb");
	gPad->BuildLegend(0.6,0.6,0.9,0.9,"");

	TFile *file = new TFile( "Hist.root","recreate");
	file -> mkdir("general");
	file -> cd("general");
	hs -> Write();
	c1 -> SaveAs("Hist.pdf");
}
