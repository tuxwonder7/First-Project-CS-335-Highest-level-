#ifndef _tree_h_
#define _tree_h_
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Tree{
	public:
	Tree(const string & treedata){ 
	// cout << treedata << endl;
	 string allInfo = treedata;
	 stringstream iss(treedata);
	// int count = 0;
	 vector<string> splitString;
	 while(iss.good())
	 {
	   string singlePart;
	   getline(iss,singlePart,',');
	   splitString.push_back(singlePart);
	 //  count++;
	 }
	 stringstream(splitString[0]) >> tree_id ;//
	 stringstream(splitString[3]) >> tree_dbh;//
	// stringstream(splitString[6]) >> status;
	// stringstream(splitString[7]) >> health;
	// stringstream(splitString[9]) >> spc_common;
	// stringstream(splitString[24]) >> address;
	// stringstream(splitString[26]) >> boroname;
	 stringstream(splitString[25]) >> zipcode ;//
	 status = status = splitString[6];
	 health = splitString[7];
	 spc_common = splitString[9];
	 address = splitString[24];
	 boroname = splitString[26];
   	 stringstream(splitString[34]) >> longitude;//
	 stringstream(splitString[33]) >> latitude;//
	}
	friend ostream& operator<< (ostream & os, const Tree & t){
		os << t.spc_common << "," << t.tree_id << ","<< t.tree_dbh << "," << t.status << "," <<  t.health << "," << t.address 
		<< "," << t.boroname << "," << t.zipcode << "," << t.latitude << "," << t.longitude << endl;
		

	}
	string write(){
		ospecInfo << spc_common << "\t" << tree_id << "\t"<< tree_dbh << "\t" << status << "\t" <<  health << "\t" << address 
		<< "\t" << boroname << "\t" << zipcode << "\t" << latitude << "\t" << longitude << "\n";
		string specInfoWrite = ospecInfo.str();
		return specInfoWrite;
	}
	private:
	string allInfo;
	string spc_common;
	string specInfo;
	ostringstream ospecInfo;
	int tree_id;
	int tree_dbh;
	string status;
	string health;
	string address;
	string boroname;
	int zipcode;
	double latitude;
	double longitude;
};



#endif
