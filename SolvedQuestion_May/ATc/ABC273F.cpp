#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 3050
int n,ex,sx;
int f[N][N][2];
int ql[N],ys[N],ls[N];
int lq[N];

int jl(int x,int y){
	//printf("jl:%lld %lld:%lld %lld:%lld\n",x,y,ls[x],ls[y],abs(ls[x]-ls[y]));//
	return abs(ls[x]-ls[y]);
}

signed main(){
	scanf("%lld%lld",&n,&ex);
	if(ex==0){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&ql[i]);
		ls[i]=ql[i];
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&ys[i]);
		ls[i+n]=ys[i];
	}
	ls[2*n+1]=0;
	ls[2*n+2]=ex;
	sort(ls+1,ls+2*n+3);
	int m=unique(ls+1,ls+2*n+3)-ls-1;
	for(int i=1;i<=n;i++){ql[i]=lower_bound(ls+1,ls+m+1,ql[i])-ls;lq[ql[i]]=i;}
	for(int i=1;i<=n;i++) ys[i]=lower_bound(ls+1,ls+m+1,ys[i])-ls;
	ex=lower_bound(ls+1,ls+m+1,ex)-ls;
	sx=lower_bound(ls+1,ls+m+1,0)-ls;
	//printf("%lld %lld\n",ex,sx);//
	memset(f,0x3f,sizeof f);
	f[sx][sx][0]=f[sx][sx][1]=0;
	int ans=inf;
	
	
	for(int len=1;len<=m;len++){
		for(int l=1;l+len-1<=m;l++){
			int r=l+len-1;
			int res=inf;
			if(((l<=ys[lq[r]]&&ys[lq[r]]<=r-1)||(lq[r]==0))&&sx<=r-1){
				res=min(res,f[l][r-1][0]+jl(l,r));
				//printf("p1%lld %lld %lld:%lld\n",l,r,p,res);//
				res=min(res,f[l][r-1][1]+jl(r-1,r));
				//printf("pr:%lld %lld r:%lld\n",l,r,res);//
				f[l][r][1]=res;
			}
			res=inf;
			if(((l+1<=ys[lq[l]]&&ys[lq[l]]<=r)||(lq[l])==0)&&l+1<=sx){
				res=min(res,f[l+1][r][0]+jl(l,l+1));
				res=min(res,f[l+1][r][1]+jl(l,r));
				//printf("pl:%lld %lld l:%lld\n",l,r,res);//
				f[l][r][0]=res;
			}
			
			if((sx>ex&&l<=ex&&sx<=r)||(sx<ex&&l<=sx&&ex<=r)){
				ans=min(ans,f[l][r][0]);
				ans=min(ans,f[l][r][1]);
				//printf("%lld %lld:%lld %lld\n",l,r,ans,min(f[l][r][0],f[l][r][1]));//
			}
		}
	}
	
	if(ans==inf)puts("-1");
	else printf("%lld\n",ans);
	return 0;
	
}




/*
lsh!

f[l][r][0/1] 0l1r



*/