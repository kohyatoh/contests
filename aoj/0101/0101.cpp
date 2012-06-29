#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    getline(cin, s);
    int T = atoi(s.c_str());
    while (T--) {
        getline(cin, s);
        if (s.size() && s[s.size()-1] == '\r') s.resize(s.size()-1);
        size_t ix = 0;
        while ((ix = s.find("Hoshino", ix)) != string::npos) {
            s[ix+6] = 'a';
        }
        cout << s << endl;
    }
    return 0;
}
