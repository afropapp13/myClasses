#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "TString.h"
#include "TMath.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

namespace Constants {

	//----------------------------------------//

    // Kerberos user name
  
	TString UserID = "apapadop";

	//----------------------------------------//

	// constants
	// Argon 

	static const double A = 40.;
	static const double Z = 18.;

	const int FontStyle = 132;
	const double TextSize = 0.07;
	const int NCont = 999; 
	const TString CutExtension = "_NoCuts_PID_NuScore_CRT";

	// UBCodeVersion

	const TString UBCodeVersion = "v08_00_00_70";

	// FV

	double FVx = 256., FVy = 230., FVz = 1036.;
	double borderx = 10., bordery = 10., borderz = 10.;

	//----------------------------------------//

	// Exporting paths

	const TString PathToFiles = "/exp/uboone/data/users/"+UserID+"/Atmospherics/OutputFiles/"+UBCodeVersion+"/";
	const TString PathToExtractedXSec = "/exp/uboone/data/users/"+UserID+"/Atmospherics/myXSec/"+UBCodeVersion+"/"; 
	const TString FileEfficienciesPath = "/exp/uboone/data/users/"+UserID+"/Atmospherics/myEfficiencies/"+UBCodeVersion+"/";
	const TString PlotPath = "/exp/uboone/data/users/"+UserID+"/Atmospherics/myPlots/"+UBCodeVersion+"/"; 
	const TString PathToSystematics = "/exp/uboone/data/users/"+UserID+"/Atmospherics/mySystematics/"+UBCodeVersion+"/";
	const TString TrueSTVPath = PathToFiles;
	const TString MigrationMatrixPath = "/exp/uboone/data/users/"+UserID+"/Atmospherics/myMigrationMatrices/"+UBCodeVersion+"/"; 

	//----------------------------------------//

	// Zarko Pavlovic, Jun 22 2020
	// /pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_01.09.2019_463_hist/readme.txt

	double Nominal_UB_XY_Surface = 256.35*233.; // cm2
	double SoftFidSurface = 236. * 210.;  // cm2
	double POTPerSpill = 4997.*5e8;

	//----------------------------------------//

	// Labels / Ranges & Label  map
	// max values

	static std::map<TString,std::pair<double,double> > XSecRange =
	{
		{ "MuonCosThetaPlot",  std::make_pair(0, 24) },
		{ "MuonCosThetaSingleBinPlot",  std::make_pair(0, 16.9) },
		{ "ThetaVisPlot",  std::make_pair(0, 0.49) },		
		{ "CosThetaVisPlot",  std::make_pair(0, 109.) },		
		{ "PMissPlot",  std::make_pair(0, 34.) },		
		{ "ThetaVis_ECal_0_00To0_50Plot",  std::make_pair(0, 0.079) },
		{ "ThetaVis_ECal_0_50To0_80Plot",  std::make_pair(0, 0.59) },
		{ "ThetaVis_ECal_0_80To2_00Plot",  std::make_pair(0, 0.29) },
		{ "SerialThetaVis_ECalPlot",  std::make_pair(0, 1.99) },			
		{ "ThetaVis_DeltaPn_0_00To0_20Plot",  std::make_pair(0, 1.99) },
		{ "ThetaVis_DeltaPn_0_20To0_40Plot",  std::make_pair(0, 0.9) },
		{ "ThetaVis_DeltaPn_0_40To1_00Plot",  std::make_pair(0, 0.089) },
		{ "SerialThetaVis_DeltaPnPlot",  std::make_pair(0, 3.99) },		
		{ "ThetaVis_PMiss_0_00To0_10Plot",  std::make_pair(0, 2.49) },
		{ "ThetaVis_PMiss_0_10To0_20Plot",  std::make_pair(0, 1.19) },
		{ "ThetaVis_PMiss_0_20To0_50Plot",  std::make_pair(0, 0.19) },
		{ "SerialThetaVis_PMissPlot",  std::make_pair(0, 3.89) },
	};	
	
	//----------------------------------------//

