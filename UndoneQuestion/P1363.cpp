#include<bits/stdc++.h>
using namespace std;
#define MAXN 1510
#define CSH 11451419
int m,n;//x,y
int kk;
struct zb{
	int tx;
	int ty;
};

zb csh;



zb vis[MAXN][MAXN];
bool tr=0,world[MAXN][MAXN];
int stx,sty;

int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void cshh(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			vis[i][j].tx=CSH;
			vis[i][j].ty=CSH;
		}
	}
}

void dfs(int x,int y){
	if(tr||kk>=1000000)
		return;
	kk++;
	
	int fx=x,fy=y;
	int tx=0,ty=0;
	while(fx<0){fx+m;tx--;}
	while(fx>=m){fx-m;tx++;}
	while(fy<0){fy+n;ty--;}
	while(fy>=n){fy-n;ty++;}
	cout << x << y << " " << tx << ty << " " << fx << fy << endl;//
	
	
	
	if((vis[fx][fy].tx!=CSH||vis[fx][fy].ty!=CSH)&&(vis[fx][fy].tx!=tx||vis[fx][fy].ty!=ty)){
		tr=1;
		return;
	}
	
	zb zbb;
	zbb.tx=tx;
	zbb.ty=ty;
	vis[fx][fy]=zbb;
	
	for(int i=0;i<4;i++){
		cout << i;//
		int lx=x+dx[i],ly=y+dy[i];
		
		cout << lx << " " << ly << " ";//
		int nfx=fx+dx[i];
		int nfy=fy+dy[i];
		
		while(nfx<0){nfx+m;tx--;}
		while(nfx>=m){nfx-m;tx++;}
		while(nfy<0){nfy+n;ty--;}
		while(nfy>=n){nfy-n;ty++;}
		cout << tx << ty << " " << nfx << nfy << world[nfx][nfy];//
		if(world[nfx][nfy]!=1&&(vis[nfx][nfy].tx!=tx||vis[nfx][nfy].ty!=ty)){
			cout << "f\n";//
			dfs(lx,ly);
		}
		cout << "a" << i << endl;//
	}
	
	vis[fx][fy]=csh;
}

int main(){
	std::ios::sync_with_stdio(false);
	csh.tx=CSH;
	csh.ty=CSH;
	while(cin >> m >> n){
		tr=0;
		cshh();
		memset(world,0,sizeof(world));
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			char c;
			cin >> c;
			cout /*<< c << " "*/ << i << j << " ";//
			if(c=='#')
				world[i][j]=1;
			else if(c=='S'){
				zb zbt;
				zbt.tx=0;
				zbt.ty=0;
				vis[i][j]=zbt;
				stx=i;
				sty=j;
				//cout << stx << " " << sty << endl;//
			}
		}
		cout << endl;//
	}
	
	kk=0;
	dfs(stx,sty);
	if(tr){
		cout << "Yes\n";
	}else
	cout << "No\n";
	}
	return 0;
}
