#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int N=3e3+7,NN=1e6+7;
int n,m,q;
ll k1,k2;
ll f[N][N],g[N][N];
ull ans;
bool vis1[N][N],vis2[N][N],vis3[N][N];
ll ru[N][N];
ull qp(ull x,int q){
    ull res=1;
    while(q){
        if(q&1)res*=x;
        x*=x;
        q>>=1;
    }
    return res;
}
void out();
void db(){
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			cout<<ru[x][y]<<" \n"[y==m];//
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			cout<<g[x][y]<<" \n"[y==m];//
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			cout<<f[x][y]<<" \n"[y==m];//
		}
	}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q>>k1>>k2;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            f[x][y]=-1e18;
        }
    }
    for(ll i=1,rx,ry,rru;i<=q;i++){
        cin>>rx>>ry;
        cin>>rru;
        if(vis1[rx][ry])ru[rx][ry]=max(ru[rx][ry],rru);
        else{ru[rx][ry]=rru;vis1[rx][ry]=1;}
    }
    ll res;
    bool flag=0;
    for(int x=1;x<=n;x++){
    	flag=0;
        for(int y=1;y<=m;y++){
            if(!flag){
                if(vis1[x][y]){{res=ru[x][y];flag=1;}}
            }else{
                res=res+k2;
                if(vis1[x][y])res=max(res,ru[x][y]);
            }
            if(flag){
                vis2[x][y]=1;
                g[x][y]=res;
            }
        }
        flag=0;
        for(int y=m;y>=1;y--){
            if(!flag){
                if(vis1[x][y]){{res=ru[x][y];flag=1;}}
            }else{
                res=res+k2;
                if(vis1[x][y])res=max(res,ru[x][y]);
            }
            if(flag){
                if(!vis2[x][y]){g[x][y]=res;vis2[x][y]=1;}
                else g[x][y]=max(g[x][y],res);
            }
        }
    }

    for(int y=1;y<=m;y++){
        flag=0;
        for(int x=1;x<=n;x++){
            if(!flag){
                if(vis2[x][y]){{res=g[x][y];flag=1;}}
            }else{
                res=res+k1;
                if(vis2[x][y])res=max(res,g[x][y]);
            }
            if(flag){
                vis3[x][y]=1;
                f[x][y]=res;
            }
        }
        flag=0;
        for(int x=n;x>=1;x--){
            if(!flag){
                if(vis2[x][y]){{res=g[x][y];flag=1;}}
            }else{
                res=res+k1;
                if(vis2[x][y])res=max(res,g[x][y]);
            }
            if(flag){
                if(!vis3[x][y]){f[x][y]=res;vis3[x][y]=1;}
                else f[x][y]=max(f[x][y],res);
            }
        }
    }
	//db();
    out();
}

void out(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
    	if(f[i][j]<0)f[i][j]=(ull)(((ll)((((ull)1)<<63)-1))+f[i][j])+(((ull)1)<<63)+1;
    	ans+=qp(131,(i-1)*m+j)*f[i][j];
    }
    cout<<ans;
}