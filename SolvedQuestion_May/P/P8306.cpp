#include<bits/stdc++.h>
using namespace std;
#define maxn 3000100
int tree[maxn][63];
int sum[maxn];
int cnt;

int ys(char a){
	if('9'-a>=0) return a-'0';
	if('Z'-a>=0) return a-'A'+10;
	return a-'a'+36;
}

void add(string a){
	int len=a.size();
	int u=0;
	for(int i=0,aa;i<len;++i){
		aa=ys(a[i]);
		if(!tree[u][aa]) tree[u][aa]=++cnt;
		u=tree[u][aa];
		sum[u]++;
	}
}

int find(string a){
	int len=a.size();
	int u=0;
	int flag=0;
	for(int i=0,aa;i<len;++i){
		aa=ys(a[i]);
		if(!tree[u][aa]) return 0;
		u=tree[u][aa];
	}
	return sum[u];
}

void csh(){
	memset(tree,0,(cnt+5)*64*4);
	memset(sum,0,(cnt+5)*4);
	cnt=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		csh();
		int n,q;
		cin >> n >> q;
		string s;
		for(int i=0;i<n;++i){
			cin >> s;
			add(s);
		}
		for(int i=0;i<q;++i){
			cin >> s;
			cout << find(s) << endl;
		}
	}
	
	
	return 0;
}
