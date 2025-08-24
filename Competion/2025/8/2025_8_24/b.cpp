#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,m;
string s[N];
int ans[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int x,y;
    for(int j=0;j<m;j++){
        x=y=0;
        for(int i=1;i<=n;i++){
            if(s[i][j]=='1')y++;
            else x++;
        }
        if(x==0||y==0)for(int i=1;i<=n;i++)ans[i]++;
        if(x<y){
            for(int i=1;i<=n;i++)if(s[i][j]=='0')ans[i]++;
        }else{
            for(int i=1;i<=n;i++)if(s[i][j]=='1')ans[i]++;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
    	//cout<<ans[i]<<" \n"[i==n];//
        res=max(res,ans[i]);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==res)cout<<i<<" ";
    }
}
