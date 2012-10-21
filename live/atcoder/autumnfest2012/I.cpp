#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

#define P   (1000000007LL)
#define MOD (1000000009LL)
#define B (1024)

int n, m, Q;
int cv_1[B*3][B*3], cv_0[B*3][B*3];
int ch_1[B*3][B*3], ch_0[B*3][B*3];
int f[B*3][B*3], w[B*3][B*3];
Int Amul, Aadd;
Int Bmul, Badd;
Int Dmul, Dadd;

int main() {
    cin >> n >> m >> Q;
    int a1, b1, d1;
    cin >> a1 >> Amul >> Aadd;
    cin >> b1 >> Bmul >> Badd;
    cin >> d1 >> Dmul >> Dadd;
    /* a */
    int a = a1, b = b1, d = d1;
    memset(cv_1, 0, sizeof(cv_1));
    memset(cv_0, 0, sizeof(cv_0));
    memset(ch_1, 0, sizeof(ch_1));
    memset(ch_0, 0, sizeof(ch_0));
    rep (_, Q) {
        w[B+a][B+b] += d;

        cv_1[B+a-d][B+b] += 1;
        cv_0[B+a-d][B+b] += -(B+a-d);
        cv_1[B+a][B+b] -= 1;
        cv_0[B+a][B+b] -= -(B+a-d);
        ch_1[B+a][B+b-d] -= 1;
        ch_0[B+a][B+b-d] -= -(B+b-d);
        ch_1[B+a][B+b] += 1;
        ch_0[B+a][B+b] += -(B+b-d);

        ch_1[B+a+1][B+b] += -1;
        ch_0[B+a+1][B+b] += (B+b)+d-1;
        ch_1[B+a+1][B+b+d] -= -1;
        ch_0[B+a+1][B+b+d] -= (B+b)+d-1;
        cv_1[B+a+2][B+b-1] -= -1;
        cv_0[B+a+2][B+b-1] -= (B+a+2)+d-1;
        cv_1[B+a+2+d][B+b-1] += -1;
        cv_0[B+a+2+d][B+b-1] += (B+a+2)+d-1;

//        printf("%d, %d, %d\n", a, b, d);
        a = (a*Amul + Aadd) % n + 1;
        b = (b*Bmul + Badd) % m + 1;
        d = (d*Dmul + Dadd) % max(n, m) + 1;
    }
    memset(f, 0, sizeof(f));
    rep (j, B*3) {
        int c1 = 0, c0 = 0;
        rep (i, B*3) {
            c1 += cv_1[i][j], c0 += cv_0[i][j];
            f[i][j] += c1*i + c0;
        }
    }
    rep (i, B*3) {
        int c1 = 0, c0 = 0;
        rep (j, B*3) {
            c1 += ch_1[i][j], c0 += ch_0[i][j];
            f[i][j] += c1*j + c0;
        }
    }
//    rep (i, 20) { rep (j, 20) printf("%d ", f[i+B-10][j+B-10]); printf("\n"); }
    rep (i, B*3) rep (j, B*3) {
        if (i && j<B*3) f[i][j] += f[i-1][j+1];
        w[i][j] += f[i][j];
    }

    /* b */
    a = a1, b = b1, d = d1;
    memset(cv_1, 0, sizeof(cv_1));
    memset(cv_0, 0, sizeof(cv_0));
    memset(ch_1, 0, sizeof(ch_1));
    memset(ch_0, 0, sizeof(ch_0));
    rep (_, Q) {
        ch_1[B+a][B+b-d] += 1;
        ch_0[B+a][B+b-d] += -(B+b-d);
        ch_1[B+a][B+b] -= 1;
        ch_0[B+a][B+b] -= -(B+b-d);
        cv_1[B+a+1][B+b] -= -1;
        cv_0[B+a+1][B+b] -= B+a+1+d-1;
        cv_1[B+a+1+d][B+b] += -1;
        cv_0[B+a+1+d][B+b] += B+a+1+d-1;

        cv_1[B+a+1-d][B+b+1] += 1;
        cv_0[B+a+1-d][B+b+1] += -(B+a+1-d);
        cv_1[B+a+1][B+b+1] -= 1;
        cv_0[B+a+1][B+b+1] -= -(B+a+1-d);
        ch_1[B+a+1][B+b+2] -= -1;
        ch_0[B+a+1][B+b+2] -= B+b+2+d-1;
        ch_1[B+a+1][B+b+2+d] += -1;
        ch_0[B+a+1][B+b+2+d] += B+b+2+d-1;

//        printf("%d, %d, %d\n", a, b, d);
        a = (a*Amul + Aadd) % n + 1;
        b = (b*Bmul + Badd) % m + 1;
        d = (d*Dmul + Dadd) % max(n, m) + 1;
    }
    memset(f, 0, sizeof(f));
    rep (j, B*3) {
        int c1 = 0, c0 = 0;
        rep (i, B*3) {
            c1 += cv_1[i][j], c0 += cv_0[i][j];
            f[i][j] += c1*i + c0;
        }
    }
    rep (i, B*3) {
        int c1 = 0, c0 = 0;
        rep (j, B*3) {
            c1 += ch_1[i][j], c0 += ch_0[i][j];
            f[i][j] += c1*j + c0;
        }
    }
//    printf("====\n");
//    rep (i, 20) { rep (j, 20) printf("%d ", f[i+B-10][j+B-10]); printf("\n"); }
    rep (i, B*3) rep (j, B*3) {
        if (i && j) f[i][j] += f[i-1][j-1];
        w[i][j] += f[i][j];
    }

    /* c */
//    printf("====\n");
//    rep (i, 20) { rep (j, 20) printf("%d ", w[i+B-10][j+B-10]); printf("\n"); }
    Int ans = 0;
    rep (i, B*3) rep (j, B*3) {
        if (1 <= i-B && i-B <= n && 1 <= j-B && j-B <= m) {
            ans = (ans * P + w[i][j]) % MOD;
//            printf("%d ", w[i][j]);
        }
//        if (1 <= i-B && i-B <= n && j == B*2-1) printf("\n");
    }
    cout << ans << endl;
    return 0;
}
