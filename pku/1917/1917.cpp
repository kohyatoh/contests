#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int ix[6];
string s[5];

int main() {
    string sep = "<><>";
    string a;
    getline(cin, a);
    int T=atoi(a.c_str());
    rep(q, T) {
        string l1, l2;
        getline(cin, l1);
        getline(cin, l2);
        ix[0]=-1;
        rep(i, 4) ix[i+1] = l1.find(sep[i], ix[i]+1);
        ix[5] = l1.size();
        rep(i, 5) s[i] = l1.substr(ix[i]+1, ix[i+1]-ix[i]-1);
        cout << s[0] << s[1] << s[2] << s[3] << s[4] << endl;
        cout << l2.substr(0, l2.find('.')) << s[3] << s[2] << s[1] << s[4] << endl;
    }
}
