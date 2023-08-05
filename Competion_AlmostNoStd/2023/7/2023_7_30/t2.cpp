#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,M=2e6+7;
int n,m;
vector<int> G[N];
bool vis[N];
int deg[N];
int ans;
int q[N],head=1,top=0;
int md,mmd;
int res;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)mmd=max(mmd,deg[i]);
    md=0;
    res=n;
    while(res&&md<=mmd){
    	bool tr=0;
    	while(!tr&&md<=mmd){
    		for(int i=1;i<=n;i++){
            	if(!vis[i]&&deg[i]<=md){
                	vis[i]=1;
                	if(deg[i]==0)continue;
                	q[++top]=i;
                	res--;
                	tr=1;
            		ans+=deg[i]-1;
            		printf("a%d:%d\n",i,md);//
            		deg[i]=0;
                	if(md>1)break;
        	    }
	        }
	        if(!tr)md++;
    	}
        while(head<=top){
            int u=q[head++];
            for(auto v:G[u]){
                if(vis[v])continue;
                deg[v]--;
                if(deg[v]==1){
                    q[++top]=v;
                    vis[v]=1;
                    res--;
                    ans+=deg[v]-1;
                    printf("b%d:%d:%d\n",v,md,deg[v]-1);//
                    deg[v]=0;
                }
            }
        }
    }
    cout << ans;
}