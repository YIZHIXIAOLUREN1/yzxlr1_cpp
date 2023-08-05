#include<iostream>
using namespace std;
int main(){
	int x,k,n,max;
	cin >> n;
	n = n/364;
	x = n-1;
	if (n-1 > 100){
		x = 100;
	}
	for (;x >= 1;x--){
		if ((n-x)%3 == 0){
			k = (n-x)/3;
			break;
		}
	}
	cout << x << endl << k;
	return 0;
}
