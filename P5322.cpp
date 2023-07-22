#include<bits/stdc++.h>
using namespace std;
#define M 20005
#define N 105
int s,n,m;
int a[N][N];
int f[M];

inline int read(){
    int w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}

int main(){
    s=read(),n=read(),m=read();
    for(int i=1;i<=s;i++)for(int j=1;j<=n;j++){
        a[j][i]=read();
        a[j][i]=(a[j][i]<<1)+1;
    }

    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+s+1);
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s;k++){
                if(j<a[i][k])break;
                f[j]=max(f[j],f[j-a[i][k]]+i*k);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)ans=max(ans,f[i]);
    printf("%d",ans);
}