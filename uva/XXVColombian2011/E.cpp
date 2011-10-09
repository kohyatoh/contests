#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef complex<double> P;
#define INF (1<<28)

int N, A, B, g[2][128][128];

vector<int> to_v(string s) {
    vector<int> v;
    v.push_back(atoi(s.c_str()));
    rep(i, s.size()-1) if(isspace(s[i]) && isdigit(s[i+1])) {
        v.push_back(atoi(s.c_str()+i+1));
    }
    return v;
}

bool solve() {
    rep(x, 2) rep(k, N) rep(i, N) rep(j, N) {
        g[x][i][j] = min(g[x][i][j], g[x][i][k]+g[x][k][j]);
    }
    rep(i, N) rep(j, N) if(i!=j) {
        if(g[1][i][j]>A*g[0][i][j]+B) return false;
    }
    return true;
}

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        N = atoi(s.c_str());
        if(N==0) return 0;
        rep(k, 2) rep(i, 128) rep(j, 128) g[k][i][j] = INF;
        rep(k, 2) rep(i, 128) g[k][i][i] = 0;
        rep(k, 2) rep(i, N) {
            getline(cin, s);
            vector<int> v(to_v(s));
            rep(j, v.size()) if(j>0) g[k][i][v[j]-1] = 1;
        }
        getline(cin, s);
        sscanf(s.c_str(), "%d%d", &A, &B);
        puts(solve() ? "Yes" : "No");
    }
}
