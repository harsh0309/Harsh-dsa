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
Node* rotateByK(Node* &head,int k){
    Node* tail=head;
    int n=0;
    while(tail->next!=NULL){
        n=n+1;
        tail=tail->next;
    };
    n++;//including last node
    k=k%n;
    if(k==0){
        return head;
    }
    tail->next=head;
    Node* temp=head;
    for(int i=1;i!=n-k;i++){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
    return head;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();
    rotateByK(ll1.head,2);
    ll1.display();
    return 0;
}