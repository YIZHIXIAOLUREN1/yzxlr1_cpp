#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,ll>
#define inf 0x3f3f3f3f3f3f3f3f
inline int read(){
    int res=0,f=1;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return res*f;
}
const int N=2e5+7;
int n;
int a[N];
int num[N],s[N];
ll xs[N],re[N],ans=inf;
vector<int> G[N],Gv[N];

bool cmp(pr a,pr b){
    return a.second>b.second;
}

void dfs1(int u,int fa){
    num[u]=1;
    s[u]=a[u];
    vector<pr> b;
    int tot;
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs1(v,u);
        num[u]+=num[v];
        s[u]+=s[v];
        b.push_back({v,s[v]});
    }
    b.push_back({fa,n-s[u]});
    sort(b.begin(),b.end(),cmp);
    ll p=1;
    xs[u]=a[u];
    for(int i=0;i<b.size();i++){
        Gv[u].push_back(b[i].first);
        if(b[i].first==fa)continue;
        xs[u]+=xs[b[i].first]+p*b[i].second;
        p+=num[b[i].first];
    }
}

void dfs2(int u,int fa){

}

int main(){
    n=read();
    for(int i=1,u,v;i<=n-1;i++){
        u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    dfs1(1,0);
    re[1]=xs[1];
    ans=min(ans,re[1]);
    dfs2(1,0);
}
