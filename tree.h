#ifndef _tree_h_
#define _tree_h_
#include <string>
#include <sstream>
using namespace std;
class Tree{
	public:
	Tree(const string & treedata){ 
	 cout << treedata << endl;
	 for(int x = 0; x < treedata.length(); x++){
	   	//treedata >> 
	 }


	}
	friend ostream& operator<< (ostream & os, const Tree & t){}
	string write(){
		ospecInfo << spc_common << "/t" << tree_id << "/t"<< tree_dbh << "/t" << status << "/t" <<  health << "/t" << address 
		<< "/t" << boroname << "/t" << zipcode << "/t" << latitude << "/t" << longitude;
		specInfo = ospecInfo.str();
	}
	private:
	//string allInfo;
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
