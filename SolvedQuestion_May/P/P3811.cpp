#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e6+7;
int n,mod;
#define gc() getchar()
#define pc(x) putchar(x)
#define print(x) pr(x),pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
// int qp(int x,int q){
//     int res=1;
//     while(q){
//         if(q&1)res=(ll)res*x%mod;
//         x=(ll)x*x%mod;
//         q>>=1;
//     }
//     return res;
// }
// int inv(int x){return qp(x,mod-2);}
int inv[N];

int main(){
    n=read(),mod=read();
    inv[1]=1;
    print(1);
    for(int i=2;i<=n;i++){
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
        //inv[i]=(1ll*(-(mod/i))*inv[mod%i]+mod)%mod;
        print(inv[i]);
    }
}