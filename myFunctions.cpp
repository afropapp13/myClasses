#include "TMath.h"
#include <TH1D.h>
#include <TH2D.h>
#include <TMatrixD.h>
#include <TVectorD.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

#include "Constants.h"

using namespace std;
using namespace Constants;

//----------------------------------------//

vector<int> get_3d_bin_break_points( vector< vector< vector<double> > > bins) {  

	// main number of slices
	int nslices = bins.size();
	vector<int> bin_break_points;
	int break_bin = 0;

	for (int islice = 0; islice < nslices; islice++) {

		// number of subslices
		int nsub = bins.at(islice).size();

		for (int isub = 0; isub < nsub; isub++) {
		
			// number of sub-subslices
			int nsubsub = bins.at(islice).at(isub).size();

			for (int isubsub = 0; isubsub < nsubsub; isubsub++) {

				if (isubsub == nsubsub-1) { 

					// store the breaking point bin
					bin_break_points.push_back(break_bin);
					// increase the counter bc we are moving to the next slice
					break_bin--; 

				}

				break_bin++;

			}

		}

	}

	//cout << "bin_break_points.size() = " << bin_break_points.size() << endl;
	//for(auto bin:bin_break_points) { cout << bin << " " << endl; }
	
	return bin_break_points;
 
}
//----------------------------------------//

void bin_number_x_title(TH2D* h) {

	TString hname = h->GetName();
	if (string(hname).find("Serial") != std::string::npos) {	

		TString axis_title = h->GetXaxis()->GetTitle();
		axis_title.ReplaceAll("deg","bin #");
		axis_title.ReplaceAll("(GeV/c)","bin #");
		axis_title.ReplaceAll("GeV","bin #");				
		h->GetXaxis()->SetTitle(axis_title);

	}

}

//----------------------------------------//

void bin_number_y_title(TH2D* h) {

	TString hname = h->GetName();
	if (string(hname).find("Serial") != std::string::npos) {	

		TString axis_title = h->GetYaxis()->GetTitle();
		axis_title.ReplaceAll("deg","bin #");
		axis_title.ReplaceAll("(GeV/c)","bin #");
		axis_title.ReplaceAll("GeV","bin #");				
		h->GetYaxis()->SetTitle(axis_title);

	}

}
//----------------------------------------//

void bin_number_x_title(TH1D* h) {

	TString hname = h->GetName();
	if (string(hname).find("Serial") != std::string::npos) {	

		TString axis_title = h->GetXaxis()->GetTitle();
		axis_title.ReplaceAll("deg","bin #");
		axis_title.ReplaceAll("(GeV/c)","bin #");
		axis_title.ReplaceAll("GeV","bin #");				
		h->GetXaxis()->SetTitle(axis_title);

	}

}
//----------------------------------------//

void TV2TH(const TVectorD vec, TH1D* histo)
{
    // Fill vector to histogram,
    for(Int_t i=0; i<vec.GetNrows(); i++)
    {
        histo->SetBinContent(i+1, vec(i));
    }
}

//----------------------------------------//

void TH2TM(const TH2D* histo, TMatrixD& mat, bool rowcolumn) {

    // Fill 2D histogram into matrix
    // If TH2D(i, j) = Matrix(i, j), rowcolumn = kTRUE, else rowcolumn = kFALSE

    for (Int_t i=0; i<histo->GetNbinsX(); i++) {

        for (Int_t j=0; j<histo->GetNbinsY(); j++) {

            if (rowcolumn) { mat(i, j) = histo->GetBinContent(i+1, j+1); }
            else { mat(j, i) = histo->GetBinContent(i+1, j+1); }

        }

    }

}

//----------------------------------------//

void TH2TV(const TH1D* histo, TVectorD& vec)
{
    // Fill 1D histogram into matrix
    for(Int_t i=0; i<histo->GetNbinsX(); i++)
    {
        vec(i) = histo->GetBinContent(i+1);
    }
}
//----------------------------------------//                                                                                               

TH1D* Multiply(TH1D* True, TH2D* SmearMatrix) {

  TH1D* TrueClone = (TH1D*)(True->Clone());

  int XBins = SmearMatrix->GetXaxis()->GetNbins();
  int YBins = SmearMatrix->GetYaxis()->GetNbins();

  if (XBins != YBins) { std::cout << "Not symmetric matrix" << std::endl; }

  TVectorD signal(XBins);
  TMatrixD response(XBins,XBins);

  TH2TV(TrueClone, signal);
  TH2TM(SmearMatrix, response, kTRUE);

  TVectorD RecoSpace = response * signal;
  TV2TH(RecoSpace, TrueClone);

  return TrueClone;

}

