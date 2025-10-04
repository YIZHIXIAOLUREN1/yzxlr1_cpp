#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,a[N],Q;
int con[N],xc[N],hc[N];
int pre[N],prx[N],prh[N];
int xcc[N];
int prxc[N];
void qp(int i){
    con[i]=xc[i]=hc[i]=xcc[i]=0;
    int xx=a[i];
    while(xx>1){
        xx/=2;
        con[i]++;
    }
    xx=a[i];
    while(xx>1){
        xx/=2;
        if(xx>1&&xx&1){xx++;xcc[i]++;}
        xc[i]++;
    }
    xc[i]-=con[i];
    xx=a[i]+1;
    while(xx>1){
        xx/=2;
        if(xx>1)xx++;
        hc[i]++;
    }
    hc[i]-=con[i]+xc[i];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            qp(i);
            pre[i]=pre[i-1]+con[i];
            prx[i]=prx[i-1]+xc[i];
            prh[i]=prh[i-1]+hc[i];
            prxc[i]=prxc[i-1]+xcc[i];
            //printf("%d:%d %d %d:%d\n",i,con[i],xc[i],hc[i],xcc[i]);//
        }
        while(Q--){
            int l,r;
            cin>>l>>r;
            cout<<pre[r]-pre[l-1]+prx[r]-prx[l-1]+
            (prh[r]-prh[l-1])/2<<"\n";
        }
    }
}