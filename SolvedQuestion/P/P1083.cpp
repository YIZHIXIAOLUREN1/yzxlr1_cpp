#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007;
int n;
int a[N];
int b[N];
int check(int k){
    int res=0,r=0;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        res+=b[i];
        if((a[i]+res)%2==0){
            if(i>n-k+1)return -1;
            b[i]++;
            res++;
            b[min(i+k,n+1)]--;
            r++;
        }
        //printf("%d %d:%d\n",k,i,res);//
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='F')a[i]=1;
    }

    for(int k=n;k>=1;k--){
        int ans=check(k);
        if(ans==-1)continue;
        else{
            cout<<k<<" "<<ans;
            break;
        }
    }
}
