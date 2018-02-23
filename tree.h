#ifndef _tree_h_
#define _tree_h_

class Tree{
	public:
	Tree(const string & treedata);
	friend ostream& operator<< (ostream & os, const Tree & t);
	string write(){
		string allInfo;
		allInfo = spc_common + "/t" + tree_id + "/t"+ tree_dbh + "/t" + status + "/t" +  health + "/t" + address 
		+ "/t" + boroname + "/t" + zipcode + "/t" + latitude + "/t" + longitude;
	}
	private:
	string spc_common;
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
