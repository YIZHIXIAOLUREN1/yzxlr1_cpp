#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+7;
int n;
bool vis[N];
int p[N/15],tot=0;


void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

int main(){
	getprime();
	//cin >> n;
	cout << tot;
}