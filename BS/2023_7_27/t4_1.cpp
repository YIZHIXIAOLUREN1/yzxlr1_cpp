#include<bits/stdc++.h>
using namespace std;
#define N 550
#define LL long long
#define int long long
int n;
int ans;

int C(int a,int b){
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--){
		res=res*j;
		res=res/i;
	}
	return res;
}

int dfs(int u,int ed,int l1,int l2){
	int res=0;
    if(u>=ed)res=1;
    else for(int i=max(l1,(LL)1);i<n;i++){
        if(l1==l2&&i==l1)continue;
        res+=dfs(u+1,ed,i,l1);
    }
    //printf("%lld:%lld %lld %lld:%lld\n",ed,u,l1,l2,res);//
    return res;
}

signed main(){
    cin >> n;
    int pes;
    for(int i=1;i<n;i++){
    	pes=dfs(0,i-1,0,0);
        ans+=2*pes;
        //printf("%lld:%lld\n",i,pes);//
    }
    pes=dfs(0,n-1,0,0);
    //printf("%lld:%lld\n",n,pes);//
    ans+=pes;
    cout << ans;
}