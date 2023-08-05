#include<iostream>
using namespace std;
int main(){
	int n,p;
	cin >> n;
	for(int i = 2;i*i <= n;i++){
		if (n%i == 0){
		p = i;
		}
	}
	p = n / p;
	cout << p;
	return 0;
}
