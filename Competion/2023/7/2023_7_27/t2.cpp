#include<bits/stdc++.h>
using namespace std;
#define N 10000500
#define M 500050
char s[N];
int v[N];
int n,m;

int read(){
    int res=0;
    char c;c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
    return res;
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    m=read();
    for(int i=1,l,r;i<=m;i++){
        l=read();r=read();
        v[l]++,v[n/2+1]--;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        now+=v[i];
        if(now&1)swap(s[i],s[n+1-i]);
    }
    puts(s+1);
}