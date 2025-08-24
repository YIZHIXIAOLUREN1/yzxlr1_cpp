#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,k,rk,nt;
ll lre[20];
ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=res*x;
        x=x*x;
        q>>=1;
    }
    return res;
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>k;
        rk=0;
		ans=0;
		lre[0]=0;
        for(int j=1;j<=14;j++){
            ll mj1=qp(10,j-1);
            lre[j]=lre[j-1]*9+45*mj1;
            if(rk+9*mj1*j<k){
                rk+=9*mj1*j;
                ans+=lre[j];
                //printf("%d %d:%d\n",j,ans,(mj1*11-1)*(9*mj1)/2);//
            }else{
                ll px=(k-rk)/j;
                rk+=px*j;
                ll pxx=mj1+px-1;
                ans+=(mj1/10)*(pxx/mj1)*((pxx/mj1)+1)/2;
                for(int jj=j;jj>=2;jj--){
                    ll mj2=qp(10,jj-1),pxl=(pxx/mj2);
                    ans+=pxl*lre[jj-1];
                    ans+=mj2*pxl*(pxl-1)/2;
                    ans+=pxl*(pxx-pxl*mj2);
                    pxx-=pxx/mj2*mj2;
                }
                ans+=(pxx+1)*pxx/2-lre[j-1];
                pxx=mj1+px;
                k=j+rk-k;
                while(k){k--;pxx/=10;}
                while(pxx){ans+=pxx%10;pxx/=10;}
                break;
            }
        }
        cout<<ans<<"\n";
    }
}
