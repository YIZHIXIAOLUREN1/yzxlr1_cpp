#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll x,a,b,c,ans,res,st;
ll qp[15];

void Solve(){
    qp[0]=1;
    for(int i=1;i<=14;i++)qp[i]=qp[i-1]*10;
    ans=inf;
    st=res=0;
    cin>>x>>a>>b>>c;
    while(1){
        res=st;
        ll cc=0,res2=inf;
        for(int len=0;len<=14;len++){
            for(ll chk=1005;chk<=1010;chk++){
            	ll l=chk*qp[len],r=(chk+1)*qp[len]-1;
            	if(l<=x&&x<=r){
            		res2=0;
            		len=15;break;
            	}
                if(x<l){
                	cc=(l-x-1)/c+1;
                	if(x+cc*c<=r)res2=min(res2,cc*b);
                }
            }
        }
        
        res+=res2;
        ans=min(ans,res);
        if(x==0)break;
        x/=10;
        st+=a;
    }

    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
