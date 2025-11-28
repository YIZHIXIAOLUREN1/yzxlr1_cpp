#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2007;
int n;
pair<int,int> a[N];
int b[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)b[i]=a[i].first;
        ll ans=0;
        for(int i=1;i<=n;i++){//a=b=c
            if(a[i].second>=3){
                ans+=1;
            }
        }
        for(int i=1;i<=n-1;i++){//a=b<c 2*a>c
            if(a[i].second<2)continue;
            for(int j=i+1;j<=n&&a[i].first*2>a[j].first;j++){
                ans+=1;
            }
        }
        for(int i=1;i<=n-1;i++){//a<b=c 2*a>c
            for(int j=i+1;j<=n;j++){
                if(a[j].second<2)continue;
                ans+=1;
            }
        }
        for(int i=1;i<=n-2;i++){//a<b<c a+b>c
            for(int j=i+1;j<=n;j++){
                int l=j+1,r=lower_bound(b+1,b+n+1,b[i]+b[j])-b-1;
                if(r<l)continue;
                ans+=r-l+1;
            }
        }
        cout<<ans<<"\n";
    }
}
