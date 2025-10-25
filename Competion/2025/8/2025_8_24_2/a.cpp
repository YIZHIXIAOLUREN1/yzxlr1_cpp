#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,a[N];
bool ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=100;i++)a[i]=0;
        ans=0;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            if(a[x])ans=1;
            a[x]++;
        }
        if(ans)cout<<"yes\n";
        else cout<<"no\n";
    }
}
