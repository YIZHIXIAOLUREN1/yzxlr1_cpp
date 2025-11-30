#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e6+7;
int n,a[N],b[N],nex[N];

#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int w[N*4],sum[N*4];

void pushup(const int u){w[u]=(w[ls]+w[rs]);sum[u]=(sum[ls]+sum[rs]);}
void clear(int u,int l,int r){
    if(l==r){w[u]=sum[u]=0;return;}
    clear(ls,l,mid);
    clear(rs,mid+1,r);
    pushup(u);
}
pair<int,int> query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return {w[u],sum[u]};
    if(l>R||r<L)return {0,0};
	pair<int,int> res1=query(ls,l,mid,L,R),res2=query(rs,mid+1,r,L,R);
    return {res1.first+res2.first,res1.second+res2.second};
}
void update1(int u,int l,int r,int tg,int x){
    if(l>tg||r<tg)return;
	if(l==r){w[u]+=x,sum[u]+=x*l;return;}////
	
	if(tg<=mid)update1(ls,l,mid,tg,x);
	else update1(rs,mid+1,r,tg,x);
	pushup(u);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans=N;
        for(int i=1;i<=n;i++)a[i]=b[i]=sum[i]=0;
        for(int i=1,ta;i<=n;i++){
            cin>>ta;
            a[ta]++;
        }
        nex[n+1]=0;
        for(int i=n;i>=1;i--){
            nex[i]=nex[i+1]+a[i];
        }
        clear(1,1,n);
        for(int i=1;i<=n;i++){
        	//printf("%d %d %d\n",i,nex[i+1],query(1,1,n,a[i]-1,n));//
            pair<int,int> res=query(1,1,n,a[i]-1,n);
            ans=min(ans,nex[i+1]+res.second-res.first*(a[i]-1));
            update1(1,1,n,a[i],1);
        }
        cout<<ans<<"\n";
    }
}
