#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
int a[N];
ll ans;
int gp(int x,int y){
    int res=1;
    while(x>=y){
        res++;
        x-=2;
    }
    return res;
}
int check(int x){
    int cl=lower_bound(a+1,a+n+1,x)-a-1;
    int cr=upper_bound(a+1,a+n+1,x)-a-1;
    ll res1=0,res2=0;
    for(int i=cl;i<=n;i++){
        res1+=(gp(a[i],a[cl]));
        res2+=(gp(a[i],a[cl]));
        if(a[i]%ap[cl]==0)
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int l=1,r=a[n];
        while(l<=r){
            int mid=(l+r)/2;
            int che=check(mid);
            if(che==2){

            }else if(che==1){
                l=r=mid;
                break;
            }else{

            }
        }
    }
}
