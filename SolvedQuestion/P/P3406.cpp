#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
int pre[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    
    for(int i=1,p1,p2;i<=m;i++){
        cin>>p2;
        if(i==1){p1=p2;continue;}
        if(p1>p2)pre[p2]++,pre[p1]--;
        else pre[p1]++,pre[p2]--;
        p1=p2;
    }

    ll ans=0,res=0;
    for(int i=1,a,b,c;i<n;i++){
        res+=pre[i];
        cin>>a>>b>>c;
        ans+=min(res*a,c+res*b);
    }
    cout<<ans;
}
