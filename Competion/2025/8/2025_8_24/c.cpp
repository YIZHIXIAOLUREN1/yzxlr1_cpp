#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,Q;
int a[N],b[N];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        ans+=min(a[i],b[i]);
    }
	char c;
    int x,v;
    while(Q--){
        cin>>c>>x>>v;
        if(c=='A'){
            ans=ans-min(a[x],b[x])+min(v,b[x]);
            a[x]=v;
        }else{
            ans=ans-min(a[x],b[x])+min(a[x],v);
            b[x]=v;
        }
        cout<<ans<<"\n";
    }
}
