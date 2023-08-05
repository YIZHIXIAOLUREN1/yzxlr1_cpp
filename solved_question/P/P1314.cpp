#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200100;
int w[N],v[N],l[N],r[N];
int n,m,mw;
ll s;
ll pv[N],pw[N];

ll check(int x){
    pv[0]=pw[0]=0;
    for(int i=1;i<=n;i++){
        if(w[i]>=x){
            pv[i]=pv[i-1]+v[i];
            pw[i]=pw[i-1]+1;
        }else{
            pv[i]=pv[i-1];
            pw[i]=pw[i-1];
        }
    }
    ll res=0;
    for(int i=1;i<=m;i++){
        res+=(pw[r[i]]-pw[l[i]-1])*(pv[r[i]]-pv[l[i]-1]);
    }
    return res;
}

int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
        mw=max(mw,w[i]);
        }
    for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
    
    int l=0,r=mw+10;
    ll ans=1e12+5;
    while(l<=r){
        int mid=(l+r)>>1;
        ll W=check(mid);
        //printf("%d:%lld\n",mid,W);//
        ans=min(ans,abs(W-s));
        if(W>s)l=mid+1;
        else r=mid-1;
    }
    
    printf("%lld",ans);

}