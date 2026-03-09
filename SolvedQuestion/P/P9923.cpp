#include<bits/stdc++.h>
using namespace std;
namespace fastio{
    const int SZ=1<<20; char buf[SZ],*p1=buf,*p2=buf,obuf[SZ],*op=obuf;
    #define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++)
    inline void flush(){fwrite(obuf,1,op-obuf,stdout);op=obuf;}
    struct F{~F(){flush();}}f;
    void write(char c){if(op==obuf+SZ)flush();*op++=c;}
    template<class T>typename enable_if<is_integral<T>::value,void>::type read(T&x){
        x=0;int f=1,c=gc();
        if constexpr(is_signed<T>::value){while(!isdigit(c)){if(c=='-')f=-1;c=gc();}}
        else while(!isdigit(c))c=gc();
        while(isdigit(c))x=x*10+(c^48),c=gc();
        if constexpr(is_signed<T>::value)x*=f;
    }

   template<class T,class...A>void read(T&t,A&...a){read(t);read(a...);}
    
    template<class T> typename enable_if<is_integral<T>::value, void>::type write(T x) {
        if(x==0){write('0');return;}
        using U=typename make_unsigned<T>::type;U u=x;
        if constexpr(is_signed<T>::value)if(x<0){write('-');u=-u;}
        static char s[30];int t=0;
        while(u)s[++t]=(u%10)^48,u/=10;
        while(t)write(s[t--]);
    }
    void write(const char*s){while(*s)write(*s++);}
    void write(const string&s){for(char c:s)write(c);}
    template<class T,class...A>void write(T t,A...a){write(t);write(a...);}
}
using fastio::read; using fastio::write;

#define ll long long
const int N=2e5+7;
int n,m;
int d[N],f[N];
vector<pair<int,int>> G[N];
bool vis[N],ans1,a1f,ans2;
int a1g;
int bl[N],tot;
vector<int> out1;
int q[2*N],top,head;
void dfs1(int u,int fa){
	bl[u]=tot;
	vis[u]=1;
    for(auto [v,vi]:G[u]){
        if(v==fa)continue;
        if(!vis[v])dfs1(v,u);
        else if(bl[v]==bl[u])ans1=a1f=1,a1g=v;
        if(ans1){
            if(a1f)out1.push_back(vi);
            if(u==a1g)a1f=0;
            return;
        }
    }
}
void print(){
    write("TAK\n",out1.size(),'\n');
    for(auto u:out1)write(u,' ');
}
void Solve(){
    read(n,m);
    for(int i=1,x,y;i<=m;i++){
        read(x,y);
        y+=n;
        G[x].push_back({y,i});
        G[y].push_back({x,i});
        d[x]++;d[y]++;
    }

    for(int i=1;i<=2*n;i++){
        if(!vis[i]){bl[i]=++tot;dfs1(i,0);}
        if(ans1)break;
    }
    if(ans1){print();return;}

    head=1;
    for(int i=1;i<=2*n;i++)if(d[i]==1)q[++top]=i;

    while(head<=top){
        int u=q[head];head++;
        if(!d[u])continue;
        d[u]--;
        for(auto [v,vi]:G[u]){
            if(!d[v])continue;
            d[v]--;
            if(!f[u]){
                out1.push_back(vi);
                f[u]^=1;f[v]^=1;
            }
            if(d[v]==1)q[++top]=v;
        }
    }
    for(int i=1;i<=2*n;i++)if(!f[i]){write("NIE");return;}
    print();
}

signed main(){
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
