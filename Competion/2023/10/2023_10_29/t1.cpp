#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,mod=998244353;
struct node{
    int size,num;
}a[N];
int n;
int tot,b[N];
int jc[N];
int ans;
//num_of_num,tot_of_num,num_to_num

int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}
int inv1(int x){return qp(x,mod-2);}
void pre(){
    jc[0]=1;
    for(int i=1;i<=N-1;i++){
        jc[i]=1ll*jc[i-1]*i%mod;
    }
}

int C(int n,int m){
	if(n==m||m==0||n==0)return 1;
    return 1ll*jc[n]*inv1(jc[m])%mod*inv1(jc[n-m])%mod;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    pre();
    //cout<<"A";//
    while(T--){
        memset(b,0,sizeof b);
        tot=0,ans=1;
        cin >> n;
        for(int i=1,u;i<=n;i++){
            cin >> u;
            if(!b[u]){
            	a[b[u]=++tot].num=u;
            	a[b[u]].size=0;
            }
            a[b[u]].size++;
        }
        for(int i=1;i<=tot;i++){
            int x=a[i].size,y=a[i].num;
            if(x%y!=0){ans=0;break;}
            int res=1;
            //printf("%d:%d %d:\n",i,x,y);//
            for(int j=1;j<=x/y-1;j++){
                res=1ll*res*C(x-(j-1)*y,y)%mod;
                //printf("%d:%d\n",j,res);//
            }
            if(res==0)res=1;
            //printf("%d\n",res);//
            res=1ll*res*inv1(jc[x/y])%mod*qp(jc[y-1],x/y)%mod;
            if(y==1)res=1;
            ans=1ll*ans*res%mod;
        }
        //cout<<"a:";//
        cout<<ans<<"\n";
    }
}
/*
(n-1)!

*/