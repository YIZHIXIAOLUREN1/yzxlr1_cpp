#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int T;
int n,m,K,j;
int kmp[N];
int s1[N],s2[N];
bool ans=0;
int main(){
    scanf("%d",&T);
    while(T--){
    ans=0;
    memset(kmp,0,sizeof kmp);
    memset(s1,0,sizeof s1);
    memset(s2,0,sizeof s2);
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++){
        scanf("%d",&s1[i]);
        s1[i+n]=s1[i];
    }
    m=n;n*=2;
    if(K==0)ans=1;
    for(int i=1;i<=m;i++){
    	scanf("%d",&s2[i]);
    	if(K==0&&s2[i]!=s1[i])ans=0;
    }
	if(K==0){
		if(ans)puts("YES");
    	else puts("NO");
    	continue;
	}
    j=0;
    for(int i=2;i<=m;i++){
        while(j&&s2[j+1]!=s2[i])j=kmp[j];
        if(s2[j+1]==s2[i])j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++){
        while(j&&s2[j+1]!=s1[i])j=kmp[j];
        if(s2[j+1]==s1[i])j++;
        if(j==m){
            ans=1;
            //printf("%d:%d\n",i,j);//
            break;
        }
    }
    if(ans)puts("YES");
    else puts("NO");

}
}