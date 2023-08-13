#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int T;
int n;
priority_queue<int> q;
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        ans=0;
        while(!q.empty())q.pop();
        int a;
        for(int i=1;i<=n;i++){
        	cin >> a;
        	q.push(a);
        }
        while(!q.empty()){
            int u=q.top();
            q.pop();
            if(q.empty())break;
            int v=q.top();
            q.pop();
            ans+=v;
            q.push(u-v);
        }
        cout << ans << "\n";
    }
}
