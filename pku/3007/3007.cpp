#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string v[800];

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int k = 0;
        for(int i=1; i<(int)s.size(); i++) {
            const string l = s.substr(0, i);
            const string r = s.substr(i);
            const string revl = rev(l);
            const string revr = rev(r);
            v[k++] = l+r;
            v[k++] = l+revr;
            v[k++] = revl+r;
            v[k++] = revl+revr;
            v[k++] = r+l;
            v[k++] = r+revl;
            v[k++] = revr+l;
            v[k++] = revr+revl;
        }
        sort(v, v+k);
        cout << unique(v, v+k) - v << endl;
    }
    return 0;
}
