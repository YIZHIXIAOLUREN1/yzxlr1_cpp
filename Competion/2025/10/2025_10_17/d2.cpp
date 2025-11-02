#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+7;
int n;


signed main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int res1,res2;
        res1=n*(n+1)/2;
        cout<<"2 1 "<<n<<endl;
        cin>>res2;
        int len=res2-res1;
        int l=1,r=n-len+2;
        while(l<r){
            int L=(l+r)/2;
            int R=L+len-1;
            int res1,res2;
            cout<<"1 1 "<<L<<endl;
            cin>>res1;
            cout<<"2 1 "<<L<<endl;
            cin>>res2;
            if(res1==res2){
                l=L+1;
            }else{
                if(res2-res1<len){
                    l=L-(res2-res1)+1;
                    break;
                }else r=L;
            }
        }
        cout<<"! "<<l<<" "<<l+len-1<<endl;
    }
}