#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=32;

struct LB{
    int b[M],p[M];
    LB(){memset(b,0,sizeof b);memset(p,0,sizeof p);}
    void ins(int x,int pos){
        for(int i=31;i>=0;i--){
            if(!(x>>i))continue;
            if(!b[i]){b[i]=x;p[i]=pos;return;}
            if(pos>p[i]){swap(b[i],x);swap(p[i],pos);}
            x^=b[i];
        }
    }
    int qry(int x,int l){
        int cnt=0;
        for(int i=31;i>=0;i--){
            if(p[i]<l)continue;
            if(x>>i&1){x^=b[i];cnt++;}
        }
        return x?0:cnt;
    }
}pre[N];

int n,q,a[N];

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        pre[i].ins(a[i],i);
    }
    
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        cout<<pre[r].qry(x,l)<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    while(T--){
        Solve();
    }
    return 0;
}