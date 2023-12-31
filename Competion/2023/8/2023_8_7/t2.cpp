#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=2e5+7,K=450;
int n,Q;
int a[N],laz[N*4],w[N*4],b[N],c[K][2],k;
int ans[N];

void mg(int u,int l,int r,int x){
    if(l==r)w[u]+=x;
    laz[u]+=x;
}

void pushdown(int u,int l,int r){
	if(l==r)return;
    mg(ls,l,mid,laz[u]);
    mg(rs,mid+1,r,laz[u]);
    laz[u]=0;
}

void cl(int u,int l,int r){
	pushdown(u,l,r);
    w[u]=laz[u]=0;
    if(l==r)return;
    cl(ls,l,mid);
    cl(rs,mid+1,r);
}

void change(int u,int l,int r,int L,int R,int x){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){
        mg(u,l,r,x);
        return;
    }
    pushdown(u,l,r);
    change(ls,l,mid,L,R,x);
    change(rs,mid+1,r,L,R,x);
}

int query1(int u,int l,int r,int x){
    if(l==r&&l==x)return w[u];
    pushdown(u,l,r);
    if(x<=mid) return query1(ls,l,mid,x);
    else return query1(rs,mid+1,r,x);
}

int cx(int x){
    int res=b[x];
    for(int i=1;i<=k;i++){
        if(c[i][0]>res)continue;
        if(c[i][1]>=res)res+=n-c[i][1];
        else res+=c[i][0]-c[i][1]-1;
    }
    return res;
}

void ud();

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> Q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[a[i]]=i;
    }
    k=0;
    while(Q--){
        int x1,x2;
        cin >> x1 >> x2;
        x1=cx(x1),x2=cx(x2);
        k++;
        c[k][0]=x1,c[k][1]=x2;
        //printf("%d %d\n",x1,x2);//
        change(1,1,n,x1,x2,n-x2);
        change(1,1,n,x2+1,n,x1-x2-1);
        //if(k>=2)
        	ud();
        //for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];//
        //for(int i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];//
    }
    ud();
    for(int i=n;i>1;i--)cout << a[i] << " ";
    cout << a[1];
}

void ud(){
    for(int i=1;i<=n;i++){
        int t=query1(1,1,n,i);
        b[ans[t+i]=a[i]]=t+i;
        //printf("%d:%d %d\n",i,t,t+i);//
    }
    //for(int i=1;i<=n;i++)printf("%d:%d\n",i,b[i]);//
    memcpy(a,ans,sizeof a);
    cl(1,1,n);
    k=0;
}