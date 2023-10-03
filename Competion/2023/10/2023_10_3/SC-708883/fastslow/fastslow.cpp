#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
int a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("fastslow.in","r",stdin);
    freopen("fastslow.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ll res=0,l=0,r=0;
        for(int j=1;j<=n;j++)if(a[j]==y)r++;
        for(int j=1;j<=n;j++){
        	if(a[j]==y)r--;
            if(a[j]==x){l++;res=max(res,1ll*l*r);}
        }
        cout << res <<"\n";
    }
}