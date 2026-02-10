#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sum(x) ((x)*a1+(x)*(x-1)/2*d)
const int N=1e5+7;
ll a1,d,top;
ll m;
int Q;

ll ef(ll l,ll r){
    r++;
    while(l<r){
        ll mid=(l+r)/2;
        if(sum(mid)>m&&sum(mid-1)<=m){l=r=mid;}
        else if(sum(mid)>m)r=mid-1;
        else l=mid+1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[6];
    for(int i=1;i<=5;i++)cin>>a[i];
    a1=a[1],d=a[2]-a[1];

    if(d<0){//a1/-d+1
        top=sum(a1/-d+1);
        //cout<<top<<"\n";//
    }

    cin>>Q;
    while(Q--){
        ll ans=0;
        cin>>m;
        if(a1>m){cout<<"1\n";continue;}
        if(a1==0&&d==0){cout<<"-1\n";continue;}
        if(d<0){
            if(m>=top){cout<<"-1\n";continue;}
            ans=ef(1,a1/-d+1);
        }else{
            ans=ef(1,min((ll)(a1==0?1e12:m/a1),(ll)((d==0)?1e12:sqrt(2*m/d))));
        }
        while(ans>1&&sum(ans-1)>m)ans--;
        while(sum(ans)<=m)ans++;
        cout<<ans<<"\n";
    }
}
/*
na1+(n-1)*n/2*d

*/