//----------------------------------------//

int LocateBinWithValue(TH1D* h, double Value) {

  int NBins = h->GetXaxis()->GetNbins();

  for (int i = 1; i <= NBins; i++) {

    double CurrentEntry = h->GetBinContent(i);
    if (CurrentEntry == Value) { return i; } 

  }

  return -99;

}

//----------------------------------------//                                                                                                

void PrettyPlot(TH1D* h) {

  h->GetXaxis()->SetLabelFont(FontStyle);
  h->GetXaxis()->SetTitleFont(FontStyle);
  h->GetXaxis()->SetTitleSize(0.06);
  h->GetXaxis()->SetLabelSize(0.06);
  h->GetXaxis()->SetTitleOffset(1.05);
  h->GetXaxis()->SetNdivisions(8);


  h->GetYaxis()->SetLabelFont(FontStyle);
  h->GetYaxis()->SetTitleFont(FontStyle);
  h->GetYaxis()->SetNdivisions(8);
  h->GetYaxis()->SetTitleOffset(1.35);
  h->GetYaxis()->SetTitleSize(0.06);
  h->GetYaxis()->SetLabelSize(0.06);
}

//----------------------------------------//

double FindOneDimHistoMaxValue(TH1D* h){

	int NBins = h->GetXaxis()->GetNbins();
	double HistoMax = -999.;	
	int bin_max = -1;

	for (int ibin = 1; ibin<= NBins; ibin++) {

		double LocalMax = h->GetBinContent(ibin);
		if (LocalMax > HistoMax) { HistoMax = LocalMax; bin_max = ibin; }

	}

	return HistoMax;

}

//----------------------------------------//

//Function to multiply by the bin width
void rm_bin_width(TH1D* h, double SF = 1.) {

  int NBins = h->GetXaxis()->GetNbins();

  for (int i = 0; i < NBins; i++) {

    double CurrentEntry = h->GetBinContent(i+1);
    double NewEntry = SF * CurrentEntry * h->GetBinWidth(i+1);

    double CurrentError = h->GetBinError(i+1);
    double NewError = SF * CurrentError * h->GetBinWidth(i+1);

    h->SetBinContent(i+1,NewEntry); 
    h->SetBinError(i+1,NewError); 
    //h->SetBinError(i+1,0.000001); 

  }

}

//----------------------------------------//

//Function to divide by the bin width and to get xsecs
void Reweight(TH1D* h, double SF = 1.) {

  int NBins = h->GetXaxis()->GetNbins();

  for (int i = 0; i < NBins; i++) {

    double CurrentEntry = h->GetBinContent(i+1);
    double NewEntry = SF * CurrentEntry / h->GetBinWidth(i+1);

    double CurrentError = h->GetBinError(i+1);
    double NewError = SF * CurrentError / h->GetBinWidth(i+1);

    h->SetBinContent(i+1,NewEntry); 
    h->SetBinError(i+1,NewError); 
    //h->SetBinError(i+1,0.000001); 

  }

}//----------------------------------------//

double FindOneDimHistoMaxValueBin(TH1D* h){

	int NBins = h->GetXaxis()->GetNbins();
	double HistoMax = -999.;	
	int bin_max = -1;

	for (int ibin = 1; ibin<= NBins; ibin++) {

		double LocalMax = h->GetBinContent(ibin);
		if (LocalMax > HistoMax) { HistoMax = LocalMax; bin_max = ibin; }

	}

	double bin_center_max = h->GetBinCenter(bin_max);

	return bin_center_max;

}//----------------------------------------//

double FindTwoDimHistoMaxValue(TH2D* h){

	int NXBins = h->GetXaxis()->GetNbins();
	int NYBins = h->GetYaxis()->GetNbins();	
	double StartHistoMax = -9999.;
	double HistoMax = StartHistoMax;	

	for (int xbin = 1; xbin <= NXBins; xbin++) {

		for (int ybin = 1; ybin <= NYBins; ybin++) {		

			double LocalMax = h->GetBinContent(xbin,ybin);
			if (LocalMax > HistoMax && !isinf(LocalMax) ) { HistoMax = LocalMax; }

		}

	}

	if (HistoMax == StartHistoMax) { cout << "HistoMax = " << HistoMax << endl; }

	return HistoMax;

}

//----------------------------------------//

double FindTwoDimHistoMinValue(TH2D* h){

	int NXBins = h->GetXaxis()->GetNbins();
	int NYBins = h->GetYaxis()->GetNbins();	
	double StartHistoMin = 999999.;
	double HistoMin = StartHistoMin;	

	for (int xbin = 1; xbin<= NXBins; xbin++) {

		for (int ybin = 1; ybin<= NYBins; ybin++) {		

			double LocalMin = h->GetBinContent(xbin,ybin);
			if (LocalMin < HistoMin) { HistoMin = LocalMin; }

		}

	}

	if (HistoMin == StartHistoMin) { cout << "HistoMin = " << HistoMin << endl; }
	return HistoMin;

}

