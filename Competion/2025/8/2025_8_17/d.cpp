#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e3+7,maxn=1e9+7;
int n;
int a[N],dp[2][N][N];
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int op;
    cin>>n>>op;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        dp[0][i][j]=maxn;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[0][i][i]=dp[1][i][i]=a[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                dp[0][i][j]=min(dp[0][i][j],dp[1][i][k]);
            }
            for(int k=i+1;k<=j;k++){
                dp[1][i][j]=max(dp[1][i][j],dp[0][k][j]);
            }
        }
    }
    cout<<dp[1][1][n]<<"\n";
    if(op==1){
        int res=0;
        for(int i=2;i<=n;i++){
            if(dp[1][1][n]==dp[0][i][n]){
                res++;
                ans.push_back(i);
            }
        }
        cout<<res<<"\n";
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" \n"[i==ans.size()];
    }
}