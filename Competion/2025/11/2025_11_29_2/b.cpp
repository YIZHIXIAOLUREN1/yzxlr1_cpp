#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+7;
int n,a[N],b[N],c[N],nc[N],tot,cnt[N],sb;
int ans;
bool cmp(int x,int y){return x>y;}
void Solve(){
    cin>>n;
    ans=sb=tot=0;
    for(int i=1;i<=2*n;i++)b[i]=c[i]=nc[i]=cnt[i]=0;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        nc[a[i]]++;
    }
    for(int i=1;i<=2*n;i++){
        if(nc[i])cnt[++tot]=nc[i];
    }
    sort(cnt+1,cnt+tot+1,cmp);
    for(int i=1;i<=tot;i++){
        if(sb<n){
            b[i]=1;
            c[i]=cnt[i]-b[i];
            sb++;
        }else{
            c[i]=cnt[i];
        }
    }

    for(int i=1;i<=tot;i++){
        while(c[i]>=2&&sb+2<=n){
            c[i]-=2;
            b[i]+=2;
            sb+=2;
        }
    }
    for(int i=1;i<=tot;i++){
        while(c[i]&&sb<n&&(b[i]%2+c[i]%2)==((b[i]+1)%2+(c[i]-1)%2)){
            c[i]--;
            b[i]++;
            sb++;
        }
    }
    for(int i=1;i<=tot;i++){
        while(c[i]&&sb<n){
            c[i]--;
            b[i]++;
            sb++;
        }
    }
    
    for(int i=1;i<=tot;i++){
        if(c[i]%2)ans++;if(b[i]%2)ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}