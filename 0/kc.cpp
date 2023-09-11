#include<bits/stdc++.h>
using namespace std;
#define print(x) if(x==0)putchar('0');else write(x)
inline int read1(){
    register int x=0,f=1;register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
inline void read2(register int &x){
    x=0;register int f=1;register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}//判断负数
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    //其中(x<<3)+(x<<1)等价于x*10,(c^48)等价于c-'0'
    x*=f;
}
inline void write(register int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