//----------------------------------------//

TString to_string_with_precision(double a_value, const int n = 1)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return TString(out.str());
}

//----------------------------------------//

void CalcChiSquared(TH1D* h_model, TH1D* h_data, TH2D* cov, double &chi, int &ndof, double &pval, double &sigma) {

	// Clone them so we can scale them 

	TH1D* h_model_clone = (TH1D*)h_model->Clone();
	TH1D* h_data_clone  = (TH1D*)h_data->Clone();
	TH2D* h_cov_clone   = (TH2D*)cov->Clone();
	int NBins = h_cov_clone->GetNbinsX();

	// Getting covariance matrix in TMatrix form

	TMatrixD cov_m;
	cov_m.Clear();
	cov_m.ResizeTo(NBins,NBins);

	// loop over rows

	for (int i = 0; i < NBins; i++) {			

		// loop over columns

		for (int j = 0; j < NBins; j++) {

			cov_m[i][j] = h_cov_clone->GetBinContent(i+1, j+1);
 
		}
	
	}

	TMatrixD copy_cov_m = cov_m;

	// Inverting the covariance matrix
	//TMatrixD inverse_cov_m = cov_m.Invert();

  	TMatrixD inverse_cov_m = cov_m;

	TDecompSVD svd(cov_m);
	inverse_cov_m = TMatrixDSym(cov_m.GetNrows(), svd.Invert().GetMatrixArray());

	// Calculating the chi2 = Summation_ij{ (x_i - mu_j)*E_ij^(-1)*(x_j - mu_j)  }
	// x = data, mu = model, E^(-1) = inverted covariance matrix 

	chi = 0.;
	
	for (int i = 0; i < NBins; i++) {

		//double XWidth = h_data_clone->GetBinWidth(i+1);

		for (int j = 0; j < NBins; j++) {

			//double YWidth = h_data_clone->GetBinWidth(i+1);

			double diffi = h_data_clone->GetBinContent(i+1) - h_model_clone->GetBinContent(i+1);
			double diffj = h_data_clone->GetBinContent(j+1) - h_model_clone->GetBinContent(j+1);
			double LocalChi = diffi * inverse_cov_m[i][j] * diffj; 
			chi += LocalChi;
		}

	}

	ndof = h_data_clone->GetNbinsX();
	pval = (chi/ndof < 1 && TMath::Prob(chi, ndof) < 0.5) ? TMath::Prob(chi, ndof) : 1 - TMath::Prob(chi, ndof);
        sigma = TMath::Sqrt( TMath::ChisquareQuantile( 1-pval, 1 ) );

	delete h_model_clone;
	delete h_data_clone;
	delete h_cov_clone;

}

//----------------------------------------//

double PeLEE_ReturnBeamOnRunPOT(TString Run) {

	double DataPOT = -99.;

	if (Run == "Run1") { DataPOT = Fulltor860_wcut_Run1 ; }
	if (Run == "Run1A_open_trigger") { DataPOT = Fulltor860_wcut_Run1A_open_trigger ; }
	if (Run == "Run1B_open_trigger") { DataPOT = Fulltor860_wcut_Run1B_open_trigger ; }
	if (Run == "Run2") { DataPOT = Fulltor860_wcut_Run2 ; }
	if (Run == "Run3") { DataPOT = Fulltor860_wcut_Run3 ; }
	if (Run == "Run4a") { DataPOT = Fulltor860_wcut_Run4a ; }
	if (Run == "Run4b") { DataPOT = Fulltor860_wcut_Run4b ; }
	if (Run == "Run4c") { DataPOT = Fulltor860_wcut_Run4c ; }	
	if (Run == "Run4d") { DataPOT = Fulltor860_wcut_Run4d ; }		
	if (Run == "Run5") { DataPOT = Fulltor860_wcut_Run5 ; }
	if (Run == "Combined") { DataPOT = Fulltor860_wcut_Combined ; }

	return DataPOT;

}

//----------------------------------------//

double round(double var,int acc = 0) 
{ 
    double value = (int)(var * TMath::Power(10.,acc) + .5); 
    return (double)value / TMath::Power(10.,acc); 
} 

//----------------------------------------//

TString ToString(double num) {

	std::ostringstream start;
	start << num;
	string start1 = start.str();
	return start1;

}

// --------------------------------------------------------------------------------------------------------------------------------------------


