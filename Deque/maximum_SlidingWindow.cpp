#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> arr,int k){
    vector<int> res;
    deque<int> dq;

    for(int i=0;i<k;i++){
        while(not dq.empty() and arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    for(int i=k;i<arr.size();i++){
        int curr=arr[i];
        if(dq.front()==(i-k)) dq.pop_front();
        while(not dq.empty() and arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    
    
    }
    return res;


}
int main(){
    int x;
    cin>>x;
    vector<int> v(x);
    for(int i=0;i<x;i++){
        cin>>v[i];
    }
    vector<int> ans=maxSlidingWindow(v,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}