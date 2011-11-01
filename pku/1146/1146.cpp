#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        if(s=="#") return 0;
        if(!next_permutation(s.begin(), s.end())) puts("No Successor");
        else puts(s.c_str());
    }
}
