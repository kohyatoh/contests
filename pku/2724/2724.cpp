#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    int w, h, m;
    vector<int> head, to, next;

    int cvis;
    vector<int> mat, vis;

    BiMatching(int _w, int _h) : w(_w), h(_h), m(0), head(_w+_h, -1) {}
    void add(int s, int t) {
        t += w;
        to.push_back(t);
        next.push_back(head[s]);
        head[s] = m;
        m++;
    }
    bool rec(int at) {
        if(at<0) return true;
        for(int x=head[at]; x!=-1; x=next[x]) if(vis[to[x]]!=cvis) {
            vis[to[x]] = cvis;
            if(rec(mat[to[x]])) {
                mat[at] = to[x];
                mat[to[x]] = at;
                return true;
            }
        }
        return false;
    }
    int match() {
        mat = vector<int>(w+h, -1);
        vis = vector<int>(w+h, -1);
        int r = 0;
        rep(i, w) {
            cvis = i;
            if(rec(i)) r++;
        }
        return r;
    }
};

int parse(char *p) {
    int a = 0;
    while(*p) { a = a*2+*p-'0'; p++; }
    return a;
}

int bitcount(int a) {
    int c = 0;
    while(a) { a &= a-1; c++; }
    return c;
}

int diff(int a, int b) { return bitcount(a^b); }

int main() {
    for(;;) {
        int n, m;
        scanf(" %d%d", &n, &m);
        if(n==0) return 0;
        vector<int> v, a, b;
        char buf[32];
        rep(_, m) {
            scanf("%s", buf);
            rep(i, n) if(buf[i]=='*') {
                buf[i] = '0';
                v.push_back(parse(buf));
                buf[i] = '1';
            }
            v.push_back(parse(buf));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        rep(i, v.size()) {
            if(bitcount(v[i])%2) a.push_back(v[i]);
            else b.push_back(v[i]);
        }
        BiMatching bm(a.size(), b.size());
        rep(i, a.size()) rep(j, b.size()) {
            if(diff(a[i], b[j])==1) bm.add(i, j);
        }
        printf("%d\n", (int)v.size()-bm.match());
    }
}
