/*******************************************************************************
  Title          : inputHandler.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the inputHandler class
  Purpose        : Handling input data and verifying integrity of input information
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#ifndef inputHandler_h
#define inputHandler_h


#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include "bitcoin.h"
using namespace std;	

class inputHandler{
	public:
	inputHandler(){}
	~inputHandler(){}
	bool inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV){ //, stringstream& oFile, stringstream& iV
	 string inputFile, outputFile;
	 int specVal;
         bool sucessfulHandling = false;
	 iFile >> inputFile;
	 ifstream inputFileHandling(inputFile);
	 if (inputFileHandling.fail()) { cerr << "File could not be found/opened as it most likely doesn't exist in this location/in general" << endl; sucessfulHandling = false;}
	 oFile >> outputFile;
	 struct stat outputBuff;
	  if(stat (outputFile.c_str(), &outputBuff) == 0){ 
	    ifstream outputFileHandling(outputFile);
	    if(outputFileHandling.fail()){ cerr << "File can not be open/read/used currently, please try again later" << endl; sucessfulHandling = false;}
	  }//Checks if file exists, if it does not it will go through condition
	  else{ cerr << "File does not exist " << endl; sucessfulHandling = false;}

	 if(!(iV >> specVal)){ cerr << "Invalid value input " << '\n'; sucessfulHandling = false;}

	 return sucessfulHandling;
	 
	}//ifstream outputFileHandling(outputFile);
	


	void newCensusSystem(){
		Bitcoin mycoin(123);
		//mycoin();
	}
	
	private:
	 //string inputFile;
	 //string outputFile;
	 //int inputVal;


};


#endif
