#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
	int _,n,B;
	scanf("%lld",&_);
	while(_--){
		scanf("%lld%lld",&n,&B);
		int len=0,m=0,num[100];
		while(n){
			num[++len]=n%B;
			n/=B;
		}
		m=num[len];
		//printf("%lld %lld\n",len,m);//
		
		int ans=len*(len-1)/2*(B-1)+(m-1)*len;
		
		for(int i=len-1;i>=1;i--){
			if(num[i]==B-1) ans+=(i==1)+1;
			else if(num[i]==B-2){
				bool tr=0;
				for(int j=i-1;j>=1;j--)
					if(num[j]!=B-1){
						tr=1;
						break;
					}
				if(!tr) ans++;break;
			}
			else break;
		}
		
		printf("%lld\n",ans+(len==1));
	}
}





