#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n;
bool vis[11];
ll a[N];
ll ans;

bool check(ll x,ll y){
	//printf("%lld:%lld\n",x,y);//
    while(x&&y){
        int a=x%10,b=y%10;
        if(a==b)return 1;
        if(a<b)swap(x,y),swap(a,b);
        y/=10;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        memset(vis,0,sizeof vis);
        while(a[i]){
        	vis[a[i]%10]=1;
        	a[i]/=10;
        }
        for(int j=0;j<=9;j++)a[i]=(a[i]<<1)|vis[j];
        //printf("%d:%d\n",i,a[i]);//
    }

    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
        	//printf("%d:%d:\n",i,j);//
            while(a[i]&a[j]){
            	ans++;
            	break;
            }
        }
    }
    cout << ans;
}