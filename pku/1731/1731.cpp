#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[256];

int main() {
    scanf("%s", s);
    const int n = strlen(s);
    sort(s, s+n);
    do puts(s); while(next_permutation(s, s+n));
    return 0;
}
