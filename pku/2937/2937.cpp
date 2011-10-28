#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

char buf[100000];

int f(int n, Int r) {
    if(r<0) r = n-(-r%n);
    return r%n;
}

int main() {
    for(;;) {
        gets(buf);
        const int n = atoi(buf);
        if(n==0) return 0;
        gets(buf);
        Int r = 0, sig = 1;
        for(char *p=buf; ; p++) {
            const int a = atoi(p+1);
            if(*p=='r') r += sig*a;
            else if(a%2) sig = -sig;
            p++;
            while(isdigit(*p)) p++;
            if(!*p) break;
        }
        vector<int> ops;
        if(sig>0) {
            if(f(n, r)<2+f(n, -r)) ops.push_back(f(n, r));
            else {
                ops.push_back(-1);
                ops.push_back(f(n, -r));
                ops.push_back(-1);
            }
        }
        else {
            if(f(n, r)<f(n, -r)) {
                ops.push_back(f(n, r));
                ops.push_back(-1);
            }
            else {
                ops.push_back(-1);
                ops.push_back(f(n, -r));
            }
        }
        bool first = true;
        rep(i, ops.size()) if(ops[i]) {
            if(!first) putchar(' ');
            if(ops[i]<0) printf("m1");
            else printf("r%d", ops[i]);
            first = false;
        }
        putchar('\n');
    }
}
