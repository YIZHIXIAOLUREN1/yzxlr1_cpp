#include<bits/stdc++.h>
using namespace std;
#define N 12
#define NN 1000000
#define mod 998244353
int n,m;
int a[N],b[N];
int v1[NN];
int s,t,ans,ls,lt;
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=m;i++)cin >> b[i];

    for(int j=1;j<pow(2,n);j++){
        for(int k=1;k<pow(2,m);k++){
        	s=t=0;
            for(int i=0;i<n;i++){
                if(j&(1<<i)){s*=10;s+=a[i+1];}
            }
            for(int i=0;i<m;i++){
                if(k&(1<<i)){t*=10;t+=b[i+1];}
            }
            if(v1[s*1025+t]||s==0||t==0)continue;
            //printf("%d %d:%d %d\n",j,k,s,t);//
            v1[s*1025+t]=1;
            if(s>t)ans++;
            ans%=mod;
        }
    }
    cout << ans;
}
