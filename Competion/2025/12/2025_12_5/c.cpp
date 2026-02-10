#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,k,a[N];
bool vis[N];
vector<int> temp,ans;
void Solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=0;
    }
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    ans.clear();
    for(int i=1;i<=n;i++){
        if(k/a[i]>n||vis[i])continue;
        bool tf=0;
        temp.clear();
        for(int j=a[i];j<=k;j+=a[i]){
        	if(j>a[n]){tf=0;break;}
            int tg=lower_bound(a+1,a+n+1,j)-a;
            if(a[tg]!=j){tf=0;break;}
            if(!vis[tg]){tf=1;temp.push_back(tg);}
        }
        if(!tf)continue;
        ans.push_back(a[i]);
        for(auto u:temp)vis[u]=1;
    }

    for(int i=1;i<=n;i++)if(!vis[i]){cout<<"-1\n";return;}
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" \n"[i==ans.size()-1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
