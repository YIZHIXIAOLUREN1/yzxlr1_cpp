#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+7;
int n,Q;
int a[N];

bool check(int s,int t,int e){
    for(int i=0;i<=t-s-1;i++){
        if(a[t+i]!=a[s+i])return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> Q;
    string s;
    cin >> s;
    for(int i=0;i<=n-1;i++){
        a[i+1]=s[i]-'a'+1;
    }
    while(Q--){
        int l,r;
        cin >> l >> r;
        int ans=0,st=l;
        for(int i=l;i<=r-1;i++){
            for(int j=i+1;2*j-i-1<=r;j++){
            	if(check(i,j,r)){
            		if((j-i)*2>ans){ans=(j-i)*2,st=i;}
            	}
            }
        }
        cout<<ans<<" "<<st<<"\n";
    }
}
