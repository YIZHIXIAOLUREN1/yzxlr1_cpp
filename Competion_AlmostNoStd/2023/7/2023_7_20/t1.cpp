#include<bits/stdc++.h>
using namespace std;
#define N 1000050
const int mod=1e9+7;
int n,k;
int a[N];
int ans;
int q2[N];
int l,r,now;


int main(){
	q2[0]=1;
	for(int i=1;i<=N-10;i++){
		q2[i]=(q2[i-1]*2)%mod;
	}
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
        switch (s[i-1]){
        case 'A':a[i]=-1;break;
        case 'B':a[i]=1;break;
        }
    }
    l=1,r=0,now=0;
    for(int i=1;i<=n;i++){
        if(now+a[i]<a[i]){l=r=i,now=a[i];}
        else{now+=a[i];r++;}
        while(now>k&&l<=r){
            if(a[l]==1){
                ans=(q2[l]+ans)%mod;
                now--;
            }else{
                now++;
            }
            l++;
        }
        //printf("%d %d:%d\n",l,r,now);//
    }
    cout << ans;
}
