#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+7;
int n,m;
vector<pair<int,int>>G[N];
int dis[N],cnt[N];
bool vis[N];
void add(int a,int b,int c){G[a].push_back(make_pair(b,c));}
queue<int> q;

bool spfa(){
    memset(dis,0x3f,(n+1)*sizeof(int));
    dis[0]=0;vis[0]=1;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto pa:G[u]){
            int v=pa.first,s=pa.second;
            if(dis[v]>dis[u]+s){
                dis[v]=dis[u]+s;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return 0;
                vis[v]=0;
                q.push(v);
            }
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >>n>>m;
    for(int i=1,t,a,b,c;i<=m;i++){
        cin >> t >> a >> b;
        switch (t){
        case 1:cin>>c;add(a,b,-c);break;
        case 2:cin>>c;add(b,a,c);break;
        case 3:add(a,b,0);add(b,a,0);break;
        }
    }
    for(int i=1;i<=n;i++)add(0,i,0);
    if(spfa())cout<<"Yes";
    else cout<<"No";
    return 0;
}
