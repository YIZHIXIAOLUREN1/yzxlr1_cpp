#include<iostream>
using namespace std;
int main(){
	int n,a = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			a++;
			if (a < 10){
				cout << "0" << a;
			}
			else{
				cout << a;
			}
		}
		cout << endl;
	}
	a = 0;
	cout << endl;
	for (int i = 1;i <= n;i++){
		int p;p = n - i;
		for (int j = 1;j <= p;j++){
			cout << "  ";
		}
		for (int j = 1;j <= i;j++){
			a++;
			if (a < 10){
				cout << "0" << a;
			}
			else{
				cout << a;
			}
		}
		cout << endl;
	}
	return 0;
}
