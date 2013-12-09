#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <assert.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

double f(string t) {
    t = t + " ";
    int n = 0, s = 0;
    rep (i, t.size()-1) if (t[i] != ' ') {
        s++;
        if (t[i+1] == ' ') n++;
    }
    assert(n > 0);
//    printf("%d, %d, %f\n", s, n, s / (double)n);
    return s / (double)n;
}

int main() {
    string buf;
    getline(cin, buf);
    const int T = atoi(buf.c_str());
    rep (_, T) {
        getline(cin, buf);
        const double t = f(buf);
        getline(cin, buf);
        const int n = atoi(buf.c_str());
        vector<pair<double, int> > cs;
        vector<string> names;
        rep (i, n) {
            getline(cin, buf);
            const int ix = buf.find(':');
            const double g = f(buf.substr(ix+1));
            names.push_back(buf.substr(0, ix));
            cs.push_back(mp(fabs(g-t), i));
        }
        sort(cs.begin(), cs.end());
        cout << names[cs[0].second] << endl;
    }
    return 0;
}
