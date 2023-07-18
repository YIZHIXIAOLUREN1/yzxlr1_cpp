#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[20005],em[20005];

int find(int x){
	if(x==fa[x])return x;
	return fa[x] = find(fa[x]);
}

void join(int c1,int c2){
	int f1=find(c1),f2=find(c2);
	fa[f1] = f2;
}

struct mmdd{
	int x;
	int y;
	int num;
}md[100005];

bool cmp(mmdd p,mmdd q){
	return p.num<q.num;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int tx,ty,tn;
		scanf("%d%d%d",&tx,&ty,&tn);
		md[i].x=tx;
		md[i].y=ty;
		md[i].num=tn;
		
	}
	sort(md+1,md+m+1,cmp);
	
	
	for(int i=m;i>0;i--){
		int tx=md[i].x,ty=md[i].y;
		if(find(tx)==find(ty)){
			cout << md[i].num;
			return 0;
		}
		if(!em[tx]) em[tx]=ty;
		else{
			join(em[tx],ty);
		}
		if(!em[ty]) em[ty]=tx;
		else{
			join(em[ty],tx);
		}
		
	}
	cout << 0;
}


