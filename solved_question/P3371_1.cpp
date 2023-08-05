#include<bits/stdc++.h>
using namespace std;
#define MAXN 600000
const int inf=2147483647;
int n,m,s;
int h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
long long dis[MAXN];
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
	//freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	int u,v,va;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&va);
		add(u,v,va);
	}
	spfa();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	cout << endl; 
	return 0;
}