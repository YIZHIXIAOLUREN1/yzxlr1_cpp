#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=2e5+7,inf=0x3f3f3f3f;
int n,Q;
int a[N],b[N];
int ans;
int tg[N];
int w[N*4];
int lazy[N*4];
vector<pair<int,int>> nod;

void push_up(int u){w[u]=(w[ls]+w[rs]);}
void maketag(int u,int l,int r,int tg){
    lazy[u]+=tg;
    w[u]+=len*tg;
}
void pushdown(int u,int l,int r){
    maketag(ls,l,mid,lazy[u]);
    maketag(rs,mid+1,r,lazy[u]);
    lazy[u]=0;
}
void build(int u,int l,int r){
    lazy[u]=0;
    if(l==r){w[u]=0;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(u);
}
int query(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
    pushdown(u,l,r);
    return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
void update(int u,int l,int r,int L,int R,int tg){
    if(L<=l&&r<=R){maketag(u,l,r,tg);return;}
    if(l>R||r<L)return;
    pushdown(u,l,r);
    update(ls,l,mid,L,R,tg);
    update(rs,mid+1,r,L,R,tg);
    push_up(u);
}

int ef(int x){
    int l=0,r=nod.size()-1;
    while(l<r){
        if(nod[mid].first>x)r=mid-1;
        else if(nod[mid].second<x)l=mid+1;
        else l=r=mid;
    }
    return l;
}
void update(int x,int val){

    for(int i=1;i*i<=x;i++){
        if(x%i)continue;
        int bi=query(1,1,n,i,i);
        if(i*i==n){
            if(bi==val)continue;

        }else{
            if(bi!=val){

            }
            int bxi=query(1,1,n,x/i,x/i);
            if(bxi!=val){
                
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        build(1,1,n);
        nod.clear();
        ans=n;
        a[0]=inf,a[n+1]=-inf;
        for(int i=1,l=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<a[i-1]){
                nod.push_back({l,i-1});
                l=i;
            }
            if(i==n)nod.push_back({l,n});
        }
        for(int i=1;i<nod.size();i++){
            int x=nod[i].first-1;//x%k==0
            update(x,0);
        }
        cout<<ans<<"\n";
        while(Q--){
            int v,w;
            cin>>v>>w;
            auto [l,r]=nod[ef(v)];
            if(l<v&&v<r){
                if(w>a[v+1]){
                    update(v,0);
                }else if(w<a[v-1]){
                    update(v-1,0);
                }
            }else if(l==v){
                if(a[v-1]>a[v+1]){
                    if(w>a[v+1]&&w<a[v-1]){
                        update(v-1,0);
                        update(v,0);
                    }else if(w>=a[v-1]){
                        update(v-1,1);
                        update(v,0);
                    }
                }else{
                    if(w<=a[v-1]&&w<=a[v]){

                    }
                }
            }
        }
    }
}