#include<iostream>
using namespace std;
int main() {
	int a,b,a3,a5,a7;
	cin >> a >> b;


	//5,7,11
	if (a == 5) {
		cout <<5<<endl;
	}
	bool px;
	if (a <= 7) {
		if (b >= 7) {
			cout <<7<<endl;
		}
	}
	if (a <= 11) {
		if (b >= 11) {
			cout <<11<<endl;
		}
	}


	//a3


	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			a3 = 100*d1 + 10*d2 + d1;
			if (a3 < a)continue;
			if (a3 > b) {
				d1 = 10;
				d2 = 10;
				break;
			}
			for (int i = 3; i*i <= a3; i+=2) {
				if (a3%i == 0) {
					px = 1;
					break;
				}
				px = 0;
			}
			if (px == 0) {
				cout <<a3<<endl;
			}
		}
	}

	//a5


	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				a5 = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
				if (a5 < a)continue;
				if (a5 > b) {
					d1 = 10;
					d2 = 10;
					d3 = 10;
					break;
				}
				for (int i = 3; i*i <= a5; i+=2) {
					if (a5%i == 0) {
						px = 1;
						break;
					}
					px = 0;
				}
				if (px == 0) {
					cout <<a5<<endl;
				}
			}
		}
	}


	//a7


	for (int d1 = 1; d1 <= 9; d1+=2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					a7 = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
					if (a7 < a)continue;
					if (a7 > b) {
						d1 = 10;
						d2 = 10;
						d3 = 10;
						d4 = 10;
						break;
					}
					for (int i = 3; i*i <= a7; i+=2) {
						if (a7%i == 0) {
							px = 1;
							break;
						}
						px = 0;
					}
					if (px == 0) {
						cout <<a7<<endl;
					}
				}
			}
		}
	}
	return 0;
}
