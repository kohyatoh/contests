#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <complex>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef complex<double> P;
typedef vector<P> convex;
#define EPS (1e-9)

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }

int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}

P projection(const P& l0, const P& l1, const P& p) {
    const double t = dot(p-l0, l1-l0) / norm(l1-l0);
    return l0 + t*(l1-l0);
}

bool intersectSP(const P& s0, const P& s1, const P& p) {
    return abs(s0-p)+abs(s1-p)-abs(s1-s0)<EPS;
}

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double a = cross(l1-l0, m1-m0);
    const double b = cross(l1-l0, l1-m0);
    if(abs(a)<EPS && abs(b)<EPS) return m0;
//    if(abs(a)<EPS) throw 0;
    return m0 + b/a*(m1-m0);
}

convex convex_cut(const convex& v, const P& l0, const P& l1) {
    convex r;
    rep(i, v.size()) {
        const P& a(v[i]), b(v[(i+1)%v.size()]);
        if(ccw(l0, l1, a)!=-1) r.push_back(a);
        if(ccw(l0, l1, a)*ccw(l0, l1, b)<0) {
            r.push_back(crosspoint(l0, l1, a, b));
        }
    }
    return r;
}

bool contains(const convex& ps, const P& p) {
    bool in = false;
    rep(i, ps.size()) {
        const int j = (i+1)%ps.size();
        P a(ps[i]-p), b(ps[j]-p);
        if(imag(a) > imag(b)) swap(a, b);
        if(imag(a) <= 0 && 0 < imag(b) && cross(a, b) < 0) in = !in;
        if(cross(a, b)==0 && dot(a, b) <= 0) return true; // on edge
    }
    return in;
}

bool intersectCVCV(const convex& a, const convex& b) {
    rep(i, a.size()) if(contains(b, a[i])) return true;
    rep(i, b.size()) if(contains(a, b[i])) return true;
    return false;
}

// convex and hinges
// hinges are represented by (1 + the index of the connected segment)
typedef pair<convex, vector<int> > segment;

int index(const convex& v, const P& s0, const P& s1) {
    const P& mid(0.5*(s0+s1));
    rep(i, v.size()) {
        const int j = (i+1)%v.size();
        if(intersectSP(v[i], v[j], mid)) return i;
    }
    return -1;
}

vector<segment> turnover(const vector<segment>& vs, P p, P q) {
    // first, determine which segments to turn over
    queue<int> qu;
    vector<int> is(vs.size(), 0);
    // rule 1
    for(int i=(int)vs.size()-1; i>=0; i--) if(contains(vs[i].first, p)) {
        qu.push(i);
        is[i] = 1;
        break;
    }
    P m(0.5*(p+q));
    P dir((p-q)*P(0, 1));
    while(!qu.empty()) {
        const int ix = qu.front();
        qu.pop();
        const convex& cv = vs[ix].first;
        convex a(convex_cut(cv, m, m-dir));
        // rule 2
        rep(i, a.size()) {
            const int j = (i+1)%a.size();
            const int k = index(cv, a[i], a[j]);
            if(k==-1) continue;
            const int tx = vs[ix].second[k]-1;
            if(tx!=-1 && !is[tx]) {
                qu.push(tx);
                is[tx] = 1;
            }
        }
        // rule 3
        for(int i=ix+1; i<(int)vs.size(); i++) {
            if(!is[i] && intersectCVCV(a, vs[i].first)) {
                qu.push(i);
                is[i] = 1;
            }
        }
    }

    // second, turn over the segments
    // in this section, hinges are left untouched, except for:
    //   hinges to segment in `s` -> positive
    //   hinges to segment in `t` -> negative
    vector<pair<int, segment> > s, t;
    rep(k, vs.size()) {
        if(is[k]==0) s.push_back(mp(k+1, vs[k]));
        else {
            const convex& cv = vs[k].first;
            convex a(convex_cut(cv, m, m+dir));
            if(a.size()>0) {
                vector<int> hg;
                rep(i, a.size()) {
                    const int j = (i+1)%a.size();
                    const int ix = index(cv, a[i], a[j]);
                    hg.push_back(ix==-1 ? -(k+1) : vs[k].second[ix]);
                }
                s.push_back(mp(k+1, mp(a, hg)));
            }
            convex b(convex_cut(cv, m, m-dir));
            if(b.size()>0) {
                vector<int> hg;
                rep(i, b.size()) {
                    const int j = (i-1+b.size())%b.size();
                    const int ix = index(cv, b[i], b[j]);
                    const P to = 2.0*projection(m, m+dir, b[i])-b[i];
                    hg.push_back(ix==-1 ? k+1 : -vs[k].second[ix]);
                }
                rep(i, b.size()) b[i] = 2.0*projection(m, m+dir, b[i])-b[i];
                reverse(b.begin(), b.end());
                reverse(hg.begin(), hg.end());
                t.push_back(mp(k+1, mp(b, hg)));
            }
        }
    }

    // third, fix the hinges
    map<int, int> of;
    rep(i, s.size()) of[s[i].first] = i+1;
    rep(i, t.size()) of[-t[i].first] = s.size()+t.size()-i;
    vector<segment> r;
    rep(i, s.size()) r.push_back(s[i].second);
    rep(i, t.size()) r.push_back(t[t.size()-1-i].second);
    rep(i, r.size()) rep(j, r[i].second.size()) {
        r[i].second[j] = of[r[i].second[j]];
    }
    return r;
}

int N, Px[16], Py[16], Qx[16], Qy[16];
int Hx, Hy;

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N==0) return 0;
        rep(i, N) scanf("%d%d%d%d", Px+i, Py+i, Qx+i, Qy+i);
        scanf("%d%d", &Hx, &Hy);
        convex v;
        v.push_back(P(0, 0)); v.push_back(P(100, 0));
        v.push_back(P(100, 100)); v.push_back(P(0, 100));
        vector<segment> vs;
        vs.push_back(mp(v, vector<int>(v.size())));
        rep(i, N) vs = turnover(vs, P(Px[i], Py[i]), P(Qx[i], Qy[i]));
        int ans = 0;
        rep(i, vs.size()) if(contains(vs[i].first, P(Hx, Hy))) ans++;
        printf("%d\n", ans);
    }
}
