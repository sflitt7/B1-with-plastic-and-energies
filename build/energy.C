void r(){

	TFile *b1 = new TFile("~/opt/B1/build/B1.root");
	TH2F *h1 = (TH2F*)b1->Get("ECom");
	h1->SetFillColor(8);

	TFile *b2 = new TFile("~/opt/B1/build/B1e.root");
	TH2F *h2 = (TH2F*)b2->Get("ECom");
	h2->SetFillColor(9);

	TFile *b3 = new TFile("~/opt/B1/build/B1m.root");
	TH2F *h3 = (TH2F*)b3->Get("ECom");
	h3->SetFillColor(2);

	TFile *b4 = new TFile("~/opt/B1/build/B1g.root");
	TH2F *h4 = (TH2F*)b4->Get("ECom");
	h4->SetFillColor(6);

	THStack *hs = new THStack();
	hs->Add(h1);
	hs->Add(h2);
	hs->Add(h3);
	hs->Add(h4);

	hs->Draw("lego1");

//	TH2F* h1temp = new TH2F("","",110,0,500,110,0,25);
//	TH2F* h2temp = new TH2F("","",110,0,500,110,0,25);
//	TH2F* h = new TH2F("","",110,0,500,110,0,25);


//	h1temp->Add(h1,h2);
//	h2temp->Add(h1temp,h3);
//	h->Add(h2temp,h4);

//	h->GetXaxis()->SetTitle("E");
//	h->GetYaxis()->SetTitle("dE");

//	h->Draw();
}
