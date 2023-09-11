#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7,N=405;
int n,m,kk;
int S[N],T[N],pre[N];
ll f[N][N][N];

ll dfs(int i,int j,int k){
	//printf("%d %d %d\n",i,j,k);//
    if(f[i][j][k]) return f[i][j][k];
    if(i<1||i>n||j<0||j>pre[i]||k<0||k>pre[i]-j)return 0;
    int l=pre[i]-j-k;
    if(S[i]==-1)return f[i][j][k]=(dfs(i-1,j+1,k)+dfs(i-1,j,k))%mod;
    else if(k<=m&&S[i]==T[k]){
        if(l)return f[i][j][k]=dfs(i-1,j,k);
        else if(k)return f[i][j][k]=dfs(i-1,j,k-1);
    	else if(j)return f[i][j][k]=dfs(i-1,j-1,k);
    }else{
    	if(l)return dfs(i-1,j,k);
        else if(j&&!k)return f[i][j][k]=dfs(i-1,j-1,k);
    }
    return 0;
}

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
            //printf("p%d:%c %d %d\n",i+1,s[i],S[i+1],pre[i+1]);//
        }
        cin >> s;
        for(int i=0;i<m;i++){
            switch (s[i]){
                case '1':T[i+1]=1;break;
                case '0':T[i+1]=0;break;
            }
        }
        f[0][0][0]=(ll)1;
        // for (int i=1;i<=n;i++) {
		// for (int j=0;j<=pre[i];j++) {
			// for (int k=0;k<=pre[i]-j;k++) {
				// int l=pre[i]-j-k;
   				// if(S[i]==-1) f[i][j][k]=(f[i-1][j+1][k]+f[i-1][j][k])%mod;
    			// else if(k<=m&&S[i]==T[k]){
    		    	// if(l) f[i][j][k]=f[i-1][j][k];
    		    	// else if(k) f[i][j][k]=f[i-1][j][k-1];
    				// else if(j) f[i][j][k]=f[i-1][j-1][k];
    			// }else{
    				// if(l) f[i][j][k]=f[i-1][j][k];
    			    // else if(j&&!k) f[i][j][k]=f[i-1][j-1][k];
    			// }
			// }
		// }
		// }
		if(pre[n]!=m)puts("0");
		else printf("%lld\n",dfs(n,0,pre[n]));
        //ll ans=0;
        // for(int i=0;i<=pre[n];i++)ans=max(ans,dfs(n,m,i));
        // printf("%lld\n",dfs(n,0,pre[n]));
    }
}
/*
f[i][j][k][l]//前i个,j个有效，前删k，后删l
k+l+j=i;pre[i]://前i个有pre[i]个'-'
l=i-j-k-pre[i]:f[i][j][k]
s[i]=='-':
f[i][j][k][l]=f[i-1][j][k+1][l]+f[i-1][j][k][l+1]
s[i]==t[j]:
    l>0:f[i-1][j][k][l-1]
    l==0:f[i-1][j-1][k][l]
    j=0:f[i-1][j][k-1][l]
s[i]!=t[j]:
    l>0:f[i-1][j][k][l-1]
    j==0&&k>0:f[i-1][j][k-1][l]

*/
