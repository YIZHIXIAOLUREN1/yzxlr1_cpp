#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007;
int M;
int n,sn;
int c[N];
ll cp[N][700];
ll cpp[700];
bool vis[N];
int p[N],tot=0;
ll ans;
void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    //for(int j=1;j<=670;j++)printf("%d:%d\n",j,p[j]);//
    for(int i=2;i<N;i++){
        int ci=i;
        for(int j=1;j<=670&&p[j]<=ci;j++){
            while(ci%p[j]==0){
                cp[i][j]++;
                ci/=p[j];
            }
        }
        
        for(int j=1;j<=670;j++)cp[i][j]+=cp[i-1][j];
        //cout<<i<<"\n";//
    }
    
    //for(int i=2;i<10;i++)for(int j=1;j<=6;j++)printf("%d %d:%d\n",i,j,cp[i][j]);//
}

ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=res*x%M;
        x=x*x%M;
        q>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getprime();
    int T;
    cin>>T>>M;
    while(T--){
        cin>>n;
        sn=0;
        for(int i=1;i<=670;i++)cpp[i]=0;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            sn+=c[i];
            
        }
        for(int j=1;j<=670&&p[j]<=sn;j++)cpp[j]+=cp[sn][j];
        //for(int i=1;i<=6;i++)printf("%d:%lld\n",p[i],cpp[i]);//
        for(int k=1;k<=n;k++){
            for(int j=1;j<=670&&p[j]<=c[k];j++)cpp[j]-=cp[c[k]][j];
        }
        //for(int i=1;i<=6;i++)printf("%d:%lld\n",p[i],cpp[i]);//
        ans=1;
        for(int i=1;i<=670;i++){
            ans=ans*qp(p[i],cpp[i])%M;
        }
        cout<<ans<<"\n";
    }
}
