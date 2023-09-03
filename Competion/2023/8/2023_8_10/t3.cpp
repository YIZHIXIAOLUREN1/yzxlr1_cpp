#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,k,m,c,d;
int a[N];
ll b[N];
ll ans;
int wz;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> m >> c >> d;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    if(k==1){
        for(int i=1;i<m;i++){
            ans=max(ans,1ll*d*(i-1)+c+a[i]);
        }
        for(int i=m;i<=n;i++){
            ans=max(ans,1ll*d*(m-1)+c+a[i]);
        }
    }else{
        for(int i=1;i<=n-m+1;i++){
        	for(int j=1;j<=n;j++){
        		if(j>=i&&j<=i-m+1)continue;
        		b[j]=a[j];
        	}
            for(int j=i;j<=i+m-1;j++)b[j]=1ll*d*(j-i)+a[j]+c;
            sort(b+1,b+n+1);
            ans=max(ans,b[n-k+1]);
        }
    }
    cout << ans;
}
