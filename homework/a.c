#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int pi[256];
void build(char *p,int m){
    int i=1,j=0;pi[0]=0;
    while(i<m){
        if(p[i]==p[j]) pi[i++]=++j;
        else if(j) j=pi[j-1];
        else pi[i++]=0;
    }
}
int kmp(char *t,int n,char *p,int m){
    int i=0,j=0;
    while(i<n){
        if(t[i]==p[j]){i++;j++; if(j==m) return 1;}
        else if(j) j=pi[j-1];
        else i++;
    }
    return 0;
}
int main(void){
    char s[256],t[256],p[256];
    if(!fgets(s,sizeof s,stdin)) return 0;
    if(!fgets(t,sizeof t,stdin)) return 0;
    int ln=strlen(s); if(ln&&s[ln-1]=='\n') s[--ln]=0;
    ln=strlen(s);
    int lt=strlen(t); if(lt&&t[lt-1]=='\n') t[--lt]=0;
    int n=strlen(s),m=strlen(t);
    int L=(n<m)?n:m;
    int i,len,found=0;
    for(len=L;len>0 && !found;len--){
        for(i=0;i+len<=n && !found;i++){
            memcpy(p,s+i,len);
            p[len]=0;
            build(p,len);
            if(kmp(t,m,p,len)){ printf("%s\n",p); found=1; }
        }
    }
    if(!found) printf("No Answer\n");
    return 0;
}