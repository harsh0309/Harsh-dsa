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
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=new_node;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
};
bool palindromeLL(Node* head){
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(fast_ptr!=NULL &&fast_ptr->next!=NULL){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    Node* curr=slow_ptr;
    Node* pev=NULL;
    while(curr!=NULL){
        Node* nex=curr->next;

        curr->next=pev;
        pev=curr;
        curr=nex;
    }
    
    Node* b_head=pev;
    Node* f_head=head;
    while(b_head!=NULL){
        if(b_head->val!=f_head->val){
            return false;
        }
        b_head=b_head->next;
        f_head=f_head->next;

    }
    return true;
}



int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();
    cout<<palindromeLL(ll.head);
}