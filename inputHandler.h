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
#include "pseudoserver.h"
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
	 ifstream inputFileHandling(inputFile.c_str());
	 if (inputFileHandling.fail()) { cerr << "File could not be found/opened as it most likely doesn't exist in this location/in general" << endl; sucessfulHandling = false;}
	 oFile >> outputFile;
	 struct stat outputBuff;
	  if(stat (outputFile.c_str(), &outputBuff) == 0){ 
	    ifstream outputFileHandling(outputFile.c_str());
	    if(outputFileHandling.fail()){ cerr << "File can not be open/read/used currently, please try again later" << endl; sucessfulHandling = false;}
	  }//Checks if file exists, if it does not it will go through condition
	  else{ cerr << "File does not exist " << endl; sucessfulHandling = false;}

	 if(!(iV >> specVal)){ cerr << "Invalid value input " << '\n'; sucessfulHandling = false;}
	 seedVal = specVal;
	 return sucessfulHandling;
	 
	}//ifstream outputFileHandling(outputFile.c_str());
	


	void newCensusSystem(){
		Bitcoin mycoin(seedVal);
		cout << mycoin() << endl;
		psuedoServer newServer;
		newServer.push_back("hi");
		cout << newServer.queuesize() << endl;
		//if(coin == 0)
		//calls pseudoserver method to get string from front of queue
		//if it is empty nothing is done, if it has something then calls tree object, passing string (tree(string))
		//create new string representation of tree object, (few fields/order) and then output tree string
		//if(coin == 1)
		//calls pseudoserver read() method, if pseudoserver reaches end of input it returns false, telling handler
		//file is empty but needs to check if queue still has data, and coin flip stops, if it is not empty
		//pseudoserver reads input and puts it in queue
		//also data regarding queue includes: average q n, max q m, empty q c (how many checks in front of queue was e
		//empty, and queue size on eof e
	}
	
	private:
	 //string inputFile;
	 //string outputFile;
	 int seedVal;


};


#endif
