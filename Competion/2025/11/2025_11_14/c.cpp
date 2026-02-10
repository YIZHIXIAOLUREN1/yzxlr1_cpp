#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,a[N];
ll pre[N],cr[N];
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
ll w[N*4];

void pushup(const int u){w[u]=max(w[ls],w[rs]);}
void build(int u,int l,int r){
    if(l==r){w[u]=cr[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
            ans+=a[i];
        }
        for(int i=1;i<=n;i++)cr[i]=i*i+i+pre[n]-pre[i];
        //for(int i=1;i<=n;i++)printf("%lld:%lld %lld\n",i,pre[i],cr[i]);//
        build(1,1,n);
        for(int l=1;l<=n;l++){
            int res=l-l*l+pre[l-1];
            //printf("%lld:%lld %lld\n",l,res,query(1,1,n,l,n));//
            res+=query(1,1,n,l,n);
            ans=max(ans,res);
        }
        cout<<ans<<"\n";
    }
}
/*

[l,r] (r-l+1)*(l+r)->r^2+r+l-l^2
->l l-l^2+pre[l-1]
r r^2+r+pre[n]-pre[r],l<=r<=n
*/