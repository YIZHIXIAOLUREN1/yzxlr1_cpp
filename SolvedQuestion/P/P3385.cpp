#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
ll dis[N],vis[N],inq[N];
ll to[N],nxt[N],val[N],head[N],tot=0;
queue<ll> q;
int n,m;

void jb(ll u,ll v,ll w){
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}

bool spfa(){
	dis[1]=0;
	q.push(1);
	vis[1]=1;
	inq[1]++;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[u]+val[i]>=dis[v]) continue;
			dis[v]=dis[u]+val[i];
			if(vis[v]) continue;
			q.push(v);
			inq[v]++;
			vis[v]=1;
			if(inq[v]>n)return 0;
		}
	}
	return 1;
}

int main(){
	//freopen("P3385_2.in","r",stdin);
	int _;
	scanf("%d",&_);
	while(_--){
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		memset(to,0,sizeof to);
		memset(nxt,0,sizeof nxt);
		memset(val,0,sizeof val);
		memset(inq,0,sizeof inq);
		memset(head,0,sizeof head);
		while(!q.empty())q.pop();
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			jb(u,v,w);
			if(w>=0)jb(v,u,w);
		}
		
		if(spfa())puts("NO");
		else puts("YES");
	}
	return 0;
}
