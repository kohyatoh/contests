#include <stdio.h>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
//#define LOG(a) (cerr<<__LINE__<<","#a":"<<(a)<<endl)
#define LOG(a) ((void)0)
#define EPS (1e-9)
typedef complex<double> P;

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0), B = cross(l1-l0, l1-m0);
    if(fabs(A)<EPS && fabs(B)<EPS) return m0;
    return m0+B/A*(m1-m0);
}
int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if(cross(b, c) > 0) return 1;
    if(cross(b, c) < 0) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
inline bool intersectSS(const P& l0, const P& l1, const P& m0, const P& m1) {
    return ccw(l0, l1, m0)*ccw(l0, l1, m1)<=0
        && ccw(m0, m1, l0)*ccw(m0, m1, l1)<=0;
}

struct seg {
    double y1, y2;
    seg(double y1, double y2) : y1(y1), y2(y2) {}
};
inline bool operator<(const seg& l, const seg& r) {
    return l.y1+l.y2 < r.y1+r.y2;
}

int N, X0[200], Y0[200], X1[200], Y1[200];
P p0[200], p1[200];

vector<vector<seg> > segs;
vector<vector<vector<pair<int, int> > > > g;
vector<vector<int> > color;
#define VOFFSET 150
vector<pair<int, int> > vert[300];

void draw(int i, int j) {
    if(color[i][j]) return ;
    color[i][j] = 1;
    rep(k, g[i][j].size()) draw(g[i][j][k].first, g[i][j][k].second);
}

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N==0) return 0;
        rep(i, N) scanf("%d%d%d%d", X0+i, Y0+i, X1+i, Y1+i);
        rep(i, N) p0[i] = P(X0[i], Y0[i]), p1[i] = P(X1[i], Y1[i]);
        vector<double> xs;
        rep(i, N) {
            xs.push_back(X0[i]);
            xs.push_back(X1[i]);
        }
        rep(i, N) rep(j, i) if(intersectSS(p0[i], p1[i], p0[j], p1[j])) {
            const P cp(crosspoint(p0[i], p1[i], p0[j], p1[j]));
            xs.push_back(cp.real());
            LOG(cp);
        }
        xs.push_back(-100);
        xs.push_back(0);
        xs.push_back(100);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        rep(i, xs.size()) LOG(xs[i]);
        segs.clear();
        rep(k, xs.size()-1) {
            const double xl = xs[k], xr = xs[k+1];
            vector<seg> s;
            rep(i, N) if(X0[i]!=X1[i]) {
                const int minx = min(X0[i], X1[i]);
                const int maxx = max(X0[i], X1[i]);
                if(xl+EPS<minx || maxx<xr-EPS) continue;
                const P cp1(crosspoint(p0[i], p1[i], P(xl, -100), P(xl, 100)));
                const P cp2(crosspoint(p0[i], p1[i], P(xr, -100), P(xr, 100)));
                s.push_back(seg(cp1.imag(), cp2.imag()));
            }
            s.push_back(seg(-100, -100));
            s.push_back(seg(100, 100));
            sort(s.begin(), s.end());
//            cerr << xl << " to " << xr << endl;
//            rep(i, s.size()) cerr << s[i].y1 << ',' << s[i].y2 << endl;
            segs.push_back(s);
        }

        rep(i, 300) vert[i].clear();
        rep(i, N) if(X0[i]==X1[i]) {
            vert[X0[i]+VOFFSET].push_back(mp(min(Y0[i], Y1[i]), max(Y0[i], Y1[i])));
        }
        rep(k, 300) if(vert[k].size()) {
            sort(vert[k].begin(), vert[k].end());
            int m = 1;
            for(int i=1; i<(int)vert[k].size(); i++) {
                if(vert[k][i].first>vert[k][m-1].second) {
                    vert[k][m++] = vert[k][i];
                }
                else {
                    vert[k][m-1].second = max(vert[k][m-1].second, vert[k][i].second);
                }
            }
            vert[k].resize(m);
        }

        g.clear();
        g.resize(segs.size());
        rep(i, segs.size()) g[i].resize(segs[i].size());

        color.clear();
        color.resize(segs.size());
        rep(i, segs.size()) color[i].resize(segs[i].size());

        rep(k, (int)segs.size()-1) {
            int j = 0;
            rep(i, (int)segs[k].size()-1) {
                const double a1 = segs[k][i].y2;
                const double b1 = segs[k][i+1].y2;
                if(b1-a1<EPS) continue;
                while(j<(int)segs[k+1].size()-1 && segs[k+1][j].y1<b1+EPS) {
                    const double a2 = segs[k+1][j].y1;
                    const double b2 = segs[k+1][j+1].y1;
                    if(b2-a2<EPS) {
                        j++;
                        continue;
                    }
                    const double c1 = max(a1, a2);
                    const double c2 = min(b1, b2);
                    bool can = c2-c1>EPS;
                    if(ceil(xs[k+1])-xs[k+1]<EPS) {
                        const int ix = ceil(xs[k+1])+VOFFSET;
                        rep(z, vert[ix].size()) {
                            const int a3 = vert[ix][z].first;
                            const int b3 = vert[ix][z].second;
                            if(a3<c1+EPS && c2<b3+EPS) can = false;
                        }
                    }
                    if(xs[k+1]-floor(xs[k+1])<EPS) {
                        const int ix = floor(xs[k+1])+VOFFSET;
                        rep(z, vert[ix].size()) {
                            const int a3 = vert[ix][z].first;
                            const int b3 = vert[ix][z].second;
                            if(a3<c1+EPS && c2<b3+EPS) can = false;
                        }
                    }
                    if(can) {
                        g[k][i].push_back(mp(k+1, j));
                        g[k+1][j].push_back(mp(k, i));
                    }
                    j++;
                }
                if(j) j--;
            }
        }
        draw(0, 0);
        rep(i, segs.size()) if(xs[i]<=0 && 0<=xs[i+1]) {
            rep(j, segs[i].size()-1) {
                const P pl1(xs[i], segs[i][j].y1);
                const P pl2(xs[i], segs[i][j+1].y1);
                const P pr1(xs[i+1], segs[i][j].y2);
                const P pr2(xs[i+1], segs[i][j+1].y2);
                const P cp1(crosspoint(pl1, pr1, P(0, -100), P(0, 100)));
                const P cp2(crosspoint(pl2, pr2, P(0, -100), P(0, 100)));
                if(cp1.imag()<EPS && cp2.imag()>EPS) {
                    puts(!color[i][j] ? "yes" : "no");
                    break;
                }
            }
            break;
        }
    }
}

