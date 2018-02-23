#ifndef _queue_h_
#define _queue_h_
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Node
{
public:
    Node* next;
    string data;
};



class Queue
{
public:
    int length;
    Node* head;

    Queue();
    ~Queue();
    void print();
    void push_back(string data);
    void pop_front();
    bool empty();
    int size();
    Node* front();
    Node* back();
};
int Queue::size(){return this->length;}
bool Queue::empty(){  return (this->length) > 0 ? false : true;}
Node* Queue::front(){
    return head;
}
Node* Queue::back(){
   Node* head = this->head;
    while(head){
        if(head->next == NULL){
            return head;
        }
        else{ head = head->next; }
     
    }  
}


Queue::Queue(){
    this->length = 0;
    this->head = NULL;
}
Queue::~Queue(){
    std::cout << "LIST DELETED";
}
void Queue::push_back(string data){
   // cout << data << endl;
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
    
}
void Queue::pop_front(){
    Node* node = new Node();
    node = head;
    node = node->next;
    free(head);
    head = node;
    this->length--;
    
}
void Queue::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

#endif
