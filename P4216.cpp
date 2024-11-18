#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=2e5+7;
int n,Q,root;
vector<int> G[N];
int dfn[N],tot,ran[N],fa[N],son[N],siz[N],top[N],d[N];
int W[N*4],a[N];

void dfs1(int u){
    siz[u]=1;
    for(auto v:G[u]){
        fa[v]=u;
        d[v]=d[u]+1;
        dfs1(v);
        siz[u]+=siz[v];
        if(!son[u]||siz[v]>siz[son[u]])son[u]=v;
    }
}

void dfs2(int u,int topp){
    dfn[u]=tot;
    ran[++tot]=u;
    top[u]=topp;
    if(son[u])dfs2(son[u],topp);
    for(auto v:G[u]){
        if(v==son[u])continue;
        dfs2(v,v);
    }
}
void pushup(int u){W[u]=W[ls]+W[rs];}
void dcg(int u,int l,int r,int x,int dx){
    if(l==r){W[u]+=dx;return;}
    else if(x<=mid)dcg(ls,l,mid,x,dx);
    else dcg(rs,mid+1,r,x,dx);
}

int qu(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    else if(l>=L&&r<=R)return W[u];
    else return qu(ls,l,mid,L,R)+qu(rs,mid+1,r,L,R);
}

pair<int,int> cx(int x,int y){
    int res1=0,res2=0;
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        res1+=d[x]-d[fa[top[x]]];
        res2+=qu(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    res1+=d[x]-d[y]+1;
    res2+=qu(1,1,n,dfn[x],dfn[y]);
    return {res1,res2};
}

struct node2{
    int x,dx;
}cg[N];
struct node{
    int L;int R;
    int mi;
}qq[N];
int totc,totq;
bool cmp1(node x,node y){
    return x.mi<y.mi;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,ffa;i<=n;i++){
        cin >> ffa;
        if(ffa)G[ffa].push_back(i);
        else root=i;
    }
    dfs1(root);
    dfs2(root,root);
    for(int i=1;i<=Q;i++){
        int md,x,y,c;
        cin>>md;
        if(md==1){cin>>x>>y>>c;qq[++totq]=(node){x,y,i-c+1};}
        else{cin>>x;cg[++totc]=(node2){x,i};}
    }

    sort(qq+1,qq+totq+1,cmp1);

    int j=0;
    for(int i=1;i<=totq;i++){
        while(j<totc&&cg[j+1].dx<qq[i].mi){
            j++;dcg(1,1,n,dfn[cg[j].x],1);
        }
        pair<int,int> res=cx(qq[i].L,qq[i].R);
        cout<<res.first<<" "<<res.second<<" \n";
    }

    return 0;
}
