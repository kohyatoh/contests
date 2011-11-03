#include <stdio.h>
#include <string>
using namespace std;
typedef long long Int;

char f[100];

int main() {
    while(gets(f)) {
        Int n = 0, d = 1;
        char *p = f+2;
        while(*p) {
            n = n*8+*p-'0';
            d *= 8;
            p++;
        }
        string r("0.");
        while(n>0) {
            n *= 10;
            r += (char)('0'+n/d);
            n %= d;
        }
        printf("%s [8] = %s [10]\n", f, r.c_str());
    }
    return 0;
}
