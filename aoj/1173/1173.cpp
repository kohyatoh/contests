#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool solve(const string& s) {
    vector<char> st;
    rep(i, s.size()) {
        if(s[i]=='(' || s[i]=='[') st.push_back(s[i]);
        if(s[i]==')' || s[i]==']') {
            if(st.empty()) return false;
            if(s[i]==')' && st.back()!='(') return false;
            if(s[i]==']' && st.back()!='[') return false;
            st.pop_back();
        }
    }
    return st.empty();
}

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        if(s==".") return 0;
        puts(solve(s) ? "yes" : "no");
    }
}
