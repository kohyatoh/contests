#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

int tbl[5][3] = {
    { 10, 6, 2 },
    { 25, 15, 5 },
    { 53, 33, 13 },
    { 87, 47, 17 },
    { 144, 80, 30 },
};
int p[5] = { 0, 8*60, 18*60, 22*60, 24*60 };

int intersect(int a, int b, int c, int d) {
    return max(0, min(b, d)-max(a, c));
}

char c, s[10];
int h1, m1, h2, m2, t1, t2, u[4], y;

int main() {
    for(;;) {
        scanf(" %c", &c);
        if(c=='#') return 0;
        scanf("%s%d%d%d%d", s, &h1, &m1, &h2, &m2);
        t1=h1*60+m1, t2=h2*60+m2;
        if(t1==t2) rep(i, 4) u[i]=p[i+1]-p[i];
        else if(t1<t2) rep(i, 4) u[i]=intersect(t1, t2, p[i], p[i+1]);
        else rep(i, 4) u[i]=p[i+1]-p[i]-intersect(t2, t1, p[i], p[i+1]);
        u[3] += u[0];
        y = 0;
        rep(i, 3) y += tbl[c-'A'][i]*u[i+1];
        printf("  %s%6d%6d%6d  %c%5d.%02d\n", s, u[1], u[2], u[3], c, y/100, y%100);
    }
}
