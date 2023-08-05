#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a[N],ls[N],rs[N];
int q[N],l,r;
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    l=1,r=0,q[0]=0;
    for(int i=1;i<=n;i++){
        while(l<=r&&a[q[r]]<=a[i])r--;
        ls[i]=q[r];
        q[++r]=i;
    }
    l=1,r=0,q[0]=n+1;
    for(int i=n;i>=1;i--){
       while(l<=r&&a[q[r]]>=a[i])r--;
       rs[i]=q[r];
       q[++r]=i;
    }
    
    //for(int i=1;i<=n;i++)printf("%d:%d %d\n",i,ls[i],rs[i]);//

    for(int i=n;i>=1;i--){
        for(int j=ls[i]+1;j<i;j++){
        	//printf("%d %d\n",j,i);//
            if(rs[j]>i){ans=max(ans,i-j+1);break;}
        }
    }
    cout << ans;
}