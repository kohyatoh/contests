#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const char *dat = "+-*";

string s(int a) { return string(1, (char)('0'+a)); }

int op(int t, int a, int b) {
    if (t == 0) return a+b;
    if (t == 1) return a-b;
    if (t == 2) return a*b;
    return 0;
}

string op(int t, const string& a, const string& b) {
    if (t == 0) return "(" + a + " + " + b + ")";
    if (t == 1) return "(" + a + " - " + b + ")";
    if (t == 2) return "(" + a + " * " + b + ")";
    return "";
}

int seq(int *a, int *b) {
    int t = a[0];
    rep (i, 3) t = op(b[i], t, a[i+1]);
    return t;
}

string mseq(int *a, int *b) {
    string t = s(a[0]);
    rep (i, 3) t = op(b[i], t, s(a[i+1]));
    return t;
}

int tre(int *a, int *b) {
    return op(b[1], op(b[0], a[0], a[1]), op(b[2], a[2], a[3]));
}

string mtre(int *a, int *b) {
    return op(b[1], op(b[0], s(a[0]), s(a[1])), op(b[2], s(a[2]), s(a[3])));
}

int main() {
    for (;;) {
        int a[4], b[3];
        rep (i, 4) scanf("%d", a+i);
        if (a[0]+a[1]+a[2]+a[3] == 0) return 0;
        sort(a, a+4);
        string ans = "0";
        do {
            rep (t, 3*3*3) {
                int p = t;
                rep (i, 3) {
                    b[i] = p % 3;
                    p /= 3;
                }
                if (seq(a, b) == 10) ans = mseq(a, b);
                if (tre(a, b) == 10) ans = mtre(a, b);
                if (ans.size() > 1) goto end;
            }
        } while (next_permutation(a, a+4));
end:
        cout << ans << endl;
    }
}
