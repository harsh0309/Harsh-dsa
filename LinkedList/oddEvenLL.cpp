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
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insertAtTail(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new_node;    
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }


};

Node* oddEvenLL(Node* &head){
    Node* even_head=head->next;
    Node* even=even_head;
    Node* odd=head;
    while(even && even->next){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=even_head;
    return head;

}
int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    oddEvenLL(ll.head);
    ll.display();
    return 0;

}