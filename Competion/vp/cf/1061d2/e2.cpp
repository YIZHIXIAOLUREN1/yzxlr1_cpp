#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
const int N=1e5+7;
const ll inf=2e9+7,INF=1e9+7;
int n,a[N];
int f[N];

/*
bj>=bi+x,j>i
bi>=bj+x,bi-x>=bj j<i
*/

int mia=INF,maa=0;
vector<int> p2,pk;
ll ma[5];
void upd1(int x){
    for(int i=1;i<=3;i++){
        if(x<=ma[i]){
            for(int j=3;j>=i+1;j--)ma[j]=ma[j-1];
            ma[i]=x;
            break;
        }
    }
}
int che1(ll x){
    int res=0;
    for(int i=1;i<=3;i++)if(ma[i]<=x)res++;
    return res;
}
void upd2(ll x){
    for(int i=1;i<=3;i++){
        if(x>=ma[i]){
            for(int j=3;j>=i+1;j--)ma[j]=ma[j-1];
            ma[i]=x;
            break;
        }
    }
}
int che2(int x){
    int res=0;
    for(int i=1;i<=3;i++)if(ma[i]>=x)res++;
    return res;
}

bool check(ll x){
	//printf("%lld:\n",x);//
    //printf("%d %d\n",mia,maa);
    
    p2.clear();
    pk.clear();
    // for(int i=1;i<=n;i++){
    //     f[i]=query(root1,mia,a[i]-x);
    //     update1(root1,a[i],1);
    // }
    // for(int i=n;i>=1;i--){
    //     f[i]+=query(root2,a[i]+x,maa);
    //     update1(root2,a[i],1);
    // }
    // for(int i=1;i<=n;i++){
    //     update1(root1,a[i],-1);
    //     update1(root2,a[i],-1);
    // }
    ma[1]=ma[2]=ma[3]=inf;
    for(int i=1;i<=n;i++){
        f[i]=che1(a[i]-x);
        upd1(a[i]);
    }
    ma[1]=ma[2]=ma[3]=-inf;
    for(int i=n;i>=1;i--){
        f[i]+=che2(a[i]+x);
        upd2(a[i]);
    }

    int res2=0,resk=0;
    for(int i=1;i<=n;i++){
    	//cout<<f[i]<<" \n"[i==n];//
        if(f[i]<2)continue;
        if(f[i]==2){
            res2++;
            p2.push_back(i);
        }else{
            resk++;
            pk.push_back(i);
        }
    }
    if(resk>=2)return 0;//x k=0,1
    if(res2+resk<=1)return 1;//1 0 0 1 0 0
    if(res2==3&&resk==0){
        return (a[p2[0]]+x<=a[p2[1]]&&a[p2[0]]+x<=a[p2[2]])||(a[p2[0]]+x<=a[p2[1]]&&a[p2[1]]+x<=a[p2[2]])||(a[p2[0]]+x<=a[p2[2]]&&a[p2[1]]+x<=a[p2[2]]);
    }
    if(res2>=2&&resk==1){
        for(auto u:p2){
        	//printf("%lld %lld:%lld %lld\n",pk[0],u,a[pk[0]],a[u]);//
            if(pk[0]<u&&a[pk[0]]+x>a[u])return 0;
            if(pk[0]>u&&a[u]+x>a[pk[0]])return 0;
        }
        return 1;
    }
    if(res2==2&&resk==0){
    	return a[p2[0]]+x<=a[p2[1]];
    }
    if(res2==1&&resk==1){
    	if(p2[0]>pk[0])swap(p2[0],pk[0]);
    	return a[p2[0]]+x<=a[pk[0]];
    }
    //resk==0&&res2>3
    return 0;
}

void Solve(){
    cin>>n;
    mia=INF,maa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mia=min(mia,a[i]);
        maa=max(maa,a[i]);
    }
    
    //printf("%d %d\n",mia,maa);
    ll l=mia-maa,r=maa-mia;
    while(l<r){
        ll mid=(l+r+1)/2;
        int res=check(mid);
        //printf(":%d\n",res);//
        if(!res)l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}