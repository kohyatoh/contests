#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    puts(s[0] == 'o' || s[s.size()-1] == 'o' ? "o" : "x");
    return 0;
}
