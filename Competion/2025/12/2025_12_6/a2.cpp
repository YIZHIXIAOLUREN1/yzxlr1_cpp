#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;

int a[N],c[N];
set<int> s1,s2;

void Solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    fill(c+1,c+n+1,1);
    
    while(q--){
        int x;
        cin>>x;
        if(c[x]){
            c[x]=0;
            if(a[x]) s1.insert(x);
            else s2.insert(x);
        }else{
            c[x]=1;
            s1.erase(x);
            s2.erase(x);
        }
        
        if(!s1.empty()&&!s2.empty()){
            for(auto u:s2) a[u]=1;
            s1.insert(s2.begin(),s2.end());
            s2.clear();
        }
    }
    
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    while(T--) Solve();
}