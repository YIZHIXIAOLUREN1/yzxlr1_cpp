#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,a[N];
bool vis[N];
vector<int> in;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            vis[i]=0;
        }
        for(int i=1;i<=n;i++){
            vis[a[i]]=1;
        }
        in.clear();
        for(int i=n;i>=1;i--){
            if(!vis[i])in.push_back(i);
        }
        int j=0;
        for(int i=1;i<=n;i++){
            if(!a[i]){
                a[i]=in[j];
                j++;
            }
        }
        int l=0,r=-1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i){
                if(!l)l=r=i;
                else r=i;
            }
        }
        cout<<r-l+1<<"\n";
    }
}
