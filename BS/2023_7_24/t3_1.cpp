#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,ng,m;
int a[N],ty[N];
int cx(int x){
    int res=0;
    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ng=sqrt(n);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int l=N,tr=0;
    for(int i=1;i<=n;i++){
        // if(i=1&&i!=n&&a[i-1]>a[i]&&a[i+1]>a[i])qi.insert({a[i],0});
        // if(a[i-1]<a[i]&&a[i+1]<a[i])qa.insert({a[i],0});
        if(i>1&&a[i]==a[i-1]){
            l=min(l,i-1);
            tr=1;
        }else if(tr){
            // if(a[i-1]<a[i]&&a[l-1]>a[i-1])qi.insert({a[i-1],0});
            // if(a[i-1]>a[i]&&a[l-1]<a[i-1])qa.insert({a[i-1],0});
            tr=0,l=N;
        }
    }

    int last=0,x1,x2;
    char ty;
    while(m--){
        cin >> ty >> x1;
        x1^=last;
        if(ty=='Q'){
            
            cout << last << "\n";
        }
        else{
            cin >> x2;x2^=last;
        }
    }
}