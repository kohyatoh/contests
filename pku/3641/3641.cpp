#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int pt[40000];
vector<int> ps;

bool isprime(int p) {
    for(int i=0; i<(int)ps.size() && ps[i]<p; i++) if(p%ps[i]==0) return false;
    return true;
}

Int powmod(Int a, Int x, Int m) {
    if(x==0) return 1;
    return x%2 ? a*powmod(a, x-1, m)%m : powmod(a*a%m, x/2, m);
}

bool solve(int p, int a) {
    return !isprime(p) && powmod(a, p, p)==a;
}

int main() {
    for(int i=2; i<40000; i++) if(pt[i]==0) {
        ps.push_back(i);
        for(int j=i*i; j<40000; j+=i) pt[j] = i;
    }
    for(;;) {
        int p, a;
        scanf("%d%d", &p, &a);
        if(p==0 && a==0) return 0;
        puts(solve(p, a) ? "yes" : "no");
    }
}
