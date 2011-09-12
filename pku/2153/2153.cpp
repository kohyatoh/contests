#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, s[10000];
string names[10000];
char buf[128];

int main() {
    n = atoi(gets(buf));
    rep(i, n) names[i]=gets(buf);
    sort(names, names+n);
    m = atoi(gets(buf));
    rep(k, m) {
        rep(i, n) {
            char *p=gets(buf);
            while(*p++!=' ');
            int score;
            sscanf(buf, "%d", &score);
            s[lower_bound(names, names+n, p)-names] += score;
        }
        int x=s[lower_bound(names, names+n, "Li Ming")-names];
        int r=0;
        rep(i, n) if(s[i]>x) r++;
        printf("%d\n", r+1);
    }
    return 0;
}
