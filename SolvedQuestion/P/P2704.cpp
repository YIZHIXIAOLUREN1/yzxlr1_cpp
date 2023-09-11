#include<bits/stdc++.h>
using namespace std;
#define N 105
#define M 11
bool ma[N][M+1];
int dp[2][(1<<M)-1][(1<<M)-1];
int n,m,maj;
vector<int> tt;

int va(int j){
	//printf("%d:",j);//
	int res=0;
	res+=j&1;
	while(j>>=1)res+=j&1;
	//printf("%d\n",res);//
	return res;
}

bool ch(int x,int y){
	int s=1;
	while(y){
		if((y&1)&&ma[x][s]) return 1;
		y>>=1;s++;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	maj=(1<<m)-1;
	//cout << maj << "\n";//
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char s;
			cin >> s;
			if(s=='H')ma[i][j]=1;
//			printf("A");//
		}
	}
	
	for(int i=0;i<=maj;i++){
		if(((i>>2)&i)||((i>>1)&i)||((i<<1)&i)||((i<<2)&i)) continue;
		tt.push_back(i);
		//printf("%d\n",i);
	}
	
	//for(auto i:tt)printf("%d ",i);//

	
	for(int i=1;i<=n;i++){
		int no=i&1,la=(i+1)&1;
		for(auto j:tt){
			if(ch(i,j)) continue;
			for(auto k:tt){
				if(i>=2&&(ch(i-1,k)||(j&k)!=0))continue;
				for(auto fl:tt){
					if(i>=3&&(fl&j||fl&k||ch(i-2,fl)))continue;
					dp[no][j][k]=max(dp[no][j][k],dp[la][k][fl]+va(j));
					//printf("%d %d %d %d %d\n",i,j,k,fl,dp[no][j][k]);//
				}
			}
			//printf("B");//
		}
		//printf("A");//
	}
	//printf("A");//
	int ans=0;
	for(auto j:tt){
		for(auto k:tt){
			ans=max(ans,dp[n%2][j][k]);
			
		}
	}
	
	printf("%d\n",ans);
	
}
