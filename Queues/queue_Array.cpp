#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
    public:
    Queue(){
        front=-1;
        back=-1;
    }
    void enque(int data){
        if(front==-1){
            v.clear();
            v.push_back(data);
            front=0;
            back=0;
        }
        else{
            v.push_back(data);
            back++;
        }
    }
    void deque(){
        if(front==back){
            back=-1;
            front=-1;
            v.clear();
        }
        else{
            front++;
        }

    }
    int getFront(){
        if(front==-1) return -1;
        return v[front];
    }
    bool isEmpty(){
        return front==-1;
    }
};
int main(){
    Queue qu;
    qu.enque(10);
    qu.enque(20);
    qu.enque(30);
    qu.deque();
    qu.enque(40);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<endl;
        qu.deque();
    }
    qu.enque(400);
    qu.enque(500);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<endl;
        qu.deque();
    }
    return 0;
}