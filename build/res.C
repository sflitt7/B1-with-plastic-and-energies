void r(){

	TFile *b1 = new TFile("~/opt/B1/build/B1.root");
	TH1F *h = (TH1F*)b1->Get("E");

	h->GetXaxis()->SetTitle("Energy");
	h->GetYaxis()->SetTitle("Counts");

	h->Draw();

//FWHM (using Laura's to follow)
//Finding half max y value
	Double_t mostpop = h->GetMaximumBin();
	Double_t maxY = h->GetBinContent(mostpop);
	Double_t halfmaxY = maxY/2;
//now have the half max y value

//Finding half max y value bin on left side (looking for x location)
	Double_t FWHMLeftXV = 0;
	int binA = 0;

//Searches for the bin in range of bin 0 to mostpop
	h->GetBinWithContent(halfmaxY,binA,0,mostpop,0);

//if statement for if no bin was found with half max y value
	if (binA == 0){
		//Finding first bin on left with half max y value
		Double_t Lower2 = h->FindFirstBinAbove(halfmaxY,1,0,mostpop);
		Double_t Lower2cont = h->GetBinContent(Lower2);

		//Finding bin below half max y value on left
		Double_t Lower1 = Lower2 - 1;
		Double_t Lower1cont = h->GetBinContent(Lower1);
	
		//Finding an approximation for the bin x value with half max y value on left
		Double_t LowBinFrac = Lower1cont/Lower2cont;
		Double_t CenterLow1 = h->GetBinCenter(Lower1);
		Double_t CenterLow2 = h->GetBinCenter(Lower2);
		Double_t LowerBinWidth = CenterLow2 - CenterLow1;
		FWHMLeftXV = CenterLow1 + (LowerBinWidth)*(LowBinFrac);
	}

	//else statement for if there is a bin with half max y value content
	else if (binA != 0){
		FWHMLeftXV = h->GetBinCenter(binA);

}

//Finding the half max y value bin on right side
	Double_t FWHMRightXV = 0;
	int binB = 0;

//Searches
	h->GetBinWithContent(halfmaxY,binB,0,500,0);

	if (binB == 0){
		Double_t Upper2 = h->FindFirstBinAbove(halfmaxY,1,mostpop,600);
		Double_t Upper2cont = h->GetBinContent(Upper2);

		Double_t Upper1 = Upper2 - 1;
		Double_t Upper1cont = h->GetBinContent(Upper1);
	
		Double_t UpBinFrac = Upper1cont/Upper2cont;
		Double_t CenterUp1 = h->GetBinCenter(Upper1);
		Double_t CenterUp2 = h->GetBinCenter(Upper2);
		Double_t UpperBinWidth = CenterUp2 - CenterUp1;
		FWHMRightXV = CenterUp1 + (UpperBinWidth)*(UpBinFrac);
	}
	else if (binB != 0){
		FWHMRightXV = h->GetBinCenter(binB);
	}

	Double_t FWHM = FWHMRightXV - FWHMLeftXV;
	cout<<"FWHM: "<< FWHM<<endl;
	}


