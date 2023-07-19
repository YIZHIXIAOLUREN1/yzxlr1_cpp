#include<bits/stdc++.h>
using namespace std;
char s[10];
int sta[4][4],ans[4][4]={
	{0,0,0,0},
	{0,1,2,3},
	{0,8,0,4},
	{0,7,6,5}
};
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

int cx,cy,k=2;
bool judge;


void ckk(){//
	for(int i=1;i<=3;i++){//
		for(int j=1;j<=3;++j){
			cout << sta[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;//
}

bool check()
{
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=sta[i][j])return 0;
    return 1;
}

bool test(int step)
{
    int cnt=0;
    for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
    if(ans[i][j]!=sta[i][j]){ 
		if(++cnt+step>k) 
			return 0;
	}
    return 1;
}



void dfs(int step,int x,int y,int pre){
	//cout << x << y;//
	if(step==k){
		if(check()) judge=1;
		return;
	}
	if(judge) return;
	
	for(int i=0;i<4;i++){
		//cout << x+dx[i] << y+dy[i];//
		int nx=x+dx[i],ny=y+dy[i];
		//cout << nx << ny  << endl;//
		if(nx<1||nx>3||ny<1||ny>3||pre+i==3) continue;
		
		swap(sta[x][y],sta[nx][ny]);
		if(test(step)){
			
			//ckk();
			dfs(step+1,nx,ny,i);
		} 
		swap(sta[x][y],sta[nx][ny]);
	}
}



int main() {
	scanf("%s",&s);
	for(int i=0;i<9;i++){
        sta[i/3+1][i%3+1]=s[i]-'0';
        if(s[i]-'0'==0){cx=i/3+1;cy=i%3+1;}
    }
	
	
	if(check()){
		printf("%d ",0);
        return 0;
		return 0;
	}
	
	
	while(++k){
		//cout << endl << k << endl << endl;//
		dfs(0,cx,cy,-1);
		if(judge) {
			printf("%d",k);
			break;
		}
	}
	return 0; 
}
