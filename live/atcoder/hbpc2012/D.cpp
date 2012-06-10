#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define INF (1<<30)

int n, m, r;
int draw, vis[16][16][4][16][16][4];
int memo[16][16][4][16][16][4];

struct S {
    int a, b, q;
    S() {}
    S(int a, int b, int q) : a(a), b(b), q(q) {}
};

int f(int a, int b) {
    const int k = a + b;
    if (k < n) return k;
    else return r ? k - n : 0;
}

void up(int &w, int &o, int v) {
    if (v <= 0) w = min(w, -v+1);
    else o = max(o, v+1);
}

int rec(int a1, int b1, int q1, int a2, int b2, int q2) {
    if (a1 == 0 && b1 == 0) return 0;
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
//    printf("%d, %d, %d, %d, %d, %d\n", a1, b1, q1, a2, b2, q2);
    int &v = vis[a1][b1][q1][a2][b2][q2];
    if (v) {
        draw = 1;
        return 0;
    }
    int &mem = memo[a1][b1][q1][a2][b2][q2];
    if (mem != 0) return mem;
    v = 1;
    int w = INF, o = 0;
    if (a1 != 0 && a2 != 0) up(w, o, rec(f(a1, a2), b2, q2, a1, b1, q1));
    if (draw) return 0;
    if (a1 != 0 && b2 != 0) up(w, o, rec(f(a1, b2), a2, q2, a1, b1, q1));
    if (draw) return 0;
    if (b1 != 0 && a2 != 0) up(w, o, rec(f(b1, a2), b2, q2, a1, b1, q1));
    if (draw) return 0;
    if (b1 != 0 && b2 != 0) up(w, o, rec(f(b1, b2), a2, q2, a1, b1, q1));
    if (draw) return 0;
    if (a1 == 0 && b1 >= 2 && q1) {
        for (int i = 1; i < b1; i++) {
            up(w, o, rec(a2, b2, q2, i, b1-i, q1-1));
            if (draw) return 0;
        }
    }
    v = 0;
    if (w < INF) return mem = w;
    else return mem = -o;
}

int main() {
    cin >> n >> m >> r;
    const int ans = rec(1, 1, m, 1, 1, m);
    if (draw) puts("Infinite");
    else {
        puts(ans > 0 ? "First" : "Second");
        printf("%d\n", abs(ans));
    }
    return 0;
}
