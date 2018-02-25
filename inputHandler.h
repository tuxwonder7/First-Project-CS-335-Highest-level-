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
#include "tree.h"
using namespace std;	

class inputHandler{
	public:
	inputHandler(){}
	~inputHandler(){}
	bool inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV, bool* sucessfulHandling){ //, stringstream& oFile, stringstream& iV
	
	 unsigned int specVal;
        
	 iFile >> inputFile;
	 ifstream inputFileHandling;
	 inputFileHandling.open(inputFile.c_str());
	 cout << inputFile << " Test23" << endl;
	 if (inputFileHandling.fail()) { cerr << "File could not be found/opened as it most likely doesn't exist in this location/in general" << endl; 
	 sucessfulHandling[0] = false;}
	 else{
	 //  pushInputFile();
	   inputFileHandling.close();
	   if(inputFileHandling.is_open()) cout << "REEE 2" << endl;
	   inputFileHandling.clear();
	   if(inputFileHandling.is_open()) cout << "REEE 3" << endl;
	   sucessfulHandling[0] = true;
	 }
	  oFile >> outputFile;
	  struct stat outputBuff;
	  if(stat (outputFile.c_str(), &outputBuff) == 0){ 
	    fstream outputFileHandling(outputFile.c_str());
	    if(outputFileHandling.fail()){ cerr << "File can not be open/read/used currently, please try again later" << endl;}
	    else{ outputFileHandling.close();  outputFileHandling.clear(); sucessfulHandling[1] = true;}
	  }//Checks if file exists, if it does not it will go through condition
	  else{ cerr << " Output File does not exist " << endl; }//sucessfulHandling[1] = false;
	  
	 if(!(iV >> specVal)){ cerr << "Invalid value input " << '\n'; sucessfulHandling[2] = false;}
	 seedVal = specVal;
	 return sucessfulHandling;
	 
	}//ifstream outputFileHandling(outputFile.c_str());
	

	void pushInputFile(ifstream & inStream){
		
		
	}
	void newCensusSystem(stringstream& iFile,stringstream& oFile, stringstream& iV){
		
		Bitcoin mycoin(seedVal);
		//cout << mycoin() << endl;
		psuedoServer newServer;
		//newServer.push_back("hi");
		//cout << newServer.queuesize() << endl;
		
		// int specVal;
		// iV >> specVal;
		// cout << inputFile << "  What are you" << endl;;
		  ifstream inputFileHandling;
		 
		  inputFileHandling.open(inputFile.c_str());
		 //  if(inputFileHandling.is_open()) cout << "REEE 2" << endl;
		//  string test;
		//  getline(inputFileHandling, test);
		//  cout << "test " << test << endl; 
		 fstream outputFileHandling;
		 outputFileHandling.open(outputFile.c_str(), ios::out | ios::in | ios::trunc);


		// if(inputFileHandling.good()) cout << "Is good\n" << endl;
		 bool endofFile = false;
		while(endofFile != true){
			if(mycoin() == 0){
			  string treeInfo;
			 // getline(inputFileHandling, treeInfo);
			 // cin.ignore();
			  getline(inputFileHandling, treeInfo);
			//  cout << "Tree info " << treeInfo << endl;
			  newServer.push_back(treeInfo);
			  if(newServer.extract(treeInfo)){
			   cout << "New tree extract success" << endl;
			    Tree newTree(treeInfo);
				
			  }
			  else{}
			}
			
		break;

			
		}
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
	 string inputFile;
	 string outputFile;
	 int seedVal;


};


#endif
