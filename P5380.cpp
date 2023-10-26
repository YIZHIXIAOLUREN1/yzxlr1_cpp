#include<bits/stdc++.h>
using namespace std;
const int N=15;
bool trend=0;
int kw[N],dx[N][N],dy[N][N],cx[N][N],cy[N][N],ic[N];//需特判car

struct node{
    bool tr;
    bool color;//0:red 1:blue
    int type;//王:0 士:1 象:2 马:3车:4 鸭:5 兵:6
}mp[N][N];
node captain,guard,elephant,horse,car,duck,soldier,none;

void csh();
bool check(int x1,int y1,int x2,int y2);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    csh();
    int Q;
    cin >> Q;
    while(Q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool f=check(x1,y1,x2,y2);
    }
    
    return 0;
}

bool check(int x1,int y1,int x2,int y2){
    if(trend||mp[x1][y1].tr==0)return 0;
    bool res=0;
    int ty=mp[x1][y1].type;
    if(ty!=4){
        for(int i=0;i<=kw[ty];i++){
            if(mp[x1+cx[i]][y1+cy[i]])
        }
    }
}
void csh(){
    kw[0]=kw[1]=kw[2]=4,kw[3]=kw[5]=kw[6]=8;
    ic[0]=ic[1]=ic[6]=0,ic[2]=ic[3]=ic[5]=1;
    dx[0][0]=1,dx[0][1]=-1,dx[0][2]=0,dx[0][3]=0;
    dy[0][0]=0,dy[0][1]=0,dy[0][2]=1,dy[0][3]=-1;

    dx[1][0]=1,dx[1][1]=-1,dx[1][2]=1,dx[1][3]=-1;
    dy[1][0]=1,dy[1][1]=-1,dy[1][2]=-1,dy[1][3]=1;

    dx[2][0]=2,dx[2][1]=-2,dx[2][2]=2,dx[2][3]=-2;
    dy[2][0]=2,dy[2][1]=-2,dy[2][2]=-2,dy[2][3]=2;

    dx[3][0]=-1,dx[3][1]=-1,dx[3][2]=-2,dx[3][3]=-2,dx[3][4]=1,dx[3][5]=1,dx[3][6]=2,dx[3][7]=2;
    dy[3][0]=2,dy[3][1]=-2,dy[3][2]=1,dy[3][3]=-1,dy[3][4]=2,dy[3][5]=-2,dy[3][6]=1,dy[3][7]=-1;
    cx[3][0]=-1,cx[3][1]=-1,cx[3][2]=-1,cx[3][3]=-1,cx[3][4]=1,cx[3][5]=1,cx[3][6]=1,cx[3][7]=1;
    cy[3][0]=1,cy[3][1]=-1,cy[3][2]=1,cy[3][3]=-1,cy[3][4]=1,cy[3][5]=-1,cy[3][6]=1,cy[3][7]=-1;

    dx[5][0]=-2,dx[5][1]=-2,dx[5][2]=-3,dx[5][3]=-3,dx[5][4]=2,dx[5][5]=2,dx[5][6]=3,dx[5][7]=3;
    dy[5][0]=3,dy[5][1]=-3,dy[5][2]=2,dy[5][3]=-2,dy[5][4]=3,dy[5][5]=-3,dy[5][6]=2,dy[5][7]=-2;
    cx[5][0]=-1,cx[5][1]=-1,cx[5][2]=-2,cx[5][3]=-2,cx[5][4]=1,cx[5][5]=1,cx[5][6]=2,cx[5][7]=2;
    cy[5][0]=2,cy[5][1]=-2,cy[5][2]=1,cy[5][3]=-1,cy[5][4]=2,cy[5][5]=-2,cy[5][6]=1,cy[5][7]=-1;

    dx[6][0]=-1,dx[6][1]=-1,dx[6][2]=-1,dx[6][3]=1,dx[6][4]=1,dx[6][5]=1,dx[6][6]=0,dx[6][7]=0;
    dy[6][0]=1,dy[6][1]=-1,dy[6][2]=0,dy[6][3]=-1,dy[6][4]=1,dy[6][5]=0,dy[6][6]=1,dy[6][7]=-1;

    captain.tr=1,captain.type=0,captain.color=0;
    guard.tr=1,guard.type=1,guard.color=0;
    elephant.tr=1,elephant.type=2,elephant.color=0;
    horse.tr=1,horse.type=3,horse.color=0;
    car.tr=1,car.type=4,car.color=0;
    duck.tr=1,duck.type=5,duck.color=0;
    soldier.tr=1,soldier.type=6,soldier.color=0;
    none.tr=0;
    for(int x=0;x<=9;x++)for(int y=0;y<=8;y++)mp[x][y]=none;
    mp[0][4]=mp[9][4]=captain;
    mp[0][3]=mp[0][5]=mp[9][3]=mp[9][5]=guard;
    mp[0][2]=mp[0][6]=mp[9][2]=mp[9][6]=elephant;
    mp[0][1]=mp[0][7]=mp[9][1]=mp[9][7]=horse;
    mp[0][0]=mp[0][8]=mp[9][0]=mp[9][8]=car;
    mp[2][0]=mp[2][9]=mp[7][0]=mp[7][9]=duck;
    mp[3][0]=mp[3][2]=mp[3][4]=mp[3][6]=mp[3][8]=
    mp[6][0]=mp[6][2]=mp[6][4]=mp[6][6]=mp[6][8]=soldier;
    mp[9][4].color=1;
}
/*
dx[0][0]=1,dx[0][1]=-1,dx[0][2]=1,dx[0][3]=1;
    dy[0][0]=1,dy[0][1]=1,dy[0][2]=1,dy[0][3]=-1;
*/