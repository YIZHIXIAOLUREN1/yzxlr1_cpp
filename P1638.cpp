#include<bits/stdc++.h>
using namespace std;
#define N 1000100
#define M 2050
int n,m;
int vis[M];
int a[N];
int l,r,al,ar,ans=N;
int tot;

int main(){
    scanf("%d%d",&n,&m);
    l=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!vis[a[i]])tot++;
        vis[a[i]]++;
        r++;
        while(tot==m){
        	printf("%d %d:%d\n",l,r,r-l+1);//
            if(r-l+1<ans){ans=r-l+1,al=l,ar=r;}
            vis[a[l]]--;
            if(!vis[a[l]])tot--;
            l++;
        }
    }
    printf("%d %d",al,ar);
}