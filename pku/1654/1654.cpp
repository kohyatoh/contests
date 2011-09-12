#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef long long Int;

Int cross(Int x0, Int y0, Int x1, Int y1) { return x0*y1-x1*y0; }

char f[1200000];

int main() {
    gets(f);
    int T = atoi(f);
    while(T--) {
        gets(f);
        Int x=0, y=0, s=0;
        for(char *p=f; *p!='5'; p++) {
            const int d = *p-'1', dx = d%3 - 1, dy = d/3 - 1;
            s += cross(x, y, x+dx, y+dy);
            x += dx, y += dy;
        }
        if(s<0) s = -s;
        if(s%2) cout << s/2 << ".5" << endl;
        else cout << s/2 << endl;
    }
    return 0;
}
