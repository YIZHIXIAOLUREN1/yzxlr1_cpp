#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod=10,N=50;
int n,k;
struct ma{
	int s[N][N];
	void cl(){
		memset(s,0,sizeof s);
	}
	void dwjz(){
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++)s[i][i]=1;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++)printf("%d ",s[i][j]%mod);
			printf("%d\n",s[i][n]%mod);
		}
		puts("");
	}
	void init(){
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				scanf("%d",&s[i][j]);
				s[i][j]%=mod;
			}
	}
	ma operator *(const ma x)const{
		ma res;
		res.cl();
		for(int i=1;i<=n;i++)
		for(int kk=1;kk<=n;kk++)
		for(int j=1;j<=n;j++)
			res.s[i][j]=(res.s[i][j]+s[i][kk]*x.s[kk][j]%mod)%mod;
		return res;
	}
	ma operator ^(int p)const{
		ma res,a;
		res.cl();
		res.dwjz();
		memcpy(a.s,s,sizeof s);
		while(p){
			if(p&(int)1)res=res*a;
			a=a*a;
			p>>=(int)1;
		}
		return res;
	}
	ma operator +(const ma x)const{
		ma res;
		res.cl();
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			res.s[i][j]=(s[i][j]+x.s[i][j])%mod;
		return res;
	}
	
	
}A,B;

ma solve(int q){
	if(q==1) return A;
	ma res;
	res=solve(q/2);
	res=res+res*(A^(q/2));
	if(q&1)res=res+(A^q);
	return res;
}

signed main(){
	while(scanf("%d%d",&n,&k)&&n){
		A.cl();
		A.init();
		B=solve(k);
		B.print();
	}
	return 0;
}