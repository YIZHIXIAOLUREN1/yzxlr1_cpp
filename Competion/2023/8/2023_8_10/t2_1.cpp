#include<bits/stdc++.h>
using namespace std;
#define db double
#define mid ((l+r)>>1)
#define ll long long
#define gc() getchar()
#define pc(x) putchar(x)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
const int N=1e6+7;
int T;
int n;
int rt,rn;
int tot=1,num=1;
int cz[N];
int la,ma;
int as,ax=1;

inline bool check(int x){
    tot=num=1;
    for(int i=1;i<=n;i++){
        if(cz[i]==1)tot++,num++;
        else if(cz[i]==0&&x)tot++,num++,x--;
        else if(num<2)return 0;
        else num--;
    }
    return 1;
}

int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main(){
    T=read();
    while(T--){
    	ma=0;
    	as=0,ax=1;
        rt=rn=1;
        tot=num=1;
        n=read();
        for(int i=1;i<=n;i++){
            cz[i]=read();
            if(cz[i]==0)ma++;
            else if(cz[i]==-1)rn--;
            else rt++,rn++;
        }
        int l=0,r=ma;
        l=max(l,((ma+1-rn)/2)-1);
        while(l<r){
            if(!check(mid))l=mid+1;
            else r=mid-1;
        }
        while(!check(l)&&l<=ma)l++;
        while(l&&check(l-1))l--;
        if(l>ma){
            pr(-1);
            pc(10);
            continue;
        }
        for(int i=l;i<=ma;i++){
            tot=rt,num=rn;
            tot+=i,num+=2*i-ma;
            if(num<1)continue;
            if(((db)as/ax)<((db)tot/num)){
            	as=tot,ax=num;
            	break;
            }
        }
		
        int tt=gcd(as,ax);
        pr(as/tt);
        pc(' ');
        pr(ax/tt);
        pc(10);
    }
}