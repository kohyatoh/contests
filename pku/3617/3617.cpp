#include <stdio.h>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int N;
char f[3000];
map<pair<int, int>, bool> memo;

bool check(int x, int y) {
    if(x>=y) return true;
    if(memo.count(mp(x, y))) return memo[mp(x, y)];
    return memo[mp(x, y)] = f[x]!=f[y] ? f[x]<f[y] : check(x+1, y-1);
}

int main() {
    scanf("%d", &N);
    rep(i, N) scanf(" %c", f+i);
    int l = 0, r = N-1;
    rep(i, N) {
        putchar(f[check(l, r) ? l++ : r--]);
        if((i+1)%80==0) putchar('\n');
    }
    if(N%80) putchar('\n');
    return 0;
}
