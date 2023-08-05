#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,inf=0x3f3f3f3f;
#define pr pair<int,int>
#define prr pair<int,pr>
int n,m;
bool vis[N],vvis[N];
vector<pr> G[N];
int head=1,top;
pr q[N];
int ans;

void dfs1(int u){
	//printf("q%d\n",u);//
    vis[u]=0;
    vvis[u]=1;
    for(int i=0;i<G[u].size();i++){
        if(!vvis[u])dfs1(G[u][i].first);
    }
}
bool ttrr=0;
int dfs(int u,int s){
	if(ttrr)return 0;
	int ss=s;
	//cout << "A";//
	//printf("%d:%d\n",u,s);//
    vis[u]=1;
    if(s<-m){
        pr ns={0,0};
        for(int i=head;i<=top;i++){
            if(G[q[i].first][q[i].second].second<ns.first){
                ns.first=G[q[i].first][q[i].second].second;
                ns.second=i;
            }
        }
        ans++;
        //printf("%d:%d %d\n",ans,q[ns.second].first,//
		//G[q[ns.second].first][q[ns.second].second].second);//
        for(int i=head;i<=ns.second;i++){
            s-=G[q[i].first][q[i].second].second;
            vis[q[i].first]=0;
        }
        head=ns.second+1;
        G[q[ns.second].first][q[ns.second].second].second=inf;
        ttrr=1;
        return 0;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].first,w=G[u][i].second;
        if(w==inf)continue;
        if(!vis[v]){
            q[++top]={u,i};
            s=dfs(v,s+w)-w;
            if(G[u][i].second==inf)s=ss;
            top--;
        }else{
            int qv=-1;
            for(int i=head;i<=top;i++){
                if(q[i].first!=v)continue;
                qv=i;
                break;
            }
            if(qv==-1){
                memset(vvis,0,sizeof vvis);
                dfs1(v);
                q[++top]={u,i};
                s=dfs(v,s+w)-w;
                if(G[u][i].second==inf)s=ss;
                top--;
            }else{
            	q[++top]={u,i};
                pr ns={0,0};
                for(int i=qv;i<=top;i++){
                    if(G[q[i].first][q[i].second].second<ns.first){
                        ns.first=G[q[i].first][q[i].second].second;
                        ns.second=i;
                    }
                }
                ans++;
                //printf("%d:%d %d\n",ans,q[ns.second].first,//
				//G[q[ns.second].first][q[ns.second].second].second);//
                for(int i=qv;i<=ns.second;i++){
                    s-=G[q[i].first][q[i].second].second;
                    vis[q[i].first]=0;
                }
                head=ns.second+1;
                G[q[ns.second].first][q[ns.second].second].second=inf;
                ttrr=1;
        		return 0;
            }
        }
    }
    return s;
}

void init();
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        init();
        cin >> n >> m;
        for(int u=1,v,w;u<=n;u++){
            cin >> v >> w;
            G[v].push_back({u,-w});
        }
        for(int i=1;i<=3;i++){
        	memset(vis,0,sizeof vis);
        	bool tr=1;
        	while(tr){
            	tr=0;
            	for(int i=1;i<=n;i++)
                	if(!vis[i]){
                		//printf("%d:\n",i);//
                		head=1,top=0;
                		ttrr=0;
                		dfs(i,0);
						tr=1;
					}
        	}
		}
        //cout << "B";//
        cout << ans << "\n";
    }
}
void init(){
    for(int i=1;i<=n;i++)G[i].clear();
    head=1,top=0;
    ans=0;
}