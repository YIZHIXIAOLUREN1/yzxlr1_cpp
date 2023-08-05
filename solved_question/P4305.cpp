#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;

inline int read(){
    int w=1,q=0;
	char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return w*q;
}

struct numm{
	long long x;
	int id;
}num[100000];

bool cmp(numm a,numm b){
	if(a.x!=b.x)
		return a.x<b.x;
	return a.id<b.id;
}

bool cmid(numm a,numm b){
	return a.id<b.id;
}

signed main(void){
	t = read();
	for(int iii=0;iii<t;iii++){
		scanf("%lld",&n);
		for(int i=0;i<n;i++){
			num[i].x = read();
			num[i].id=i;
		}
		sort(num,num+n,cmp);
		int tr=0;
		for(int i=0;i<n;i+=tr){
			tr=1;
			for(int j=i+1;j<=n;j++){
				if(num[j].x==num[i].x)num[j].x=-2147483659UL,tr++;
				else break; 
			}
		}
		sort(num,num+n,cmid);
		for(int i=0;i<n;i++){
			if(num[i].x!=-2147483659UL)printf("%lld ",num[i].x);
		}
		printf("\n");
	}
	
	
	return 0;
}
