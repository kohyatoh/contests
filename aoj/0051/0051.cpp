#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    getline(cin, s);
    int T = atoi(s.c_str());
    while (T--) {
        getline(cin, s);
        if (s.size() && s[s.size()-1] == '\r') s.resize(s.size()-1);
        sort(s.begin(), s.end());
        const int a = atoi(s.c_str());
        reverse(s.begin(), s.end());
        const int b = atoi(s.c_str());
        printf("%d\n", b-a);
    }
    return 0;
}
