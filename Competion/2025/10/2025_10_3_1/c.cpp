#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,a[N],Q;
int pre1[N],pre2[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre1[i]=a[i]+pre1[i-1];
            pre2[i]=pre2[i-1];
            if((i>1&&a[i]==a[i-1])){
            	pre2[i]++;
            }
            //printf("%d:%d %d\n",i,pre1[i],pre2[i]);//
        }
        while(Q--){
            int l,r;
            cin>>l>>r;
            if((r-l+1)%3||(pre1[r]-pre1[l-1])%3){
                cout<<"-1\n";continue;
            }
            cout<<(r-l+1)/3+(pre2[r]-pre2[l]==0)<<"\n";
        }
    }
}