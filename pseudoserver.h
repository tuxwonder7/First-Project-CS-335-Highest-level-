#ifndef _pseudoserver_h_
#define _pseudoserver_h_
#include "queue.h"
using namespace std;

class psuedoServer{
	public:
	bool read(istream & is);
	bool extract(string & s);
	int queuesize();
	void pop_front();
	void push_back(string s);
	bool empty();
	private:
	Queue* queue = new Queue();
};
int psuedoServer::queuesize(){ return queue->size();}
bool psuedoServer::extract(string & s){
	if(queuesize() != 0){
		s = queue->front()->data;
		queue->pop_front();
		return true;
	}
	else{
		return false;
	}
}
void psuedoServer::pop_front(){ queue->pop_front();}
void psuedoServer::push_back(string s){ queue->push_back(s);}
bool psuedoServer::empty(){ if(queuesize() < 1){return true;}else{ return false;}}
#endif
