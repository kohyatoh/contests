#include <stdio.h>
#include <string>
using namespace std;

const char dat[10][2] = {
    "w", "", "k", "s", "t", "n", "h", "m", "y", "r"
};
const char au[] = "aiueo";

char s[1024];

int main() {
    const string of = "TLURD";
    scanf("%s", s);
    for (int i = 0; s[i]; i+=2) {
        const int ix = of.find(s[i+1]);
        if (s[i] == '0' && ix == 2) printf("nn");
        else printf("%s%c", dat[s[i]-'0'], au[ix]);
    }
    printf("\n");
    return 0;
}
