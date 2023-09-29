#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f;
int n;
ll a[N],b[N];
ll mp[N];
int ans;
int f[N];

ll laz[N*4];

void maketag(int u,ll x){laz[u]=min(laz[u],x);}
void pushdown(int u){maketag(ls,laz[u]);maketag(rs,laz[u]);}
ll query(int u,int l,int r,int x){
	//printf("%d:%d %d:%d\n",u,l,r,x);//
	if(l==r)return mp[l]=min(mp[l],laz[u]);
    pushdown(u);
	if(x<=mid)return query(ls,l,mid,x);
	else return query(rs,mid+1,r,x);
}
void updateq(int u,int l,int r,int L,int R,ll x){
	//printf("%d:%d %d:%d %d:%lld\n",u,l,r,L,R,x);//
	if(L<=l&&r<=R){maketag(u,x);return;}
	if(l>R||r<L)return;
    pushdown(u);
	updateq(ls,l,mid,L,R,x);
	updateq(rs,mid+1,r,L,R,x);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];
    memset(mp,0x3f,sizeof mp);
    memset(laz,0x3f,sizeof laz);
    mp[0]=0;
    for(int i=1;i<=n;i++){
        int l=0,r=ans;
        while(l<r){
        	if(query(1,0,n,mid)*b[mid]<a[i])l=mid+1;
        	else r=mid-1;
        }
        while(l<ans&&query(1,0,n,l)*b[l+1]<a[i])l++;
        while(l>0&&query(1,0,n,l)*b[l]>=a[i])l--;
        f[i]=l+1;
        //for(int j=0;j<=l;j++)mp[j+1]=min(mp[j+1],a[i]);
        updateq(1,0,n,1,l+1,a[i]);
        ans=max(ans,f[i]);
        //printf("%d:%d\n",i,f[i]);//
    }
    cout << ans;
}