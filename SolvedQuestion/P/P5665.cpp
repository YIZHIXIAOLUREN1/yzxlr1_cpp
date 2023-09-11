#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define calc(x) (2*s[x]-s[g[x]])
inline int read1()
{
    int x=0,flag=1;char c;
    while((c=getchar())<'0' || c>'9') if(c=='-') flag=-1;
    while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return x*flag;
}
inline ll read2()
{
    ll x=0,flag=1;char c;
    while((c=getchar())<'0' || c>'9') if(c=='-') flag=-1;
    while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return x*flag;
}
inline void print(__int128 x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int N=40000005,M=100005;
const ll mod=1<<30;
int n;
int a,g[N];
ll s[N];
int fir=1,las=1;
ll x,y,z,l[M],r[M];
ll b1,b2,b3;
int p[M],m;
int q[N];
int main(){
    int _;
    n=read1();_=read1();
    if(_==0){
        for(int i=1;i<=n;i++){
        	a=read1();
            s[i]=a+s[i-1];
        }
    }else{
    	x=read2();y=read2();z=read2();
    	b3=read2();b2=read2();m=read1();
        for(int i=1;i<=m;i++){
        	p[i]=read1();l[i]=read2();r[i]=read2();
        }
        for(int j=1;j<=m;j++){
            for(int i=p[j-1]+1;i<=p[j];i++){
            	if(i==1)a=b3%(r[j]-l[j]+1)+l[j];
            	else if(i==2)a=b2%(r[j]-l[j]+1)+l[j];
            	else{
            		b1=(x*b2+y*b3+z)%mod;
               		b3=b2;
               		b2=b1;
                	a=b1%(r[j]-l[j]+1)+l[j];
            	}
                s[i]=s[i-1]+a;
             }
        }
    }
    for(int i=1;i<=n;i++){
        while(fir<las&&calc(q[fir+1])<=s[i])fir++;
        g[i]=q[fir];
        while(fir<las&&calc(q[las])>=calc(i))las--;
        q[++las]=i;
    }
    int now=n;LL ans=0;
	while(now){
		ans+=((LL)s[now]-s[g[now]])*(s[now]-s[g[now]]);
		now=g[now];
	}
    print(ans);
    return 0;
}
