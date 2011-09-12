#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char dayOfWeeks[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ys[8000], ms[12];

int main() {
    int cy=0;
    rep(i, 8000) {
        ys[i]=cy;
        cy += 365+(i%400==0 || (i%4==0 && i%100!=0));
    }
    for(;;) {
        int d;
        scanf("%d", &d);
        if(d==-1) return 0;
        int dd=d;
        int y=upper_bound(ys, ys+8000, dd)-ys-1;
        dd -= ys[y];
        int cm=0;
        rep(i, 12) {
            ms[i]=cm;
            cm += daysOfMonth[i]+(i==1 && (y%400==0 || (y%4==0 && y%100!=0)));
        }
        int m=upper_bound(ms, ms+12, dd)-ms-1;
        dd -= ms[m];
        printf("%04d-%02d-%02d %s\n", y+2000, m+1, dd+1, dayOfWeeks[(d+6)%7]);
    }
}

