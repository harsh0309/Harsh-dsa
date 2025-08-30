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
        }
        temp->next=new_node;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

Node* mergeLinkedList(Node* head1,Node* head2){
    Node* dummy_head=NULL;
    Node* temp;
    Node* ptr1=head1;
    Node* ptr2=head2;
    
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val<ptr2->val){
            if(dummy_head==NULL){
                dummy_head=ptr1;
                temp=ptr1;
                ptr1=ptr1->next;

            }
            else{
                temp->next=ptr1;
                ptr1=ptr1->next;
                temp=temp->next;

            }
            
        }
        else{
            if(dummy_head==NULL){
                dummy_head=ptr2;
                temp=ptr2;
                ptr2=ptr2->next;
            }
            else{
                temp->next=ptr2;
                ptr2=ptr2->next;
                temp=temp->next;
            }
        }
    }
    if(ptr1==NULL) temp->next=ptr2;
    else temp->next=ptr1;

    return dummy_head;
}
int main(){
    LinkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.display();
    Node* mergehead=mergeLinkedList(ll1.head,ll2.head);
    Node* temp=mergehead;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

    
}