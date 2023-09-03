#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5050;
int n,T;
int zb[N];
int Q[N][N];
int l,r;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        if(n==1){
        	puts("1");
        	continue;
        }
        l=0,r=n;
        for(int i=1;i<=n;i++){
        	if(i==2)
        	for(int j=1;j<=n-1;j++){
            	zb[Q[1][j]]=j;
    	    }
    	    
            for(int j=1;j<=n-1;j++){
                cin >> Q[i][j];
                if(Q[i][j]>=i)Q[i][j]++;
            }
            
            if(i>1)
            for(int j=1;j<=n-1;j++){
                if(Q[i][j]==1){
                    if(j>1)l=max(l,zb[Q[i][j-1]]);
                    if(j<n-1)r=min(r,zb[Q[i][j+1]]);
                    //cout<<l<<" "<<r<<"\n";//
                    break;
                }
            }
        }

        for(int i=1;i<=n-1;i++){
            if(i==r)cout << "1 ";
            cout << Q[1][i];
            if(i<n-1)cout << " ";
            if(i==n-1&&r==n)cout << " ";
        }
        if(r==n)cout << "1";
        cout <<"\n";
    }
}