#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,K,m;
ll c,d;
ll a[N];
ll b[N];

bool check(ll k){
    int res=0;
    for(int i=1;i<=n+1;i++)b[i]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=k)res++;
        else{
            int l=1,r=min(m,i);
            if(1ll*a[i]+c+1ll*(r-1)*d<k)continue;
            
            if(a[i]+c>=k){
                b[i-r+1]++;b[i-l+2]--;
            }else{
                l=(k-c-a[i]+d-1)/d+1;
                b[i-r+1]++;b[i-l+2]--;
            }
            //printf("%lld %d:%d %d\n",k,a[i],l,r);//
        }
    }
    bool che=0;
    int rb=0;
    for(int i=1;i<=n+1;i++){
        rb+=b[i];
        che=max((res+rb>=K),che);
    }
    //printf("c%lld:%d\n",k,res);//
    return che;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>K>>m>>c>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
    ll l=0,r=1e18;
    while(l<r){
        ll mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else r=mid-1;
    }
    while(l&&!check(l))l--;
    while(check(l+1))l++;
    cout<<l<<"\n";
}
