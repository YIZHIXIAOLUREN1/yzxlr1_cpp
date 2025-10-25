#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,cx,cy,dx,dy;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>cx>>cy>>dx>>dy;
        if(cx==dx){
            cout<<(cy<dy?dy:n-dy)<<"\n";
        }else if(cy==dy){
            cout<<(cx<dx?dx:n-dx)<<"\n";
        }else{
            cout<<max((cx<dx?dx:n-dx),(cy<dy?dy:n-dy))<<"\n";
        }
    }
}
