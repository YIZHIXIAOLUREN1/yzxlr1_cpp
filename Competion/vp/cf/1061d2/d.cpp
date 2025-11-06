#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+7;
int n;
bool vis[N];
int res0,res1,res[N];
int tot[27];
int ans;
void Solve(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        for(int j=0;(1<<j)<=4*n;j++){
            tot[j]=0;
        }
    }
    
    for(int j=0;(1<<j)<=4*n;j++){
        for(int i=1;i<=n;i++){
            bool fl=0;
            for(int k=0;k<j;k++){
                if((i&(1<<k))!=(ans&(1<<k))){
                    fl=1;
                    break;
                }
            }
            if(fl)continue;
            tot[j]+=((i&(1<<j))?1:0);
        }
        res0=res1=0;
        for(int i=1;i<=n-1;i++){
            if(vis[i])continue;
            cout<<"? "<<i<<" "<<(1<<j)<<endl;
            cin>>res[i];
            if(res[i])res1++;
            else res0++;
        }
        //printf("%d:%d %d\n",tot[j],res1,res0);//
        if(tot[j]==1+res1){
            ans|=(1<<j);
            for(int i=1;i<=n-1;i++){
                if(vis[i])continue;
                if(!res[i]){
                    vis[i]=1;
                }
            }
        }else{
            for(int i=1;i<=n-1;i++){
                if(vis[i])continue;
                if(res[i]){
                    vis[i]=1;
                }
            }
        }
    }
    cout<<"! "<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
