#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n;
bool vis[N];
vector<pair<int,int>> ans;
void Solve(){
    cin>>n;
    if(n==2||n==4||n==8||n==16||n==32||n==64){cout<<"-1\n";return;}
    if(n==1||n==3||n==7||n==15||n==31||n==63){
        cout<<n-1<<"\n";
        for(int i=1;i<=n-1;i++)cout<<i<<" "<<n<<"\n";
        return;
    }
    if(n>=7&&n%4==3){
        cout<<n-1<<"\n";
        for(int i=2;i<=n;i++)cout<<"1 "<<i<<"\n";
        return;
    }

    if(n>=5&&n%4==1){
        cout<<(n/2)*(n/2)+n-1<<"\n";
        for(int i=2;i<=n;i++)cout<<"1 "<<i<<"\n";
        for(int i=2;i<=n/2+1;i++){
            for(int j=n/2+2;j<=n;j++){
                cout<<i<<" "<<j<<"\n";
            }
        }
        return;
    }

    for(int i=1;i<=n;i++)vis[i]=0;
    cout<<"-1\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
*/