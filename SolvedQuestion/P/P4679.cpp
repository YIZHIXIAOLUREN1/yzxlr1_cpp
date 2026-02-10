#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=1e5+7,inf=0x3f3f3f3f;
int n,m;
int a[N],b[N];//0,01,10,11
vector<int> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

struct seg{
    bool is0;
    int al[2][2],ar[2][2];
    bool tg[2][2];
    seg operator+(seg y)const{
        if(y.is0)return *this;
        if(is0)return y;
        seg res;
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            res.al[i][j]=al[i][j],res.ar[i][j]=y.ar[i][j];
        }

        for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++){
            if(tg[i][j]&&al[i][j]>-inf&&y.al[j][k]>-inf){
                res.al[i][k]=max(res.al[i][k],al[i][j]+y.al[j][k]);
            }
            if(y.tg[j][i]&&y.ar[i][j]>-inf&&ar[j][k]>-inf){
                res.ar[i][k]=max(res.ar[i][k],y.ar[i][j]+ar[j][k]);
            }
            if(tg[i][j]&&y.tg[j][k])res.tg[i][k]=1;
        }
        // printf("t%d %d:\n",idl,idr);//
        // for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d %d\n",i,j,tg[i][j],al[i][j],ar[i][j]);//
        // printf("T%d %d:\n",y.idl,y.idr);//
        // for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d %d\n",i,j,y.tg[i][j],y.al[i][j],y.ar[i][j]);//
        // printf("r%d %d:\n",res.idl,res.idr);//
        // for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d %d\n",i,j,res.tg[i][j],res.al[i][j],res.ar[i][j]);//
        return res;
    }
	seg(){
		is0=0;
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)al[i][j]=ar[i][j]=-inf,tg[i][j]=0;
	}
    void set(int val){
    	is0=0;
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)al[i][j]=ar[i][j]=-inf,tg[i][j]=0;
    	if(!(val&1))al[0][0]=ar[0][0]=tg[0][0]=1;
        if(!(val/2))al[1][1]=ar[1][1]=tg[1][1]=1;
        if(!val)al[0][1]=ar[0][1]=al[1][0]=ar[1][0]=2,tg[0][1]=tg[1][0]=1;
    }
    void rp(){
        swap(al,ar);
        swap(tg[0][1],tg[1][0]);
    }
} w[N*4],w0;

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto v:G[u]){
        if(v==fas)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>ms)ms=siz[v],son[u]=v;
    }
}

void dfs2(int u,int tof){
    id[u]=++idx;
    b[idx]=a[u];
    top[u]=tof;
    if(siz[u]==1)return;
    dfs2(son[u],tof);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]){
			swap(x,y);
		}
		x=fa[top[x]];
	}
	return (d[x]<d[y])?x:y;
}

inline void pushup(int u){w[u]=w[ls]+w[rs];}

void build(int u,int l,int r){
    if(l==r){w[u].set(b[l]);return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

seg query(int u,int l,int r,int L,int R){
	seg res;
    if(l>R||r<L)res=w0;
    else if(l>=L&&r<=R)res=w[u];
    //return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R));
	else res=(query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R));    
	// if(res.is0)printf("O%d %d:%d %d:\n",L,R,l,r);//
	// else{
		// printf("t%d %d:%d %d:\n",L,R,l,r);//
		// for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d\n",i,j,res.al[i][j],res.ar[i][j]);//
	// }
	return res;
}

void change(int u,int l,int r,int tg,int x){
    if(l>tg||r<tg)return;
    if(l==r){b[l]=x;w[u].set(x);return;}
    if(tg<=mid)change(ls,l,mid,tg,x);
    else change(rs,mid+1,r,tg,x);
    pushup(u);
    // if(w[u].is0)printf("CO%d %d:\n",l,r);//
	// else{
		// printf("C%d %d:\n",l,r);//
		// for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d\n",i,j,w[u].al[i][j],w[u].ar[i][j]);//
	// }
}

seg q1(int x,int y){
    seg res1=w0,res2=w0,ns=w0;
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]){
            ns=query(1,1,n,id[top[y]],id[y]);
            ns.rp();
            res2=res2+ns;
            y=fa[top[y]];
        }else{
            ns=query(1,1,n,id[top[x]],id[x]);
            ns.rp();
            res1=res1+ns;
            x=fa[top[x]];
        }
        
    }
    if(d[x]<d[y]){
        ns=query(1,1,n,id[x],id[y]);
        res1=res1+ns;
    }else{
        ns=query(1,1,n,id[y],id[x]);
        ns.rp();
        res1=res1+ns;
    }
    
    res2.rp();
    return res1+res2;
}

// seg q1(int x,int y){
//     int ti=0;
//     seg res1=w0,res2=w0,ns=w0;
//     if(d[x]<d[y]){ti++;swap(x,y);swap(res1,res2);}
//     while(top[x]!=top[y]){
//         if(d[top[x]]<d[top[y]]){ti++;swap(x,y);swap(res1,res2);}
//         ns=query(1,1,n,id[top[x]],id[x]);
//         printf("%d %d:%d %d:",res1.idl,res1.idr,ns.idl,ns.idr);//
//         res1=res1+ns;
//         printf("%d %d\n",res1.idl,res1.idr);//
//         x=fa[top[x]];
//     }
//     if(d[x]<d[y]){ti++;swap(x,y);swap(res1,res2);}
//     ns=query(1,1,n,id[y],id[x])+res1;
//     printf("%d %d:%d %d:",res1.idl,res1.idr,ns.idl,ns.idr);//
//     res1=res1+ns;
//     printf("%d %d\n",res1.idl,res1.idr);//
//     if(ti&1){ti++;swap(x,y);swap(res1,res2);}
//     res1.rp();
//     printf("r%d %d\n",res1.idl,res1.idr);//
//     printf("r%d %d\n",res2.idl,res2.idr);//
//     return res1+res2;
// }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    w0.is0=1;
    cin >> n  >> m;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[i]=(s[0]=='#')*2+(s[1]=='#');
        //printf("%d:%d\n",i,a[i]);//
    }
    
    dfs1(1,0);
    dfs2(1,1);
	//for(int i=1;i<=n;i++)cout<<id[i]<<" \n"[i==n];//
    build(1,1,n);
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='Q'){
            int x,y;
            cin>>x>>y;
            seg res=q1(x,y);
            //res.rp();
            //printf("A%d %d:%d %d\n",x,y,res.idl,res.idr);//
            //for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("%d %d:%d %d\n",i,j,res.al[i][j],res.ar[i][j]);//
            int ans=0;
            for(int i=0;i<2;i++)for(int j=0;j<2;j++)ans=max(ans,res.al[i][j]);
            cout<<ans<<"\n";
        }else{
            int u;
            cin>>u>>s;
            b[id[u]]=a[u]=(s[0]=='#')*2+(s[1]=='#');
            change(1,1,n,id[u],a[u]);
        }
    }
}