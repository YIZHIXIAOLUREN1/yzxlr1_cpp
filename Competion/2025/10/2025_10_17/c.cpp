#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int k,ans[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        k=0;
        bool f=1;
        for(int i=0;i<=30;i++){
            if((a&(1<<i))!=(b&(1<<i))){
                int p=1<<i;
                if(p>a){
                    cout<<"-1\n";
                    f=0;
                    break;
                }
                ans[++k]=p;
                a^=p;
            }
        }
        if(!f)continue;
        cout<<k<<"\n";
        for(int i=1;i<=k;i++){
            cout<<ans[i]<<" \n"[i==k];
        }
    }
}
