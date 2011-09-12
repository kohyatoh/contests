#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool is_vowel(char ch) {
    return ch=='a' || ch=='i' || ch=='u' || ch=='e' || ch=='o';
}

bool same(const vector<string>& a, const vector<string>& b) {
    return a.back()==b.back();
}

int main() {
    string s, w;
    getline(cin, s);
    int T=atoi(s.c_str());
    while(T--) {
        vector<string> v[4];
        rep(k, 4) {
            getline(cin, s);
            istringstream sin(s);
            while(sin>>w) {
                rep(i, w.size()) w[i]=tolower(w[i]);
                int ix=0;
                rep(i, w.size()) if(is_vowel(w[i])) ix=i;
                v[k].push_back(w.substr(ix));
            }
        }
        if(same(v[0], v[1]) && same(v[2], v[3])) {
            if(same(v[0], v[2])) cout << "perfect" << endl;
            else cout << "even" << endl;
        }
        else if(same(v[0], v[2]) && same(v[1], v[3])) cout << "cross" << endl;
        else if(same(v[0], v[3]) && same(v[1], v[2])) cout << "shell" << endl;
        else cout << "free" << endl;
    }
    return 0;
}
