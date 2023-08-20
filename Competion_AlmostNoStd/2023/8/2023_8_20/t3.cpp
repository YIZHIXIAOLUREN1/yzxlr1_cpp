#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1007;

#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=gc();return w*q;}
inline void pr(ll x){if(x<0)pc('-'),x=-x;if(x>9)pr(x/10);pc(x%10+'0');}

int n,T;
int ax[N],ay[N];
int f[N][N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    n=read();
    for(int i=1;i<=n;i++){
        ax[i]=read();
        ay[i]=read();
    }
    memset(f,0x3f,sizeof f);

    for(int i=1;i<=n;i++){
        f[i][i]=0;
        for(int j=i+1;j<=n;j++){
            if((abs(ax[j]-ax[i])==1&&ay[i]==ay[j])||
            (abs(ay[j]-ay[i])==1&&ax[i]==ax[j])){
                f[i][j]=f[j][i]=1;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
            	int a,b;
            	a=(i<=k)?f[i][k]:f[k][i];
            	b=(j<=k)?f[j][k]:f[k][j];
                f[i][j]=min(f[i][j],a+b);
            }
        }
    }
    T=read();
    while(T--){
        int s,t;
        s=read();t=read();
        pr((s<=t?f[s][t]:f[t][s])),endl;
    }

}
