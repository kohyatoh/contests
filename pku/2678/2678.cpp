#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const double EPS=1e-8;
typedef complex<double> P;
#define X(p) real(p)
#define Y(p) imag(p)
namespace std {
    bool operator<(const P& a, const P& b) {
        return X(a)!=X(b) ? X(a)<X(b) : Y(a)<Y(b);
    }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b-=a, c-=a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}
vector<P> convex_hull(vector<P> ps) {
    int n=ps.size(), k=0;
    sort(ps.begin(), ps.end());
    vector<P> v(2*n);
    for(int i=0; i<n; v[k++]=ps[i++]) {
        while(k>1 && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    for(int i=n-2, t=k; i>=0; v[k++]=ps[i--]) {
        while(k>t && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    v.resize(k-1);
    return v;
}
bool strictly_crossing(const P& l0, const P& l1, const P& m0, const P& m1) {
    return cross(m1-m0, l0-m0)*cross(m1-m0, l1-m0)<0
        && cross(l1-l0, m0-l0)*cross(l1-l0, m1-l0)<0;
}

int T, n, m, x, y;
P p[500];
vector<P> cs[500];
int E, to[1000], next[1000], head[500];
double cost[1000], d[500];

bool contained(const P& u, int k) {
    int pdir=0;
    rep(i, cs[k].size()) {
        int a=i, b=(i+1)%cs[k].size();
        int dir=ccw(cs[k][a], cs[k][b], u);
        if(dir!=1 && dir!=-1) return false;
        if(i>0 && pdir!=dir) return false;
        pdir = dir;
    }
    return true;
}

bool blocking(int u, int v) {
    rep(i, n) {
        if(contained(p[u], i)|| contained(p[v], i) || contained(0.5*(p[u]+p[v]), i)) return true;
        rep(j, cs[i].size()) {
            int a=j, b=(j+1)%cs[i].size(), c=(j+2)%cs[i].size();
            P m0(0.5*(cs[i][a]+cs[i][b])), m1(0.5*(cs[i][b]+cs[i][c]));
            if(strictly_crossing(p[u], p[v], cs[i][a], cs[i][c])) return true;
            if(strictly_crossing(p[u], p[v], m0, m1)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        rep(i, 500) d[i]=1e100;
        rep(i, 500) head[i]=-1;
        rep(i, 500) cs[i].clear();
        scanf("%d", &n);
        m = E = 0;
        rep(i, n+1) {
            int c;
            if(i==0) c=2;
            else scanf("%d", &c);
            rep(j, c) {
                scanf("%d%d", &x, &y);
                p[m] = P(x, y);
                if(i>0) cs[i-1].push_back(p[m]);
                m++;
            }
            if(i>0) {
                cs[i-1]=convex_hull(cs[i-1]);
                rep(j, c) p[m-c+j] = cs[i-1][j];
            }
        }
        rep(u, m) rep(v, u) if(!blocking(u, v)) {
            double co=sqrt((double)norm(p[u]-p[v]));
            to[E]=v; cost[E]=co; next[E]=head[u]; head[u]=E; E++;
            to[E]=u; cost[E]=co; next[E]=head[v]; head[v]=E; E++;
        }
        priority_queue<pair<double, int> > q;
        q.push(mp(0, 0));
        while(!q.empty()) {
            pair<double, int> v(q.top());
            q.pop();
            int cur=v.second;
            if(d[cur]<-v.first) continue;
            d[cur] = -v.first;
            if(cur==1) break;
            for(int x=head[cur]; x!=-1; x=next[x]) {
                if(d[to[x]]>-v.first+cost[x]) {
                    d[to[x]] = -v.first+cost[x];
                    q.push(mp(v.first-cost[x], to[x]));
                }
            }
        }
        if(d[1]<1e100) printf("%.3f\n", d[1]);
        else printf("%d\n", -1);
    }
    return 0;
}
