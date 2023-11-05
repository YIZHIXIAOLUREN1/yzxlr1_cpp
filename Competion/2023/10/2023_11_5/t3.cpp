#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,K,D;
int t[N];
ll h[N],f[N];

ll val(int a,int b){
	//printf("%lld:%lld:%lld\n",a,b,(b-a)/K*D);//
    return (b-a)/K*D;
}
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(f,0xc0,sizeof f);
    cin >> n >> K >> D;
    for(int i=1;i<=n;i++)cin >> h[i];
    for(int i=1;i<=n-1;i++)cin >> t[i];
    f[n]=h[n];
	//printf("%lld:%lld\n",n,f[n]);//
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=min(n,i+t[i]);j++){
            f[i]=max(f[i],f[j]-val(i,j));
        }
        f[i]+=h[i];
        //printf("%lld:%lld:%lld\n",i+f[i],ans,ans^(i+f[i]));//
        //ans=ans^(i+f[i]);
    }
    for(int i=1;i<=n;i++)ans=ans^(i+f[i]);
    cout << ans;
}
