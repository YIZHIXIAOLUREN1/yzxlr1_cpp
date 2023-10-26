#include<bits/stdc++.h>
using namespace std;
const int N=15;
bool trend=0,ncolor;
int kw[N],dx[N][N],dy[N][N],cx[N][N],cy[N][N],ic[N];//需特判car
int cap[2][2];

struct node{
    bool tr;
    bool color;//0:red 1:blue
    int type;//王:0 士:1 象:2 马:3车:4 鸭:5 兵:6
    string name;
}mp[N][N];
node captain,guard,elephant,horse,car,duck,soldier,none;

void csh();
bool check(int x1,int y1,int x2,int y2);
void move(int x1,int y1,int x2,int y2);
bool wkc();//will_kill_captain
void update();
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    csh();
    int Q;
    cin >> Q;
    while(Q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(check(x1,y1,x2,y2)&&ncolor==mp[x1][y1].color){
            cout << (ncolor?"blue ":"red ");
            cout << mp[x1][y1].name<<";";
            move(x1,y1,x2,y2);
            cout << (wkc()?"yes":"no")<<";";
            cout << (trend?"yes":"no");
            cout<<"\n";
            ncolor^=1;
        }else cout <<"Invalid command\n";
    }
    
    return 0;
}
void update(){
    for(int x=0;x<=9;x++)for(int y=0;y<=8;y++)
        if(mp[x][y].tr&&mp[x][y].type==0){
            cap[mp[x][y].color][0]=x;
            cap[mp[x][y].color][1]=y;
        }
}
bool wkc(){
    if(trend)return 0;
    update();
    for(int x=0;x<=9;x++)for(int y=0;y<=8;y++)if(mp[x][y].tr)
    if(check(x,y,cap[!mp[x][y].color][0],cap[!mp[x][y].color][1]))return 1;
    return 0;
}
void move(int x1,int y1,int x2,int y2){
    update();
    if(mp[x2][y2].tr==1){
        cout << (ncolor?"red ":"blue ");
        cout << mp[x2][y2].name<<";";
        if(mp[x2][y2].type==0)trend=1;
    }else cout<<"NA;";
    mp[x2][y2]=mp[x1][y1];
    if(mp[x1][y1].type==0){
        cap[mp[x1][y1].color][0]=x2;
        cap[mp[x1][y1].color][1]=y2;
    }
    mp[x1][y1]=none;
}
bool check(int x1,int y1,int x2,int y2){
    if(trend||mp[x1][y1].tr==0||x2<0||x2>9||y1<0||y2>8)return 0;
    if(mp[x2][y2].tr==1&&mp[x1][y1].color==mp[x2][y2].color)return 0;
    int ty=mp[x1][y1].type;
    if(ty!=4){
        for(int i=0;i<=kw[ty];i++){
            if(x1+dx[ty][i]!=x2||y1+dy[ty][i]!=y2)continue;
            if(ic[ty]&&mp[x1+cx[ty][i]][y1+cy[ty][i]].tr==1)continue;
            if(ty==5&&mp[x1+cx[3][i]][y1+cy[3][i]].tr==1)continue;
            return 1;
        }
        return 0;
    }else{
        if(x1==x2){
            for(int i=min(y1,y2)+1;i<=max(y1,y2)-1;i++){
                if(mp[x1][i].tr==1)return 0;
            }
        }else if(y1==y2){
            for(int i=min(x1,x2)+1;i<=max(x1,x2)-1;i++){
                if(mp[i][y1].tr==1)return 0;
            }
        }else return 0;
        return 1;
    }
}
void csh(){
    kw[0]=kw[1]=kw[2]=3,kw[3]=kw[5]=kw[6]=7;
    ic[0]=ic[1]=ic[6]=0,ic[2]=ic[3]=ic[5]=1;
    dx[0][0]=1,dx[0][1]=-1,dx[0][2]=0,dx[0][3]=0;
    dy[0][0]=0,dy[0][1]=0,dy[0][2]=1,dy[0][3]=-1;

    dx[1][0]=1,dx[1][1]=-1,dx[1][2]=1,dx[1][3]=-1;
    dy[1][0]=1,dy[1][1]=-1,dy[1][2]=-1,dy[1][3]=1;

    dx[2][0]=2,dx[2][1]=-2,dx[2][2]=2,dx[2][3]=-2;
    dy[2][0]=2,dy[2][1]=-2,dy[2][2]=-2,dy[2][3]=2;
    cx[2][0]=1,cx[2][1]=-1,cx[2][2]=1,cx[2][3]=-1;
    cy[2][0]=1,cy[2][1]=-1,cy[2][2]=-1,cy[2][3]=1;

    dx[3][0]=-1,dx[3][1]=-1,dx[3][2]=-2,dx[3][3]=-2,dx[3][4]=1,dx[3][5]=1,dx[3][6]=2,dx[3][7]=2;
    dy[3][0]=2,dy[3][1]=-2,dy[3][2]=1,dy[3][3]=-1,dy[3][4]=2,dy[3][5]=-2,dy[3][6]=1,dy[3][7]=-1;
    cx[3][0]=0,cx[3][1]=0,cx[3][2]=-1,cx[3][3]=-1,cx[3][4]=0,cx[3][5]=0,cx[3][6]=1,cx[3][7]=1;
    cy[3][0]=1,cy[3][1]=-1,cy[3][2]=0,cy[3][3]=0,cy[3][4]=1,cy[3][5]=-1,cy[3][6]=0,cy[3][7]=0;

    dx[5][0]=-2,dx[5][1]=-2,dx[5][2]=-3,dx[5][3]=-3,dx[5][4]=2,dx[5][5]=2,dx[5][6]=3,dx[5][7]=3;
    dy[5][0]=3,dy[5][1]=-3,dy[5][2]=2,dy[5][3]=-2,dy[5][4]=3,dy[5][5]=-3,dy[5][6]=2,dy[5][7]=-2;
    cx[5][0]=-1,cx[5][1]=-1,cx[5][2]=-2,cx[5][3]=-2,cx[5][4]=1,cx[5][5]=1,cx[5][6]=2,cx[5][7]=2;
    cy[5][0]=2,cy[5][1]=-2,cy[5][2]=1,cy[5][3]=-1,cy[5][4]=2,cy[5][5]=-2,cy[5][6]=1,cy[5][7]=-1;

    dx[6][0]=-1,dx[6][1]=-1,dx[6][2]=-1,dx[6][3]=1,dx[6][4]=1,dx[6][5]=1,dx[6][6]=0,dx[6][7]=0;
    dy[6][0]=1,dy[6][1]=-1,dy[6][2]=0,dy[6][3]=-1,dy[6][4]=1,dy[6][5]=0,dy[6][6]=1,dy[6][7]=-1;

    captain.tr=1,captain.type=0,captain.color=0;captain.name="captain";
    guard.tr=1,guard.type=1,guard.color=0;guard.name="guard";
    elephant.tr=1,elephant.type=2,elephant.color=0;elephant.name="elephant";
    horse.tr=1,horse.type=3,horse.color=0;horse.name="horse";
    car.tr=1,car.type=4,car.color=0;car.name="car";
    duck.tr=1,duck.type=5,duck.color=0;duck.name="duck";
    soldier.tr=1,soldier.type=6,soldier.color=0;soldier.name="soldier";
    none.tr=0;
    for(int x=0;x<=9;x++)for(int y=0;y<=8;y++)mp[x][y]=none;
    mp[0][4]=mp[9][4]=captain;
    cap[0][0]=0,cap[0][1]=4,cap[1][0]=9,cap[1][1]=4;
    mp[0][3]=mp[0][5]=guard;guard.color=1;
    mp[9][3]=mp[9][5]=guard;
    mp[0][2]=mp[0][6]=elephant;elephant.color=1;
    mp[9][2]=mp[9][6]=elephant;
    mp[0][1]=mp[0][7]=horse;horse.color=1;
    mp[9][1]=mp[9][7]=horse;
    mp[0][0]=mp[0][8]=car;car.color=1;
    mp[9][0]=mp[9][8]=car;
    mp[2][0]=mp[2][8]=duck;duck.color=1;
    mp[7][0]=mp[7][8]=duck;
    mp[3][0]=mp[3][2]=mp[3][4]=mp[3][6]=mp[3][8]=soldier;
    soldier.color=1;
    mp[6][0]=mp[6][2]=mp[6][4]=mp[6][6]=mp[6][8]=soldier;
    mp[9][4].color=1;
}