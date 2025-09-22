#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};
class doublyLinkedList{
    public:
    Node* head;
    Node* tail;
    doublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtstart(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
        
    }
    void insertAtEnd(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;


    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtPosition(int val,int k){
        //K is less than or equal to length of list
        Node* temp=head;
        int count=1;
        while(count<(k-1)){
            count++;
            temp=temp->next;
        }
        Node* new_node=new Node(val);
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next=new_node;
        new_node->next->prev=new_node;

        
    }

};
int main(){
    doublyLinkedList ll;
    ll.insertAtEnd(1);
    //ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtPosition(2,2);
    
    ll.display();

    return 0;
}