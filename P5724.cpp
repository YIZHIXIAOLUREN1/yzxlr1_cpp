#include<iostream>
using namespace std;
int main(){
	int max = 0,min = 1000,n,x;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x;
		if (x < min){
			min = x;
		}
		if (x > max){
			max = x;
		}
	}
	cout << max-min;
	return 0;
}
