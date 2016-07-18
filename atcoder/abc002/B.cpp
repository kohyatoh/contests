#include <stdio.h>
#include <string>
using namespace std;

int main() {
    char s[40];
    scanf("%s", s);
    const string v = "aiueo";
    for (int i = 0; s[i]; i++) if (v.find(s[i]) == string::npos) putchar(s[i]);
    putchar('\n');
    return 0;
}
