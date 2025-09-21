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
Node* reoderLL(Node* &head){
    //Finding middle element and last element 1->2->3->4->5->6->NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    //Seperat list in two half 1->2->3->4->NULL and reverse second half 6->5->NULL
    Node* curr=slow->next;
    slow->next=NULL;
    Node* pev=NULL;

    while(curr){
        Node* nex=curr->next;
        curr->next=pev;
        pev=curr;
        curr=nex;
    }
    Node* head2=pev;
    Node* temp1=head;
    Node* temp2=head2;
    while(temp1 && temp2){
        Node* nex1=temp1->next;
        Node* nex2=temp2->next;
        temp1->next=temp2;
        temp2->next=nex1;
        temp1=nex1;
        temp2=nex2;
    }
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
    ll.insertAtTail(7);
    ll.display();
    ll.head=reoderLL(ll.head);
    ll.display();

    return 0;
}