#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=27;
int n,q,s[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>q;
        string c;
        cin>>c;
        bool f1=0;
        for(int i=1;i<=n;i++){
            s[i]=(c[i-1]=='A')?1:0;
            if(!s[i])f1=1;
        }
        while(q--){
            int a;
            cin>>a;
            if(!f1){
                cout<<a<<"\n";
                continue;
            }
            int j=1,ans=0;
            while(a){
                if(s[j])a--;
                else a/=2;
                ans++;
                j=(j<n)?j+1:1;
            }
            cout<<ans<<"\n";
        }
    }
}
