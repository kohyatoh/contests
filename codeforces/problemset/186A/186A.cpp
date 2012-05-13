#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int c = 0;
    for (unsigned i = 0; i < a.size() && i < b.size(); i++) {
        c += a[i] != b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    puts(a == b && c == 2 ? "YES" : "NO");
    return 0;
}
