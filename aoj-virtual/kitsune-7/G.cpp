#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef complex<int> P;

vector<string> expr(), term(), factor();
string psrc;
unsigned pix;

char token() {
    return pix < psrc.size() ? psrc[pix] : 0;
}

vector<string> parse(const string& s) {
    psrc = s;
    pix = 0;
    vector<string> r(expr());
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    reverse(r.begin(), r.end());
    while (r.size() && r.back() == "") r.pop_back();
    reverse(r.begin(), r.end());
    return r;
}

vector<string> expr() {
    vector<string> a(term());
    while (token() == '|') {
        pix++;
        vector<string> b(term());
        rep (i, b.size()) a.push_back(b[i]);
    }
    return a;
}

vector<string> term() {
    vector<string> a(factor());
    while (token() == '1' || token() == '(' || islower(token())) {
        vector<string> b(factor()), r;
        rep (i, a.size()) rep (j, b.size()) r.push_back(a[i]+b[j]);
        r.swap(a);
    }
    return a;
}

vector<string> factor() {
    if (token() == '(') {
        pix++;
        vector<string> r(expr());
        assert(token() == ')');
        pix++;
        return r;
    }
    else if (token() == '1') {
        pix++;
        return vector<string>(1, string());
    }
    else {
        assert(islower(token()));
        const char ch = token();
        pix++;
        return vector<string>(1, string(1, ch));
    }
}

struct Trie {
    Trie *next[32];
    bool end;
    Trie() : end(false) { memset(next, 0, sizeof(next)); }
    ~Trie() { rep (i, 32) if (next[i]) delete next[i]; }

    static Trie* build(const vector<string>& ss) {
        Trie *root = new Trie();
        rep (k, ss.size()) {
            Trie *t = root;
            rep (i, ss[k].size()) {
                const int ix = ss[k][i] - 'a';
                if (t->next[ix] == NULL) t->next[ix] = new Trie();
                t = t->next[ix];
            }
            t->end = true;
        }
        return root;
    }

    bool contains(const string& s) {
        Trie *t = this;
        rep (i, s.size()) {
            const int ix = s[i] - 'a';
            if (t->next[ix] == NULL) return false;
            t = t->next[ix];
        }
        return t->end;
    }
};

pair<bool, bool> rel(const vector<string> &rs1, const vector<string>& rs2) {
    Trie *t = Trie::build(rs2);
    bool all = true, some = false;
    rep (i, rs1.size()) {
        if (t->contains(rs1[i])) some = true; else all = false;
    }
    delete t;
    return mp(all, some);
}

int main() {
    char buf[128];
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", buf);
        const vector<string> rs1(parse(buf));
        assert(rs1.size() > 0 && rs1[0] != "");
        scanf(" %s", buf);
        const vector<string> rs2(parse(buf));
        assert(rs2.size() > 0 && rs2[0] != "");
//        printf("=====\n");
//        rep (i, rs1.size()) printf("%s\n", rs1[i].c_str());
//        printf("---\n");
//        rep (i, rs2.size()) printf("%s\n", rs2[i].c_str());
        const pair<bool, bool> a = rel(rs1, rs2);
        const pair<bool, bool> b = rel(rs2, rs1);
        if (a.first && b.first) puts("=");
        else if (a.first) puts("<");
        else if (b.first) puts(">");
        else if (a.second || b.second) puts("1");
        else puts("0");
    }
    return 0;
}
