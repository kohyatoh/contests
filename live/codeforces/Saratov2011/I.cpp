#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define pb push_back
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline double sq(double a) { return a*a; }

const char shapes[10][8] = {
    "1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011",
};

int tbl[10][10];
char f[300000], t[300000];

const char *solve() {
    const int n = strlen(f)/2;

    int s = 0;
    rep(i, n) s += tbl[f[i]-'0'][f[i+n]-'0'];

    memcpy(t, f, n*2);
    t[n*2] = '\0';

    int cur = s;
    deque<int> ps;
    for(int i=2*n-1; i>=n; i--) {
        const int w = f[i-n]-'0';
        cur -= tbl[f[i]-'0'][w];
        for(int k=f[i]-'0'+1; k<10; k++) {
            t[i] = k+'0';
            const int x = cur + tbl[k][w];
            if(x+(int)ps.size()>s) {
                rep(j, s-x+1) {
                    const int ix = ps[j]-n;
                    t[ix+n] = f[ix]<'9' ? f[ix] : '8';
                }
                return t;
            }
        }
        t[i] = '0';
        cur += tbl[0][w];
        if(tbl[0][w]<tbl[w][w]) ps.push_back(i);
    }

    for(int i=n-1; i>=0; i--) {
        while(ps.size() && ps.front()>=i+n) ps.pop_front();
        cur -= tbl[f[i]-'0'][0];
        for(int k=f[i]-'0'+1; k<10; k++) {
            const int x = cur + tbl[k][0];
            t[i] = k+'0';
            const int add = tbl[k][0]!=tbl[k][8];
            if(x+(int)ps.size()+add>s) {
                if(add) ps.push_back(i+n);
                sort(ps.begin(), ps.end());
                reverse(ps.begin(), ps.end());
                rep(j, s-x+1) {
                    const int ix = ps[j];
                    if(ix<n) t[ix] = t[ix+n] = '8';
                    else t[ix] = t[ix-n]<'9' ? t[ix-n] : '8';
                }
                return t;
            }
        }
        t[i] = '0';
        cur += tbl[0][0];
        ps.push_back(i);
    }
    return "-1";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    rep(i, 10) rep(j, 10) {
        rep(k, 8) if(shapes[i][k]=='1' && shapes[j][k]=='1') tbl[i][j]++;
    }
    scanf("%s", f);
    puts(solve());
    return 0;
}


