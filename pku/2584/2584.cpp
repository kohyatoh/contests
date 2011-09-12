#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char sizes[] = "SMLXT";
char s[100];
int n, a[5], f[100], t[100];

int main() {
    for(;;) {
        scanf("%s", s);
        if(s[0]=='E') return 0;
        scanf("%d", &n);
        rep(i, n) {
            scanf("%s", s);
            f[i] = find(sizes, sizes+5, s[0])-sizes;
            t[i] = find(sizes, sizes+5, s[1])-sizes;
        }
        rep(i, 5) scanf("%d", a+i);
        rep(k, 5) {
            vector<pair<int, int> > v;
            rep(i, n) if(f[i]==k) v.push_back(make_pair(t[i], i));
            sort(v.begin(), v.end());
            rep(i, v.size()) f[v[i].second]=k+1;
            rep(i, min((int)v.size(), a[k])) f[v[i].second]=t[v[i].second]=-1;
        }
        int c=0;
        rep(i, n) if(f[i]!=-1) c++;
        puts(c==0 ? "T-shirts rock!" : "I'd rather not wear a shirt anyway...");
        scanf("%s", s);
    }
}

