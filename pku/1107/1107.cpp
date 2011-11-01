#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int x[3];
char f[256];

int type(char ch) {
    if('a'<=ch && ch<='i') return 0;
    if('j'<=ch && ch<='r') return 1;
    return 2;
}

int main() {
    for(;;) {
        scanf("%d%d%d", x, x+1, x+2);
        if(x[0]==0 && x[1]==0 && x[2]==0) return 0;
        scanf(" %s", f);
        vector<pair<int, char> > cs[3];
        for(int i=0; f[i]; i++) cs[type(f[i])].push_back(mp(i, f[i]));
        rep(k, 3) rep(i, cs[k].size()) {
            f[cs[k][(i+x[k])%cs[k].size()].first] = cs[k][i].second;
        }
        puts(f);
    }
}
