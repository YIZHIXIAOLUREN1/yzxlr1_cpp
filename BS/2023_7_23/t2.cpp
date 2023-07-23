#include<bits/stdc++.h>
using namespace std;
const int N=2007,mod1=1e9+7,mod2=998244353;

inline int read(){
    int res=0,f=1;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return res*f;
}

int n,P;
int a[N],tot,s[N];
int f[N][N];


int main(){
    n=read(),P=read();
    for(int i=1,x;i<=n;i++){
        x=read();
        for(int j=tot+1;j<=min(tot+x,n);j++)a[j]=i;
        tot+=x;
        if(tot>n)break;
    }
    for(int i=1;i<=tot;i++)s[i]=a[i],s[i]+=s[i-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            
        }
    }
}