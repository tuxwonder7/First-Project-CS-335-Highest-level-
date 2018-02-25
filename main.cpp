
#include <iostream>
#include <sstream>

#include <algorithm>
#include "inputHandler.h"

using namespace std;
int main(int argc, char* argv[])
{
	
	
	if (argc != 4) { 
	cerr<< "Usage: " << argv[0] << " inputFile name " << " outputFile name " << " inputVal " << endl; }
	else{
	for(int i = 0; i < 4; i++) cout << argv[i] << endl;
	 inputHandler newCensus;
	 stringstream arg1(argv[1]);
	 stringstream arg2(argv[2]);
	 stringstream arg3(argv[3]);
 	 bool successArray[] = {true,true,true,true};
	 newCensus.inputVerify(arg1, arg2, arg3, successArray);
	 bool tempSucc = true;
	 for(int x = 0; x < 4; x++){
		cout << " successArray[x] " << successArray[x] << endl;
		if(successArray[x] == true){}
		else{ tempSucc = false;}
 	 }
	 
	 cout << "tempSucc " << tempSucc << endl;
	 if(tempSucc == true){
	  cout << "Sucessful" << endl;
		
	  newCensus.newCensusSystem(arg1, arg2, arg3); 
	 }
	 else{  }
	 
	}
	
	
  
}


