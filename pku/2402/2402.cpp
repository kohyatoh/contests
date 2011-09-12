#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long Int;

string to_rs(Int a) {
    ostringstream sout;
    sout << a;
    string s = sout.str();
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        Int c=0, b=9;
        while(c+b*2<n) {
            c += b*2;
            b *= 10;
        }
        if(n<=c+b) {
            const Int a = c/2+(n-c);
            cout << a << to_rs(a).substr(1) << endl;
        }
        else {
            const Int a = c/2+(n-c-b);
            cout << a << to_rs(a) << endl;
        }
    }
}
