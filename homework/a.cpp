#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;

char* fun(char *a,char *b){
    char *p=a;
    while(*p) p++;
    while(*b) *p++=*b++;
    *p='\0';
    return a;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char a[N],b[N];
    cin.getline(a,N);
    cin.getline(b,N);
    cout<<fun(a,b)<<"\n";
}