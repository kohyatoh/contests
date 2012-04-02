#include <stdio.h>
#include <stdlib.h>

char buf[800000];

int main() {
    int T, n, m, a, b;
    const char *p;
    gets(buf);
    T = atoi(buf);
    while (T--) {
        gets(buf);
        n = atoi(buf);
        m = 2000000;
        a = 0;
        gets(buf);
        p = buf;
        while (n--) {
            b = 0;
            while (*p >= '0') b = b*10+*(p++)-'0';
            p++;
            if (b < m) m = b;
            else if (b-m > a) a = b-m;
        }
        if (a) printf("%d\n", a); else puts("UNFIT");
    }
    return 0;
}
