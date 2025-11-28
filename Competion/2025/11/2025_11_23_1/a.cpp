#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7,inf=0x3f3f3f3f;
int n,a[N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
    	int l,r;
    	cin>>l>>r;
    	int ans=0;
    	if(l<=1&&r>=1)ans++
    	;if(l<=9&&r>=9)ans++;
    	cout<<ans<<"\n";
    }
}
