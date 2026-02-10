#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,v[N];
int A;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>A;
        for(int i=1;i<=n;i++)cin>>v[i];
        int res1=0,res2=0,B=A-1;
        for(int i=1;i<=n;i++){
            res1+=(abs(v[i]-A)>abs(v[i]-(A-1)));
            res2+=(abs(v[i]-A)>abs(v[i]-(A+1)));
        }
        if(A==0)cout<<"1\n";
        else if(A==2e9)cout<<A-1<<"\n";
        else cout<<((res1>res2)?A-1:A+1)<<"\n";
    }
}
