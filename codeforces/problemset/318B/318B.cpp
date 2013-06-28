#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long Int;

char s[2000000];

int main() {
    scanf("%s", s);
    Int ans = 0, c = 0;
    for (int i = 0; s[i]; i++) {
        if (strncmp(s+i, "heavy", 5) == 0) c++;
        if (strncmp(s+i, "metal", 5) == 0) ans += c;
    }
    cout << ans << endl;
    return 0;
}
