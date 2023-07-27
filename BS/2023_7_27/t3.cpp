#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
const int p=998244353;

int read(){
    int res=0;
    char c;c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
    return res;
}
void write(int x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

int ksm(int a, int b){
	int res = 1;
	while(b){
		if(b&1)res=(LL)res*a%p;
		a=(LL)a*a%p;
		b>>=1;
	}
	return res;
}
int inv(int a){
    return ksm(a,p-2);
}
int C(int a,int b){
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--){
		res=(LL)res*j%p;
		res=(LL)res*inv(i)%p;
	}
	return res;
}

int work(int n,int m){
    int ns=C(n+1-m,n+1-2*m),res=0;
    //printf("%d:%d %d\n",m,ns,(res+ns)%p);//
    for(int i=m;i<(n+1)/2;i++){
    	//cout << "A";//
        res=(res+ns)%p;
        ns=(LL)ns*(n+1-2*i)%p*(n-2*i)%p*inv(n+1-i)%p*inv(i+1)%p;
        //printf("%d:%d %d %d/%d %d\n",i,ns,n+1-2*i,n-2*i,inv(n+1-i),inv(i+1));//
    }
    res=(res+ns)%p;
    return res;
}

signed main(){
    int T=read();
    while(T--){
        int x=read(),y=read();
        printf("%lld\n",work(x,y));
    }
}