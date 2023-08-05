#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 400000000
#define M 40000000
ll p;
ll ans=1,q;
bool tof[N];
int prime[M],tot;


int main(){
    cin >> p;
    p--;
    ll mp=sqrtl(p)+1;
    for(int i=2;i<=mp;i++){
    if(tof[i] == 0){
        tof[i] = 1;
        prime[++tot] = i;
        q=0;
        while(p%i==0){++q;p/=i;}
        ans*=q+1;
    }
    for(int j=1;j<=tot && i * prime[j] <= mp;j++){
        tof[i * prime[j]] = true;
        if(i % prime[j] == 0) break;
    }
}
    cout << ans;
}