#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, k;
pair<int, int> qq[1000];
char buf[256];

int main() {
    for(;;) {
        gets(buf);
        if(*buf=='#') break;
        sscanf(buf, "Register %d %d", &qq[n].first, &qq[n].second);
        n++;
    }
    gets(buf);
    k=atoi(buf);
    sort(qq, qq+n);
    set<pair<int, int> > q;
    rep(i, n) q.insert(mp(qq[i].second, i));
    while(k>0) {
        pair<int, int> v=*q.begin();
        q.erase(q.begin());
        printf("%d\n", qq[v.second].first);
        k--;
        q.insert(mp(v.first+qq[v.second].second, v.second));
    }
    return 0;
}
