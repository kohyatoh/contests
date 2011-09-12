#include <stdio.h>
#include <string.h>

char h[19][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
char t[20][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };

int main() {
    int n, d, m, y, ix;
    char mn[80];
    scanf("%d", &n);
    printf("%d\n", n);
    while(n--) {
        scanf("%d. %s %d", &d, mn, &y);
        for(m=0; strcmp(h[m], mn); m++);
        ix = y*365 + m*20 + d;
        printf("%d %s %d\n", ix%13+1, t[ix%20], ix/260);
    }
    return 0;
}
