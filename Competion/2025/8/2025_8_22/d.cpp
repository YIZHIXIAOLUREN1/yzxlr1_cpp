#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n;
int c;
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>c;
            for(int j=1;j<=c;j++){
                if(i==1||j==1||j==c||(i*j%10==6))ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
