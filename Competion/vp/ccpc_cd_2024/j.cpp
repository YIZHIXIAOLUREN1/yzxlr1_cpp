#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,m;
int a[N],b[N];
int las[N];
ll num;
ll sum;
ll ans;
ll pum[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            las[i]=0;
        }
        num=sum;
        bool fl=0;
        for(int i=1;i<=m;i++){
            int opt;
            cin>>b[i]>>opt;
            if(fl)continue;
            if(sum<b[i]-b[i-1]){
                ans=b[i-1]+sum;
                fl=1;
                continue;
            }
            pum[i]=pum[i-1];
            if(b[i]-b[i-1]>a[opt]){
                sum-=b[i]-b[i-1]-a[opt];
                pum[i]+=b[i]-b[i-1]-a[opt];
            }else{
            	int tum=min(a[opt]-(b[i]-b[i-1]),min(b[i-1]-b[las[opt]],pum[i]-(las[opt]?pum[las[opt]-1]:0)));
            	sum+=tum;
            	pum[i]-=tum;
                //sum+=min(a[opt]-(b[i]-b[i-1]),b[i-1]-b[las[opt]]);
                //sum=min(sum,num);
            }
            las[opt]=i;
            //printf("%d:%d %d\n",i,sum,pum[i]);//
            //printf("%d:%d\n",i,sum);//
        }
        if(!fl)cout<<b[m]+sum<<"\n";
        else cout<<ans<<"\n";
    }
}
