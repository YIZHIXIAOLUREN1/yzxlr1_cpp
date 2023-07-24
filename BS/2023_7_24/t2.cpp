#include<bits/stdc++.h>
using namespace std;
const int N=5e6+7;
int n;
int pre[N];
int ans=0;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,x,ss,tt;i<=n;i++){
        cin >> x;
        ss=max(1,i-x);
        tt=min(n,i+x);
        pre[ss]=max(tt+1,pre[ss]);
    }
    
    for(int i=1;i<=n;i++){
		pre[i]=max(pre[i-1],pre[i]);
	}
    int now=1;
    while(pre[now]<=n){
        ans++;
        now=pre[now];
    }
    ans++;
    cout << ans;
}