#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[13],c[13][13];
bool b[13];

void dfs(int k,int s) {
	//cout << k << " " << s << endl;//
	if(s>sum)
		return;

	if(k>n) {
		if(s==sum) {
			cout << a[1];
			for(int i=2; i<=n; i++) cout << " " << a[i];
			exit(0);
		}
		return;
	}


	for(int i=1; i<=n; i++) {
		if(b[i]==0) {
			b[i]=1;
			a[k]=i;
			dfs(k+1,s+i*c[n][k]);
			b[i]=0;
		}
	}
}

int main() {
	cin >> n >> sum;
	c[1][1]=1;


	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			//cout << c[i][j] << " ";//
		}
		//cout << endl;//
	}

	dfs(1,0);

	return 0;
}
