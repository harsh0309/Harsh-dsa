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
void insertAtHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}
void insertATTail(Node* &head,int val){
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

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtPosition(Node* &head,int val,int pos){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node* temp=head;
    int cur_pos=0;
    while(cur_pos!=pos-1){
        temp=temp->next;
        cur_pos++;
    }
    Node* new_node=new Node(val);
    new_node->next=temp->next;
    temp->next=new_node;
    return;



}
void UpdateAtposition(Node* &head,int k,int val){
    Node* temp=head;
    int curr_pos=0;
    while(curr_pos!=k){
        temp=temp->next;
        curr_pos++;
    }
    temp->val=val;
    return;
}
void deletionAtposition(Node* &head,int pos){
int curr_pos=0;
Node* prev=head;
while(curr_pos!=pos-1){
    curr_pos++;
    prev=prev->next;

}
Node* temp=prev->next;
prev->next=prev->next->next;
delete(temp);
return;



}
int main(){
    Node* head=NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertATTail(head,3);
    display(head);
    insertAtPosition(head,4,2);
    display(head);
    UpdateAtposition(head,2,5);
    display(head);
    deletionAtposition(head,2);
    display(head);

    return 0;

}