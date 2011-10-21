#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool match(const string& s, int i, const char *p) {
    while(*p) {
        if(i>=(int)s.size() || s[i]!=*p) return false;
        i++, p++;
    }
    return true;
}

int main() {
    string s;
    for(;;) {
        getline(cin, s);
        rep(i, s.size()) {
            if(match(s, i, "EOF")) return 0;
            else if(match(s, i, "pink")) {
                printf("floyd");
                i += 3;
            }
            else if(match(s, i, "dd")) {
                putchar('p');
                i += 1;
            }
            else if((i==0 || s[i-1]!='c') && match(s, i, "ei")) {
                printf("ie");
                i += 1;
            }
            else {
                if(islower(s[i]) || isspace(s[i])) putchar(s[i]);
            }
        }
        putchar('\n');
    }
}
