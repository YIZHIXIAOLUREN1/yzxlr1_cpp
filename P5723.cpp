#include<iostream>
using namespace std;
int main(){
	int L,a = 1,n = 0;
	cin >> L;
	int s = 0;
	for (int i = 2;s + i <= L;i ++){
		for(int j = 2;j*j <= i;j ++){
			if (i % j == 0){
				a = 0;
				break;
			}
			else{
				a = 1;
			}
		}
	if (a == 1){
		s += i;
		n++;
		cout << i << endl;
	}
	}
	cout << n;
	return 0;
}
