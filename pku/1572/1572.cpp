#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string s, f[10], r[10];

int main() {
    for(;;) {
        getline(cin, s);
        n = atoi(s.c_str());
        if(n==0) return 0;
        rep(i, n) { getline(cin, f[i]); getline(cin, r[i]); }
        getline(cin, s);
        rep(i, n) {
            int ix;
            while((ix=s.find(f[i]))!=string::npos) {
                s.replace(ix, f[i].size(), r[i]);
            }
        }
        cout << s << endl;
    }
}

