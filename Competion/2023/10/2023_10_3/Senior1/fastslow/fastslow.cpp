#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
int a[N],lsh[N];
int rr[N],nxt[N],la[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        lsh[i]=a[i];
    }
    sort(lsh+1,lsh+n+1);
    int cnt=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1;i<=n;i++){
    	a[i]=lower_bound(lsh+1,lsh+cnt+1,a[i])-lsh;
    	//printf("%d:%d\n",i,a[i]);//
    }

    for(int i=1;i<=n;i++){rr[a[i]]++;la[i]=n+1;}
    for(int i=n;i>=1;i--){
        nxt[i]=la[a[i]];
        la[a[i]]=i;
    }
    nxt[0]=n+1;
    
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        if(x<lsh[1])x=0;
        else x=lower_bound(lsh+1,lsh+cnt+1,x)-lsh;
        if(y<lsh[1])y=0;
        else y=lower_bound(lsh+1,lsh+cnt+1,y)-lsh;
        //printf("%d %d\n",x,y);//
        ll res=0;
        int l=0,r=0,lx=la[x],ly=la[y];
        r=rr[y];
        for(int j=1;j<=n;){
        	if(a[j]==y)r--;
            if(a[j]==x){l++;res=max(res,1ll*l*r);}
            if(lx<=j)lx=nxt[lx];
            if(ly<=j)ly=nxt[ly];
            if(j<lx&&j<ly)j=min(lx,ly);
        }
        cout << res <<"\n";
    }
}