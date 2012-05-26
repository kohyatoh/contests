#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int X, Y;

int calc(const vector<int>& xs, int p) {
    int cur = 0, h = p;
    rep (i, xs.size()) {
        if (xs[i]*p > X) return -1;
        if (cur + xs[i]*p > X) {
            cur = 0;
            h += p;
        }
        cur += xs[i]*p+p;
    }
    return h;
}

int solve(const vector<string>& ss) {
    vector<vector<int> > xss;
    rep (k, ss.size()) {
        vector<int> xs;
        int cur = 0;
        rep (i, ss[k].size()) if (ss[k][i] == ' ') {
            xs.push_back(i-cur);
            cur = i+1;
        }
        xss.push_back(xs);
    }
    for (int i = 28; i >= 8; i--) {
        int h = 0;
        rep (j, xss.size()) {
            const int k = calc(xss[j], i);
            if (k == -1) {
                h = -1;
                break;
            }
            h += k;
        }
        if (h == -1) continue;
        if (h <= Y) return i;
    }
    return -1;
}

int main() {
    string buf;
    getline(cin, buf);
    int T = atoi(buf.c_str());
    while (T--) {
        getline(cin, buf);
        const int n = atoi(buf.c_str());
        vector<string> ss;
        rep (i, n) {
            getline(cin, buf);
            while (isspace(buf[buf.size()-1])) buf.resize(buf.size()-1);
            buf += ' ';
            ss.push_back(buf);
        }
        getline(cin, buf);
        sscanf(buf.c_str(), "%d%d", &X, &Y);
        const int ans = solve(ss);
        if (ans == -1) puts("No solution");
        else printf("%d\n", ans);
    }
    return 0;
}
