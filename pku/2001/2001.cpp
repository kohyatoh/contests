#include <stdio.h>

int nx[30000][30];
int ct[30000];
int x;

char a[3000][100];

int main() {
    int n;
    x=1;
    for(n=0; gets(a[n]); n++) {
        ct[0]++;
        int cur=0;
        for(char *p=a[n]; *p; p++) {
            if(nx[cur][*p-'a']==0) { ct[x]=0; nx[cur][*p-'a']=x++; }
            cur=nx[cur][*p-'a'];
            ct[cur]++;
        }
    }
    for(int i=0; i<n; i++) {
        printf("%s ", a[i]);
        int cur=0;
        for(char *p=a[i]; *p; p++) {
            cur=nx[cur][*p-'a'];
            putchar(*p);
            if(ct[cur]==1) break;
        }
        putchar('\n');
    }
    return 0;
}

