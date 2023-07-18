#include<bits/stdc++.h>
using namespace std;
int n,ans;
int b[15];
bool wo[15][15];
void output(){
	for(int i=0;i<n;i++)cout << b[i]+1 << " ";
	cout << endl;
}

void dfs(int k){
	if(k==n){
		//if(ans<=3){
			output();
		//}
		ans++;
		return;
	}
	for(int i=0;i<n;i++){
		if(wo[k][i]==0){
			cout << k << " " << i << endl;
			b[k]=i;
			for(int j=0;j<n;j++){
				if(k-i+j<n&&k-i+j>=0){
					wo[k-i+j][j]=1;
				}
				wo[j][i]=1;
			}
			for(int p=0;p<n;p++){
				for(int q=0;q<n;q++){
					cout << wo[p][q] << " ";
				}
				cout << endl;
			}
			//cout << endl;
			dfs(k+1);
			b[k]=0;
			for(int j=0;j<n;j++){
				if(k-i+j<n&&k-i+j>=0){
					wo[k-i+j][j]=0;
				}
				wo[j][i]=0;
			}
		}
	}
}


int main(){
	cin >> n;
	dfs(0);
	cout << ans;
	
	
	
}
