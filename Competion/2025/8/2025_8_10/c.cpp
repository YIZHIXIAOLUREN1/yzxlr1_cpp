#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,k,a[N],b[N];
bool ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]%=k;
            if(k-a[i]<a[i])a[i]=k-a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
            b[i]%=k;
            if(k-b[i]<b[i])b[i]=k-b[i];
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        ans=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){ans=0;break;}
        }
        cout<<(ans?"YES\n":"NO\n");
    }
}
