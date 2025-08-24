#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
char s[N],ns;
int n,ans,res;
int kmp[N];
int kmpp(){
	for(int i=0;i<=n;i++)kmp[i]=0;
    int j=0;
    for(int i=2;i<=n;i++){
        while(j&&s[j+1]!=s[i])j=kmp[j];
        if(s[j+1]==s[i])j++;
        kmp[i]=j;
    }
    //printf("%d %d:",x,kmp[n]);//
    //for(int i=1;i<=n;i++)cout<<kmp[i]<<" \n"[i==n];//
    return kmp[n];
}
void j1();
void j2();
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%s",s+1);
    n=strlen(s+1);
    res=kmpp();
    if(n<=2000)j1();
    //else j2();
    cout<<res;
}
void j1(){
    int k=kmpp();
    for(int i=k+1;i<=n-k;i++){
        ns=s[i];
	    for(char c='a';c<='z';c++){
	        s[i]=c;
	        res=max(res,kmpp());
	    }
	    s[i]=ns;
    }
}

void j2(){
    int k=kmpp();
    for(int i=k+1;i<=n-k;i++){
        ns=s[i];
	    for(char c='a';c<='z';c++){
	        s[i]=c;
	        res=max(res,kmpp());
	    }
	    s[i]=ns;
    }
}