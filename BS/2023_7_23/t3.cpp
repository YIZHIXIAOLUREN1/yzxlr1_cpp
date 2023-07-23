#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,ll>
#define prr pair<int,pair<int,ll>>
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
int n,ns;
int a[N];
int num[N],s[N];
ll xs[N],ss[N],re[N],ans=inf;
vector<int> G[N];

bool cmp1(pr a,pr b){
    return a.second>b.second;
}

void dfs1(int u,int fa){
	//printf("1:%d\n",u);//
    num[u]=1;
    s[u]=a[u];
    vector<pr> b;
    b.clear();
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs1(v,u);
        num[u]+=num[v];
        s[u]+=s[v];
        b.push_back({v,s[v]});
    }
    if(fa!=0)b.push_back({fa,ns-s[u]});
    sort(b.begin(),b.end(),cmp1);
    ll p=1;
    xs[u]=a[u];
    for(int i=0;i<b.size();i++){
        if(b[i].first==fa)continue;
        xs[u]+=xs[b[i].first]+p*b[i].second;
        p+=num[b[i].first];
    }
}

void dfs2(int u,int fa){
	//printf("1:%d\n",u);//
    vector<pr> b;
    b.clear();
    for(auto v:G[u]){
        if(v==fa)continue;
        b.push_back({v,s[v]});
    }
    if(fa!=0)b.push_back({fa,ns-s[u]});
    sort(b.begin(),b.end(),cmp1);
    ll p=1;
    re[u]=a[u];
    for(int i=0;i<b.size();i++){
        if(b[i].first==fa){
            re[u]+=ss[b[i].first]+p*b[i].second;
            p+=n-num[u];
        }
        else{
        	re[u]+=xs[b[i].first]+p*b[i].second;
        	p+=num[b[i].first];
        }
    }
    ans=min(ans,re[u]);
    //printf("%d:%lld %lld %d %d\n",u,re[u],xs[u],s[u],num[u]);//
    for(auto v:G[u]){
        if(v==fa)continue;
        b.clear();
        for(auto vv:G[u]){
            if(vv==v||vv==fa)continue;
            b.push_back({vv,s[vv]});
        }
        if(fa!=0)b.push_back({fa,ns-s[u]});
        sort(b.begin(),b.end(),cmp1);
        p=1;
        ss[u]=a[u];
        for(int i=0;i<b.size();i++){
            if(b[i].first==fa){
                ss[u]+=ss[b[i].first]+p*b[i].second;
                p+=n-num[u];
            }
            else{
            	ss[u]+=xs[b[i].first]+p*b[i].second;
            	p+=num[b[i].first];
            }
        }
        //printf("%d %d:%lld\n",u,v,ss[u]);//
        dfs2(v,u);
    }
}

bool cmp2(prr a,prr b){
    if(a.second.first!=b.second.first)return a.second.first<b.second.first;
    return a.second.second>b.second.second;
}

void dfs3(int u,int fa){
    num[u]=1;
    s[u]=a[u];
    vector<prr> b;
    b.clear();
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs3(v,u);
        num[u]+=num[v];
        s[u]+=s[v];
        b.push_back({v,{num[v],s[v]}});
    }
    if(fa!=0)b.push_back({fa,{n-num[u],ns-s[u]}});
    sort(b.begin(),b.end(),cmp2);
    ll p=1;
    xs[u]=a[u];
    for(int i=0;i<b.size();i++){
        if(b[i].first==fa)continue;
        xs[u]+=xs[b[i].first]+p*b[i].second.second;
        p+=b[i].second.first;
    }
}

void dfs4(int u,int fa){
    vector<prr> b;
    b.clear();
    for(auto v:G[u]){
        if(v==fa)continue;
        b.push_back({v,{num[v],s[v]}});
    }
    if(fa!=0)b.push_back({fa,{n-num[u],ns-s[u]}});
    sort(b.begin(),b.end(),cmp2);
    ll p=1;
    re[u]=a[u];
    for(int i=0;i<b.size();i++){
        if(b[i].first==fa)
            re[u]+=ss[b[i].first]+p*b[i].second.second;
        else 
            re[u]+=xs[b[i].first]+p*b[i].second.second;
        p+=b[i].second.first;
    }
    ans=min(ans,re[u]);
    //printf("%d:%lld %lld %d %d\n",u,re[u],xs[u],s[u],num[u]);//
    for(auto v:G[u]){
        if(v==fa)continue;
        b.clear();
        for(auto vv:G[u]){
            if(vv==v||vv==fa)continue;
            b.push_back({vv,{num[vv],s[vv]}});
        }
        if(fa!=0)b.push_back({fa,{n-num[u],ns-s[u]}});
        sort(b.begin(),b.end(),cmp2);
        p=1;
        ss[u]=a[u];
        for(int i=0;i<b.size();i++){
            if(b[i].first==fa)
            ss[u]+=ss[b[i].first]+p*b[i].second.second;
        else 
            ss[u]+=xs[b[i].first]+p*b[i].second.second;
        p+=b[i].second.first;
        }
        //printf("%d %d:%lld\n",u,v,ss[u]);//
        dfs4(v,u);
    }
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
        ns+=a[i];
    }
    dfs1(1,0);
    re[1]=xs[1];
    ans=min(ans,re[1]);
    dfs2(1,0);
    dfs3(1,0);
    re[1]=xs[1];
    ans=min(ans,re[1]);
    dfs4(1,0);
    cout << ans;
}