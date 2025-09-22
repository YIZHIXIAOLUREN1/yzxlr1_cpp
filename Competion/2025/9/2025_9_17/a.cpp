#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,a[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int k=1;k<=n;k++){
            int l=0,r=0;
            for(int i=1;i<=n;i++){
                if(!l&&a[i]){l=i;a[i]--;}
                else if(l&&!a[i]){
                    break;
                }else if(l){
                    a[i]--;
                }
            }
            //for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];//
        }
        
        

        bool fl=1;
        for(int i=1;i<=n;i++)if(a[i]){fl=0;break;}
        if(fl)cout<<"yes\n";
        else cout<<"no\n";
    }
}
