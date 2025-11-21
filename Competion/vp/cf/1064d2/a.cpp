#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
string s;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>s;
        int ans=0;
        for(int i=n-1;i>=1;i--){
            if(s[i]!=s[i-1]){
                s[i-1]=s[i];
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
