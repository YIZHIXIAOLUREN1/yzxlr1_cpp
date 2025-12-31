#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;

void Solve(){
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    ll ans=4e18;
    vector<pair<ll,ll>> v;
    ll cur=x,cst=0;
    v.push_back({cur,cst});
    while(cur>0){
        cur/=10;
        cst+=a;
        v.push_back({cur,cst});
    }
    for(auto p:v){
        ll val=p.first,bas=p.second;
        ll p10=1;
        for(int k=0;k<=15;++k){
            for(int pre=1005;pre<=1010;++pre){
                ll L=(ll)pre*p10;
                ll R=L+p10-1;
                if(R<val)continue;
                ll st=max(L,val);
                ll rem=val%c;
                ll crem=st%c;
                ll add=(rem-crem+c)%c;
                ll Y=st+add;
                if(Y<=R){
                    ll m=(Y-val)/c;
                    if(m>2e14)continue;
                    ans=min(ans,bas+m*b);
                }
            }
            if(k<15)p10*=10;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}