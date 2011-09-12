#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char a[4000], b[4000];

vector<int> make(char s[], int i, int j) {
    vector<int> r;
    int z = 0;
    for(int k=i; k<j; k++) {
        if(z==0) r.push_back(k);
        if(s[k]=='0') z++;
        else z--;
    }
    r.push_back(j);
    return r;
}

bool same(int ai, int aj, int bi, int bj) {
    if(aj-ai != bj-bi) return false;
    if(aj-ai <= 0) return true;
    vector<int> av(make(a, ai, aj)), bv(make(b, bi, bj));
    if(av.size()!=bv.size()) return false;
    const int n = bv.size()-1;
    vector<int> u(n, 0);
    rep(i, n) {
        bool match = false;
        rep(j, n) if(u[j]==0 && same(av[i]+1, av[i+1]-1, bv[j]+1, bv[j+1]-1)) {
            match = true;
            u[j] = 1;
            break;
        }
        if(!match) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) {
        scanf("%s%s", a, b);
        puts(same(0, strlen(a), 0, strlen(b)) ? "same" : "different");
    }
    return 0;
}
