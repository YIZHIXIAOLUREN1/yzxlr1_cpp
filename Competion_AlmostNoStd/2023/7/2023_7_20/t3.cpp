#include<bits/stdc++.h>
using namespace std;
#define N 100050
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
int n,K,a,b;
ll f[1005][1005][2];/////////////////////
struct node{
    int w,s,p,ba;
}pe[N],pz[N],py[N];

bool cmp(node x,node y){
    return x.w<y.w;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for(int i=1;i<=n;i++){
        cin >> pe[i].w >> pe[i].s >> pe[i].p;
        if(pe[i].p==1||pe[i].p==3)pz[++a]=pe[i],pz[a].ba=i;
        if(pe[i].p==2||pe[i].p==3)py[++b]=pe[i],py[b].ba=i;
    }
    //ll f[n+10][n+10][2];
    memset(f,0x3f,sizeof f);
    sort(pz+1,pz+a+1,cmp);
    sort(py+1,py+b+1,cmp);
    for(int j=1;j<=a;j++)
        for(int k=1;k<=b;k++){
            f[j][k][0]=0;
        }
    for(int i=1;i<=K;i++){
        int ni=i&1,li=(i^1)&1;
        for(int j=1;j<=a;j++){
            for(int k=1;k<=b;k++){
                f[j][k][ni]=min(f[j-1][k][ni],f[j][k-1][ni]);
                if(pz[j].ba!=py[k].ba&&pz[j].w>=py[k].w){
                    f[j][k][ni]=min(f[j][k][ni],f[j-1][k-1][li]+(ll)(pz[j].s+py[k].s));
                	//printf("%d %d %d:%lld\n",i,j,k,f[j][k][ni]);//
                }
            }
        }
    }
    ll ans=inf;
    for(int j=1;j<=a;j++)
        for(int k=1;k<=b;k++){
        	//if(f[j][k][K&1]!=inf)printf("%d %d:%lld\n",j,k,f[j][k][K&1]);//
            ans=min(ans,f[j][k][K&1]);
        }
    if(ans==inf)cout << "-1";
    else cout << ans;
}
