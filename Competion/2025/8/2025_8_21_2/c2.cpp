#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,k;
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
int jy[20];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        //cout<<mx(n)<<" ";//
        ans=0;
        int rk=0,mxj=mx(n);
        for(int j=mxj;j>=0;j--){
        	jy[j]=0;
            ll mj=qp(3,j);
            while(n>=mj){
                n-=mj;
                jy[j]++;
                rk++;
                //printf("%d %d %d\n",j,n,ans);//
            }
        }
        if(rk>k){cout<<"-1\n";continue;}
        else{
            int tp=mxj;
            while(rk<=k-2&&tp){
                if(!jy[tp])tp--;
                else{
                    int jk=min((k-rk)/2,jy[tp]);
                    jy[tp]-=jk,jy[tp-1]+=3*jk;
                    rk+=2*jk;
                }
            }
        }
        for(int i=0;i<=mxj;i++){
            ll mj=qp(3,i);
            ans+=(3*mj+i*mj/3)*jy[i];
        }
        cout<<ans<<"\n";
    }
}
