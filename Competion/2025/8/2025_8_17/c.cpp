#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=5e6+7;
int w[N*4];
int lazyh[N*4];
int n;
int a[N];
bool v[N];
int s[N];
int ans;

void pushup(const int u){w[u]=(w[ls]+w[rs]);}
void maketag(int u,int l,int r,int xh){
	lazyh[u]=lazyh[u]+xh;
	w[u]=xh*len;
}
void pushdown(int u,int l,int r){
	maketag(ls,l,mid,lazyh[u]);
	maketag(rs,mid+1,r,lazyh[u]);
	lazyh[u]=0;
}
void build(int u,int l,int r){
    if(l==r){w[u]=a[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	pushdown(u,l,r);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
void update1(int u,int l,int r,int L,int R,int xh){
	if(L<=l&&r<=R){maketag(u,l,r,xh);return;}
	if(l>R||r<L)return;
	pushdown(u,l,r);
	update1(ls,l,mid,L,R,xh);
	update1(rs,mid+1,r,L,R,xh);
	pushup(u);
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin>>n;
        memset(w,0,n*4*4);
        for(int i=1;i<=n;i++){
            cin>>a[i];v[i]=0;s[i]=0;
        }
        ans=0;
        int vs=0;
        for(int i=1;i<=n;i++){
        	vs=0;
            //for(int j=1;j<=i-1;j++) if(a[j]>a[i])vs++;
            vs=query(1,1,n,a[i],a[i]);
            vs=2*vs+a[i]-i;
            v[i]=vs%2;
            s[i]=s[i-1]+v[i];
            ans+=v[i];
            update1(1,1,n,1,a[i],1);
            //printf("%d:%d %d\n",i,a[i],v[i]);//
        }
        
        int res1=0,res2=-N;

        int mj1=-N,mj2=-N;
        if(n%2){
            mj1=n-2*s[n];
        }else{
            mj2=n-2*s[n];
        }
        for(int i=n-1;i>=1;i--){
            res2=-N;
            if(i%2){
                res2=max(mj1,mj2+(v[i]?-1:1));
            }else{
                res2=max(mj2,mj1+(v[i]?-1:1));
            }
            res2+=2*s[i]-i;
            res1=max(res1,res2);
            if(i%2){
                mj1=max(mj1,i-2*s[i]);
            }else{
                mj2=max(mj2,i-2*s[i]);
            }
        }
		
        cout<<ans+res1<<"\n";
    }
}
