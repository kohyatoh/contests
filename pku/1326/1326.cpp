#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int mile;
    for(;;) {
        getline(cin, s);
        if(s=="#") return 0;
        int ans=0;
        while(s!="0") {
            int m;
            char c;
            sscanf(s.c_str(), "%*s %*s %d %c", &m, &c);
            if(c=='F') ans+=m+m;
            else if(c=='B') ans+=m+m-m/2;
            else ans+=max(m, 500);
            getline(cin, s);
        }
        cout << ans << endl;
    }
}

