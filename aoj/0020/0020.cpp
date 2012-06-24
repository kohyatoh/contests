#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.size() > 0 && s[s.size()-1] == '\r') s.resize(s.size()-1);
        rep (i, s.size()) if (islower(s[i])) s[i] = toupper(s[i]);
        cout << s << endl;
    }
    return 0;
}
