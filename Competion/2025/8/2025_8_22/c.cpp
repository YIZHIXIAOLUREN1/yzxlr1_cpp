#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,a,b;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==1)break;
        if(x==0)a++;
        b++;
    }
    cout<<b<<" "<<a;
}
