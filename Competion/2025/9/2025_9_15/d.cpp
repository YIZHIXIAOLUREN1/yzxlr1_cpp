#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=2e5+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,Y,c[N],cc[N+1],prc[N+1];
ll ans=-inf;
int rou(int x,int y){
    int res=x/y;
    if(x%y)res++;
    return res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Y;
        for(int i=1;i<=N;i++)cc[i]=0;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            cc[c[i]]++;
        }
        for(int i=1;i<=N;i++){
            prc[i]=prc[i-1]+cc[i];
        }
        sort(c+1,c+n+1);
        //for(int i=1;i<=n;i++)cout<<c[i]<<" \n"[i==n];//
        ans=-inf;
        for(int x=2;x<=max(1ll*2,c[n]);x++){
            ll res=0,cp=0;
            //cout<<x<<":\n";//
            //for(int i=1;i<=c[n];i++)res+=rou(i,x)*cc[i];
            for(int i=1;i<=rou(c[n],x);i++){
            	//printf("%d:%d %d %d\n",i,cc[i],i*x,(i-1)*x+1);//
                //res+=rou(i,x)*cc[i];
            	res+=i*(prc[min(i*x,c[n])]-prc[(i-1)*x]);
            	cp+=min(cc[i],prc[min(i*x,c[n])]-prc[(i-1)*x]);
            	//res+=i*(prc[i*x]-prc[(i-1)*x]);
            	//cp+=min(cc[i],prc[i*x]-prc[(i-1)*x]);
            }
            //printf("R%d %d:%d\n",res,cp,res-(n-cp)*Y);
            res-=(n-cp)*Y;
            //cout<<res<<"R\n";//
            ans=max(ans,res);
        }
        cout<<ans<<"\n";
    }
}