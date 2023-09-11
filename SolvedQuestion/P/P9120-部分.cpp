#include<bits/stdc++.h>
using namespace std;
#define N 200000
#define inf 0x3f3f3f3f
int k,n;
int a[N][5];
int main(){
	//freopen("lock3.in","r",stdin);//
	int _;
	scanf("%d %d",&_,&k);
	while(_--){
		scanf("%d",&n);
		if(k==1){
			int ma=0,mi=inf;
			
			for(int i=1;i<=n;i++){
				//cout << "A";//
				int x;
				scanf("%d",&x);
				ma=max(ma,x);
				mi=min(mi,x);
				
			}
			printf("%d\n",ma-mi);
		}
	}
}
