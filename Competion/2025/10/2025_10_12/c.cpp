#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int a[10],n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        int b;
        cin>>b;
        while(b%2==0)a[2]++,b/=2;
        while(b%3==0)a[3]++,b/=3;
        while(b%5==0)a[5]++,b/=5;
    }
    cout<<min(a[2],min(a[3],a[5]));
}
