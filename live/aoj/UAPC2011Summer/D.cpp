#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int v[6], c[3], x[3], r[3];

int main() {
    for(;;) {
        rep(i, 6) scanf("%d", v+i);
        if(*max_element(v, v+6)==0) return 0;
        c[0] = v[0]+v[3];
        c[1] = v[1]+v[4];
        c[2] = v[2]+v[5];
        rep(i, 3) x[i] = c[i]/3;
        rep(i, 3) r[i] = c[i]%3;
        int add = 0;
        int k = 0;
        rep(i, 3) if(r[i]) k++;
        if(k==3) {
            add = 3;
            rep(i, 3) add = min(add, r[i]);
        }
        else if(k==2) {
            if(r[0]+r[1]+r[2]==4) rep(i, 3) if(r[i]==0 && x[i]>0) {
                x[i]--;
                add += 2;
                break;
            }
        }
        printf("%d\n", x[0]+x[1]+x[2]+add);
    }
}

