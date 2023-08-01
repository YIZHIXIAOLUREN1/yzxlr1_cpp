#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
template<int set_,int mod>
struct trie{
    struct node{
        node* son[set_];
        int flag;
    };
    node* root,*ctrl_c;
    inline void init(){
        clear(root);
        root=new node(),ctrl_c=root;
    }
    inline void insert(string line){
        root=ctrl_c;
        for(int i=0;i<line.length();i++){
            if(root->son[line[i]%mod]==NULL){
                root->son[line[i]%mod]=new node(),root->son[line[i]%mod]->flag=0;
            }
            root=root->son[line[i]%mod];
        }
        root->flag++,root=ctrl_c;
    }
    inline int count(string line){
        root=ctrl_c;
        for(int i=0;i<line.length();i++){
            if(root->son[line[i]%mod]==NULL){
                root=ctrl_c;
                return false;
            }
            root=root->son[line[i]%mod];
        }
        return root->flag;
    }
    inline void del(string line){
        root=ctrl_c;
        for(int i=0;i<line.length();i++){
            if(root->son[line[i]%mod]==NULL){
                root=ctrl_c;
                return;
            }
            root=root->son[line[i]%mod];
        }
        root->flag=(root->flag==0?0:root->flag-1);
    }
    void clear(node* now){
        if(now==NULL) return;
        for(int i=0;i<set_;i++) if(now->son[i]!=NULL) clear(now->son[i]);
        delete now;
    } 
};
