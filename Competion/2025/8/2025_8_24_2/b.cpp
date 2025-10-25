#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N];
ll ans;
bool cmp(int x,int y){return x>y;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1,cmp);
        ans=0;
        for(int i=1;i<=n/2;i++){
            ans+=a[i*2-1];
        }
        if(n%2)ans+=a[n];
        cout<<ans<<"\n";
    }
}
