
#include <iostream>
#include <sstream>
#include "inputHandler.h"
using namespace std;
int main(int argc, char* argv[])
{
	
	if (argc < 4){ cerr<< "Usage: " << argv[0] << " inputFile name " << " outputFile name " << " inputVal " << endl;
	} 
	else if (argc == 4) { 
	 inputHandler newCensus;
	 stringstream arg1(argv[1]);
	 stringstream arg2(argv[2]);
	 stringstream arg3(argv[3]);
	 if(newCensus.inputVerify(arg1, arg2, arg3)){
	  cout << "Sucessful" << endl;
	  newCensus.newCensusSystem();
	 } 
	 
	
	}
	else{}
	
  
}


