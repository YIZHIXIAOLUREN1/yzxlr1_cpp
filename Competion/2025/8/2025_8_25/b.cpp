#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=1e5+7,M=1e6+7;

int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x;
        x=(ll)x*x;
        q>>=1;
    }
    return res;
}
void exgcd(int a,int b,int &x,int &y){
	if(a%b==0) x=0,y=1;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int n,k;
int a[N];

bool vis[M];
int p[N],tot=0;
int ans[N];
void getprime(){
    for(int i=2;i<M;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<M;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getprime();
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        int mxai=0;
        for(int i=1;i<=n;i++){cin>>a[i];mxai=max(mxai,a[i]);}
        for(int i=1;i<=tot;i++){
            bool flag=1;
            int kg=__gcd(k,p[i]);
            //printf("%d %d %d:\n",i,p[i],kg);//
            for(int j=1,x=0,y=0;j<=n;j++){
                ans[j]=a[j];
                if(a[j]%kg!=0){flag=0;break;}
                x=y=0;
                //cout<<"A";//
                exgcd(k,p[i],x,y);
                x*=a[j]/kg;
                y*=a[j]/kg;
                //printf("%d %d:%d %d\n",j,a[j],x,y);//
                while(x>0){
                	int kx=(x/(p[i]/kg)+1);
                	if(x%(p[i]/kg)==0)kx--;
                	x-=kx*(p[i]/kg);
                	y+=kx*(k/kg);
                }
                while(-x>=(p[i]/kg)){
                	int kx=(-x/(p[i]/kg));
                	//if(x%(p[i]/kg)==0)kx--;
                	x+=kx*(p[i]/kg);
                	y-=kx*(k/kg);
                }
                x=-x;
                ans[j]=y*p[i];
                //printf("%d %d:%d\n",x,y,ans[j]);//
                if(x>k){flag=0;break;}
            }

            if(flag){
                for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
                break;
            }
        }
    }
}
