#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

#define NUM (120000)
#define DAY (4000000)
int N, Q, t[NUM], x[NUM], y[NUM];
Int w[NUM];
int s[NUM];
Int val[NUM];
vector<int> ev[DAY];
Int a, b, c;

void enq(int ix, int d) {
    if (t[ix] == 0) c++;
    else if (t[ix] == 1) b++, c -= d;
    else a++, b -= 2*d, c += (Int)d*d;
    s[ix] = d;
    ev[d+x[ix]].push_back(ix);
}

void deq(int ix) {
    if (t[ix] == 0) c--;
    else if (t[ix] == 1) b--, c += s[ix];
    else a--, b += 2*s[ix], c -= (Int)s[ix]*s[ix];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    rep (i, N) cin >> w[i] >> t[i] >> x[i];
    rep (i, Q) cin >> y[i];
    rep (i, N) s[i] = DAY;
    int p = 0, q = 0;
    Int cur = 0;
    for (int d = 0; d < DAY; d++) {
        cur += a*d*d + b*d + c;
        if (d == 0) c++;
        while (p < N && w[p] <= cur) enq(p++, d);
        rep (i, ev[d].size()) deq(ev[d][i]);
        while (q < Q && y[q] == d) val[q++] = cur;
    }
    rep (i, N) {
        if (s[i] > 3652425) cout << "Many years later" << endl;
        else cout << s[i] << endl;
    }
    rep (i, Q) cout << val[i] << endl;
    return 0;
}
