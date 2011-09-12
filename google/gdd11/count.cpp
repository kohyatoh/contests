#include <iostream>
#include <string>
using namespace std;

int main() {
    int L=0, R=0, U=0, D=0;
    string s;
    while(cin>>s) {
        for(int i=0; i<(int)s.size(); i++) {
            if(s[i]=='L') L++;
            if(s[i]=='R') R++;
            if(s[i]=='U') U++;
            if(s[i]=='D') D++;
        }
    }
    cout << L << ' ' << R << ' ' << U << ' ' << D << endl;
    cout << L+R+U+D << endl;
    return 0;
}

