#include<bits/stdc++.h>
using namespace std;

void input(int *number,int n){
    for(int i=0;i<n;i++) cin>>number[i];
}

void max_min_value(int *number,int n){
    int *minp=number,*maxp=number;
    for(int i=1;i<n;i++){
        if(number[i]<*minp) minp=number+i;
        if(number[i]>*maxp) maxp=number+i;
    }
    swap(*minp,number[0]);
    if(maxp==number) maxp=minp;
    swap(*maxp,number[n-1]);
}

void output(int *number,int n){
    for(int i=0;i<n;i++) cout<<number[i]<<" ";
    cout<<endl;
}

void Solve(){
    int a[10];
    cout<<"input 10 numbers:";
    input(a,10);
    max_min_value(a,10);
    cout<<"Now,they are:    ";
    output(a,10);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    while(T--){
        Solve();
    }
}