#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1007;
int n;
int a[N];
int bs[N];
int res;
int main(){
    //ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n-1;i++){
            cout<<"throw "<<i<<endl;
            cin>>res;
            bs[i]=res;
        }
        
        if(bs[n-1]==2){
            a[n-1]=1;
        }else{
            a[n-1]=2;
        }
        cout<<"swap "<<n-1<<endl;
        cout<<"throw "<<n-1<<endl;
        cin>>res;
        if(res==2)a[n]=1;
        else a[n]=2;
        for(int i=n-2;i>=1;i--){
            if(a[i+1]==1){
                if(bs[i]==bs[i+1])a[i]=2;
                else a[i]=1;
            }else{
                if(a[i+2]==1){
                    if(bs[i]==bs[i+1])a[i]=2;
                    else a[i]=1;
                }else{
                    
                }
            }
        }
        cout<<"! ";
        for(int i=1;i<n;i++)cout<<a[i]<<" ";
        cout<<a[n]<<endl;
    }
}
