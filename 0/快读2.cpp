#include <bits/stdc++.h>
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

inline void next_integer(int& x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
}

int main(){
    int n,seed;
    read(n,seed);
    write(n,' ',seed,'\n');
    while(n--){
    	next_integer(seed);
    	write(seed,'\n');
    }
}