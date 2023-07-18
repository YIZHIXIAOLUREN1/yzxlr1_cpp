#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector <int>, greater <int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--){
        int op,x;
        cin >> op;
        if(op==1){cin >> x;q.push(x);}
        else if(op==2) cout << q.top() << endl;
        else q.pop();
    }

}