#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int R, G, B;
double dp[2][64][64][64];

int kount(int x1, int y1, int z1, int x2, int y2, int z2) {
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (z1 < 0) z1 = 0;
    x2++, y2++, z2++;
    if (x2 > R) x2 = R;
    if (y2 > G) y2 = G;
    if (z2 > B) z2 = B;
    return (x2-x1) * (y2-y1) * (z2-z1);
}

void add(double (*a)[64][64], int x1, int y1, int z1, int x2, int y2, int z2, double val) {
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (z1 < 0) z1 = 0;
    x2++, y2++, z2++;
    if (x2 > R) x2 = R;
    if (y2 > G) y2 = G;
    if (z2 > B) z2 = B;
    a[x1][y1][z1] += val;
    a[x2][y1][z1] -= val;
    a[x1][y2][z1] -= val;
    a[x2][y2][z1] += val;
    a[x1][y1][z2] -= val;
    a[x2][y1][z2] += val;
    a[x1][y2][z2] += val;
    a[x2][y2][z2] -= val;
}

void fix(double (*a)[64][64]) {
    rep (y, G) rep (z, B) {
        rep (x, R) a[x+1][y][z] += a[x][y][z];
    }
    rep (x, R) rep (z, B) {
        rep (y, G) a[x][y+1][z] += a[x][y][z];
    }
    rep (x, R) rep (y, G) {
        rep (z, B) a[x][y][z+1] += a[x][y][z];
    }
}

class RandomColoring {
public:
    double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
        memset(dp, 0, sizeof(dp));
        d1--;
        R = maxR;
        G = maxG;
        B = maxB;
        double (*cur)[64][64] = dp[0];
        double (*nxt)[64][64] = dp[1];
        cur[startR][startG][startB] = 1.0;
        rep (_, N-1) {
            memset(nxt, 0, sizeof(dp[0]));
            rep (i, maxR) rep (j, maxG) rep (k, maxB) {
                int c = kount(i-d2, j-d2, k-d2, i+d2, j+d2, k+d2);
                if (d1 >= 0) c -= kount(i-d1, j-d1, k-d1, i+d1, j+d1, k+d1);
                if (c <= 0) continue;
                add(nxt, i-d2, j-d2, k-d2, i+d2, j+d2, k+d2,
                        cur[i][j][k] / c);
                if (d1 >= 0) {
                    add(nxt, i-d1, j-d1, k-d1, i+d1, j+d1, k+d1,
                            - cur[i][j][k] / c);
                }
            }
            fix(nxt);
            swap(cur, nxt);
        }
        double ans = 0;
        rep (i, maxR) rep (j, maxG) rep (k, maxB) {
            const int x = abs(startR - i);
            const int y = abs(startG - j);
            const int z = abs(startB - k);
            if (x <= d2 && y <= d2 && z <= d2) {
                if (x > d1 || y > d1 || z > d1) {
                    ans += cur[i][j][k];
                }
            }
        }
        if (ans > 1) return 0;
        return 1 - ans;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
