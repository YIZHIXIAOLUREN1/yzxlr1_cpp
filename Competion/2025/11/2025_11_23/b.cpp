#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,m,a[N],b[N],c[N];
ll sum[N],sc[N];

bool check(ll x){
    bool res=1;
    ll tc=0;
    for(int i=1;i<=m;i++){
        if(sum[i]<x)return 0;
        tc+=min(sc[i],sum[i]-x);
    }
    return tc>=x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        sum[a[i]]+=b[i];
        if(c[i])sc[a[i]]++;
    }
    ll l=0,r=0;
    for(int i=1;i<=m;i++)r=max(r,sum[i]);
    r++;
    while(l<r){
        ll mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    while(l&&!check(l))l--;
    while(check(l+1))l++;
    cout<<l;
}
