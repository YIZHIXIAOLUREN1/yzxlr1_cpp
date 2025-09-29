#include<bits/stdc++.h>

/*一：【准备工作】*/
#define LD double
#define LL long long
#define Re register int
#define Vector Point
using namespace std;
const int N=2e3+7;
const LD eps=1e-6,Pi=acos(-1.0);
inline int dcmp(LD a){return a<-eps?-1:(a>eps?1:0);}//处理精度
inline LD Abs(LD a){return a*dcmp(a);}//取绝对值
struct Point{
    LD x,y;Point(LD X=0,LD Y=0){x=X,y=Y;}
    inline void in(){scanf("%lf%lf",&x,&y);}
    inline void out(){printf("%.2lf %.2lf\n",x,y);}
};

/*二：【向量】*/
inline LD Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//【点积】
inline LD Cro(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//【叉积】
inline LD Len(Vector a){return sqrt(Dot(a,a));}//【模长】
inline LD Angle(Vector a,Vector b){return acos(Dot(a,b)/Len(a)/Len(b));}//【两向量夹角】
inline Vector Normal(Vector a){return Vector(-a.y,a.x);}//【法向量】
inline Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
inline Vector operator-(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
inline Vector operator*(Vector a,LD b){return Vector(a.x*b,a.y*b);}
inline bool operator==(Point a,Point b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}//两点坐标重合则相等

/*三：【点、向量的位置变换】*/

/*1.【点、向量的旋转】*/
inline Point turn_P(Point a,LD theta){//【点A\向量A顺时针旋转theta(弧度)】
    LD x=a.x*cos(theta)+a.y*sin(theta);
    LD y=-a.x*sin(theta)+a.y*cos(theta);
    return Point(x,y);
}
inline Point turn_PP(Point a,Point b,LD theta){//【将点A绕点B顺时针旋转theta(弧度)】
    LD x=(a.x-b.x)*cos(theta)+(a.y-b.y)*sin(theta)+b.x;
    LD y=-(a.x-b.x)*sin(theta)+(a.y-b.y)*cos(theta)+b.y;
    return Point(x,y);
}

/*四：【图形与图形之间的关系】*/

/*1.【点与线段】*/
inline int pan_PL(Point p,Point a,Point b){//【判断点P是否在线段AB上】
    return !dcmp(Cro(p-a,b-a))&&dcmp(Dot(p-a,p-b))<=0;//做法一
//  return !dcmp(Cro(p-a,b-a))&&dcmp(min(a.x,b.x)-p.x)<=0&&dcmp(p.x-max(a.x,b.x))<=0&&dcmp(min(a.y,b.y)-p.y)<=0&&dcmp(p.y-max(a.y,b.y))<=0;//做法二
    //PA,AB共线且P在AB之间(其实也可以用len(p-a)+len(p-b)==len(a-b)判断，但是精度损失较大)
}
inline LD dis_PL(Point p,Point a,Point b){//【点P到线段AB距离】
    if(a==b)return Len(p-a);//AB重合
    Vector x=p-a,y=p-b,z=b-a;
    if(dcmp(Dot(x,z))<0)return Len(x);//P距离A更近
    if(dcmp(Dot(y,z))>0)return Len(y);//P距离B更近
    return Abs(Cro(x,z)/Len(z));//面积除以底边长
}

/*2.【点与直线】*/
inline int pan_PL_(Point p,Point a,Point b){//【判断点P是否在直线AB上】
    return !dcmp(Cro(p-a,b-a));//PA,AB共线
}
inline Point FootPoint(Point p,Point a,Point b){//【点P到直线AB的垂足】
    Vector x=p-a,y=p-b,z=b-a;
    LD len1=Dot(x,z)/Len(z),len2=-1.0*Dot(y,z)/Len(z);//分别计算AP,BP在AB,BA上的投影
    return a+z*(len1/(len1+len2));//点A加上向量AF
}
inline Point Symmetry_PL(Point p,Point a,Point b){//【点P关于直线AB的对称点】
    return p+(FootPoint(p,a,b)-p)*2;//将PF延长一倍即可
}

/*3.【线与线】*/
inline Point cross_LL(Point a,Point b,Point c,Point d){//【两直线AB,CD的交点】
    Vector x=b-a,y=d-c,z=a-c;
    return a+x*(Cro(y,z)/Cro(x,y));//点A加上向量AF
}
inline int pan_cross_L_L(Point a,Point b,Point c,Point d){//【判断直线AB与线段CD是否相交】
    return pan_PL(cross_LL(a,b,c,d),c,d);//直线AB与直线CD的交点在线段CD上
}
inline int pan_cross_LL(Point a,Point b,Point c,Point d){//【判断两线段AB,CD是否相交】
    LD c1=Cro(b-a,c-a),c2=Cro(b-a,d-a);
    LD d1=Cro(d-c,a-c),d2=Cro(d-c,b-c);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(d1)*dcmp(d2)<0;//分别在两侧
}

/*4.【点与多边形】*/
inline int PIP(Point *P,Re n,Point a){//【射线法】判断点A是否在任意多边形Poly以内
    Re cnt=0;LD tmp;
    for(Re i=1;i<=n;++i){
        Re j=i<n?i+1:1;
        if(pan_PL(a,P[i],P[j]))return 2;//点在多边形上
        if(a.y>=min(P[i].y,P[j].y)&&a.y<max(P[i].y,P[j].y))//纵坐标在该线段两端点之间
            tmp=P[i].x+(a.y-P[i].y)/(P[j].y-P[i].y)*(P[j].x-P[i].x),cnt+=dcmp(tmp-a.x)>0;//交点在A右方
    }
    return cnt&1;//穿过奇数次则在多边形以内
}

#define rou(x) ((int)(x+0.5))

int n;
Point PP[N],P[N];
int tot=2,tl=1;
int ans;
#define li(x) (x>tl?x-1:tot)
#define ri(x) (x<tot?x+1:tl)
bool vis[N];
Point dwP(Point P){return P*(1/Len(P));}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=n;i>=1;i--){
        cin>>PP[i].x>>PP[i].y;
    }
    P[1]=PP[1];P[2]=PP[2];
    for(int i=3;i<=n;i++){
        while(i<=n&&(dwP((PP[i]-P[tot]))==dwP(P[tot]-P[tot-1])))tot--;
        P[++tot]=PP[i];
    }
    while((dwP((P[tot]-P[tot-1]))==dwP(P[tl]-P[tot])))tot--;
    while((dwP((P[tl+1]-P[tl]))==dwP(P[tl]-P[tot])))tl++;
    //!
    //for(int i=tl;i<=tot;i++)printf("%d:%d %d\n",i,rou(P[i].x),rou(P[i].y));//

    for(int i=tl;i<=tot;i++){
        if(P[li(i)].y<P[i].y||P[ri(i)].y<P[i].y||vis[i])continue;
        else if(rou(P[li(i)].y)==rou(P[i].y)||rou(P[ri(i)].y)==rou(P[i].y)){
            int l=i,r=i;
            while(rou(P[li(l)].y)==rou(P[l].y))l=li(l);
            while(rou(P[ri(r)].y)==rou(P[r].y))r=ri(r);
            
            for(int i=l;i!=ri(r);i=ri(i))vis[i]=1;

            Point pz=P[l]+(P[r]-P[l])*0.5;
            Point che=P[li(l)]-pz+P[ri(r)]-pz;
            che=che*(1/(2*Len(che)));
            che=che+pz;
            if(P[li(l)].y>P[i].y&&P[ri(r)].y>P[i].y&&PIP(P,tot,che)==1){
                ans++;
            }
            //printf("%d:%d %d\tot",i,l,r);
        }else{
            Point che=P[li(i)]-P[i]+P[ri(i)]-P[i];
            che=che*(1/(2*Len(che)));
            che=che+P[i];
            if(PIP(P,tot,che)==1){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}