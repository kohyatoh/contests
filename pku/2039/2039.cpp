#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, h;
char s[1000];

int main() {
    for(;;) {
        scanf("%d", &w);
        if(w==0) return 0;
        scanf("%s", s);
        h = strlen(s)/w;
        rep(i, w) rep(j, h) putchar(j%2 ? s[w*j+w-1-i] : s[w*j+i]);
        putchar('\n');
    }
}
