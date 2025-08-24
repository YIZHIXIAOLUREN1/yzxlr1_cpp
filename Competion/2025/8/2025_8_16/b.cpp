#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
priority_queue <int,vector<int>,greater<int>> q;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int Q;
    cin>>Q;
    while(Q--){
        int ty,x;
        cin>> ty;
        if(ty==1){
            cin>>x;
            q.push(x);
        }else{
            cout<<q.top()<<"\n";
            q.pop();
        }
    }
}
