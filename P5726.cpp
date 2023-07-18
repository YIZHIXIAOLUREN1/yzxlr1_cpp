#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a,n,max = 0,min = 10;
	float s;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a;
		if (a > max){
			max = a;
		}
		if (a < min){
			min = a;
		}
		s += a;
	}
	s = (s - max - min)/(n - 2);
	printf("%.2f",s);
	return 0;
}
