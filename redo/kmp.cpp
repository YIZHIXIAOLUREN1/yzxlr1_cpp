#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=998244353;
char s1[N],s2[N];
int n,m;
int kmp[N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1);
    m=strlen(s2+1);
    int j=0;
    for(int i=2;i<=m;i++){
        while(j&&s2[j+1]!=s2[i])j=kmp[j];
        if(s2[j+1]==s2[i])j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++){
        while(j&&s2[j+1]!=s1[i])j=kmp[j];
        if(s2[j+1]==s1[i])j++;
        if(j==m)cout<<i-m+1<<"\n";
    }
    for(int i=1;i<=m;i++)cout<<kmp[i]<<" \n"[i==m];
    
    return 0;
}
