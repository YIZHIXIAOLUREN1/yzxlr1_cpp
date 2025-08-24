#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,m;
int p[N];
vector<int> G[N],Gs[N],fGs[N];
int dfn[N],low[N],tot,vis[N];
int st[N],top,icp[N],tcp;
vector<int> cp[N],cps[N];
int icps[N],tcps;
void dfs(int u){
    low[u]=dfn[u]=++tot;
    st[++top]=u;
    vis[u]=1;
    for(auto v:G[u]){
        if(vis[v])low[u]=min(low[u],dfn[v]);
        else if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dfn[u]){
        tcp++;
        int vv;
        do{
            vv=st[top--];
            icp[vv]=tcp;
            vis[vv]=0;
            cp[tcp].push_back(vv);
        }while(vv!=u);
    }
}
struct qq
{
    int val,qqqqqqq;
    bool operator<(const qq&b)const{
        return val>b.val;
    }
};


int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
void dfs2(int u);
void dfs3(int u);
int ans[N],mps[N],aps[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(u==v)continue;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);

    for(int i=1;i<=tcp;i++)fa[i]=i;
    for(int u=1;u<=n;u++){
        for(auto v:G[u]){
            if(icp[u]==icp[v])continue;
            Gs[icp[u]].push_back(icp[v]);
            fGs[icp[v]].push_back(icp[u]);
            merge(icp[u],icp[v]);
        }
    }
    for(int u=1;u<=tcp;u++){
    	//for(auto v:Gs[u])printf("%d-%d\n",u,v);//
    }
    //for(int i=1;i<=tcp;i++)printf("f%d:%d\n",i,find(i));//
    for(int i=1;i<=tcp;i++){
        int fi=find(i);
        if(!icps[fi]){
        	cps[++tcps].push_back(i);
        	icps[fi]=tcps;
        }
        else{
            cps[icps[fi]].push_back(i);
        }
        ans[i]=1e9+7;
    }
    //for(int i=1;i<=tcp;i++)printf("%d:%d\n",i,icps[find(i)]);//
    for(int i=1;i<=n;i++){
    	//printf("%d:%d %d\n",i,icp[i],icps[find(icp[i])]);//
    }
    for(int i=1;i<=n;i++){
        if(mps[icps[find(icp[i])]]<p[i])mps[icps[find(icp[i])]]=p[i];
    }
    //cout<<mps[1]<<"\n";//
    for(int i=1;i<=n;i++){
        if(p[i]==mps[icps[find(icp[i])]]){
            //if(ans[icp[i]]==1)continue;
            ans[icp[i]]=1;
            //dfs2(icp[i]);
            //dfs3(icp[i]);
        }
    }

    priority_queue<qq> qz,qf;
    for(int i=1;i<=tcps;i++){
        for(auto u:cps[i]){
            if(ans[u]==1){
                qz.push(qq{1,u});
                qf.push(qq{1,u});
            }
        }
        while(!qz.empty()||!qf.empty()){
        	//cout<<"A";//
            if(!qz.empty()){
                qq p=qz.top();
                qz.pop();
                for(auto v:Gs[p.qqqqqqq]){
                	//printf("a%d %d:%d\n",p.qqqqqqq,v,ans[v]);//
                    if(ans[v]>ans[p.qqqqqqq]){
                        ans[v]=ans[p.qqqqqqq];
                        
                        qz.push(qq{ans[v],v});
                    }
                }
                for(auto v:fGs[p.qqqqqqq]){
                    if(ans[v]>ans[p.qqqqqqq]+1){
                        ans[v]=ans[p.qqqqqqq]+1;
                        //printf("b%d %d:%d\n",p.qqqqqqq,v,ans[v]);//
                        qf.push(qq{ans[v],v});
                    }
                }
            }
            if(!qf.empty()){
                qq p=qf.top();
                qf.pop();
                for(auto v:fGs[p.qqqqqqq]){
                    if(ans[v]>ans[p.qqqqqqq]){
                        ans[v]=ans[p.qqqqqqq];
                        qf.push(qq{ans[v],v});
                    }
                }
                for(auto v:Gs[p.qqqqqqq]){
                    if(ans[v]>ans[p.qqqqqqq]+1){
                        ans[v]=ans[p.qqqqqqq]+1;
                        qz.push(qq{ans[v],v});
                    }
                }
            }
        }
    }
    // for(int i=1;i<=tcp;i++){
    	// for(auto v:Gs[i])cout<<v<<" ";//
    	// cout<<"\n";//
    // }
    
    for(int i=1;i<=n;i++){
        if(p[i]==mps[icps[find(icp[i])]])cout<<"0"<<" \n"[i==n];
        else cout<<ans[icp[i]]<<" \n"[i==n];
    }
    return 0;
}
void dfs2(int u){
    for(auto v:Gs[u]){
        if(ans[v]>ans[u]){
            ans[v]=ans[u];
            //printf("%d %d:2 1\n",u,v);//
            dfs2(v);
        }
    }
    for(auto v:fGs[u]){
        if(ans[v]>ans[u]+1){
            ans[v]=ans[u]+1;
            //printf("%d %d:2 2\n",u,v);//
            dfs3(v);
        }
    }
}
void dfs3(int u){
    for(auto v:fGs[u]){
        if(ans[v]>ans[u]){
            ans[v]=ans[u];
            //printf("%d %d:3 1\n",u,v);//
            dfs3(v);
        }
    }
    for(auto v:Gs[u]){
        if(ans[v]>ans[u]+1){
            ans[v]=ans[u]+1;
            //printf("%d %d:3 2\n",u,v);//
            dfs2(v);
        }
    }
}