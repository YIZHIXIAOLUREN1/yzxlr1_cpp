#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=res*x;
        x=x*x;
        q>>=1;
    }
    return res;
}
ll ans[20],res;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        res=0;
        for(ll j=1,i=1;j<=18;j++){
            i=1+qp(10,j);
            if(i>n)break;
            if(n%i==0){
                ans[++res]=n/i;
            }
        }
        cout<<res<<"\n";
        if(!res)continue;
        for(int i=res;i>=1;i--){
            cout<<ans[i]<<" \n"[i==1];
        }
    }
}
