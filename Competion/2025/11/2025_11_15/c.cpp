#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,a[N],x,y;
int c[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    bool f=1;
    ans+=a[1]-c[1];
    for(int i=2;i<=n;i++){
        if((a[i]-a[i-1])*y%(y-x)){f=0;break;}
        c[i]=c[i-1]+(a[i]-a[i-1])*y/(y-x);
        if(c[i]>a[i]){f=0;break;}
        ans+=a[i]-c[i];
        //cout<<c[i]<<" \n"[i==n];//
    }
    if(!f)cout<<"-1";
    else cout<<ans;
}
