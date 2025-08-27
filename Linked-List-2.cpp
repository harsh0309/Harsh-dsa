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
void deleteAlternateNode(Node* &head){
    Node* curr=head;
    Node* temp=head;
    while(curr!=NULL && curr->next!=NULL ){
        temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
        curr=curr->next;
      
    }

}
void deleteDuplicateElements(Node* &head){
    Node* curr=head;
    Node* temp=head;
    while(curr!=NULL&&curr->next!=NULL){
        if(curr->val==curr->next->val){
            temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);

        }
        else{
            curr=curr->next;
        }
        
    }



}
void reversePrint(Node* &head){
    if(head==NULL){
        return;
    }
    reversePrint(head->next);
    cout<<head->val<<"->";
}
Node* reverseLL(Node* &head){
    Node* pev=NULL;
    Node* curr=head;

    while(curr){
        Node* nex=curr->next;
        curr->next=pev;
        pev=curr;
        curr=nex;

    }
    return pev;


}
Node* recursiveLLreverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* new_head=recursiveLLreverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;


}
Node* reccursiveKLL(Node* &head,int k){
    Node* pev=NULL;
    Node* curr=head;
    int ctr=0;
    while(curr!=NULL && ctr<k){
        Node* nex=curr->next;
        curr->next=pev;
        pev=curr;
        curr=nex;
        ctr++;
    }
    if(curr!=NULL){
        Node* new_head=reccursiveKLL(curr,k);
        head->next=new_head;

    }
    return pev;












}


int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.display();
    ll.insertAtTail(2);
    ll.display();
    ll.insertAtTail(3);
    ll.display();
    ll.insertAtTail(4);
    ll.display();
    ll.insertAtTail(5);
    ll.display();
    ll.insertAtTail(6);
    ll.display();

    //deleteAlternateNode(ll.head);
    //deleteDuplicateElements(ll.head);
    //reversePrint(ll.head);
    //ll.head=reccursiveKLL(ll.head,2);
    cout<<endl;
    ll.display();


    return 0;

}





