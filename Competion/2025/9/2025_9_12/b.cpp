#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if('a'<=s[i]&&s[i]<='z')s[i]='L';
        else s[i]='Q';
    }
    cout<<s;
}
