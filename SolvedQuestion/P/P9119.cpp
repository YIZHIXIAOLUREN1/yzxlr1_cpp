#include<bits/stdc++.h>
using namespace std;
#define N 2500
#define ld double
int n,s=1;
struct ddd{
	ld x,y;
} a[N],b[N];
int c[N];
ld f[N][N][2];
int g[N][N][2];

ld jl(int x,int y){
	ld sx=b[x].x-b[y].x,sy=b[x].y-b[y].y;
	//printf("%d %d:%lf %lf:%lf\n",x,y,sx,sy,sqrt(sx*sx+sy*sy));//
	return sqrt(sx*sx+sy*sy);
}

int st[N],top=0;

void dfs(int l,int r,int p);

int main(){
	//freopen("tree6.in","r",stdin);//
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if(a[i].y>a[s].y)s=i;
	}
	for(int i=s-1;i>=1;i--){b[s-i]=b[s-i+n]=a[i];c[s-i]=c[s-i+n]=i;}
	for(int i=n;i>=s+1;i--){b[n-i+s]=b[2*n-i+s]=a[i];c[n-i+s]=c[2*n-i+s]=i;}
	b[n]=a[s];c[n]=s;s=n;
	
	//for(int i=1;i<=2*n-1;i++)printf("%d:%lf %lf\n",i,b[i].x,b[i].y);//
	
	memset(f,0x43,sizeof f);
	memset(g,0x43,sizeof g);
	f[s][s][0]=f[s][s][1]=0;
	
	for(int len=2;len<=n;len++){
		for(int l=s-len+1;l<=s;l++){
			int r=l+len-1;
			//printf("%d:%d %d\n",len,l,r);//
			if(f[l][r-1][1]+jl(r-1,r)>f[l][r-1][0]+jl(l,r)){
				g[l][r][1]=0;f[l][r][1]=f[l][r-1][0]+jl(l,r);
			}else{
				g[l][r][1]=1;f[l][r][1]=f[l][r-1][1]+jl(r-1,r);
			}
			
			if(f[l+1][r][1]+jl(l,r)>f[l+1][r][0]+jl(l,l+1)){
				g[l][r][0]=0;f[l][r][0]=f[l+1][r][0]+jl(l,l+1);
			}else{
				g[l][r][0]=1;f[l][r][0]=f[l+1][r][1]+jl(l,r);
			}
			//printf("%d %d 1:%lf\n",l,r,f[l][r][1]);//
			//printf("%d %d 0:%lf\n",l,r,f[l][r][0]);//
		}
	}
	
	int as=0,ap=0;
	ld res=0x43434343;
	for(int l=1;l<=s;l++)
	if(res>f[l][l+n-1][0]){res=f[l][l+n-1][0];as=l,ap=0;}
	else if(res>f[l][l+n-1][1]){res=f[l][l+n-1][1];as=l,ap=1;}
	
	dfs(as,as+n-1,ap);
	top++;
	while(--top>1){
		printf("%d ",st[top]);
	}
	printf("%d\n",st[1]);
}

void dfs(int l,int r,int p){
	//st[++top]=(p?(r>n?r-n:r):(l>n?l-n:l));
	//printf("%d\n",st[top]);//
	st[++top]=(p?c[r]:c[l]);
	if(p){
		if(l<=s&&r-1>=s){
			dfs(l,r-1,g[l][r][p]);
		}
	}else{
		if(l+1<=s&&r>=s){
			dfs(l+1,r,g[l][r][p]);
		}
	}
}
