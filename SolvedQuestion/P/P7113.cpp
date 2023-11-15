#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll __int128
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
#define kg pc(32)
inline ll read(){ll w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
const int N=1e5+7;
int n,m;
vector<int> G[N];
bool out[N];
queue<int> Q;
int in[N];
ll p[N],q[N];

ll gcd(ll a,ll b){
    return (a%b==0)?b:gcd(b,a%b);
}

void yf(int i){
    ll d=gcd(p[i],q[i]);
    p[i]=p[i]/d,q[i]=q[i]/d;
}

void add(int i,ll fz,ll fm){
    p[i]=p[i]*fm+fz*q[i],q[i]=q[i]*fm;
    yf(i);
}

signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    n=read();m=read();
    for(int i=1,d,v;i<=n;i++){
        q[i]=1;
        d=read();
        if(d==0)out[i]=1;
        while(d--){v=read();G[i].push_back(v);in[v]++;}
    }
    for(int i=1;i<=m;i++){
        p[i]=1;
        Q.push(i);
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        if(out[u])continue;
        q[u]=q[u]*G[u].size();
        yf(u);
        for(auto v:G[u]){
            add(v,p[u],q[u]);
            in[v]--;
            if(!in[v])Q.push(v);
        }
    }
    for(int i=1;i<=n;i++)if(out[i]){
        //cout<<p[i]<<" "<<q[i]<<"\n";
        pr(p[i]);kg;pr(q[i]);endl;
    }
    return 0;
}
/*
p1/q1+p2/q2=(p1*q2+q1*p2)/(q1*q2)
*/