#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll n,K,ans;
int mmi,f[50][50],g[50][50];
void Solve(){
    cin>>n>>K;
    n<<=1;
    ans=0;
    memset(f,0,sizeof(f));
    for(int i=1;(1ll<<(i-1))<=n;i++)mmi=i;
    for(int i=1;(1ll<<(i-1))<=n;i++){
        for(int j=0;j<=min(1ll*i,K);j++){
            int nlen=0,nst=0;
            for(int l=i;(1ll<<(l-1))<=n;l++){
                if((1ll<<l)&n||(l==i&&f[i][j])){
                    if((l==i&&f[i][j])||((1ll<<(l-1))&n)==0&&!(l-1==i&&f[i][j])){
                    	//printf("st:%d\n",l);//
                    	nst=l,nlen=1;
                    }
                    else nlen++;
                }else if(l&&(((1ll<<(l-1))&n)||(l-1==i&&f[i][j]))){
                	//cout<<"A";//
                    f[l][j+1]=max(f[l][j+1],f[i][j]+nlen);
                    //printf("a%d %d:%d:%d %d %d\n",l,j+1,f[l][j+1],i,j,nlen);//
                }
            }
        }
    }
    ll res=0,mk=0;
    for(int i=1;(1ll<<(i-1))<=n;i++){
        for(int j=0;j<=min(1ll*i,K);j++){
            //printf("%d %d:%d\n",i,j,f[i][j]);//
            res=max(res,f[i][j]+K-j);
        }
	}
	
    cout<<res<<"\n";
    // for(int i=1;i<=K;i++){
    //     int len=0,st=0,nlen=0,nst=0;
    //     for(int j=0;(1ll<<(j-1))<=n;j++){
    //         if((1ll<<j)&n){
    //             if(j==0||((1ll<<(j-1))&n)==0)nst=j,nlen=1;
    //             else nlen++;
    //         }else if(j&&((1ll<<(j-1))&n))if(nlen>len)st=nst,len=nlen;
    //     }
    //     printf("%d %d\n",st,len);//
    //     ans+=len;
    //     n=n+(1ll<<st);
    // }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}

/*
dp[i][j] 


*/
