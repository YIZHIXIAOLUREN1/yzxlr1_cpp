#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,b[20];
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
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int top=0;
        while(a[i])b[++top]=a[i]%10,a[i]/=10;
        sort(b+1,b+1+top);
        for(int j=top;j>=1;j--){
            a[i]=a[i]*10+b[j];
            while(b[j]==b[j-1])j--;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
        	//printf("%d:%d:\n",i,j);//
            if(check(a[i],a[j]))ans++;
        }
    }
    cout << ans;
}
