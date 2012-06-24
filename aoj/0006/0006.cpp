#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    getline(cin, s);
    if (s.size() > 0 && s[s.size()-1] == '\r') s.resize(s.size()-1);
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
