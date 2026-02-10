#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,inf=1e9+7;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int x,mi=inf,ma=-inf;
        for(int i=1;i<=n;i++){
        	cin>>a[i];
        	mi=min(a[i],mi);
        	ma=max(a[i],ma);
        }
        
        cin>>x;
        bool ans=(mi<=x&&x<=ma);
        cout<<(ans?"YES\n":"NO\n");
    }
}
