#include<iostream>
#include<climits>
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

class Stack{
    Node* head;
    int capasity;
    int currsize;

    public:
    Stack(int c){
        this->head=NULL;
        this->capasity=c;
        this->currsize=0;


    }

    void push(int val){
        if(this->capasity==this->currsize){
            cout<<"OverFlow"<<endl;
            return;
        }
        Node* new_node=new Node(val);
        new_node->next=this->head;
        this->head=new_node;
        this->currsize++;

    }
    bool isEmty(){
        return this->head==NULL;
    }
    bool isFull(){
        return this->currsize==this->capasity;
    }
    int pop(){
        if(this->head==NULL){
            cout<<"UnderFlow"<<endl;
            return INT_MIN;
        }
        Node* toBeRemove=this->head;
        this->head=this->head->next;
        int result=toBeRemove->val;
        delete(toBeRemove);
        currsize--;
        return result;
    }
    int peek(){
        if(this->head==NULL){
            cout<<"UnderFlow"<<endl;
            return INT_MIN;
        }
        int result=this->head->val;
        return result;
    }
    int size(){
        return this->currsize;
    }
};
int main(){
Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.peek()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.peek()<<endl;

    st.push(6);

    st.pop();
    st.pop();
    cout<<st.peek()<<endl;


    return 0;
}