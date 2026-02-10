#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m,k,l,r;
int a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>l>>r;
    while(k--){
        int x,y,v;
        cin>>x>>y>>v;
        if(v<=l)v=100;
        else if(v>=r)v=0;
        a[x]+=v;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}
