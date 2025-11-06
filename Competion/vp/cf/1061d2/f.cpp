#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,a[N],b[N];

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    bool fl=1;
    while(fl){
    	fl=0;
        bool f1=0,f2=0;
    	for(int i=n-2;i>=1;i--){
            if(a[i]<3)continue;
            int j=b[a[i]-2],k=b[a[i]-1];
            if(i>j||i>k)continue;
            if(j>k){f2=1;continue;}
            f1=1;
            a[i]-=2;a[j]++;a[k]++;
            b[a[i]]=i;b[a[j]]=j;b[a[k]]=k;
            break;
	    }
        fl=f1|f2;
        if(f1)continue;
        if(f2){
            for(int i=n-2;i>=1;i--){
                if(a[i]<3)continue;
                int j=b[a[i]-2],k=b[a[i]-1];
                if(i>j||i>k)continue;
                a[i]-=2;a[j]++;a[k]++;
                b[a[i]]=i;b[a[j]]=j;b[a[k]]=k;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}