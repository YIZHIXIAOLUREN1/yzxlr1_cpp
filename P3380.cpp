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
    template<class T,class...A>void write(T t,A...a){write(t);write(a...);}
}
using fastio::read; using fastio::write;
const int N=5e4+7,inf=0x7fffffff;
int n,m;
int a[N];
pair<int,int> b[N];

int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        read(a[i]);
        b[i]={a[i],i};
    }
    sort(b+1,b+n+1);
    for(int mm=1;mm<=m;mm++){
        int opt,l,r,k,pos,res;
        read(opt);
        if(opt==1){
            res=1;
            read(l,r,k);
            for(int i=l;i<=r;i++)if(a[i]<k)res++;
            write(res,'\n');
        }else if(opt==2){
            read(l,r,k);
            for(int i=1;i<=n;i++){
                auto [na,ni]=b[i];
                if(l<=ni&&ni<=r){
                    if(k>1)k--;
                    else{res=na;break;}
                }
            }
            write(res,'\n');
        }else if(opt==3){
            read(pos,k);
            a[pos]=k;
            int tb;
            for(int i=1;i<=n;i++){
                if(b[i].second==pos){
                   tb=i;break;
                }
            }
            b[tb].first=k;
            while(tb>1&&b[tb]<b[tb-1]){swap(b[tb],b[tb-1]);tb--;}
            while(tb<n&&b[tb]>b[tb+1]){swap(b[tb],b[tb+1]);tb++;}
        }else if(opt==4){
            res=-inf;
            read(l,r,k);
            for(int i=l;i<=r;i++)if(a[i]<k&&a[i]>res)res=a[i];
            write(res,'\n');
        }else{
            res=inf;
            read(l,r,k);
            for(int i=l;i<=r;i++)if(a[i]>k&&a[i]<res)res=a[i];
            write(res,'\n');
        }
    }
}
