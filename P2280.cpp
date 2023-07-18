#include<bits/stdc++.h>
using namespace std;
const int M=5050;
int n,m;
int v,x,y;
int s[M+5][M+5];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&v);
        s[x+1][y+1]=v;
    }

    for(int i=1;i<=M;i++){
        for(int j=1;j<=M;j++){
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=m;i<=M;i++){
    	for(int j=m;j<=M;j++){
    		ans=max(s[i][j]-s[i][j-m]-s[i-m][j]+s[i-m][j-m],ans);
    	}
    }
    printf("%d",ans);
}