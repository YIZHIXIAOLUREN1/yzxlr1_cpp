#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10;
int n,a[N];
int b[N];
int ans=0x3f3f3f3f;

void dfs(int u,int tot){
    if(u==(n+1)>>1){
        ans=min(ans,tot);
        return;
    }
    int x=b[u+1],y=b[n-u];
    if(x==y)dfs(u+1,tot);
    else{
        b[u+1]=y;
        dfs(u+1,tot+(y>x?y-x:10+y-x));
        b[u+1]=x;
        b[n-u]=x;
        dfs(u+1,tot+(x>y?x-y:10+x-y));
        b[n-u]=y;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    n=s.size();
    for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
    memcpy(b,a,sizeof a);
    dfs(0,0);
    cout << ans;
}