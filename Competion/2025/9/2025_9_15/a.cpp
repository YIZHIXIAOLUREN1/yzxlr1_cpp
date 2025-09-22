#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=47;
int n,a[N],pre[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=a[i]+pre[i-1];
        }
        bool fl=0;
        for(int l=1;l<=n-2;l++){
            for(int r=l+1;r<=n-1;r++){
                int s1=pre[l]%3,s2=(pre[r]-pre[l])%3,s3=(pre[n]-pre[r])%3;
                //printf("%d %d:%d %d %d\n",l,r,s1,s2,s3);//
                if((s1!=s2&&s2!=s3&&s3!=s1)||(s1==s2&&s2==s3)){
                    cout<<l<<" "<<r<<"\n";
                    l=r=n;
                    fl=1;
                }
            }
        }
        if(!fl)cout<<"0 0\n";
    }
}
