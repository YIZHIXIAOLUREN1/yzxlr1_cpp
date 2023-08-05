//谁会手写哈希啊doge
#include<bits/stdc++.h>
using namespace std;
#define N 10050
int n;
set<string> ha;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){cin >> s;ha.insert(s);}
	cout << ha.size();
}