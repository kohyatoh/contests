#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int n, m;
string ops[2][32];
int args[2][32][3];

void readp(int n, int ix) {
    rep (i, n) {
        cin >> ops[ix][i];
        if (ops[ix][i][0] != 'I') {
            string a, b;
            cin >> a >> b;
            args[ix][i][0] = atoi(a.c_str()+1);
            args[ix][i][1] = atoi(b.c_str()+1);
        }
        else if (ops[ix][i][1] == 'N') {
            string a;
            cin >> a;
            args[ix][i][0] = atoi(a.c_str()+1);
        }
        else {
            string a, b, c;
            cin >> a >> b >> c;
            args[ix][i][0] = atoi(a.c_str()+1);
            args[ix][i][1] = atoi(b.c_str()+1);
            args[ix][i][2] = atoi(c.c_str());
        }
    }
    ops[ix][n] = "END";
}

set<int> vis, ans;

void visit(int sig) {
    if (vis.count(sig)) return ;
    vis.insert(sig);
    int w = sig, op[2], oa[5];
    rep (i, 5) {
        oa[4-i] = w % 4;
        w /= 4;
    }
    op[0] = w / m, op[1] = w % m;
    assert(0 <= op[0] && op[0] < n);
    assert(0 <= op[1] && op[1] < m);
    rep (i, 5) assert(0 <= oa[i] && oa[i] < 4);
//    printf("%d, %d. %d %d %d %d %d\n", op[0], op[1], oa[0], oa[1], oa[2], oa[3], oa[4]);
    int no = 0;
    rep (ix, 2) {
        int p[2], a[5];
        rep (i, 2) p[i] = op[i];
        rep (i, 5) a[i] = oa[i];
        int r1 = args[ix][p[ix]][0];
        int r2 = args[ix][p[ix]][1];
        int r3 = args[ix][p[ix]][2];
        if (ops[ix][p[ix]][0] == 'E') {
            no++;
            continue;
        }
        else if (ops[ix][p[ix]][0] == 'M') a[r1] = a[r2], p[ix]++;
        else if (ops[ix][p[ix]][0] == 'A') a[r1] = (a[r1] + a[r2]) % 4, p[ix]++;
        else if (ops[ix][p[ix]][0] == 'T') {
            int tm = a[r1];
            a[r1] = 1;
            a[r2] = tm;
            p[ix]++;
        }
        else if (ops[ix][p[ix]][1] == 'N') {
            a[r1] = (a[r1] + 1) % 4;
            p[ix]++;
        }
        else {
            if (a[r1] < a[r2]) {
                p[ix] += r3;
            }
            else {
                p[ix]++;
            }
        }
        int s2 = p[0] * m + p[1];
        rep (i, 5) s2 = s2 * 4 + a[i];
        visit(s2);
    }
    if (no == 2) ans.insert(sig);
}

int main() {
    int T;
    cin >> T;
    rep (_, T) {
        cin >> n;
        readp(n, 0);
        cin >> m;
        readp(m, 1);
        vis.clear();
        ans.clear();
        n++, m++;
        visit(0);
//        cout << vis.size() << endl;
        cout << ans.size() << endl;
    }
    return 0;
}
