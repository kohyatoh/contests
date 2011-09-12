#include <stdio.h>
#include <set>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

int f[10];

int main() {
    f[0]=1;
    rep(i, 9) f[i+1]=f[i]*(i+1);
    set<int> s;
    rep(d, 1<<10) {
        int a=0;
        rep(i, 10) if(d&(1<<i)) a+=f[i];
        s.insert(a);
    }
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n<0) return 0;
        if(n>0 && s.find(n)!=s.end()) puts("YES");
        else puts("NO");
    }
}

