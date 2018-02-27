#include "inputHandler.h"
#include "bitcoin.h"
#include "pseudoserver.h"
#include "tree.h"
bool inputHandler::inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV, bool* sucessfulHandling){ //, stringstream& oFile, stringstream& iV
	 unsigned int specVal;
	 iFile >> inputFile;
	 ifstream inputFileHandling;
	 inputFileHandling.open(inputFile.c_str());
	 if (inputFileHandling.fail()) { cerr << "File could not be found/opened as it most likely doesn't exist in this location/in general" << endl; 
	 sucessfulHandling[0] = false;}
	 else{
	   inputFileHandling.close();
	   sucessfulHandling[0] = true;
	 }
	  oFile >> outputFile;
	  struct stat outputBuff;
	  if(stat (outputFile.c_str(), &outputBuff) == 0){ 
	    fstream outputFileHandling(outputFile.c_str());
	    if(outputFileHandling.fail()){ cerr << "File can not be open/read/used currently, please try again later" << endl;}
	    else{ outputFileHandling.close();  outputFileHandling.clear(); sucessfulHandling[1] = true;}
	  }//Checks if file exists, if it does not it will go through condition
	  else{ cerr << " Output File does not exist " << endl; }
	 if(!(iV >> specVal)){ cerr << "Invalid value input " << '\n'; sucessfulHandling[2] = false;}
	 seedVal = specVal;
	 return sucessfulHandling;
 }

void inputHandler::newCensusSystem(stringstream& iFile,stringstream& oFile, stringstream& iV){
		 Bitcoin mycoin(seedVal);
		 psuedoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 fstream outputFileHandling;
		 outputFileHandling.open(outputFile.c_str(), ios::out | ios::in | ios::trunc);
		 double totalQueue = 0, avgQueue = 0, maxQueue = 0, emptyQueue = 0, eofQueue = 0, totalIteration = 0;
		 bool endofFile = false;
		while(endofFile != true){
			if(mycoin() == 0){  
			    string treeInfo;
			  if(newServer.extract(treeInfo)){
			    Tree newTree(treeInfo);
			    outputFileHandling << newTree;	
			  }
			  else{
			   emptyQueue++;
			      }
			}
			else{
				
				if(!(newServer.read(inputFileHandling))){ endofFile = true; eofQueue = newServer.queuesize(); avgQueue = totalQueue;  break;}
				else{     
				   if(newServer.queuesize() > maxQueue) maxQueue = newServer.queuesize();
				}
			}
			totalQueue+= newServer.queuesize();	 
			totalIteration++;
		}
		avgQueue /= totalIteration;
		while(newServer.queuesize() != 0){ 
			 string treeInfo;
			 getline(inputFileHandling, treeInfo);
			 if(newServer.extract(treeInfo)){
			    Tree newTree(treeInfo);
			    outputFileHandling << newTree;		
			  }
			  else ;
			

		}
		cout << "average queue size: " << avgQueue << endl;
		cout << "maximum queue size: " << maxQueue << endl;
		cout << "empty queue count: " << emptyQueue << endl;
		cout << "queue size on eof: " << eofQueue << endl;
}
