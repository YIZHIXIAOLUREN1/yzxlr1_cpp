#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
const int N=1e5+7,inf=0x3f3f3f3f;
int n,k;
int deg[N];
bool vis[N];
int dis[N];
vector<int> od,G[N];
int res=0;
struct node{
    int id,s;
    friend bool operator < (node a,node b){
        return a.s>b.s;
    }
};
priority_queue<node> q;

void pre(){
	memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    res=0;
    for(auto u:od){
        vis[u]=1;
        dis[u]=0;
        q.push({u,0});
    }
    while(!q.empty()){
        int u=q.top().id;
        q.pop();
        vis[u]=0;
        for(auto v:G[u]){
        	//if(u<=100||v<=100)//
        	//printf("%d %d:%d %d\n",u,v,dis[u],dis[v]);//
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                if(!vis[v]){
                	q.push({v,dis[v]});
					vis[v]=1;
				}
            }
        }
    }
}

bool check(int xa){
	res=0;
    //cout << "\n";//
    for(int i=1;i<=n;i++){
    	if(dis[i]<xa)res++;
    	//if(xa==3)printf("%d:%d\n",i,dis[i]);//
	}
    //if(xa==3)printf("%d:%d\n",xa,res);//
    if(res>=n-k)return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1,u,v;i<=n-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)if(deg[i]==1){
    	od.push_back(i);
    	//if(i<=1000)printf("%d ",i);//
    }
    pre();
    // int md=0;
    // for(int i=1;i<=n;i++){
    	// if(dis[i]!=inf)md=max(md,dis[i]);
    // }
    // cout << md <<"\n";//
    //cout << "\n";//
    int l=0,r=n/2+1;
    //check(3);
    while(l<=r){
    	bool tr=check(mid);
    	//printf("%d %d:%d\n",l,r,tr);//
        if(!tr)l=mid+1;
        else r=mid-1;
    }
    while(!check(l))l++;
    while(check(l-1)&&l>=1)l--;
    cout << l;
}