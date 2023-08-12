#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
#define gc() getchar()
#define pc(x) putchar(x)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}
inline void prs(){
	pc('C'),pc('r'),pc('o'),pc('s'),pc('s'),pc('i'),pc('n');
	pc('g'),pc(' '),pc('t'),pc('h'),pc('e'),pc(' '),pc('l');
	pc('i'),pc('n'),pc('e'),pc(10);
}
int n,m;
bool vis[N];
int p[N/10],tot=0;
int pre[N];

inline void getprime(){
    for(int i=2;i<=m;i++){
        pre[i]=pre[i-1];
        if(!vis[i])p[++tot]=i,pre[i]++;
        for(int j=1;j<=tot&&(ll)p[j]*i<=m;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);
    n=read(),m=read();
    getprime();
    int l,r;
    while(n--){
        l=read(),r=read();
        if(l<1||r>m)prs();
        else pr(pre[r]-pre[l-1]),pc(10);
    }
}