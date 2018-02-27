#ifndef _pseudoserver_h_
#define _pseudoserver_h_
#include "queue.h"
using namespace std;

class pseudoServer{
	public:
	bool read(istream & is){
	 string treeInfo;
	 getline(is, treeInfo);
	 if(is.bad()  || is.eof()){ return false;}
	 else{
	  queue->push_back(treeInfo);
	  return true;
	 }
	}
	bool extract(string & s);
	int queuesize();
	void pop_front();
	void push_back(string s);
	bool empty();
	private:
	Queue* queue = new Queue();
};
int pseudoServer::queuesize(){ return queue->size();}
bool pseudoServer::extract(string & s){
	if(queuesize() != 0){
		s = queue->front()->data;
		queue->pop_front();
		return true;
	}
	else{
		return false;
	}
}
void pseudoServer::pop_front(){ queue->pop_front();}
void pseudoServer::push_back(string s){ queue->push_back(s);}
bool pseudoServer::empty(){ if(queuesize() < 1){return true;}else{ return false;}}
#endif
