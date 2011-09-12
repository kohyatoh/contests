#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char f[20000000];
int of[256];

int main() {
    memset(of, -1, sizeof(of));
    int n, nc;
    gets(f);
    sscanf(f, "%d%d", &n, &nc);
    gets(f);
    int m = 0;
    for(int i=0; f[i]; i++) if(of[f[i]]==-1) of[f[i]] = m++;
    typedef unsigned long long hash_t;
    const hash_t X = 133;
    hash_t h=0, t=1;
    rep(i, n) t *= X;
    vector<int> v;
    for(int i=0; f[i]; i++) {
        h = h*X + of[f[i]];
        if(i>=n) h -= t*of[f[i-n]];
        if(i>=n-1) v.push_back(h);
    }
    sort(v.begin(), v.end());
    printf("%u\n", unique(v.begin(), v.end())-v.begin());
    return 0;
}
