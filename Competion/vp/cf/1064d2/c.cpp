#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,a[N],pre[N],nex[N];
bool vis[N];


struct cmp{
    bool operator()(const pair<pair<int,int>,pair<int,int>>&x,const pair<pair<int,int>,pair<int,int>> &y){
        return max(x.second.first,x.second.second)>max(y.second.first,y.second.second);
    }
};


priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int> > > ,cmp> q;
ll ans;
void Solve(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=i-1;
        nex[i]=i+1;
        vis[i]=0;
    }
    pre[1]=n;
    nex[n]=1;
    while(!q.empty())q.pop();
    for(int i=1;i<n;i++){
        q.push({{i,i+1},{a[i],a[i+1]}});
    }
    q.push({{n,1},{a[n],a[1]}});
    while(!q.empty()){
        auto [nnnl,nnnr]=q.top();
        auto [l,r]=nnnl;auto [al,ar]=nnnr;
        q.pop();
        //printf("%lld %lld:%lld %lld\n",l,r,a[l],a[r]);//
        if(al!=a[l]||ar!=a[r]||vis[l]||vis[r])continue;
        int ma=max(a[l],a[r]);
        //printf("y%lld\n",ma);//
        a[l]=ma;
        vis[r]=1;
        ans+=ma;
        pre[nex[r]]=l;
        nex[l]=nex[r];
        if(pre[l]==r||nex[r]==l)break;
        q.push({{pre[l],l},{a[pre[l]],ma}});
        q.push({{l,nex[r]},{ma,a[nex[r]]}});
    }
    cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
a[i],a[i+1]->ma del
a[i]=ma;
vis[i+1]=1;
pre,nex
a[i-1],a[i]->a[i-1],ma
a[i+1],a[i+2]->ma,a[i+2]
*/