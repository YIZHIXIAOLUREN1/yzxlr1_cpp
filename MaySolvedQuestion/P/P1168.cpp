#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> q1;
priority_queue<int, vector<int> ,greater<int>> q2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(q1.empty()||x<=q1.top())q1.push(x);
        else q2.push(x);
        if(q1.size()>q2.size()+1)q2.push(q1.top()),q1.pop();
        else if(q1.size()<q2.size())q1.push(q2.top()),q2.pop();
        if(i&1)cout << q1.top() << endl;
    }

}