#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int tbl[9][9] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1},
};

int a[9], c[9], d[9];

void unpack(int b) {
    rep(i, 9) {
        c[i] = b%4;
        b /= 4;
    }
}

int main() {
    rep(i, 9) scanf("%d", a+i);
    int ans = 100, ansi = -1;
    rep(b, 1<<18) {
        unpack(b);
        rep(i, 9) d[i] = 0;
        rep(i, 9) rep(j, 9) d[j] += c[i]*tbl[i][j];
        bool ok = true;
        rep(i, 9) if((a[i]+d[i])%4!=0) ok = false;
        if(ok) {
            int s = 0;
            rep(i, 9) s += c[i];
            if(ans>s) {
                ans = s;
                ansi = b;
            }
        }
    }
    unpack(ansi);
    vector<int> as;
    rep(i, 9) while(c[i]) as.push_back(i+1), c[i]--;
    rep(i, as.size()) printf("%d%c", as[i], i<(int)as.size()-1 ? ' ' : '\n');
    return 0;
}
