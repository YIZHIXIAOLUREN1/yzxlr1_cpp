#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+7,MA=1e6+7;
int n,m,wm,w[N],v[N],nl[N],nr[N];
ll s,pre[N],ss[N];
ll ans;

ll check(int ww){
    ll res=0;
    for(int i=1;i<=n;i++){
        if(w[i]>=ww)pre[i]=pre[i-1]+v[i],ss[i]=ss[i-1]+1;
        else pre[i]=pre[i-1],ss[i]=ss[i-1];
    }
    for(int i=1;i<=m;i++){
        res+=(pre[nr[i]]-pre[nl[i]-1])*(ss[nr[i]]-ss[nl[i]-1]);
    }
    return res;
}

void erfen(){
    int l=0,r=wm;
    ll lc=check(0),rc=check(wm),mc;
    ans=min(abs(lc-s),abs(rc-s));
    //printf("%d %d\n",lc,rc);//
    while(l<=r){
        int mid=(l+r)>>1;
        mc=check(mid);
        ans=min(ans,abs(mc-s));
        //printf("%d %d:%d:%d\n",l,r,mid,mc);//
        if(mc==s)break;
        else if(mc>s)l=mid+1;
        else r=mid-1;
    }
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++){cin >> w[i] >> v[i];wm=max(wm,w[i]);}
    for(int i=1;i<=m;i++){cin >> nl[i] >> nr[i];}
    erfen();
    cout<<ans;
    return 0;
}
