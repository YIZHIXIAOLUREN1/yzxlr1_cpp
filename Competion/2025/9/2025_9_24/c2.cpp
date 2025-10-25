#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+7;
int n,a[N];
ll ans;
ll pre[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
    	ans=0;
        cin>>n;
        for(int i=1;i<=2*n;i++){
            cin>>a[i];
        }
        for(int i=2;i<=2*n;i++){
            pre[i]=pre[i-2]+(a[i]-a[i-1]);
            //cout<<pre[i]<<" \n"[i==2*n];//
        }
        for(int k=1;k<=n;k++){
            ll res=0;
            res=pre[2*n-k+1]-pre[k-1];
            cout<<ans+res<<" \n"[k==n];
            ans+=a[2*n-k+1]-a[k];
        }
    }
}
