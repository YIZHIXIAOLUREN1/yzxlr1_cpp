#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+7;
int n=100;
int a[N];
bool v[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }

    srand((unsigned)time(NULL));
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[j]>a[i])v[i]^=1;
        }
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i])v[i]^=1;
        }
    }

    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
    //for(int i=1;i<=n;i++)cout<<v[i]<<" \n"[i==n];
}
