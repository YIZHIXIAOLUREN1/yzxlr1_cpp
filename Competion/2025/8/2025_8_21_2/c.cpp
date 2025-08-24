#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
ll ans=0;

ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=res*x;
        x=x*x;
        q>>=1;
    }
    return res;
}
int mx(int p){
    int res=0,np=1,xp=p;
    while(p){
        res++;p/=3;
        np*=3;
    }
    while(np>xp){res--;np/=3;}
    while(np*3<=xp){res++;np*=3;}
    //cout<<"A";//
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        //cout<<mx(n)<<" ";//
        ans=0;
        for(int j=mx(n);j>=0;j--){
        	
            ll mj=qp(3,j);
            while(n>=mj){
                n-=mj;
                ans+=3*mj+j*mj/3;
                //printf("%d %d %d\n",j,n,ans);//
            }
        }
        cout<<ans<<"\n";
    }
}
