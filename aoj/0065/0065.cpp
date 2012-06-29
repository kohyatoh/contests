#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    map<int, int> cnt, f;
    vector<int> xs;
    string buf;
    int t = 1;
    while (getline(cin, buf)) {
        if (buf.size() == 0) { t++; continue; }
        int id, _;
        sscanf(buf.c_str(), "%d,%d", &id, &_);
        cnt[id]++;
        f[id] |= t;
        xs.push_back(id);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    rep (i, xs.size()) if (f[xs[i]] == 3) {
        printf("%d %d\n", xs[i], cnt[xs[i]]);
    }
    return 0;
}
