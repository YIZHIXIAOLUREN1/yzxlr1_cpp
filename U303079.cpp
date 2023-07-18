#include<bits/stdc++.h>
using namespace std;
#define N 1000050
int n,k,k1;
pair<int,int> b[N];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second>y.second;
}
int ans,xk;
bool tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    k1=k;
    for(int i=1,a;i<=n;i++){
        b[i].first=i;
        cin >> a;
        b[a].second++;
    }
    sort(b+1,b+n+1,cmp);
    k=b[1].second;
    for(int i=1;i<=n;i++){
        if(!b[i].second){
            break;
        }
        if(k1>=k-b[i].second){
        	
            ans++;
            //cout << i << ":" << k1 << "\n";//
        }else break;
    }
    if(k1>=k)puts("pigstd");
    else cout << ans;
}