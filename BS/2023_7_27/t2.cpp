#include<bits/stdc++.h>
using namespace std;
#define N 10000500
#define M 500050
int a[N],ans;
int s[N];
int n,m;
void reads(){
    char c;c=getchar();
    while((c<'0'||c>'9')&&c!='\r'&&c!='\n'){
    	a[++n]=c;
    	//printf("%d:%d\n",n,c);//
    	c=getchar();
    }
}
int read(){
    int res=0;
    char c;c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
    return res;
}

int main(){
    reads();
    m=read();
    for(int i=1,l,r;i<=m;i++){
        l=read();r=read();
        s[l]++,s[r+1]--;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        now+=s[i];
        if(now&1) ans=a[n+1-i];
        else ans=a[i];
        putchar(ans);
    }
}