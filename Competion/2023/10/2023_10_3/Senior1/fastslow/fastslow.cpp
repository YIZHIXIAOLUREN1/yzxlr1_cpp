#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
int a[N],lsh[N];
int rr[N],nxt[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        lsh[i]=a[i];
    }
    sort(lsh+1,lsh+n+1);
    int cnt=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+cnt+1,a[i])-lsh;

    for(int i=1;i<=n;i++)rr[a[i]]++;

    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        x=lower_bound(lsh+1,lsh+cnt+1,x)-lsh;
        y=lower_bound(lsh+1,lsh+cnt+1,y)-lsh;
        ll res=0,l=0,r=0;
        r=rr[y];
        for(int j=1;j<=n;j++){
        	if(a[j]==y)r--;
            if(a[j]==x){l++;res=max(res,1ll*l*r);}
        }
        cout << res <<"\n";
    }
}