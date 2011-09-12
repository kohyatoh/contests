#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool upper(char ch) { return 'A'<=ch && ch<='Z'; }

string f(string s) {
    if(upper(s[0]) || s[0]=='_') return "Error!";
    bool cpp=false, java=false;
    rep(i, s.size()) if(s[i]=='_') cpp=true;
    rep(i, s.size()) if(upper(s[i])) java=true;
    if(!cpp && !java) return s;
    if(cpp && java) return "Error!";
    string r;
    if(java) {
        rep(i, s.size()) {
            if(upper(s[i])) {
                r += '_';
                r += (s[i]-'A'+'a');
            }
            else r += s[i];
        }
    }
    else {
        rep(i, s.size()) {
            if(s[i]=='_') {
                if(i==(int)s.size()-1 || s[i+1]=='_') return "Error!";
                r += (s[i+1]-'a'+'A');
                i++;
            }
            else {
                r += s[i];
            }
        }
    }
    return r;
}

int main() {
    string s;
    cin >> s;
    cout << f(s) << endl;
    return 0;
}
