#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    string s;
    getline(cin, s);
    while(getline(cin, s)) {
        reverse(s.begin(), s.end());
        int a, b;
        sscanf(s.c_str(), "%d%d", &a, &b);
        int c=a+b;
        string r;
        while(c>0) { r+=(c%10+'0'); c/=10; }
        cout << r.substr(r.find_first_not_of('0')) << endl;
    }
    return 0;
}
