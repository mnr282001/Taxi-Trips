#include <iostream>
#include <fstream>
#include <string>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl;


int main() {

//	const unsigned int MAX_TRIPS = 10000;
  // TODO(student): implement

  string inputFile;
  cout << "Enter name of input file: ";
  cin >> inputFile;
  ifstream fs;
  fs.open(inputFile);
  if (fs.is_open()) {
	  int i = 0;
	  int invalidCounter = 0;
	  int totalNum = 0;
	  double durationArray[MAX_TRIPS];
	  double distanceArray[MAX_TRIPS];
	  double fareArray[MAX_TRIPS];
	  double tipArray[MAX_TRIPS];
	  bool typeChecker;
	  while (!fs.eof()) {	  
		  string taxiId;
	   	  double tripSeconds;
		  double tripMiles;
		  double tripFare;
		  double tripTip;
		  string paymentType;
		  string line;
		  //getline(fs,line);
		  
		  
		  fs >> taxiId >> tripSeconds >> tripMiles >> tripFare >> tripTip >> paymentType;
		 // cout << taxiId << " " << tripSeconds << " "<< tripMiles << " " << tripFare << " " << tripTip << " " << paymentType;// << endl;
		  
		  string validTypes[4];
		  validTypes[0] = "CreditCard";
		  validTypes[1] = "Cash";
		  validTypes[2] = "NoCharge";
		  validTypes[3] = "Unknown";
		  typeChecker = is_payment_valid(paymentType, validTypes,4);
		 // cout << typeChecker << endl;
		  
		  if (tripSeconds > 86400) {
			  ++invalidCounter;
			 // cout << "duration issue";
		  } else if (tripMiles > 1500) {
			  ++invalidCounter;
			 // cout << "distance issue";
		  } else if (tripFare + tripTip > 5000) {
			 ++invalidCounter;
			 //cout << "overcharge issue";
		  } else if (typeChecker == false) {
			  ++invalidCounter;
			 // cout << "wrong method issue";
		  } else if ((tripSeconds == 0 && tripMiles == 0) && tripFare != 0) {
			  ++invalidCounter;
			  //cout << "wrongful charge issue";
		  } else {
			  durationArray[i] = tripSeconds;
			  distanceArray[i] = tripMiles;
			  fareArray[i] = tripFare;
			  tipArray[i] = tripTip;
			  ++i;
			  ++totalNum;
			 
			  
		  }
		//cout << invalidCounter << endl;  
	  }
	 fs.close();
	  cout << "Number of trips: " << totalNum << endl;
	  cout << "Number of trips with invalid data: " << invalidCounter << endl;
	  cout << "Duration: max " << max(durationArray,totalNum) << " min " << min(durationArray,totalNum) << " avg " << average(durationArray,totalNum) << " mode " << mode(durationArray, totalNum) << endl;
	  cout << "Distance: max " << max(distanceArray,totalNum) << " min " << min(distanceArray,totalNum) << " avg " << average(distanceArray,totalNum) << " mode " << mode(distanceArray, totalNum) << endl;
	  cout << "Fare: max " << max(fareArray,totalNum) << " min " << min(fareArray,totalNum) << " avg " << average(fareArray,totalNum) << " mode " << mode(fareArray, totalNum) << endl;
	  cout << "Tip: max " << max(tipArray,totalNum) << " min " << min(tipArray,totalNum) << " avg " << average(tipArray,totalNum) << " mode " << mode(tipArray, totalNum) << endl;
	  cout << "Length of longest sequence without tips: " << length_longest_seq_zeros(tipArray,totalNum) << endl;
	  
  } else {
	  cout << "Can't open " << inputFile << endl;
  }
  return 0;
}