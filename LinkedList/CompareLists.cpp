//2-pointer pattern - Given two linked list, print if they are equal or not
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
        }cout<<"NULL"<<endl;
    }
};
int getLength(Node* head){
    Node* temp=head;
    int ctr=0;
    while(temp!=NULL){
        ctr++;
        temp=temp->next;
    }
    return ctr;
}
bool compareList(Node* head1,Node* head2){  
    Node* curr1=head1;
    Node* curr2=head2;
    
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val!=curr2->val){
            return false;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return(curr1==NULL && curr2==NULL);


}


int main(){
    LinkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.display();
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.display();
    cout<<compareList(ll1.head,ll2.head);
return 0;

}