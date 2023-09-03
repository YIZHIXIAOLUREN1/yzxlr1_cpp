#include<bits/stdc++.h>
using namespace std;
//#define ll long long
const int N=2007;
const int inf=0x3f3f3f3f;
int n,p[5];
bool a[4][N];
bool vis1[4][4][N][N],vis2[4][4][N][N],g[4][4][N][N];
int f[4][4][N][N];

bool check(int x1,int x2,int y1,int y2){
	if(vis1[x1][x2][y1][y2])return g[x1][x2][y1][y2];
	bool res=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)res=max(res,a[i][j]);
	vis1[x1][x2][y1][y2]=1;
	return g[x1][x2][y1][y2]=res;
}

int dp(int x1,int x2,int y1,int y2){
    if(vis2[x1][x2][y1][y2])return f[x1][x2][y1][y2];
    int res=inf;
    for(int t=1;t<=4;t++){
        if(x2-x1>t)
            res=min(res,dp(x1,x1+t,y1,y2)+dp(x1+t+1,x2,y1,y2)),
            res=min(res,dp(x1,x2-t-1,y1,y2)+dp(x2-t,x2,y1,y2));
        if(y2-y1>t)
            res=min(res,dp(x1,x2,y1,y1+t)+dp(x1,x2,y1+t+1,y2)),
            res=min(res,dp(x1,x2,y1,y2-t-1)+dp(x1,x2,y2-t,y2));
        if(x2-x1+1<=t&&y2-y1+1<=t)res=min(res,p[t]*check(x1,x2,y1,y2));
    }
    vis2[x1][x2][y1][y2]=1;
    return f[x1][x2][y1][y2]=res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> p[1] >> p[2] >> p[3] >> p[4];
    string s;
    for(int i=0;i<=3;i++){
        cin >> s;
        for(int j=0;j<n;j++)a[i][j+1]=(s[j]=='A'?1:0);
    }
    
    cout<<dp(0,3,1,n);
}