/*
x=ans
kmp[x]=0
->kmp[n]=n-x
->x=n-km,p[n]
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int kmp[N];
char s1[N];
int n,j;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s1+1;
    for(int i=2;i<=n;i++){
        while(j&&s1[j+1]!=s1[i])j=kmp[j];
        if(s1[j+1]==s1[i])j++;
        kmp[i]=j;
        //cout << i << ":" << kmp[i] << "\n";//
    }
    cout << n-kmp[n];
}