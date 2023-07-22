#include<bits/stdc++.h>
using namespace std;
#define N 500007
#define ll int
#define inf 0x3f3f3f3f
struct node{
    int ty,l,r;ll s;
   	friend bool operator < (const node x,const node y){
        return x.s>y.s;
    }
}a[N];

int n,k;
int vis[N];
ll ans;
priority_queue<node> q;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> a[0].s;
    n--;
    for(int i=1;i<=n;i++){
        cin >> a[i].s;
        a[i].ty=i;
        a[i].l=i-1;
        a[i].r=i+1;
    }
    for(int i=n;i>=1;i--){
    	a[i].s-=a[i-1].s;
        q.push(a[i]);
    	//printf("%d:%d\n",i,a[i]);//
    }
    a[0].s=a[n+1].s=inf;
    while(k--){
    	while(vis[q.top().ty])q.pop();
        node u=q.top();
        int v=u.ty;
        u=a[v];
        q.pop();
        ans+=u.s;
        vis[u.l]=vis[u.r]=1;
        u.s=a[u.l].s+a[u.r].s-u.s;
        u.l=a[u.l].l;
        u.r=a[u.r].r;
        a[u.r].l=v;
        a[u.l].r=v;
        a[v]=u;
        q.push(a[v]);
    }
    cout << ans;
}