#include<bits/stdc++.h>
using namespace std;
#define N 100
#define int __int128
void print(int num){
	if(num>9) print(num/10);
	putchar(num%10+'0');
}
int read(){
	int res=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){res*=10;res+=s[i]-'0';}
	return res;
}

int n,m;
int a[N];
int dp[N][N];
int p2[N];

int dps(int i,int j){
	if(dp[i][j]) return dp[i][j];
	int res=0,t=m-j+i-1;
	if(i>1) res=max(res,dps(i-1,j)+p2[t]*a[i-1]);
	if(j<m) res=max(res,dps(i,j+1)+p2[t]*a[j+1]);
	//print(i);print(j);cout << ":";print(res);cout << endl;//
	return dp[i][j]=res;
}

signed main(){
	p2[0]=1;
	
	n=read();m=read();
	for(int i=1;i<=90;++i) p2[i]=p2[i-1]*int(2);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			a[j]=read();
		memset(dp,0,sizeof dp);
		int ansn=0;
		for(int i=1;i<=m;++i){
			ansn=max(ansn,dps(i,i)+p2[m]*a[i]);
		}
		ans+=ansn;
	}
	print(ans);
}
