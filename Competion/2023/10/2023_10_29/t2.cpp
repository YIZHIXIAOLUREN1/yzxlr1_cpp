#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007;
ll a[N][N];
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=5000;i++)a[i][1]=i;
    for(int j=1;j<=5000;j++)a[1][j]=1;
    for(int i=2;i<=5000;i++)for(int j=2;j<=5000;j++)a[i][j]=a[i-1][j]^a[i][j-1];
    int T;
    cin >> T;
    while(T--){
        int r1,r2,c1,c2;
        cin >> r1 >> r2 >> c1 >> c2;
        ans=0;
        for(int i=r1;i<=r2;i++)for(int j=c1;j<=c2;j++)ans=ans^a[i][j];
        cout<<ans<<"\n";
    }
}
