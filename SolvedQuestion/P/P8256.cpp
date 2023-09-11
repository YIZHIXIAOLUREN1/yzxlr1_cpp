#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7,N=405;
int n,m,kk;
int S[N],T[N],pre[N];
ll f[N][N][N];

int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%d%d",&n,&m);
        memset(S,0,sizeof S);
        memset(T,0,sizeof T);
        memset(f,0,sizeof f);
        memset(pre,0,sizeof pre);
        kk=(n-m)>>1;
        string s;
        cin >> s;
        for(int i=0;i<n;i++){
            switch(s[i]){
                case '1':S[i+1]=1;break;
                case '0':S[i+1]=0;break;
                case '-':S[i+1]=-1;break;
            }
            pre[i+1]=(S[i+1]!=-1)?(pre[i]+1):(pre[i]-1);
        }
        cin >> s;
        for(int i=0;i<m;i++){
            switch (s[i]){
                case '1':T[i+1]=1;break;
                case '0':T[i+1]=0;break;
            }
        }
        f[0][0][0]=(ll)1;
        for (int i=1;i<=n;i++) {
		for (int j=0;j<=pre[i];j++) {
			for (int k=0;k<=pre[i]-j;k++) {
				int l=pre[i]-j-k;
   				if(S[i]==-1) f[i][j][k]=(f[i-1][j+1][k]+f[i-1][j][k])%mod;
    			else if(k<=m&&S[i]==T[k]){
    		    	if(l) f[i][j][k]=f[i-1][j][k];
    		    	else if(k) f[i][j][k]=f[i-1][j][k-1];
    				else if(j) f[i][j][k]=f[i-1][j-1][k];
    			}else{
    				if(l) f[i][j][k]=f[i-1][j][k];
    			    else if(j&&!k) f[i][j][k]=f[i-1][j-1][k];
    			}
			}
		}
		}
		if(pre[n]!=m)puts("0");
		else printf("%lld\n",f[n][0][pre[n]]);
    }
}