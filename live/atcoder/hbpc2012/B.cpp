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

int readT() {
    string s;
    cin >> s;
    int h, m;
    sscanf(s.c_str(), "%d:%d", &h, &m);
    return h*60+m;
}

#define T (24*60)

string cityA, cityB;
string hours[32];
int N;
string city1[32], city2[32];
int time1[32], time2[32];
int timeB;
int m;
map<string, int> ids;
vector<pair<int, int> > g[128];
int off[128];

void add(const string& s) {
    if (!ids.count(s)) ids[s] = m++;
}

int index(const string& s) {
    return ids[s];
}

void rec(int at, int t) {
    if (off[at] != -1) {
        assert(off[at] == t);
        return ;
    }
    off[at] = t;
    rep (i, g[at].size()) {
        const int nt = (t + g[at][i].second) % T;
        rec(g[at][i].first, nt);
    }
}

int main() {
    cin >> cityA;
    rep (i, 24) cin >> hours[i];
    cin >> N;
    rep (i, N) {
        cin >> city1[i];
        time1[i] = readT();
        cin >> city2[i];
        time2[i] = readT();
    }
    cin >> cityB;
    timeB = readT();
    add(cityA);
    add(cityB);
    rep (i, N) add(city1[i]), add(city2[i]);
    rep (i, N) {
        const int i1 = index(city1[i]);
        const int i2 = index(city2[i]);
        g[i1].push_back(mp(i2, (time2[i]-time1[i]+T)%T));
        g[i2].push_back(mp(i1, (time1[i]-time2[i]+T)%T));
    }
    memset(off, -1, sizeof(off));
    rec(index(cityA), 0);
    const int ans = (timeB - off[index(cityB)] + T) % T;
    cout << hours[ans/60] << endl;
    return 0;
}
