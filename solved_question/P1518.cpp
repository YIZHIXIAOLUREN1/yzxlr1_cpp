#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int x,y;
	int ptt;
	int on;
}jotn;
int move(int &ax,int &ay,int &ao,int &ap){
	if (ao == 1){
		ap++;
		if (ap > 4){
			ap = 1;
		}
	}
	else{
		switch(ap){
			case 1:ay--;break;
			case 2:ax++;break;
			case 3:ay++;break;
			case 4:ax--;break;
		}
	}
}
int main(){
	char s[12][12]={0};
	jotn niu,fam;
	int n=0;
	for (int j=1;j<=10;j++){
		for (int i=1;i<=10;i++){
			cin >> s[i][j];
			if (s[i][j] == 'C'){
				if (s[i][j-1] == '.'||s[i][j-1] == 'F'){
					niu.x = i;
					niu.y = j;
					niu.ptt = 1;
					niu.on = 0;
				}
				else{
					niu.x = i;
					niu.y = j;
					niu.ptt = 1;
					niu.on = 1;
				}
				s[i][j]='.';
			}
			if (s[i][j] == 'F'){
				if (s[i][j-1] == '.'||s[i][j-1] == 'C'){
					fam.x = i;
					fam.y = j;
					fam.ptt = 1;
					fam.on = 0;
				}
				else{
					fam.x = i;
					fam.y = j;
					fam.ptt = 1;
					fam.on = 1;
				}
				s[i][j]='.';
			}
		}
	}
	while(1){
		if (fam.x == niu.x && fam.y ==niu.y){
			cout << n;
			break;
		}
		else{
			move(fam.x,fam.y,fam.on,fam.ptt);
			move(niu.x,niu.y,niu.on,niu.ptt);
			switch (niu.ptt){
				case 1:if(niu.y == 1) niu.on = 1;else if(s[niu.x][niu.y-1] =='*') niu.on=1;else niu.on=0;break;
				case 2:if(niu.x == 10)niu.on = 1;else if(s[niu.x+1][niu.y] =='*') niu.on=1;else niu.on=0;break;
				case 3:if(niu.y == 10)niu.on = 1;else if(s[niu.x][niu.y+1] =='*') niu.on=1;else niu.on=0;break;
				case 4:if(niu.x == 1) niu.on = 1;else if(s[niu.x-1][niu.y] =='*') niu.on=1;else niu.on=0;break;
			}
			switch (fam.ptt){
				case 1:if(fam.y == 1) fam.on = 1;else if(s[fam.x][fam.y-1] =='*') fam.on=1;else fam.on=0;break;
				case 2:if(fam.x == 10)fam.on = 1;else if(s[fam.x+1][fam.y] =='*') fam.on=1;else fam.on=0;break;
				case 3:if(fam.y == 10)fam.on = 1;else if(s[fam.x][fam.y+1] =='*') fam.on=1;else fam.on=0;break;
				case 4:if(fam.x == 1) fam.on = 1;else if(s[fam.x-1][fam.y] =='*') fam.on=1;else fam.on=0;break;
			}
			n++;
			if (n>147){
				cout << "0";break;
			}
		}
	}
	return 0;
}
