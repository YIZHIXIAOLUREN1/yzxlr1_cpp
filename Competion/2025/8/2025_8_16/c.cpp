#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e9+7,M=1e9;
int ne=-N,nw=N,se=-N,sw=N,n;
int xma=-N,xmi=N,yma=-N,ymi=N;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    // for(int i=1,x,y;i<=n;i++){
    //     cin>>x>>y;
    //     ne=max(ne,x-y);
    //     nw=min(nw,x+y);
    //     se=max(se,x+y);
    //     sw=min(sw,x-y);
    // }
    // //printf("%d %d %d %d:",ne,nw,se,sw);//
    // cout<<((ne-sw)/2+(se-nw)/2)/2;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        xma=max(xma,x);
        xmi=min(xmi,x);
        yma=max(yma,y);
        ymi=min(ymi,y);
    }
    //printf("%d %d %d %d:",ne,nw,se,sw);//
    cout<<(max(xma-xmi,yma-ymi)+1)/2;
}