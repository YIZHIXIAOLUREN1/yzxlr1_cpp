#include<bits/stdc++.h>
using namespace std;

int main(){
    int _;
    cin >> _;
    string e="ding",f="zhen";
    while(_--){
        string a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a[0]=='y'&&b[0]=='y'&&e==c&&d==f)puts("Yes");
        else puts("No");
    }
}