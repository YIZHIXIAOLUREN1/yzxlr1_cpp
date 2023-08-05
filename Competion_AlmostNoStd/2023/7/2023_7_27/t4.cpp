#include<bits/stdc++.h>
using namespace std;
#define N 550
#define LL long long
#define int long long
int n,K;
int ans;

int C(int a,int b){
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--){
		res=res*j;
		res=res/i;
	}
	return res;
}

signed main(){
    cin >> n >> K;
    for(int i=1;i<=K;i++){
        string c;
        int a,b;
        cin >> a >> c >> b;
    }
    if(K!=0){cout << "114514";return 0;}
    for(int i=1;i<=n;i++){
        int res=C(2*n-2,i-1),pes=0;
        for(int j=1;j<=(i-1)/2;j++){
            if(j&1)pes=-1;
            else pes=1;
            pes=pes*C(n-1,j)*C(2*n-2-2*j,i-1-2*j);
            res+=pes;
            //printf("%d:%d %d\n",i,res,pes);//
        }
        //printf("n%d:%d %d\n",i,res,ans);//
        ans+=res;
    }
    cout << ans;
}