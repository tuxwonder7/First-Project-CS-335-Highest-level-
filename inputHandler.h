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
#ifndef _inputHandler_h_
#define _inputHandler_h_


#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;	

class inputHandler{
	public:
	inputHandler(){}
	~inputHandler(){}
	bool inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV, bool* sucessfulHandling);
	void pushInputFile(ifstream & inStream){}
	void newCensusSystem(stringstream& iFile,stringstream& oFile, stringstream& iV);
	
	private:
	 string inputFile;
	 string outputFile;
	 int seedVal;


};


#endif
