#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
const int N=57,inf=0x3f3f3f3f;
int n,A,B,w[N];
int f[N][N];
int ma[N*2],mi[N*2];

void pushup(int u){ma[u]=max(ma[ls],ma[rs]);mi[u]=min(mi[ls],mi[rs]);}
void build(int u,int l,int r){
    if(l==r){ma[u]=mi[u]=w[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

int qa(int u,int l,int r,int L,int R){
    if(L>r||R<l)return 0;
    if(L<=l&&R>=r)return ma[u];
    return max(qa(ls,l,mid,L,R),qa(rs,mid+1,r,L,R));
}
int qi(int u,int l,int r,int L,int R){
    if(L>r||R<l)return inf;
    if(L<=l&&R>=r)return mi[u];
    return min(qi(ls,l,mid,L,R),qi(rs,mid+1,r,L,R));
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(mi,0x3f,sizeof mi);
    cin >> n >> A >> B;
    for(int i=1;i<=n;i++)cin>>w[i];
    build(1,1,n);
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n+1-len;i++){
            int j=i+len-1;
            int qma=qa(1,1,n,i,j),qmi=qi(1,1,n,i,j);
            f[i][j]=A+B*(qma-qmi)*(qma-qmi);
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
            printf("%d %d:%d\n",i,j,f[i][j]);//
        }
    }
    cout<<f[1][n];
    return 0;
}
