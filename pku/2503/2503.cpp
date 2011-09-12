#include <stdio.h>
#include <string>
#include <map>
using namespace std;

char buf[80], s[80];
char en[100000][30];
int nx[300000][30];
int si[300000];

int main() {
    map<string, string> m;
    int x=1;
    for(int i=0;; i++) {
        gets(buf);
        if(!*buf) break;
        sscanf(buf, "%s %s", en[i], s);
        int cur=0;
        for(char *p=s; *p; p++) {
            if(nx[cur][*p-'a']==0) nx[cur][*p-'a']=x++;
            cur=nx[cur][*p-'a'];
        }
        si[cur]=i+1;
    }
    while(gets(s)) {
        int cur=0;
        for(char *p=s; *p; p++) {
            if(nx[cur][*p-'a']==0) { cur=0; break; }
            cur=nx[cur][*p-'a'];
        }
        if(cur && si[cur]>0) printf("%s\n", en[si[cur]-1]);
        else printf("eh\n");
    }
}

