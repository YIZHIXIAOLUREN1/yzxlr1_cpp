#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,m,q;
int a[N],b[N],c[N];
ll sb[N],sqc[N];
ll sf[N],f[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    memset(sf,0x3f,sizeof sf);
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++){
        cin >> b[i];
        sb[i]=sb[i-1]+b[i];
    }
    for(int i=1;i<=n;i++)cin >> c[i];
    sf[0]=0;
    for(int i=1;i<=n;i++){
        sf[i]=min(1ll*a[i],sf[i-1]+b[i]);
    }
    cin >> q;
    sf[0]=0;
    while(q--){
        cin >> m;
        if(m==0){
        	cout << sf[n]<<"\n";
        	continue;
        }
        int u,v;
        cin >> u;
        f[u]=min(sf[u]+c[u],sf[u-1]);
        sqc[1]=c[u];
        for(int i=2;i<=m;i++){
            cin >> v;
            sqc[i]=c[v]+sqc[i-1];
            f[v]=min(f[u]+sb[v-1]-sb[u],sf[v-1]+sqc[i-1]);
            f[v]=min(f[v],sf[v]+sqc[i]);
            u=v;
        }
        if(u!=n)f[n]=min(f[u]+sb[n]-sb[u],sf[n]+sqc[m]);
        cout << f[n] <<"\n";
    }

}



/*
f[i]=min(a[i]+sc[i],f[i-1]+iq[i]?b[i]:c[i];)



1 0 0 0 1
*/