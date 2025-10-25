#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=2e5+7,inf=0x3f3f3f3f;
int n,Q;
int a[N],b[N];//b[i]+px;
int ans;
int c[2*N];//c[i+2*N-px]
int px=N;
int qlr[2][N];
int W[2][N*4];
int lazy[N*4];
void maketag(int o,int u,int l,int r,int tg){
    if(!tg)return;
    lazy[u]=tg;
    W[o][u]=tg;
}
void pushdown(int o,int u,int l,int r){
    maketag(o,ls,l,mid,lazy[u]);
    maketag(o,rs,mid+1,r,lazy[u]);
}
void build(int o,int u,int l,int r){
    lazy[u]=0;
    if(l==r){W[o][u]=qlr[o][l];return;}
    build(o,ls,l,mid);
    build(o,rs,mid+1,r);
}
int query1(int o,int u,int l,int r,int L){
    if(l==r)return W[o][u];
    pushdown(o,u,l,r);
    if(L<=mid)return query1(o,ls,l,mid,L);
    else return query1(o,rs,mid+1,r,L);
}
void updateq(int o,int u,int l,int r,int L,int R,int tg){
	if(R>L)return;
    if(L<=l&&r<=R){maketag(o,u,l,r,tg);return;}
    if(l>R||r<L)return;
    pushdown(o,u,l,r);
    updateq(o,ls,l,mid,L,R,tg);
    updateq(o,rs,mid+1,r,L,R,tg);
}

void update(int x,int val){
    for(int i=1;i*i<=x;i++){
        if(x%i)continue;
        if(i*i==x){
            c[b[i]+2*N]--;
            c[b[i]+2*N-val]++;
            b[i]-=val;
        }else{
            c[b[i]+2*N]--;
            c[b[i]+2*N-val]++;
            b[i]-=val;
            c[b[x/i]+2*N]--;
            c[b[x/i]+2*N-val]++;
            b[x/i]-=val;
        }
    }
    px+=val;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        
        ans=n;
        px=N;
        for(int i=-n;i<=n;i++)c[i]=0;
        c[2*N-px]=n;
        a[0]=-inf,a[n+1]=inf;
        for(int i=1,l=1;i<=n;i++){
            b[i]=-N;
            cin>>a[i];
        }
        qlr[0][1]=1;
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]){
                qlr[0][i]=i;
            }else{
                qlr[0][i]=qlr[0][i-1];
            }
        }
        qlr[1][n]=n;
        for(int i=n-1;i>=1;i--){
            if(a[i]>a[i+1]){
                qlr[1][i]=i;
            }else{
                qlr[1][i]=qlr[1][i+1];
            }
        }
        build(0,1,1,n);build(1,1,1,n);
        for(int i=1;i<=n;i++)printf("%d:%d %d\n",i,qlr[0][i],qlr[1][i]);//
        for(int i=1;i<=n;i++){
            if(i!=qlr[0][i])continue;
            update(i-1,1);
        }
        cout<<c[2*N-px]<<"\n";
        for(int i=0;i<=n;i++)printf("%d:%d\n",i,c[i+2*N-px]);//
        while(Q--){
            int v,w;
            cin>>v>>w;
            int l=query1(0,1,1,n,v),r=query1(1,1,1,n,v);
            cout<<l<<" "<<r<<":\n";//
            if(l<v&&v<r){
                if(w>a[v+1]){
                    update(v,1);
                    updateq(1,1,1,n,l,v,v);
                    updateq(0,1,1,n,v+1,r,v+1);
                }else if(w<a[v-1]){
                    update(v-1,1);
                    updateq(1,1,1,n,l,v-1,v-1);
                    updateq(0,1,1,n,v,r,v);
                }
            }else if(l==v){
                if(a[v-1]>a[v+1]){
                    if(w>a[v+1]&&w<a[v-1]){
                        update(v-1,1);
                        update(v,1);
                        updateq(1,1,1,n,query1(0,1,1,n,v-1),v-1,v-1);
                        updateq(0,1,1,n,v+1,r,v+1);
                        updateq(0,1,1,n,v,v,v);
                        updateq(1,1,1,n,v,v,v);
                    }else if(w>=a[v-1]){
                        update(v-1,-1);
                        update(v,1);
                        updateq(1,1,1,n,query1(0,1,1,n,v-1),v,v);
                        updateq(0,1,1,n,v+1,r,v+1);
                    }
                }else{
                    if(w>=a[v-1]&&w<=a[v+1]){
                        update(v-1,-1);
                        int nl=query1(0,1,1,n,v-1),nr=r;
                        updateq(0,1,1,n,nl,r,nl);
                        updateq(1,1,1,n,nl,r,r);
                    }else if(w>a[v+1]){
                        update(v-1,-1);
                        update(v,1);
                        updateq(1,1,1,n,query1(0,1,1,n,v-1),v,v);
                        updateq(0,1,1,n,v+1,r,v+1);
                    }
                }
            }else{//r==v
                if(a[v-1]>a[v+1]){
                    if(w>a[v+1]&&w<a[v-1]){
                        update(v,1);
                        updateq(1,1,1,n,l,v,v);
                        updateq(0,1,1,n,v+1,query1(1,1,1,n,v+1),v+1);
                    }else if(w<=a[v+1]){
                        update(v+1,-1);
                        update(v,1);
                        updateq(1,1,1,n,l,v-1,v-1);
                        updateq(0,1,1,n,v,query1(1,1,1,n,v+1),v);
                    }
                }else{
                    if(w>=a[v-1]&&w<=a[v+1]){
                        update(v+1,-1);
                        int nr=query1(1,1,1,n,v+1);
                        updateq(0,1,1,n,l,nr,l);
                        updateq(1,1,1,n,l,nr,nr);
                    }else if(w<a[v-1]){
                        update(v,1);
                        update(v+1,-1);
                        updateq(1,1,1,n,l,v-1,v-1);
                        updateq(0,1,1,n,v,query1(1,1,1,n,v+1),v);
                    }
                }
            }
            for(int i=1;i<=n;i++)printf("%d:%d %d\n",i,query1(0,1,1,n,i),query1(1,1,1,n,i));//
			a[v]=w;
            cout<<c[2*N-px]<<"\n";
            for(int i=0;i<=n;i++)printf("%d:%d\n",i,c[i+2*N-px]);//
        }
    }
}