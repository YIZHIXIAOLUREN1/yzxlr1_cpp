#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=207;
int n,m;
int b[N];
int mib,mab,f;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        mib=n+1,mab=0,f=0;
        
        for(int i=1;i<=m;i++){
            cin>>b[i];
            mib=min(mib,b[i]);
            mab=max(mab,b[i]);
            if(b[i]<=b[i-1]){
                f=1;
            }
        }
        if(f)cout<<"1\n";
        else{
            cout<<n-mab+1<<"\n";
        }
    }
}
