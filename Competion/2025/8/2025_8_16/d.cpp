#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int cg[N],cf[N];
int n,m;
string S,T;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>S>>T;
    for(int i=1,L,R;i<=m;i++){
        cin>>L>>R;
        cf[L]++,cf[R+1]--;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        now+=cf[i];
        if(now%2)S[i-1]=T[i-1];
    }
    cout<<S<<"\n";
}
