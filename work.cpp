#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
const int N=1e18,M=1e9+7;
int T;
ll L,R;
ll q,h,l,r;

ll find(ll x){
    l=1,r=M;
    while(l<r){
        if(mid*mid>=x)r=mid-1;
        else l=mid+1;
    }
    while(l*l<x)l++;
    while((l-1)*(l-1)>=x&&l>1)l--;
    return l;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> L >> R;
        q=find(L)-1;
        h=find(R);
        if(h*h>R)h--;
        cout << h-q << "\n";
    }
}