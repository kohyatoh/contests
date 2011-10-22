#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool isvowel(char ch) {
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

bool endwith(const string& s, const string& t) {
    if(s.size()<t.size()) return false;
    const unsigned b = s.size()-t.size();
    rep(i, t.size()) if(s[b+i]!=t[i]) return false;
    return true;
}

char b[128], c[128];

int main() {
    vector<string> ec;
    ec.push_back("o");
    ec.push_back("s");
    ec.push_back("ch");
    ec.push_back("sh");
    ec.push_back("x");
    map<string, string> dict;
    int L, N;
    scanf("%d%d", &L, &N);
    rep(_, L) {
        scanf("%s%s", b, c);
        dict[b] = c;
    }
    rep(_, N) {
        scanf("%s", b);
        string s(b);
        if(dict.count(s)) s = dict[s];
        else if(s.size()>=2 && s[s.size()-1]=='y' && !isvowel(s[s.size()-2])) {
            s = s.substr(0, s.size()-1) + "ies";
        }
        else {
            bool es = false;
            rep(i, ec.size()) if(endwith(s, ec[i])) es = true;
            s += es ? "es" : "s";
        }
        puts(s.c_str());
    }
    return 0;
}
