#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+7;
int n,sum[2*N];
pair<int,int> a[N];
int lsh[2*N],cnt;
int vis[2*N],vb[N];
vector<int> g[2*N];


class comp{
    public:
    bool operator()(const pair<int,int>&x, const pair<int,int>&y)const{
        if(x.first!=y.first)return x.first>y.first;
        return x.second>y.second;
    }
};

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,r;
        cin>>x>>r;
        a[i]={x-r,x+r};
        lsh[2*i-1]=x-r;
        lsh[2*i]=x+r;
    }
    sort(lsh+1,lsh+2*n+1);
	cnt=unique(lsh+1,lsh+2*n+1)-lsh-1;
	for(int i=1;i<=n;i++){
        a[i].first=lower_bound(lsh+1,lsh+cnt+1,a[i].first)-lsh;
        a[i].second=lower_bound(lsh+1,lsh+cnt+1,a[i].second)-lsh;
        //printf("%d:%d %d\n",i,a[i].first,a[i].second);//
        sum[a[i].first]++;
        sum[a[i].second]++;
        g[a[i].first].push_back(i);
        g[a[i].second].push_back(i);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;
    for(int i=1;i<=cnt;i++){
    	//printf("a%d %d\n",i,sum[i]);//
        q.push({sum[i],i});
    }
    while(!q.empty()){
        auto [su,u]=q.top();
        
        q.pop();
        if(vis[u]||sum[u]!=su)continue;
        //printf("c%d %d\n",u,su);//
        int tg,stg=-1;
        for(auto v:g[u]){
            if(vb[v])continue;
            //printf("d%d\n",v);//
            if(a[v].second==u){
                if(sum[a[v].first]>stg){
                    tg=v;
                    stg=sum[a[v].first];
                }
            }else{
                if(sum[a[v].second]>stg){
                    tg=v;
                    stg=sum[a[v].second];
                }
            }
        }
        if(stg==-1)continue;
        //printf("%d %d\n",u,tg);//
        vb[tg]=1;
        vis[u]=1;
        if(a[tg].second==u){
            if(!vis[a[tg].first]){
                sum[a[tg].first]--;
                q.push({sum[a[tg].first],a[tg].first});
            }
        }else{
            if(!vis[a[tg].second]){
                sum[a[tg].second]--;
                q.push({sum[a[tg].second],a[tg].second});
            }
        }
    }

    int ans=0;
    for(int i=1;i<=cnt;i++)if(vis[i])ans++;
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        Solve();
    }
}
