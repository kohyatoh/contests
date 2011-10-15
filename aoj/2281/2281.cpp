#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[200], b[200];
char s[200];

char rot(char ch, int a) { return 'a' + (ch-'a'+a)%26; }

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%s", s);
        rep(i, n) scanf("%d%d", a+i, b+i);
        rep(i, n) a[i]--, b[i]--;
        for(int i=n-1; i>=0; i--) {
            swap(s[a[i]], s[b[i]]);
            s[a[i]] = rot(s[a[i]], b[i]-a[i]);
            s[b[i]] = rot(s[b[i]], b[i]-a[i]);
        }
        puts(s);
    }
}
