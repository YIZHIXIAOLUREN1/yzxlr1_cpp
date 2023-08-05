#include<iostream>
using namespace std;
int main(){
	long x,y,max = 1,a = 1;
	int n;
	cin >> n;
	cin >> x;
	for (int i = 2; i <= n;i++){
		cin >> y;
		if (y - x == 1){
			a++;
		}
		else{
			a = 1;
		}
		if (max < a){
			max = a;
		}
		x = y;
	}
	cout << max;
	return 0;
}
