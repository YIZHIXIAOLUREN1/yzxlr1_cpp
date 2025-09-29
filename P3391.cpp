#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
mt19937 rnd;

struct node{
    node *ch[2];
    int cnt,siz;
    int val;
    int prio;
    node (int _val):val(_val),cnt(1),siz(1){
        ch[0]=ch[1]=nullptr;
        prio=rnd();
    }

    //
    void pushdown(){}
};

pair<node *,node *> split_val(node *cur,int val){
    
    if(cur->val <=val){
        
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
}
