#include<bits/stdc++.h>
using namespace std;
#define N 550
#define LL long long
#define int long long
int n,K;
int ans;
int no[N];
int dfs(int u,int ed,int l1,int l2){
	int res=0;
    if(u>=ed)res=1;
    else for(int i=max(l1,(LL)1);i<n;i++){
        if(l1==l2&&i==l1)continue;
        res+=dfs(u+1,ed,i,l1);
    }
    return res;
}

signed main(){
    cin >> n >> K;
    int pes;
    for(int i=1;i<2*n;i++){
    	no[i]=no[i+1]=n;
    	pes=dfs(0,i-1,0,0);
        ans+=2*pes;
    }
    pes=dfs(0,n-1,0,0);
    ans+=pes;
    cout << ans;
}