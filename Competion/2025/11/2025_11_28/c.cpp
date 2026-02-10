#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
ll k;
int r[N],q[N];

bool check(int x,int y){//q,r
    return 1ll*x*y+x+y<=k;
}

void Solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=1;i<=n;i++)cin>>r[i];
    sort(r+1,r+n+1);
    sort(q+1,q+n+1);
    int j=1,ans=0;
    while(j<n&&check(q[j+1],r[1]))j++;
    for(int i=1;i<=n&&r[i]+1<=k;i++){
        while(j&&!check(q[j],r[i]))j--;
        if(!j)break;
        ans++;
        j--;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
