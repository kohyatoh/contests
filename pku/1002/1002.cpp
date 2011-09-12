#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
char f[27] = "2223334445556667-77888999-";
int v[1000001];

int main() {
    int n=0;
    char ch;
    while((ch=getchar())!='\n') n=n*10+ch-'0';
    rep(i, n) {
        while((ch=getchar())!='\n') if(ch!='-') {
            if('0'<=ch && ch<='9') v[i]=v[i]*10+ch-'0';
            else v[i]=v[i]*10+f[ch-'A']-'0';
        }
    }
    sort(v, v+n);
    v[n]=-1;
    int s=0, c=0, p=-1;
    rep(i, n+1) {
        if(v[i]==p) c++;
        else {
            if(c>0) {
                printf("%03d-%04d %d\n", p/10000, p%10000, c+1);
                s++;
            }
            c=0;
            p=v[i];
        }
    }
    if(s==0) printf("No duplicates.\n");
    return 0;
}

