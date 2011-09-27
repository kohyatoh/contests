#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
inline double sq(double a) { return a*a; }

int n, ox[200], oy[200];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", ox+i, oy+i);
        vector<int> ys;
        rep(i, n) ys.push_back(oy[i]);
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        vector<double> x;
        vector<int> y;
        rep(i, n) {
            x.push_back(ox[i]);
            y.push_back(oy[i]);
            if(i==n-1) break;
            if(oy[i]<oy[i+1]) {
                rep(j, ys.size()) if(oy[i]<ys[j] && ys[j]<oy[i+1]) {
                    const double dx = ox[i+1]-ox[i], dy = oy[i+1]-oy[i];
                    x.push_back(ox[i]+dx/dy*(ys[j]-oy[i]));
                    y.push_back(ys[j]);
                }
            }
            else if(oy[i]>oy[i+1]) {
                const int m = ys.size();
                for(int j=m-1; j>=0; j--) if(oy[i+1]<ys[j] && ys[j]<oy[i]) {
                    const double dx = ox[i+1]-ox[i], dy = oy[i+1]-oy[i];
                    x.push_back(ox[i]+dx/dy*(ys[j]-oy[i]));
                    y.push_back(ys[j]);
                }
            }
        }
        typedef pair<int, int> node;
        set<node> vis;
        priority_queue<pair<double, node> > q;
        q.push(mp(0, mp(0, x.size()-1)));
        while(!q.empty()) {
            pair<double, node> vv(q.top());
            q.pop();
            const double c = -vv.first;
            const int l = vv.second.first;
            const int r = vv.second.second;
            if(vis.find(mp(l, r))!=vis.end()) continue;
            vis.insert(mp(l, r));
            if(l==r) {
                printf("%.9f\n", c);
                break;
            }
            for(int i=-1; i<=1; i++) if(0<=l+i && l+i<(int)x.size()) {
                for(int j=-1; j<=1; j++) if(0<=r+j && r+j<(int)x.size()) {
                    if(y[l+i]==y[r+j]) {
                        const double d1 = sqrt(sq(x[l]-x[l+i])+sq(y[l]-y[l+i]));
                        const double d2 = sqrt(sq(x[r]-x[r+j])+sq(y[r]-y[r+j]));
                        q.push(mp(-c-d1-d2, mp(l+i, r+j)));
                    }
                }
            }
        }
    }
}

