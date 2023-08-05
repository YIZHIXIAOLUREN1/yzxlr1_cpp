#include<iostream>
using namespace std;
int main(){
	long n,a = 0,b = 1,t;
	cin >> n;
	if (n == 0){
		cout << "0.00";
		return 0;
	}
	for(int i = 1;i < n;i++){
		t = b;
		b = b + a;
		a = t;
	}
	cout << b << ".00";
	return 0;
}
