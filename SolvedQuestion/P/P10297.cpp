#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,a[N],b[N];
int l[N],r[N];
tuple<char,int,int> ans[N];
int top;
void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    
    for(int i=1,li=1,lj=1;i<=n;i++){
        if(b[i+1]==b[li]&&i!=n)continue;
        while(lj<=n&&a[lj]!=b[i])lj++;
        if(lj>n){cout<<"NO\n";return;}
        //printf("a%d:%d %d\n",lj,li,i);//
        l[lj]=li,r[lj]=i;
        li=i+1;
    }
    for(int i=n;i>=1;i--){
        if(!r[i])continue;
        if(r[i]<=i)continue;
        ans[++top]={'R',i,r[i]};
    }
    for(int i=1;i<=n;i++){
        if(!l[i])continue;
        if(i<=r[i]&&l[i]>=i)continue;
        ans[++top]={'L',l[i],max(i,r[i])};
    }
    
    cout<<"YES\n";
    cout<<top<<"\n";
    for(int i=1;i<=top;i++){
        auto [c,x,y]=ans[i];
        //cout<<c<<" "<<x<<" "<<y<<"\n";//
    }
    for(int i=1;i<=top;i++){
        auto [c,x,y]=ans[i];
        cout<<c<<" "<<x-1<<" "<<y-1<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
