#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    void read(double&x){
        x=0;int f=1,c=gc();
        while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
        while(isdigit(c))x=x*10+(c^48),c=gc();
        if(c=='.'){double b=1;c=gc();while(isdigit(c))b/=10,x+=b*(c^48),c=gc();}
        x*=f;
    }
    void read(char&c){int t=gc();while(isspace(t))t=gc();c=t;}
    void read(char*s){int c=gc();while(isspace(c))c=gc();while(c!=-1&&!isspace(c))*s++=c,c=gc();*s=0;}
    void read(string&s){s.clear();int c=gc();while(isspace(c))c=gc();while(c!=-1&&!isspace(c))s+=c,c=gc();}
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
    void write(double x,int p=6){
        if(x<0)write('-'),x=-x;
        long long i=(long long)x;write(i);write('.');x-=i;
        while(p--){x*=10;int d=(int)x;write((char)(d+'0'));x-=d;}
    }
    template<class T,class...A>void write(T t,A...a){write(t);write(a...);}
}
using fastio::read; using fastio::write;
const int N=1e5+7,B1=2200,B2=6000,S1=(N-1)/B1+1,S2=(N-1)/B2+1;
int n,m,qq,a[2][N],b[2][N];
int fa[N];
vector<int> G[N];
bitset<N> dag[N];
int f[S1+1][N];
tuple<int,int,int,int> query[N];
bool vis[N],visa[N];
int hcg[N],top;
int ni,li;
void pre(){
    for(int i=1;i<=S1&&(i-1)*B1<n;i++){
        int l=(i-1)*B1+1,r=min(i*B1,n);
        for(int j=n;j>=1;j--){
            f[i][j]=0;
            if(l<=a[ni][j]&&a[ni][j]<=r&&!vis[j])f[i][j]=b[ni][j];
            for(auto v:G[j]){
                f[i][j]=max(f[i][j],f[i][v]);
            }
        }
    }
}
void Solve(){
    read(n,m,qq);
    ni=1,li=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
        dag[i].reset();
        dag[i].set(i);
        vis[i]=visa[i]=0;
    }
    for(int i=1,u,v;i<=m;i++){
        read(u,v);
        G[u].push_back(v);
        dag[u].set(v);
    }
    for(int i=1;i<=n;i++){
        read(a[ni][i]);
        fa[a[ni][i]]=i;
        a[li][i]=a[ni][i];
    }
    for(int i=1;i<=n;i++){
        read(b[ni][i]);
        b[li][i]=b[ni][i];
    }
    for(int i=n;i>=1;i--){
        for(auto v:G[i]){
            dag[i]=dag[i]|dag[v];
        }
    }
    for(int q=1;q<=qq;q++){
        int op,x,y,l,r;
        read(op);
        if(op==3){
            read(x,l,r);
            query[q]={op,x,l,r};
        }
        else{
            read(x,y);
            query[q]={op,x,y,x};
        }
    }
    for(int i=1;i<=S2&&(i-1)*B2<qq;i++){
        ni=i&1;
        li=!ni;
        top=0;
        for(int q=(i-1)*B2+1;q<=min(qq,i*B2);q++){
            auto [op,x,y,l]=query[q];
            if(op!=3){
                if(!vis[x])hcg[++top]=x;
                if(!vis[y])hcg[++top]=y;
                vis[x]=vis[y]=1;
                visa[a[ni][x]]=visa[a[ni][y]]=1;
            }
        }
        pre();
        for(int q=(i-1)*B2+1;q<=min(qq,i*B2);q++){
            auto [op,x,L,R]=query[q];
            int ml=n+1,mr=0;
            if(op==3){
                int res=0;
                for(int j=1;j<=S1&&(j-1)*B1<n;j++){
                    int l=(j-1)*B1+1,r=min(j*B1,n);
                    if(L<=l&&R>=r)res=max(res,f[j][x]),ml=min(ml,l),mr=max(mr,r);
                }
                
                
                if(ml>mr){
                	for(int j=L;j<=R;j++){
 	                    if(visa[j])continue;
	                    int u=fa[j];
	                    if(!dag[x][u])continue;
	                    res=max(res,b[ni][u]);
	                }
                }else{
                	for(int j=L;j<ml;j++){
	                    if(visa[j])continue;
	                    int u=fa[j];
	                    if(!dag[x][u])continue;
	                    res=max(res,b[ni][u]);
	                }
	                for(int j=mr+1;j<=R;j++){
	                    if(visa[j])continue;
	                    int u=fa[j];
	                    if(!dag[x][u])continue;
	                    res=max(res,b[ni][u]);
	                }
                }
                for(int ii=1,u;ii<=top;ii++){
                    u=hcg[ii];
                    if(dag[x][u]&&L<=a[li][u]&&a[li][u]<=R){
                        res=max(res,b[li][u]);
                    }
                }
                write(res,"\n");
            }else if(op==1){
                int y=L;
                swap(a[li][x],a[li][y]);
            }else{
                int y=L;
                swap(b[li][x],b[li][y]);
            }
        }
        for(int q=(i-1)*B2+1;q<=min(qq,i*B2);q++){
        	auto [op,x,y,R]=query[q];
        	if(op==1){
                swap(a[ni][x],a[ni][y]);
            }else if(op==2){
                swap(b[ni][x],b[ni][y]);
            }
        }
        for(int i=1;i<=n;i++)fa[a[li][i]]=i;
        for(int ii=1,u;ii<=top;ii++){
            u=hcg[ii];
            vis[u]=visa[a[li][u]]=0;
        }
    }
}

int main(){
    int c,T=1;
    read(c,T);
    while(T--){
        Solve();
    }
}

/*

*/