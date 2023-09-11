#include<bits/stdc++.h>
using namespace std;
#define N 200000
int n;
struct dia{
	double x,y;
} p[N],sx[N],ss[N];

bool cmp(dia a,dia b){
	if(-1e-4<a.x-b.x&&a.x-b.x<1e-4) return a.y<b.y;
	return a.x<b.x;
}

double jl(dia a,dia b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double xji(dia a,dia b,dia o){//OA x OB
	return a.x*b.y-a.x*o.y-o.x*b.y-a.y*b.x+b.x*o.y+a.y*o.x;
}

int cntx=0,cnts=0;

void andrewx(){
	cntx=0;
	sx[++cntx]=p[1];
	for(int i=2;i<=n;++i){
		while(cntx>=2&&xji(sx[cntx-1],p[i],sx[cntx])<=0) cntx--;
		sx[++cntx]=p[i];
		//printf("i:%dcnt:%d:%.2f,%.2f\n",i,cntx,p[i].x,p[i].y);//
	}
}

void andrews(){
	cnts=0;
	ss[++cnts]=p[n];
	for(int i=n-1;i>=1;--i){
		while(cnts>=2&&xji(ss[cnts-1],p[i],ss[cnts])<=0) cnts--;
		ss[++cnts]=p[i];
		//printf("i:%dcnt:%d:%.2f,%.2f\n",i,cnts,p[i].x,p[i].y);//
	}
}



int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lf%lf",&p[i].x,&p[i].y);
	//for(int i=1;i<=n;++i) printf("%.2f %.2f\n",p[i].x,p[i].y);//
	sort(p+1,p+n+1,cmp);
	//for(int i=1;i<=n;++i) printf("%.2f %.2f\n",p[i].x,p[i].y);//
	
	andrewx();
	andrews();
	double ans=0;
	for(int i=2;i<=cntx;i++) ans+=jl(sx[i-1],sx[i]);
	for(int i=2;i<=cnts;i++) ans+=jl(ss[i-1],ss[i]);
	printf("%.2f\n",ans);
}




