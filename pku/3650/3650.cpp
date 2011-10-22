#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int es[256];
char s[128];
const char ts[8] = " !$%()*";

int main() {
    rep(i, 7) es[(int)ts[i]] = 1;
    for(;;) {
        gets(s);
        if(s[0]=='#') return 0;
        for(int i=0; s[i]; i++) {
            if(es[(int)s[i]]) printf("%%%02x", (int)s[i]);
            else putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}
