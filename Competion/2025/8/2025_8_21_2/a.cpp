#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
char d[N],v[N];
string a,b;
int td,tv;
int n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>a>>m>>b;
        char c;
        td=tv=0;
        for(int i=1;i<=m;i++){
            cin>>c;
            if(c=='D'){
                d[++td]=b[i-1];
            }else{
                v[++tv]=b[i-1];
            }
        }
        for(int i=tv;i>=1;i--)cout<<v[i];
        cout<<a;
        for(int i=1;i<=td;i++)cout<<d[i];
        cout<<"\n";
    }
}
