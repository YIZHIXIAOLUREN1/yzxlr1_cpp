#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+5;
int n,m,q,sh1,sh2,sh3,mu=1;
int a[N],b[N],type0[N],type1[N];
struct hhs1{
    int p,v,t;
    void in(){scanf("%lld%lld",&p,&v);}
}h1[N];
struct hhs2{
    int v,t;
    void in(){scanf("%lld",&v);}
}h2[N];
struct hhs3{
    int c,t;
    vector<int> hs;
    void in(){
        scanf("%lld",&c);
        for(int x,i=1;i<=c;i++){
        	scanf("%lld",&x);
        	hs.push_back(x);
		}
    }
}h3[N];

void dfs(int h){
    int ty=type0[h],s=type1[h];
    if(ty==(int)3){
        for(int v=h3[s].c-1;v>=(int)0;v--){
            dfs(h3[s].hs[v]);
        }
    }else if(ty==(int)2){
        mu=mu*h2[s].v%mod;
    }else{
    	//h1[s].t=(h1[s].t+mu)%mod;
        a[h1[s].p]=(a[h1[s].p]+h1[s].v*mu)%mod;
    }
}

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    scanf("%lld",&m);
    for(int ty,i=1;i<=m;i++){
        scanf("%lld",&ty);
        switch (ty){
            case (int)1:h1[++sh1].in();type0[i]=(int)1,type1[i]=sh1;break;
            case (int)2:h2[++sh2].in();type0[i]=(int)2,type1[i]=sh2;break;
            case (int)3:h3[++sh3].in();type0[i]=(int)3,type1[i]=sh3;break;
        }
    }
    h3[0].in();
    type0[0]=(int)3;
    type1[0]=(int)0;
    dfs((int)0);
    // for(int i=1;i<=sh1;i++){
    //     if(!h1[i].t)continue;
    // 	a[h1[i].p]=h1[i].v*h1[i].t%mod;
    // }
    for(int i=1;i<n;i++){
        printf("%lld ",(a[i]+b[i]*mu)%mod);
    }
    printf("%lld\n",(a[n]+b[n]*mu)%mod);
    return 0;
}
