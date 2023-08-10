#include<bits/stdc++.h>
using namespace std;
#define db double
#define mid ((l+r)>>1)
#define ll long long
const int N=1e6+7;
int T;
int n;
int rt,rn;
int tot=1,num=1;
int cz[N];
int la,ma;
int as,ax=1;

bool check(int x){
	//printf("c%d:",x);//
    tot=num=1;
    for(int i=1;i<=n;i++){
        if(cz[i]==1||(cz[i]==0&&x))tot++,num++;
        else if(num<2)return 0;
        else num--;
    }
    if(num<1)return 0;
    //if(((db)as/ax)<((db)tot/num))as=tot,ax=num;
    //printf("y");//
    return 1;
}

int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
    	ma=0;
    	as=0,ax=1;
        rt=rn=1;
        tot=num=1;
        cin >> n;
        //cout << "A";//
        for(int i=1;i<=n;i++){
            cin >> cz[i];
            if(cz[i]==0)ma++;
            else if(cz[i]==-1)rn--;
            else rt++,rn++;
        }
        int l=0,r=ma;
        //l=max(l,((ma+1-rn)/2)-1);
        //cout << l;//
        while(l<r){
            if(!check(mid))l=mid+1;
            else r=mid-1;
            //printf("\n");//
        }
        while(!check(l)&&l<=ma)l++;
        while(l&&check(l-1))l--;
        if(l>ma){
            cout << "-1" << "\n";
            continue;
        }
        cout << l << ":\n";//
        for(int i=l;i<=ma;i++){
            tot=rt,num=rn;
            tot+=i,num+=2*i-ma;
            if(num<1)continue;
            printf("%d:%d %d\n",i,tot,num);//
            if(((db)as/ax)<((db)tot/num)){
            	as=tot,ax=num;
            	break;
            	//printf("%d:%d %d\n",i,as,ax);//
            }
        }
		
        int tt=gcd(as,ax);
        cout << as/tt << " " << ax/tt << "\n";

    }
}
