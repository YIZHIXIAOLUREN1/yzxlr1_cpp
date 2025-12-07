#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll n,k,ans;
void Solve(){
    cin>>n>>k;
    ans=0;
    for(int i=1;i<=k;i++){
        int len=0,st=0,nlen=0,nst=0;
        for(int j=0;(1<<(j-1))<=n;j++){
            if((1<<j)&n){
                if(j==0||((1<<(j-1))&n)==0){
                	
                    nst=j;
                    nlen=1;
                }else{
                    nlen++;
                }
            }else{
                if(j&&((1<<(j-1))&n)){
                    if(nlen>len){
                        st=nst;
                        len=nlen;
                    }
                }
            }
        }
        printf("%d %d\n",st,len);//
        ans+=len;
        n=n+(1<<st);
    }
    cout<<ans<<"\n";
}

int main(){
    //::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}

/*
dp[i][j] 


*/
