#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define ll long long
#define inf 0x3f3f3f3f
int n,m,X,k;
int fa[N];
ll a[N],w[N],u[N],v[N];

int find(int x){
    if(x!=fa[x])return fa[x]=find(fa[x]);
    return x;
}

void hb(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)fa[x]=y;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&X,&k);
    for(int i=1;i<=n;i++)a[i]=inf,fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
        if(w[i]==0)hb(u[i],v[i]);
    }
    for(int i=1;i<=m;i++){
        if(w[i]){
            if(find(u[i])==find(v[i]))
                a[fa[u[i]]]=min(a[fa[u[i]]],w[i]);
            else{
                a[fa[u[i]]]=min(a[fa[u[i]]],2*w[i]);
                a[fa[v[i]]]=min(a[fa[v[i]]],2*w[i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[find(i)]<=(ll)X*k)printf("1 ");
        else printf("0 ");
    }
    if(a[find(n)]<=(ll)X*k)printf("1");
    else printf("0");

}