#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n;
int a[N],s[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int m=1;m<=n-1;m++){
        a[m]=n/m-1;
        s[m]=a[m]+s[m-1];
        
    }
    cout<<"0 ";
    for(int i=1;i<=n-1;i++){
    	int ans=s[i];
    	for(int j=1;j<=i-1;j++){
    		ans-=i/j-1;
    	}
    	cout<<ans<<" \n"[i==n-1];
    }
}

//