	static std::map<TString,TString> VarLabel =
	{
		{ "MuonCosThetaPlot",  "#frac{d#sigma}{dcos#theta_{#mu}} #left[10^{-38} #frac{cm^{2}}{Ar}#right]" },
		{ "MuonCosThetaSingleBinPlot",  "#frac{d#sigma}{dcos#theta_{#mu}} #left[10^{-38} #frac{cm^{2}}{Ar}#right]" },
		{ "ThetaVisPlot",  "#frac{d#sigma}{d#theta_{vis}} #left[10^{-38} #frac{cm^{2}}{deg Ar}#right]" },
		{ "CosThetaVisPlot",  "#frac{d#sigma}{dcos#theta_{vis}} #left[10^{-38} #frac{cm^{2}}{Ar}#right]" },
		{ "PMissPlot",  "#frac{d#sigma}{dp_{miss}} #left[10^{-38} #frac{cm^{2}}{(GeV/#it{c}) Ar}#right]" },
		{ "ThetaVis_ECal_0_00To0_50Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dE_{reco}} #left[10^{-38} #frac{cm^{2}}{deg GeV Ar}#right]"  },
		{ "ThetaVis_ECal_0_50To0_80Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dE_{reco}} #left[10^{-38} #frac{cm^{2}}{deg GeV Ar}#right]"  },
		{ "ThetaVis_ECal_0_80To2_00Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dE_{reco}} #left[10^{-38} #frac{cm^{2}}{deg GeV Ar}#right]"  },
		{ "SerialThetaVis_ECalPlot", "#frac{d^{2}#sigma}{d#theta_{vis}dE_{reco}} #left[10^{-38} #frac{cm^{2}}{deg GeV Ar}#right]"  },			
		{ "ThetaVis_DeltaPn_0_00To0_20Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{n}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "ThetaVis_DeltaPn_0_20To0_40Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{n}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "ThetaVis_DeltaPn_0_40To1_00Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{n}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "SerialThetaVis_DeltaPnPlot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{n}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },			
		{ "ThetaVis_PMiss_0_00To0_10Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{miss}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "ThetaVis_PMiss_0_10To0_20Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{miss}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "ThetaVis_PMiss_0_20To0_50Plot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{miss}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },
		{ "SerialThetaVis_PMissPlot", "#frac{d^{2}#sigma}{d#theta_{vis}dp_{miss}} #left[10^{-38} #frac{cm^{2}}{deg (GeV/#it{c}) Ar}#right]"  },			
	
	};

	static std::map<TString,TString> LatexLabel =
	{
		{ "MuonCosThetaPlot",  " all events" },
		{ "MuonCosThetaSingleBinPlot",  " all events" },
		{ "ThetaVisPlot", " all events" },	
		{ "CosThetaVisPlot", " all events" },	
		{ "PMissPlot", " all events" },	
		{ "ThetaVis_ECal_0_00To0_50Plot", "0 < E_{reco} < 0.5 GeV"  },
		{ "ThetaVis_ECal_0_50To0_80Plot", "0.5 < E_{reco} < 0.8 GeV"  },
		{ "ThetaVis_ECal_0_80To2_00Plot", "0.8 < E_{reco} < 2 GeV"  },
		{ "SerialThetaVis_ECalPlot", " all events"  },			
		{ "ThetaVis_DeltaPn_0_00To0_20Plot", "p_{n} < 0.2 GeV/#it{c}"  },
		{ "ThetaVis_DeltaPn_0_20To0_40Plot", "0.2 < p_{n} < 0.4 GeV/#it{c}"  },
		{ "ThetaVis_DeltaPn_0_40To1_00Plot", "0.4 < p_{n} < 1 GeV/#it{c}"  },
		{ "SerialThetaVis_DeltaPnPlot", " all events"  },			
		{ "ThetaVis_PMiss_0_00To0_10Plot", "|p_{miss}| < 0.1 GeV/#it{c}"  },
		{ "ThetaVis_PMiss_0_10To0_20Plot", "0.1 < |p_{miss}| < 0.2 GeV/#it{c}"  },
		{ "ThetaVis_PMiss_0_20To0_50Plot", "0.2 < |p_{miss}| < 0.5 GeV/#it{c}"  },
		{ "SerialThetaVis_PMissPlot", " all events"  },			
	
	};	
	
	//----------------------------------------//
	
	static std::map<TString,TString> MapUncorCor =
	{

		{ "MuonCosThetaPlot", "MuonCosThetaPlot" },
		{ "MuonCosThetaSingleBinPlot", "MuonCosThetaSingleBinPlot" },
		{ "ThetaVisPlot", "ThetaVisPlot" },
		{ "CosThetaVisPlot", "CosThetaVisPlot" },
		{ "PMissPlot", "PMissPlot" },
		{ "ThetaVis_ECal_0_00To0_50Plot","ThetaVis_ECal_0_00To0_50Plot"},
		{ "ThetaVis_ECal_0_50To0_80Plot","ThetaVis_ECal_0_50To0_80Plot"},
		{ "ThetaVis_ECal_0_80To2_00Plot","ThetaVis_ECal_0_80To2_00Plot"},
		{ "SerialThetaVis_ECalPlot_0","ThetaVis_ECal_0_00To0_50Plot"},
		{ "SerialThetaVis_ECalPlot_1","ThetaVis_ECal_0_50To0_80Plot"},
		{ "SerialThetaVis_ECalPlot_2","ThetaVis_ECal_0_80To2_00Plot"},
		{ "SerialThetaVis_ECalPlot", "SerialThetaVis_ECalPlot"  },			
		{ "ThetaVis_DeltaPn_0_00To0_20Plot","ThetaVis_DeltaPn_0_00To0_20Plot"},
		{ "ThetaVis_DeltaPn_0_20To0_40Plot","ThetaVis_DeltaPn_0_20To0_40Plot"},
		{ "ThetaVis_DeltaPn_0_40To1_00Plot","ThetaVis_DeltaPn_0_40To1_00Plot"},
		{ "SerialThetaVis_DeltaPnPlot_0","ThetaVis_DeltaPn_0_00To0_20Plot"},
		{ "SerialThetaVis_DeltaPnPlot_1","ThetaVis_DeltaPn_0_20To0_40Plot"},
		{ "SerialThetaVis_DeltaPnPlot_2","ThetaVis_DeltaPn_0_40To1_00Plot"},
		{ "SerialThetaVis_DeltaPnPlot", "SerialThetaVis_DeltaPnPlot"  },			
		{ "ThetaVis_PMiss_0_00To0_10Plot","ThetaVis_PMiss_0_00To0_10Plot"},
		{ "ThetaVis_PMiss_0_10To0_20Plot","ThetaVis_PMiss_0_10To0_20Plot"},
		{ "ThetaVis_PMiss_0_20To0_50Plot","ThetaVis_PMiss_0_20To0_50Plot"},
		{ "SerialThetaVis_PMissPlot", "SerialThetaVis_PMissPlot"  },	
		{ "SerialThetaVis_PMissPlot_0","ThetaVis_PMiss_0_00To0_10Plot"},
		{ "SerialThetaVis_PMissPlot_1","ThetaVis_PMiss_0_10To0_20Plot"},
		{ "SerialThetaVis_PMissPlot_2","ThetaVis_PMiss_0_20To0_50Plot"},
		{ "SerialThetaVis_PMissPlot", "SerialThetaVis_PMissPlot"  },			
	
	};
					
	// -------------------------------------------------------------------------------------------------------------------------

	// Global Constants

	static const double Units = 1E38; // so that the extracted cross-section is in 10^{-38} cm^{2}
	static const double NTargets = 1.05E30; // Argon nuclei, not nucleons
	
	static const int NuMuPdg = 14, MuonPdg = 13, ProtonPdg = 2212, AbsChargedPionPdg = 211, NeutralPionPdg = 111;
	static const int ElectronPdg = 11, PhotonPdg = 22, NeutronPdg = 2112, KaonPdg = 321;
	static const int DeuteriumPdg = 1000010020, HeliumPdg = 1000020040, ArgonPdg = 1000180400;

	static const double MuonMass = 106, ProtonMass = 938.272, NeutronMass = 939.565; // MeV
	static const double MuonMass_GeV = 0.106, ProtonMass_GeV = 0.938272, NeutronMass_GeV = 0.939565; // GeV
	static const double DeltaM2 = TMath::Power(NeutronMass_GeV,2.) - TMath::Power(ProtonMass_GeV,2.); // GeV^2	

	// -------------------------------------------------------------------------------------------------------------------------

	// Plots to be included for xsec extraction purposes

	vector<TString> PlotNames{
				 "MuonCosThetaPlot"
				 ,"MuonCosThetaSingleBinPlot"
				 ,"ThetaVisPlot"
				 ,"CosThetaVisPlot"
				 ,"PMissPlot"
				 ,"ThetaVis_ECal_0_00To0_50Plot"
				 ,"ThetaVis_ECal_0_50To0_80Plot"
				 ,"ThetaVis_ECal_0_80To2_00Plot"
				 ,"SerialThetaVis_ECalPlot"			
				 ,"ThetaVis_DeltaPn_0_00To0_20Plot"
				 ,"ThetaVis_DeltaPn_0_20To0_40Plot"
				 ,"ThetaVis_DeltaPn_0_40To1_00Plot"
				 ,"SerialThetaVis_DeltaPnPlot"			
				 ,"ThetaVis_PMiss_0_00To0_10Plot"
				 ,"ThetaVis_PMiss_0_10To0_20Plot"
				 ,"ThetaVis_PMiss_0_20To0_50Plot"
				 ,"SerialThetaVis_PMissPlot"			
			 };
	
	//----------------------------------------//
	
	vector<TString> OneDimXSec = {
				  // 1D
				  "MuonCosThetaPlot"
				 ,"MuonCosThetaSingleBinPlot"
				 ,"ThetaVisPlot"
				 ,"CosThetaVisPlot"
				 ,"PMissPlot"
				 ,"ThetaVis_ECal_0_00To0_50Plot"
				 ,"ThetaVis_ECal_0_50To0_80Plot"
				 ,"ThetaVis_ECal_0_80To2_00Plot"
				 ,"SerialThetaVis_ECalPlot"			
				 ,"ThetaVis_DeltaPn_0_00To0_20Plot"
				 ,"ThetaVis_DeltaPn_0_20To0_40Plot"
				 ,"ThetaVis_DeltaPn_0_40To1_00Plot"
				 ,"SerialThetaVis_DeltaPnPlot"			
				 ,"ThetaVis_PMiss_0_00To0_10Plot"
				 ,"ThetaVis_PMiss_0_10To0_20Plot"
				 ,"ThetaVis_PMiss_0_20To0_50Plot"
				 ,"SerialThetaVis_PMissPlot"			
				 				 
			};	
	
	//----------------------------------------//
	
	vector<TString> MultiDimXSec = {
				  "MuonCosThetaPlot"
				 ,"MuonCosThetaSingleBinPlot"
				 ,"ThetaVisPlot"
				 ,"CosThetaVisPlot"
				 ,"PMissPlot"
				 ,"ThetaVis_ECal_0_00To0_50Plot"
				 ,"ThetaVis_ECal_0_50To0_80Plot"
				 ,"ThetaVis_ECal_0_80To2_00Plot"
				 ,"SerialThetaVis_ECalPlot"			
				 ,"ThetaVis_DeltaPn_0_00To0_20Plot"
				 ,"ThetaVis_DeltaPn_0_20To0_40Plot"
				 ,"ThetaVis_DeltaPn_0_40To1_00Plot"
				 ,"SerialThetaVis_DeltaPnPlot"			
				 ,"ThetaVis_PMiss_0_00To0_10Plot"
				 ,"ThetaVis_PMiss_0_10To0_20Plot"
				 ,"ThetaVis_PMiss_0_20To0_50Plot"
				 ,"SerialThetaVis_PMissPlot"			
	};	

	// --------------------------------------------------------------------------------------------------------------------------

	// POT Normalization & Runs
	// Add 4a ???

//	vector<TString> Runs{"Run1"};
	vector<TString> Runs{"Run1","Run2","Run3","Run4b","Run4c","Run4d","Run5","Combined"};

	vector<TString> xsec_Runs{"Run4b_unified"};	
	//vector<TString> xsec_Runs{"Run4b_standalone","Run4b_unified"};	

	// ------------------------------------ //

	// Run 1 

	static const double tor860_wcut_Run1 = 4.566e+19;
	static const double E1DCNT_wcut_Run1 = 10127594.0;
	static const double EXT_Run1 = 32514217.0;

	static const double Fulltor860_wcut_Run1 = 1.67e20;
	static const double FullE1DCNT_wcut_Run1 = 37273255.0;
	static const double FullEXT_Run1 = 65744587.0;
	
	// ------------------------------------ //

	// Run 1A Open Trigger 

	static const double tor860_wcut_Run1A_open_trigger = 5.885e+19;
	static const double E1DCNT_wcut_Run1A_open_trigger = 15639842.0;
	static const double EXT_Run1A_open_trigger = 65744587.0;

	static const double Fulltor860_wcut_Run1A_open_trigger = 5.885e+19;
	static const double FullE1DCNT_wcut_Run1A_open_trigger = 15639842.0;
	static const double FullEXT_Run1A_open_trigger = 65744587.0;
	
	// ------------------------------------ //

	// Run 1B Open Trigger 

	static const double tor860_wcut_Run1B_open_trigger = 8.932e+19;
	static const double E1DCNT_wcut_Run1B_open_trigger = 19789737.0;
	static const double EXT_Run1B_open_trigger = 65744587.0;

	static const double Fulltor860_wcut_Run1B_open_trigger = 8.932e+19;
	static const double FullE1DCNT_wcut_Run1B_open_trigger = 19789737.0;
	static const double FullEXT_Run1B_open_trigger = 65744587.0;
	
	// ------------------------------------ //	
	
	// Run 2 

	static const double tor860_wcut_Run2 = 0.;
	static const double E1DCNT_wcut_Run2 = 0.;
	static const double EXT_Run2 = 1.;

	static const double Fulltor860_wcut_Run2 = 2.61e20;
	static const double FullE1DCNT_wcut_Run2 = 61882791.0;
	static const double FullEXT_Run2 = 153905891.0;
	
	// ------------------------------------ //	
	
	// Run 3 

	static const double tor860_wcut_Run3 = 9.513e+18;
	static const double E1DCNT_wcut_Run3 = 2299517.0;
	static const double EXT_Run3 = 131356320.0;

	static const double Fulltor860_wcut_Run3 = 2.57e20;
	static const double FullE1DCNT_wcut_Run3 = 61326657.0;
	static const double FullEXT_Run3 = 207224641.0;
	
	// ------------------------------------ //	
	
	// Run 4a 

	static const double tor860_wcut_Run4a = 0.;
	static const double E1DCNT_wcut_Run4a = 0.;
	static const double EXT_Run4a = 1.;

	static const double Fulltor860_wcut_Run4a = 4.5e19;
	static const double FullE1DCNT_wcut_Run4a = 9897624.;
	static const double FullEXT_Run4a = 27596585.;	

	// ------------------------------------ //	
	
	// Run 4b 

	static const double tor860_wcut_Run4b = 0.;
	static const double E1DCNT_wcut_Run4b = 0.;
	static const double EXT_Run4b = 1.;

	static const double Fulltor860_wcut_Run4b = 1.36e20;
	static const double FullE1DCNT_wcut_Run4b = 32305463.0;
	static const double FullEXT_Run4b = 89244940.0;	

	// ------------------------------------ //	
	
	// mcc9_10 Run 4b standalone

	static const double tor860_wcut_mcc9_10_Run4b_standalone = 0.;
	static const double E1DCNT_wcut_mcc9_10_Run4b_standalone = 0.;
	static const double EXT_mcc9_10_Run4b_standalone = 1.;

	// good run list applied
	// produced by production team
	//static const double Fulltor860_wcut_mcc9_10_Run4b_standalone = 3.92e+19;
	//static const double FullE1DCNT_wcut_mcc9_10_Run4b_standalone = 9515547.0;
	//static const double FullEXT_mcc9_10_Run4b_standalone = 27868945.0;	

	//// good run list applied and rse matched
	//// Afro filtered it so proceed with caution
	static const double Fulltor860_wcut_mcc9_10_Run4b_standalone = 3.776e+19;
	static const double FullE1DCNT_wcut_mcc9_10_Run4b_standalone = 9176822.0;
	static const double FullEXT_mcc9_10_Run4b_standalone = 27868945.0;		

	// ------------------------------------ //	
	
	// mcc9_10 Run 4b unified

	static const double tor860_wcut_mcc9_10_Run4b_unified = 0.;
	static const double E1DCNT_wcut_mcc9_10_Run4b_unified = 0.;
	static const double EXT_mcc9_10_Run4b_unified = 1.;

	// CM Indiana May 13 2025
	static const double Fulltor860_wcut_mcc9_10_Run4b_unified = 1.2e20;
	static const double FullE1DCNT_wcut_mcc9_10_Run4b_unified = 28396891;
	static const double FullEXT_mcc9_10_Run4b_unified = 46393391;

	// //Erin filtered them and added her vars and good run list applied
	//static const double Fulltor860_wcut_mcc9_10_Run4b_unified = 4.28e19;
	//static const double FullE1DCNT_wcut_mcc9_10_Run4b_unified = 10398793.;
	//static const double FullEXT_mcc9_10_Run4b_unified = 28964045.;	
	
	//// Afro rse's the WC processed files from Erin
	//static const double Fulltor860_wcut_mcc9_10_Run4b_unified = 3.776e+19;
	//static const double FullE1DCNT_wcut_mcc9_10_Run4b_unified = 9176822.0;
	//static const double FullEXT_mcc9_10_Run4b_unified = 28964045.;	

	//static const double Fulltor860_wcut_mcc9_10_Run4b_unified = 3.776e+19;
	//static const double FullE1DCNT_wcut_mcc9_10_Run4b_unified = 9176822.0;
	//static const double FullEXT_mcc9_10_Run4b_unified = 28964045.;	

	// ------------------------------------ //
		
	// Run 4c

	static const double tor860_wcut_Run4c = 0.;
	static const double E1DCNT_wcut_Run4c = 0.;
	static const double EXT_Run4c = 1.;

	static const double Fulltor860_wcut_Run4c = 8.95e19;
	static const double FullE1DCNT_wcut_Run4c = 20273291.0;
	static const double FullEXT_Run4c = 47178301.0;	

	// ------------------------------------ //
		
	// Run 4d 

	static const double tor860_wcut_Run4d = 0.;
	static const double E1DCNT_wcut_Run4d = 0.;
	static const double EXT_Run4d = 1.;

	static const double Fulltor860_wcut_Run4d = 4.93e19;
	static const double FullE1DCNT_wcut_Run4d = 11192660.0;
	static const double FullEXT_Run4d = 74409530.0;	

	// ------------------------------------ //
		
	// Run 5 

	static const double tor860_wcut_Run5 = 0.;
	static const double E1DCNT_wcut_Run5 = 0.;
	static const double EXT_Run5 = 1.;

	static const double Fulltor860_wcut_Run5 = 1.48e20;
	static const double FullE1DCNT_wcut_Run5 = 35265730.0;
	static const double FullEXT_Run5 = 107466402.0;	

	// ------------------------------------ //	
	
	// Combined POT

	static const double Fulltor860_wcut_Run1all = Fulltor860_wcut_Run1 + Fulltor860_wcut_Run1A_open_trigger + Fulltor860_wcut_Run1B_open_trigger;	
	static const double Fulltor860_wcut_Run4 = Fulltor860_wcut_Run4a + Fulltor860_wcut_Run4b + Fulltor860_wcut_Run4c + Fulltor860_wcut_Run4d;	
	static const double Fulltor860_wcut_Combined = Fulltor860_wcut_Run1all + Fulltor860_wcut_Run2 + Fulltor860_wcut_Run3 + Fulltor860_wcut_Run4 + Fulltor860_wcut_Run5;	
	
	static const double FullEXT_Run1all = FullEXT_Run1 + FullEXT_Run1A_open_trigger + FullEXT_Run1B_open_trigger;
	static const double FullEXT_Run4 = FullEXT_Run4a + FullEXT_Run4b + FullEXT_Run4c + FullEXT_Run4d;
	static const double FullEXT_Combined = FullEXT_Run1all + FullEXT_Run2 + FullEXT_Run3 + FullEXT_Run4 + FullEXT_Run5;	

	static const double FullE1DCNT_wcut_Run1all = FullE1DCNT_wcut_Run1 + FullE1DCNT_wcut_Run1A_open_trigger + FullE1DCNT_wcut_Run1B_open_trigger;	
	static const double FullE1DCNT_wcut_Run4 =  FullE1DCNT_wcut_Run4a + FullE1DCNT_wcut_Run4b + FullE1DCNT_wcut_Run4c + FullE1DCNT_wcut_Run4d;	
	static const double FullE1DCNT_wcut_Combined = FullE1DCNT_wcut_Run1all + FullE1DCNT_wcut_Run2 + FullE1DCNT_wcut_Run3 + FullE1DCNT_wcut_Run4 + FullE1DCNT_wcut_Run5;
	
	// -----------------------------------------------------------------------------------------------------------------------------

	// Binning

	//----------------------------------------//

	//wc_numu_score

	TString LabelXAxiswc_numu_score = ";wc numu score", LabelXAxiswc_numu_score2D = ";true wc numu score"; 
	int NBinswc_numu_score = 100;
	double min_wc_numu_score = -10, max_wc_numu_score = 10;	

	//ns_time

	TString LabelXAxisns_time = ";ns time [ns]", LabelXAxisns_time2D = ";true ns time [ns]"; 
	int NBinsns_time = 50;
	double min_ns_time = 2500, max_ns_time = 5500;		


	//nuscore

	TString LabelXAxisNuScore = ";#nu score", LabelXAxisNuScore2D = ";true #nu score"; 
	int NBinsNuScore = 50;
	double min_nuscore = 0., max_nuscore = 1.;		

	// Blips

	static TString LabelXAxisBlip_x = ";x-blip [cm]"; 
	static TString LabelXAxisTrueBlip_x = ";True x-blip [cm]";	
	static const int NBinsBlip_x = 20;
	static TString LabelXAxisBlip_x2D = LabelXAxisTrueBlip_x+";Reco x-blip [cm]";

	static TString LabelXAxisBlip_y = ";y-blip [cm]"; 
	static TString LabelXAxisTrueBlip_y = ";True y-blip [cm]";	
	static const int NBinsBlip_y = 20;
	static TString LabelXAxisBlip_y2D = LabelXAxisTrueBlip_y+";Reco y-blip [cm]";	

	static TString LabelXAxisBlip_z = ";z-blip [cm]"; 
	static TString LabelXAxisTrueBlip_z = ";True z-blip [cm]";	
	static const int NBinsBlip_z = 20;
	static TString LabelXAxisBlip_z2D = LabelXAxisTrueBlip_z+";Reco z-blip [cm]";		

	int radius = 20; // cm
	TString LabelXAxisnBlips_radius = ";# blips within " + TString( to_string(radius) ) + "cm from vertex", LabelXAxisnBlips_radius2D = ";true # radius blips within " + TString( to_string(radius) ) + "cm from vertex"; 
	int NBinsnBlips_radius = 8;
	double nBlips_radius_min = -0.5, nBlips_radius_max = 7.5;

	TString LabelXAxisnBlips_saved = ";# saved blips", LabelXAxisnBlips_saved2D = ";true # saved blips"; 
	int NBinsnBlips_saved = 16;
	double nBlips_saved_min = -0.5, nBlips_saved_max = 15.5;
	
	TString LabelXAxisBlip_size = ";blip size [cm]", LabelXAxisBlip_size2D = ";true blip size [cm]"; 
	int NBinsBlip_size = 15;
	double Blip_size_min = 0., Blip_size_max = 3.;	

	TString LabelXAxisBlip_energy = ";blip energy [MeV]", LabelXAxisBlip_energy2D = ";true blip energy [MeV]"; 
	int NBinsBlip_energy = 20;
	double Blip_energy_min = 0., Blip_energy_max = 5.;	

	TString LabelXAxisBlip_proxtrkdist = ";blip-proxtrack distance [cm]", LabelXAxisBlip_proxtrkdist2D = ";true blip-proxtrack distance [cm]"; 
	int NBinsBlip_proxtrkdist = 50;
	double Blip_proxtrkdist_min = 0., Blip_proxtrkdist_max = 250.;
	
	TString LabelXAxisBlip_pairdist = ";blip-pair track min distance [cm]", LabelXAxisBlip_pairdist2D = ";true blip-pair track min distance [cm]"; 
	int NBinsBlip_pairdist = 50;
	double Blip_pairdist_min = 0., Blip_pairdist_max = 250.;	

	TString LabelXAxisblip_vrt = ";blip-vertex distance [cm]", LabelXAxisblip_vrt2D = ";true blip-vertex distance [cm]"; 
	int NBinsblip_vrt = 50;
	double blip_vrt_min = 0., blip_vrt_max = 250.;		


	//----------------------------------------//	

	static const int NBinsMuonCosTheta = 18;
	static const double ArrayNBinsMuonCosTheta[NBinsMuonCosTheta+1] = { -1.,-0.85,-0.7,-0.57,-0.45,-0.32,-0.2,-0.1,0.,0.1,0.2,0.3,0.4,0.5,0.6,0.72,0.84,0.95,1.};

	static const int NBinsProtonCosTheta = 11;
	static const double ArrayNBinsProtonCosTheta[NBinsProtonCosTheta+1] = { -1.,-0.73,-0.43,-0.18,0.05,0.2,0.37,0.54,0.7,0.8,0.9,1.};

	static const int NBinsThetaVis = 15;
	static const double ArrayNBinsThetaVis[NBinsThetaVis+1] = { 0.,5.,10.,15.,20.,25.,30.,40.,50.,60.,70.,80.,90.,115.,140.,180.};

	static const int NBinsCosThetaVis = 18;
	static const double ArrayNBinsCosThetaVis[NBinsCosThetaVis+1] = { -1.,-0.85,-0.7,-0.57,-0.45,-0.32,-0.2,-0.1,0.,0.1,0.2,0.3,0.4,0.5,0.6,0.72,0.84,0.95,1.};

	static const int NBinsProtonMomentum = 10; static const double ArrayNBinsProtonMomentum[NBinsProtonMomentum+1] = {0.3,0.38,0.45,0.5,0.55,0.625,0.7,0.75,0.8,0.87,1.};
	static const int NBinsMuonMomentum = 10; static const double ArrayNBinsMuonMomentum[NBinsMuonMomentum+1] = { 0.1,0.2,0.3,0.4,0.5,0.64,0.77,0.9,1.,1.1,1.2};

	static const int NBinsECal = 9; static const double ArrayNBinsECal[NBinsECal+1] = {0.2,0.35,0.5,0.65,0.8,0.95,1.1,1.25,1.4,1.6}; 

	static const int NBinsPMiss = 9; static const double ArrayNBinsPMiss[NBinsPMiss+1] = {-0.5,-0.35,-0.20,-0.1,-0.04,0.04,0.1,0.20,0.35,0.5};
	
	static const int NBinsEv = 16;	
	static const double ArrayNBinEv[NBinsEv+1] = {0.2,0.25,0.3,0.35,0.4,0.45,0.5,.55,0.6,0.65,0.7,0.75,0.8,0.85,1.1,1.3,1.6};

	// -----------------------------------------------------------------------------------------------------------------------------------------------

	// Labels for 1D plots
	
	static TString LabelXAxisMuonCosTheta = ";cos#theta_{#mu}"; static TString LabelXAxisTrueMuonCosTheta = ";True cos#theta_{#mu}";
	static TString LabelXAxisThetaVis = ";#theta_{vis} [deg]"; static TString LabelXAxisTrueThetaVis = ";True #theta_{vis} [deg]";
	static TString LabelXAxisPMiss = ";p_{miss} [GeV/c]"; static TString LabelXAxisTruePMiss = ";True p_{miss} [GeV/c]";
	static TString LabelXAxisCosThetaVis = ";cos#theta_{vis}"; static TString LabelXAxisTrueCosThetaVis = ";True cos#theta_{vis}";
	
	// ------------------------------------------------------------------------------------------------------------------------------------

	// Labels for 2D Plots

	static TString LabelXAxisMuonCosTheta2D = LabelXAxisTrueMuonCosTheta+";Reco cos#theta_{#mu}";
	static TString LabelXAxisThetaVis2D = LabelXAxisTrueThetaVis+";Reco #theta_{vis} [deg]";
	static TString LabelXAxisCosThetaVis2D = LabelXAxisTrueCosThetaVis+";Reco cos#theta_{vis}";
	static TString LabelXAxisPMiss2D = LabelXAxisTruePMiss+";Reco p_{miss}";

	// --------------------------------------------------------------------------------------------------------------------------------------

	static int MCUncColor = kGray;	
	static int OverlayColor = kAzure-4;
	static int BeamOnColor = kBlack;
	static int GenieOverlayColor = kBlack;
	static int GenieColor = 610;
	static int Geniev3OutOfTheBoxColor = kMagenta;
	static int GiBUUColor = kGreen+1; // 410
	static int NuWroColor = kOrange+10;
	static int NEUTColor = kRed+1;
	static int GENIEv2Color = kBlue;	
	static int GENIEv3_0_4_Color = kGray+1;
	static int SuSav2Color = kOrange-3;	
	
	static int NormUncBandColor = kGray+3;	
	
	static int G18LineStyle = kSolid;
	
	static int GiBUULineStyle = 2;
	static int NEUTLineStyle = 7;
	static int NuWroLineStyle = 5;
	
	static int UntunedLineStyle = 2;
	static int G21LineStyle = 7;
	static int Gv2LineStyle = 5;							
	
	// ---------------------------------------------------------------------------------------------------------------------------------------

	// Constants, Cuts & Thresholds

	static const double ProtonLLRPIDScore = 0.05;

	static const double CosmicPID = -999.;
	static const int CosmicPdg = -99;

	static const double BE = 0.04; // GeV

	static const double ThresholdPurity = 0.1; // 10%
	static const double UBSpaceReso = 0.3; // cm // 3mm spacing between the wires

	static const double MaxMuPDistance = 2.; // cm

	static const double MaxPFParticleTrackDistance = 20.; // cm

	static const double YZBeamFlashVertexMaxDistance = 500.; // cm
	static const double BeamFlashPEThreshold = 100; // PEs

	static const double ChargedPionMomentumThres = 0.07;
	static const double NeutralPionMomentumThres = 0.0;

	static const double PurityThreshold = 0.1;

	static double POTUncertainty = 0.02; // 2% POT Uncertainty		

	static double NTargetUncertainty = 0.01; // 1% NTarget Uncertainty

	constexpr float TRACK_SCORE_CUT = 0.5;	

	// Quality cuts

	const TString MuRangeMCSAgree = "0.25"; const double MuRangeMCSAgreeValue = 0.25;
	const TString MuMinMCSLengthThres = "100";  const double MuMinMCSLengthThresValue = 100;
	const TString MuMinSumHits = "0.7";  const double MuMinSumHitsValue = 0.7;
	const TString PMinSumHits = "1.";  const double PMinSumHitsValue = 1.;	

	//----------------------------------------//
	
	// Interaction labels
	
	const std::vector<int> InteBreakColors{kBlack,kAzure-4,kOrange-3,kGreen+1,kRed+1,kBlue};		
	std::vector<TString> InteractionLabels = {"","QE","MEC","RES","DIS","COH"};
	const int NInte = InteractionLabels.size();
	
	//----------------------------------------//		

	static const int TwoDNBinsECal = 3; std::vector<double> TwoDArrayNBinsECal{0.0,0.5,0.8,2.0};
	static const int TwoDNBinsMuonMomentum = 3; std::vector<double> TwoDArrayNBinsMuonMomentum{0.1,0.4,0.6,1.2};
	static const int TwoDNBinsProtonMomentum = 3; std::vector<double> TwoDArrayNBinsProtonMomentum{0.3,0.5,0.7,1.};	
	static const int TwoDNBinsDeltaPT = 3; std::vector<double> TwoDArrayNBinsDeltaPT{0.0,0.2,0.4,1.0};
	static const int TwoDNBinsDeltaPn = 3; std::vector<double> TwoDArrayNBinsDeltaPn{0.0,0.2,0.4,1.0};	
	static const int TwoDNBinsPMiss = 3; std::vector<double> TwoDArrayNBinsPMiss{0.0,0.1,0.2,0.5};	
	static const int TwoDNBinsDeltaAlphaT = 4; std::vector<double> TwoDArrayNBinsDeltaAlphaT{0.0,45.0,90.0,135.0,180.0};
	static const int TwoDNBinsDeltaAlpha3D = 4; std::vector<double> TwoDArrayNBinsDeltaAlpha3D{0.0,45.0,90.0,135.0,180.0};

	static const int NBinsDeltaPT = 13; static const double ArrayNBinsDeltaPT[NBinsDeltaPT+1] = {0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.47,0.55,0.65,0.75,0.9};
	static const int NBinsDeltaPn = 10; static const double ArrayNBinsDeltaPn[NBinsDeltaPn+1] = {0,0.07,0.14,0.2,0.3,0.4,0.47,0.55,0.65,0.75,0.85};
	static const int TwoDNBinsMuonCosTheta = 4; std::vector<double> TwoDArrayNBinsMuonCosTheta{-1.,0.0,0.5,0.75,1.0};
	static const int TwoDNBinsProtonCosTheta = 4; std::vector<double> TwoDArrayNBinsProtonCosTheta{-1.,0.0,0.5,0.75,1.0};

	//----------------------------------------//

	static std::map<TString,double> MultiDimScaleFactor =
	{
		{ "MuonCosThetaPlot", 1. },
		{ "MuonCosThetaSingleBinPlot", 1. },
		{ "ThetaVisPlot", 1. },
		{ "CosThetaVisPlot", 1. },
		{ "PMissPlot", 1. },
		{ "ThetaVis_ECal_0_00To0_50Plot",  TwoDArrayNBinsECal.at(1) - TwoDArrayNBinsECal.at(0)  },
		{ "ThetaVis_ECal_0_50To0_80Plot", TwoDArrayNBinsECal.at(2) - TwoDArrayNBinsECal.at(1)  },
		{ "ThetaVis_ECal_0_80To2_00Plot",  TwoDArrayNBinsECal.at(3) - TwoDArrayNBinsECal.at(2) },
		{ "SerialThetaVis_ECalPlot", 1.  },			
		{ "ThetaVis_DeltaPn_0_00To0_20Plot",  TwoDArrayNBinsDeltaPn.at(1) - TwoDArrayNBinsDeltaPn.at(0)  },
		{ "ThetaVis_DeltaPn_0_20To0_40Plot", TwoDArrayNBinsDeltaPn.at(2) - TwoDArrayNBinsDeltaPn.at(1)  },
		{ "ThetaVis_DeltaPn_0_40To1_00Plot",  TwoDArrayNBinsDeltaPn.at(3) - TwoDArrayNBinsDeltaPn.at(2) },
		{ "SerialThetaVis_DeltaPnPlot", 1.  },			
		{ "ThetaVis_PMiss_0_00To0_10Plot",  TwoDArrayNBinsPMiss.at(1) - TwoDArrayNBinsPMiss.at(0)  },
		{ "ThetaVis_PMiss_0_10To0_20Plot",  TwoDArrayNBinsPMiss.at(2) - TwoDArrayNBinsPMiss.at(1)  },
		{ "ThetaVis_PMiss_0_20To0_50Plot", TwoDArrayNBinsPMiss.at(3) - TwoDArrayNBinsPMiss.at(2)  },
		{ "SerialThetaVis_PMissPlot", 1.  },			
	};	

	//----------------------------------------//
	
	std::vector< std::vector<double> > TwoDArrayNBinsThetaVisInECalSlices{ 
										{0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,115.,180.},
										{0.,5.,10.,15.,20.,25.,30.,40.,50.,60.,180.},
										{0.,5.,10.,15.,20.,30.,180.}
	};	

	std::vector< std::vector<double> > TwoDArrayNBinsThetaVisInDeltaPnSlices{ 
										{0.,10.,20.,180.},
										{0.,10.,20.,30.,40.,50.,60.,180.},
										{0.,30.,40.,50.,60.,70.,80.,90.,115.,180.},
	};	

	std::vector< std::vector<double> > TwoDArrayNBinsThetaVisInPMissSlices{ 
										{0.,10.,20.,30.,40.,50.,60.,180.},
										//{0.,30.,40.,50.,60.,70.,80.,90.,115.,180.},
										{0.,15.,30.,40.,50.,60.,70.,80.,90.,115.,180.},
										{0.,15.,30.,40.,50.,60.,70.,80.,90.,115.,180.},
	};	


	static std::map<TString,vector< vector<double> > > map_to_2d_bin =
	{
		{ "SerialThetaVis_ECalPlot", TwoDArrayNBinsThetaVisInECalSlices  },			
		{ "SerialThetaVis_DeltaPnPlot", TwoDArrayNBinsThetaVisInDeltaPnSlices },			
		{ "SerialThetaVis_PMissPlot", TwoDArrayNBinsThetaVisInPMissSlices },			
	
	};


}
#endif
