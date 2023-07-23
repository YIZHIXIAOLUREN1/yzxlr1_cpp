#include<bits/stdc++.h>
using namespace std;


inline int read(){
    int res=0,f=1;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return res*f;
}