#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N],b[N];
bool ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        ans=1;
        for(int i=n;i>=1;i--){
        	//cout<<i<<" "<<a[i]<<" "<<" "<<(a[i]^a[i+1])<<"\n";//
            if(a[i]==b[i])continue;
            if(i==n){ans=0;break;}
            if((a[i]^a[i+1])==b[i]||(a[i]^b[i+1])==b[i]){continue;}
            ans=0;break;
        }
        cout<<(ans?"YES\n":"NO\n");
    }
}