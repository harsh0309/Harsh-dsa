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
int getLength(Node* head){
        int ctr=0;
        Node* temp=head;
        while(temp!=NULL){
            ctr++;
            temp=temp->next;
        }
        return ctr;
}
Node* move(Node* head,int m){
    Node* temp=head;
    while(m!=0){
        temp=temp->next;
        m--;
    }
    return temp;
}

Node* getintesection(Node* head1,Node* head2){
    int l1=getLength(head1);
    int l2=getLength(head2);

    Node* ptr1=head1;
    Node* ptr2=head2;

    if(l1>l2){
        int m=l1-l2;
        ptr1=move(head1,m);
    }
    else{
        int m=l2-l1;
        ptr2=move(head2,m);
    }
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;    
    }
    return NULL;

}


int main(){
    LinkedList ll1,ll2;

    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head->next->next=ll1.head->next->next->next;
    ll2.display();
    Node* intersection=getintesection(ll1.head,ll2.head);
    
    if(intersection){
        cout<<intersection->val<<endl;
    }
    else{
        cout<<"No Intersection"<<endl;
    }
    
    return 0;
}