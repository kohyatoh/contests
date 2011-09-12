#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int w[10][3] = {
    {1, 0, 1}, {0, 0, 0}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0},
    {1, 1, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 1, 1}
};
const int h[10][4] = {
    {1, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 1, 1},
    {1, 0, 0, 1}, {1, 1, 0, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {1, 0, 1, 1},
};

void pw(int d, int k, int s) {
    putchar(' ');
    rep(i, s) putchar(w[d][k] ? '-' : ' ');
    putchar(' ');
}

void ph(int d, int k, int s) {
    putchar(h[d][k] ? '|' : ' ');
    rep(i, s) putchar(' ');
    putchar(h[d][k+2] ? '|' : ' ');
}

void pwl(const vector<int>& v, int k, int s) {
    rep(i, v.size()) {
        if(i>0) putchar(' ');
        pw(v[i], k, s);
    }
    putchar('\n');
}

void phl(const vector<int>& v, int k, int s) {
    rep(i, v.size()) {
        if(i>0) putchar(' ');
        ph(v[i], k, s);
    }
    putchar('\n');
}

int main() {
    for(int _q;; _q++) {
        int s, n;
        scanf("%d%d", &s, &n);
        if(s==0 && n==0) return 0;
        vector<int> v;
        do {
            v.push_back(n%10);
            n /= 10;
        } while(n);
        reverse(v.begin(), v.end());
        pwl(v, 0, s);
        rep(i, s) phl(v, 0, s);
        pwl(v, 1, s);
        rep(i, s) phl(v, 1, s);
        pwl(v, 2, s);
        puts("");
    }
}

