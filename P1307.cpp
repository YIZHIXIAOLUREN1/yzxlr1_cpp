#include<iostream>
using namespace std;
int main(){
	int a,p;
	cin >> a;
	if (a < 0){
		cout << "-";
		a = -a;
	}
	if (a == 0){
		cout << "0";
		return 0;
	}
	for (int m = 1;;m++){
		p = a%10;
		if (p!=0){
			break;
		}
		a/=10;
	}
	for(int i = 1;a != 0;i++){
		p = a%10;
		cout << p;
		a/=10;
	}
	return 0;
}
