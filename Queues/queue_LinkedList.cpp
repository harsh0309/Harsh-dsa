#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;

    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        this->size=0;

    }
    void enque(int data){
        Node* new_node=new Node(data);
        if(head==NULL){
            head=tail=new_node;
        }
        else {
            tail->next=new_node;
            tail=new_node;

        }
        size++;
    }
    void deque(){
        if(this->head==NULL){
            //Queue is Empty
            return;
        }
        else{
            Node* new_head=this->head->next;
            Node* old_head=this->head;
            this->head=new_head;
            old_head->next=NULL;
            delete old_head;
            size--;

        }
        
    }
    int getSize(){
        return this->size;
    }
    bool isEmpty(){
        return this->head==NULL;
        
    }
    int front(){
        if(this->head==NULL) return -1;
        return this->head->val;
    }

};

int main(){
    Queue qu;
    qu.enque(10);
    qu.enque(20);
    qu.enque(30);
    qu.deque();
    qu.enque(40);
    while( !qu.isEmpty()){
        cout<<qu.front()<<endl;
        qu.deque();

    }
    return 0;
}