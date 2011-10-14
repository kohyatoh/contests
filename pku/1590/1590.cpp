#include <stdio.h>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const char from[] = "AEHIJLMOSTUVWXYZ12358";
const char to[]   = "A3HILJMO2TUVWXY51SEZ8";

char of[128];

bool is_palindrome(const string& s) {
    rep(i, s.size()) if(s[i]!=s[s.size()-1-i]) return false;
    return true;
}

bool is_mirror(const string& s) {
    string r(s);
    rep(i, s.size()) {
        if(of[(int)s[i]]==0) return false;
        r[i] = of[(int)s[i]];
    }
    reverse(r.begin(), r.end());
    return s == r;
}

char s[128];

int main() {
    for(int i=0; from[i]; i++) of[(int)from[i]] = to[i];
    while(gets(s)) {
        int n = 0;
        while(s[n] && !isspace(s[n])) n++;
        s[n] = '\0';
        const bool p = is_palindrome(s);
        const bool m = is_mirror(s);
        printf("%s -- is ", s);
        if(p && m) puts("a mirrored palindrome.");
        else if(p) puts("a regular palindrome.");
        else if(m) puts("a mirrored string.");
        else puts("not a palindrome.");
        puts("");
    }
    return 0;
}
