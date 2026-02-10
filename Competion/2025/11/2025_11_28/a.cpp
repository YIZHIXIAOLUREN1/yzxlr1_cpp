#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
#define a(i,j) (n*(i-1)+j)

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int res=a(i,j);
                if(i>1)res+=a(i-1,j);
                if(i<n)res+=a(i+1,j);
                if(j>1)res+=a(i,j-1);
                if(j<n)res+=a(i,j+1);
                ans=max(ans,res);
            }
        }
        cout<<ans<<"\n";
    }
}
