#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
bool vis[N];
int p[N],tot=0,phi[N];


void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}

void pre(){
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i])p[++p[0]]=i,phi[i]=i-1;
		for(int j=1;j<=p[0]&&1ll*i*p[j]<N;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}