#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, s[20];
char names[20][20], a[20], b[20];

int main() {
    for(int q=0;; q++) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        map<string, int> ids;
        rep(i, n) {
            scanf("%s", names[i]);
            ids[names[i]] = i;
        }
        rep(i, m) {
            int c;
            scanf("%s%s%d", a, b, &c);
            s[ids[a]] += c;
            s[ids[b]] -= c;
        }
        printf("Case #%d\n", q+1);
        rep(i, n) if(s[i]) {
            rep(j, n) if((long long)s[i]*s[j]<0) {
                int c = min(abs(s[i]), abs(s[j]));
                if(s[i]>0) {
                    printf("%s %s %d\n", names[j], names[i], c);
                    s[i] -= c;
                    s[j] += c;
                }
                else {
                    printf("%s %s %d\n", names[i], names[j], c);
                    s[i] += c;
                    s[j] -= c;
                }
            }
        }
        printf("\n");
    }
}

