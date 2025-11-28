#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n;
ll a[N];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ll ma=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]++;
            ma=max(ma,a[i]);
        }
        int l=2,r=1;
        ll ns=0,ans=1;
        for(int i=2;i<=n;i++){
            while(l<=r&&ns+a[i]+1>ma){ns-=a[l];l++;}
            r++;
            ns+=a[i];
            if(ns+1<=ma)ans=max(ans,(ll)r-l+2);
            //printf("%d %d:%lld\n",l,r,ns);//
        }
        cout<<ans<<"\n";
    }
}