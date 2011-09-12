#include <stdio.h>

char s[100500], t[100500];

int main() {
    while(scanf("%s%s", s, t)!=EOF) {
        char *p, *q;
        for(p=s, q=t; *p; p++,q++) {
            while(*q && *p!=*q) q++;
            if(*q==0) break;
        }
        puts(*p ? "No" : "Yes");
    }
    return 0;
}

