
#include<iostream>
using namespace std;
int main(){
	int l,m,x = 0,p,n,i;
	for(i = 1;i<=12;i++){
		cin >> m;
		if(x + 300 < m){
			p = 1;
			break;
		}
		else{
			n = (x+300-m)/100;
			x = (x+300-m)%100;
			l += 100*n;
			p = 0;
		}
	}
	if (p == 1){
		cout << - i;
	}
	else{
		cout << 1.2*l + x;
	}
	return 0;
}
