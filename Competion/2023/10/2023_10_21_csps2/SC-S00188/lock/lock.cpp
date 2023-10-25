#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
int a[N][N];
int ans=0,a1,a2;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)cin >> a[j][i];

    for(int i=0;i<=99999;i++){
        bool f=1;
        int c=0,ii=i,ff=0,w,lw,tf;
        for(int j=1;j<=n;j++){
            c=0,ii=i,ff=0,lw=0,w=0,tf=0;e
            for(int k=1;k<=5;k++){
                w=ii%10;
                ii/=10;
                int cc=(w-a[k][j]+10)%10;
                //if(i==51111)printf("%d:%d:%d %d:%d\n",j,k,w,c,ff);//e
                if(w!=a[k][j]&&c){
                    if(cc!=c||ff||lw+1!=k)j=n+1,k=6,f=0;
                    ff=1;
                }
                if(w!=a[k][j]&&!c)c=cc,lw=k,tf=1;
            }
            if(!tf)j=n+1,f=0;
        }
        if(f){
        	ans++;
        	if(ff){
        		a2++;
        		//printf("2:%d:%d\n",i,c);//
			}
        	else{
        		a1++;
        		//printf("1:%d:%d\n",i,c);//
			}
		}
    }
    cout << ans<<"\n";
    //cout << a1<<"\n";
    //cout << a2<<"\n";
}
