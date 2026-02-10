#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,k,kk,a,b,ans[N],tot;

void Solve(){
    cin>>n>>k;
    kk=k;
    a=b=tot=0;
    int cn=n;
    for(int i=(1ll<<29);i>=1;i>>=1){
        if(i>n)continue;
        if(n&i){
            if(!a){
                a=i;
            }else if(!b){
                b=i;
            }else{
                b^=i;
            }
        }else if(a&&b){
            a^=i;
            b^=i;
        }
    }
    if(k%2==0){
    	ans[++tot]=a;
    	ans[++tot]=b;
    	k-=2;
    }
    while(k>=2){
        ans[++tot]=n;
    	ans[++tot]=n;
        k-=2;
    }
    if(k)ans[++tot]=n;
    //cout<<tot<<":\n";//
    for(int i=1;i<=kk;i++)cout<<ans[i]<<" \n"[i==kk];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
0001 0110 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
0011 0101 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111
*/