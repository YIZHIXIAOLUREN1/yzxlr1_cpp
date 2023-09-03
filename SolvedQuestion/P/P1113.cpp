#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
const int inf=MAXN;
int n,s;
int va[MAXN];
int h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
int dis[MAXN];
bool vis[MAXN];
int cnt;

void add(int u,int v,int va){
	to[++cnt]=v;
	val[cnt]=va;
	nxt[cnt]=h[u];
	h[u]=cnt;
}

queue<int> q;

void spfa(){
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[s]=0;
	q.push(s);
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[to[i]]>dis[u]+val[i]){
				dis[to[i]]=dis[u]+val[i];
                if(!vis[to[i]]){
                    q.push(to[i]);
                    vis[to[i]]=1;
                }
			}
		}
	}
	return;
}


int main(){
	scanf("%d",&n);
    s=1;
	int id,u;
	for(int i=1;i<=n;i++){
        scanf("%d%d",&id,&va[i]);
        scanf("%d",&u);
        while(u){
            add(u,i,-va[u]);
            scanf("%d",&u);
        }
	}
	spfa();
    int ans=0;
	for(int i=1;i<=n;i++)
		ans=min(ans,dis[i]-va[i]);
    printf("%d",-ans);
	return 0;
}
