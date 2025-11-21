#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
    	//cout<<"Yes\n";
    	//continue;
    	//
        cin>>n;
        bool ans=1;
        for(int i=1;i<=n;i++){
        	cin>>a[i];
        	if(!a[i])ans=0;
        }

        
        int cg=0;
        for(int i=1;i<=n;i++){
            if(a[i]<cg){ans=0;break;}
            if(a[i]<=a[i-1])continue;
            cg++;
        }
        cout<<(ans?"Yes\n":"No\n");
    }
}
