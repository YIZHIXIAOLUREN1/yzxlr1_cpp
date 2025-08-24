#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=17;
int n,a[N],b[N];
int t1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
    	t1=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]){
                t1+=a[i]-b[i];
            }
        }
        cout<<t1+1<<"\n";
    }
}
