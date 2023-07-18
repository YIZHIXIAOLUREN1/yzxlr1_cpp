#include<bits/stdc++.h>
using namespace std;
struct da{
	int a;
	int x;
}day[40000];

bool cmp(da p,da q){
	return p.a<q.a;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&day[i].a);
		day[i].x=i;
	}
	sort(day+1,day+n+1,cmp);
	//cout << day[1].x << " " << day[1].a << " " << day[2].x << " " << day[2].a;
	
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(day[i].x==1){
			ans+=day[i].a;
			continue;
		}
		int j=0;
		int minx=pow(10,7);
		while(i-1>j&&day[i-j].x>=day[i].x)j++;
		if(i!=1&&day[i-j].x<day[i].x)minx=abs(day[i-j].a-day[i].a);
		j=0;
		while(i+j<n&&day[i+j].x>=day[i].x)j++;
		if(i!=n&&day[i+j].x<day[i].x)minx=min(minx,abs(day[i+j].a-day[i].a));
		//cout << minx << endl;//
		ans+=minx;
		
	}
	cout << ans;
	return 0;
}
