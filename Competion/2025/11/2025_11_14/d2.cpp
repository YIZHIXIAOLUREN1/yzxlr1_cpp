#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int x,y,k;

int check(int ans){
    int f=1;
    for(int i=1;i<=x;){
        if(ans%y==0)f=-1;
        ans-=ans/y;
        i++;
        int r=ans/y;
        if(!r)break;
        int px=(ans%y)/r;
        px=min(px,x-i+1);
        ans-=px*r;
        i+=px;
        
        if(ans<k)return 1;
        //if(ans/y==0)break;
    }
    return f*(1+(ans>k)+(ans>=k));
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>x>>y>>k;
        int l=1,r=1e12+1;
        if(abs(check(1e12))==1){cout<<"-1\n";continue;}
        while(l<=r){
            int mid=(l+r)/2;
            int res=check(mid);
            //printf("%lld:%lld\n",mid,res);//
            if(res==2){l=r=mid;break;}
            else if(res==3||res==-3||res==-2)r=mid;
            else if(res==1||res==-1)l=mid;
        }
        cout<<l<<"\n";
    }
}