#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int p;
char f[3000];

void draw(int r, int y, int o) {
    if(r==1) {
        f[p++]='X';
        if(o) f[p++]=0;
    }
    else {
        int d=1;
        rep(i, r-2) d*=3;
        if(y<d) {
            draw(r-1, y, 0);
            rep(k, d) f[p++]=' ';
            draw(r-1, y, o);
        }
        else if(y<d+d) {
            rep(k, d) f[p++]=' ';
            if(o) draw(r-1, y-d, 1);
            else {
                draw(r-1, y-d, 0);
                rep(k, d) f[p++]=' ';
            }
        }
        else {
            draw(r-1, y-d-d, 0);
            rep(k, d) f[p++]=' ';
            draw(r-1, y-d-d, o);
        }
    }
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==-1) return 0;
        int d=1;
        rep(i, n-1) d*=3;
        rep(y, d) {
            p=0;
            draw(n, y, 1);
            puts(f);
        }
        puts("-");
    }
}

