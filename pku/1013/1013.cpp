#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int c[12], u[12];

void f(char *a, char *b, char *w) {
    const int n = strlen(a);
    memset(u, 0, sizeof(u));
    rep(i, n) u[a[i]-'A'] = u[b[i]-'A'] = 1;
    if(w[0]=='e') rep(i, n) c[a[i]-'A'] = c[b[i]-'A'] = 0;
    else rep(i, 12) if(u[i]==0) c[i] = 0;
    if(w[0]=='u') {
        rep(i, n) c[a[i]-'A'] &= ~1;
        rep(i, n) c[b[i]-'A'] &= ~2;
    }
    if(w[0]=='d') {
        rep(i, n) c[a[i]-'A'] &= ~2;
        rep(i, n) c[b[i]-'A'] &= ~1;
    }
}

int main() {
    char a[8], b[8], w[8];
    int T;
    scanf("%d", &T);
    while(T--) {
        rep(i, 12) c[i] = 3;
        rep(_, 3) {
            scanf("%s%s%s", a, b, w);
            f(a, b, w);
        }
        rep(i, 12) {
            if(c[i]&1) {
                printf("%c is the counterfeit coin and it is light.\n", i+'A');
            }
            if(c[i]&2) {
                printf("%c is the counterfeit coin and it is heavy.\n", i+'A');
            }
        }
    }
    return 0;
}
