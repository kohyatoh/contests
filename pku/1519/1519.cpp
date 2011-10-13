#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        if(s=="0") return 0;
        int ans = 0;
        rep(i, s.size()) ans = (ans+s[i]-'0')%9;
        cout << (ans==0 ? 9 : ans) << endl;
    }
}
