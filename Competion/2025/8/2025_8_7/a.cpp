#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int ans=1;
        a[0]=-1;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==-1)continue;
            if(a[i]==0){ans=0;continue;}
            if(a[0]==-1)a[0]=a[i];
            else if(a[0]==a[i])continue;
            else ans=0;
        }
        if(ans==1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
/*
mex=0,1,2,3


0: min=0,max==mex X
mex=1/2/3 => ai=0 => x
so mex=0 so max=min
a a+1 x
a a+2 

*/