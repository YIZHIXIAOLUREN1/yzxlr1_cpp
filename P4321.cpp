#include<bits/stdc++.h>
using namespace std;
#define ull long long
#define N 10000050
#define M 600050
#define pc putchar
#define re register
static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline ull read(){
    ull w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}

inline void write(ull x){
	if(x==0){pc('0');return ;}
	if(x<0){pc('-');x=-x;}
	char nnu[25];int top=0;
	while(x){nnu[++top]=x%10+'0';x/=10;}
	for(int i=top;i;i--) pc(nnu[i]);
	return ;
}

ull n,m;
ull dc[N],fr[N];
ull d,res;
ull ans1,ans2;
ull l,r,s,e;
int main(){
    n=read();
    m=read();
    ++n,++m;
    for(re int i=1;i^m;++i){
        l=read(),r=read(),s=read(),e=read();
        ull dd=(e-s)/(r-l);
        ull f=s-dd;
        dc[l]+=dd,dc[r+1]-=dd;
        fr[l]+=f,fr[r+1]-=e;
    }
    
    for(re int i=1;i^n;++i){
        d+=dc[i];
        res+=fr[i]+d;
        ans1^=res;
        if(ans2<res)ans2=res;
    }
    write(ans1);
    pc(' ');
    write(ans2);
}