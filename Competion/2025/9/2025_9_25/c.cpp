#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,k,a[N],b[N];
int ans,res;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ans=res=0;
        b[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            b[a[i]]++;
        }
        for(int i=0;i<k;i++){
            if(!b[i])ans++;
        }
        ans=max(ans,b[k]);
        cout<<ans<<"\n";
    }
}
