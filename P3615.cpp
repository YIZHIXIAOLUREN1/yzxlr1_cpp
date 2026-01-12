#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
ll n;
int m;
string s[N];
ll k[N];
ll ans,cnt;
ll check(int x){
    ll dt=cnt;
    for(int i=s[x].size()-1;i>=0;i--){
        if(s[x][i]=='F')cnt++;
        else cnt--;
        ans=min(ans,cnt);
    }
    return cnt-dt;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>s[i]>>k[i];
    for(int i=m;i>=1;i--){
        ll dt=check(i);
        k[i]--;
        if(k[i]>1){
            cnt+=dt*(k[i]-1);
            k[i]=1;
        }
        if(k[i])check(i);
    }
    if(cnt<0)ans=-1;
    else ans=max(-ans-1,0ll);
    cout<<ans<<"\n";
}
