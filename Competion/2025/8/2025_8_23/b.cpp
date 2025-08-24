#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,a[N],b[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        if(n==1){cout<<"Yes\n";continue;}
        int ans=1;
        for(int i=1;i<=n;i++){
            if(a[i]%2!=b[i]%2){ans=0;break;}
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
