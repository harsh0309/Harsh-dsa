#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<int> qu;
    stack<int> st;
    cout<<"No. of element"<<endl;
    int n;
    cin>>n;
    while(n>0){
        int q;
        cin>>q;
        qu.push(q);
        n--;
    }
    cout<<endl;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }
       while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}