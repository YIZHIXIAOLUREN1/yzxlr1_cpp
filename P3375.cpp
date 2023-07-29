#include<bits/stdc++.h>
using namespace std;
#define N 1000050
int n,m,j;
int kmp[N];
char s1[N],s2[N];


int main(){
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1);
    m=strlen(s2+1);
    //cout << n << m;//
    for(int i=2;i<=m;i++){
        while(j&&s2[j+1]!=s2[i])j=kmp[j];
        if(s2[j+1]==s2[i])j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++){
        while(j&&s2[j+1]!=s1[i])j=kmp[j];
        if(s2[j+1]==s1[i])j++;
        if(j==m)printf("%d\n",i-m+1);
    }
    for(int i=1;i<m;i++){
        printf("%d ",kmp[i]);
    }
    printf("%d",kmp[m]);
}