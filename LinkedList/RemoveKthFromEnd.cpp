// Given the head of a linked list, remove the kth node from the end of the list and return its head
#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int val;
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
        while(temp){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }

};
void removeKnodeFromEnd(Node* &head,int k){
    Node* ptr1=head;
    Node* ptr2=head;

    while(k--){
        ptr1=ptr1->next;
    }
    //If k is equal to length of Linked List
    if(ptr1==NULL){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return ;

    }

    while(ptr1->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    ptr1=ptr2->next;
    ptr2->next=ptr1->next;
    delete(ptr1);

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
    removeKnodeFromEnd(ll.head,3);
    ll.display();
    return 0;

}

