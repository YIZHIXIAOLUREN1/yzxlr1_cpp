#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007,mod=998244353;
int n,m,I=1;
bool vis[N];
int p[N],tot=0,phi[N];
int ans;

int qp(int x,int q){
    if(q==0)return 1;
    int res=1;
    while(q){
        if(q&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        q>>=1;
    }
    return res;
}

void pre(){
	phi[1]=1;
    ans+=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
            p[++p[0]]=i;
            phi[i]=(qp(i,I)-qp(i,I-1)+mod)%mod;
            ans=(ans+phi[i])%mod;
        }

		for(int j=1;j<=p[0]&&1ll*i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=1ll*phi[i]*qp(p[j],I)%mod;
                ans=(ans+phi[i*p[j]])%mod;
				break;
			}else{
                phi[i*p[j]]=1ll*phi[i]*(qp(p[j],I)-1+mod)%mod;
                ans=(ans+phi[i*p[j]])%mod;
            }
		}
	}
}

int main(){
    cin >> n >> m;
    for(;I<=m;I++){
        pre();
    }
    cout << ans;
}