#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+7;
int n;

pair<int,int> query(int l,int r){
    int res1,res2;
    cout<<"1 "<<l<<" "<<r<<endl;
    cin>>res1;
    cout<<"2 "<<l<<" "<<r<<endl;
    cin>>res2;
    if(res1==res2)return {-1,-1};
    else if(res2==res1+(r-l+1)){
        return {l,r};
    }
    
    int mid=(l+r)>>1;
    auto [l1,r1]=query(l,mid);
    auto [l2,r2]=query(mid+1,r);
    if(l1<0)return {l2,r2};
    if(l2<0)return {l1,r1};
    return {l1,r2};
}

signed main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        auto [l,r]=query(1,n);
        cout<<"! "<<l<<" "<<r<<endl;
    }
}