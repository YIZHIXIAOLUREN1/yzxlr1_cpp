#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=3e5+7,mod=998244353;
int n;
ll kk;
int k[N],len=0,st=1,en,a[N];

int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        len=0,st=1;
        cin>>n>>kk;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(kk){
            k[++len]=kk%2;
            kk/=2;
        }
        en=len;
        for(int i=1;i<=n;i++){
            if(i&1){
                st+=a[i];
                en+=a[i];
            }else{
                st-=a[i];
                en-=a[i];
                st=max(st,1ll*1);
                en=max(en,1ll*0);
            }
        }

        ll ans=0,ns=qp(2,st-1);
        //if(en<st){cout<<"0\n";continue;}
        for(int i=st;i<=en;i++){
            int j=i-en+len;
            ans=(ans+k[j]*ns)%mod;
            ns=ns*2%mod;
        }
        cout<<ans<<"\n";
    }
}
