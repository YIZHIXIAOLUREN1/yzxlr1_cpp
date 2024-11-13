#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
const ll inf=0xc0c0c0c0c0c0c0c0;
ll f[N],s[N];
ll mf,ms[N];
int n,a[N],b[N];

int C(int x,int y){return (b[a[x]]==b[a[y]])*b[a[x]];}

int main(){
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
        sort(b+1,b+n+1);
        int cmp=unique(b+1,b+n+1)-b;
        for(int i=1;i<=n;i++){
            a[i]=lower_bound(b+1,b+cmp+1,a[i])-b;
            ms[i]=inf;
            s[i]=C(i,i-1);
        }
        //memset(f,0,sizeof(f));
        //memset(g,0,sizeof(g));
        f[0]=f[1]=s[1]=s[0]=0;
        mf=0;
        ms[a[1]]=0;
        for(int i=2;i<n;i++){
            f[i]=s[i]+max(1ll*0,max(mf,ms[a[i+1]]+b[a[i+1]]));
            mf=max(mf,f[i]-s[i+1]);
            ms[a[i]]=max(ms[a[i]],f[i]-s[i+1]);
        }
		f[n]=s[n]+mf;
        cout<<f[n]<<"\n";
    }
}