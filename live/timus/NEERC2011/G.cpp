#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
map<vector<string>, string> fs;
map<string, string> of;

int nextInt() {
    string buf;
    getline(cin, buf);
    return atoi(buf.c_str());
}

vector<string> nextLine() {
    string buf;
    getline(cin, buf);
    rep(i, buf.size()) if(!isalpha(buf[i])) buf[i] = ' ';
    istringstream sin(buf);
    string s;
    vector<string> vs;
    while(sin>>s) vs.push_back(s);
    return vs;
}

vector<string> ts[128];

int main() {
    n = nextInt();
    rep(i, n) {
        vector<string> vs(nextLine());
        string s(vs.back());
        vs.pop_back();
        fs[vs] = s;
    }
    vector<string> ans;
    const int Q = nextInt();
    rep(i, Q) ts[i] = nextLine();
    rep(i, Q) {
        vector<string>& vs = ts[i];
        if(of.count(vs[1])) {
            cout << "Error on line " << i+1 << ": Double declaration" << endl;
            return 0;
        }
        vector<string> sig;
        sig.push_back(vs[2]);
        for(int k=3; k<(int)vs.size(); k++) {
            if(of.count(vs[k])==0) {
                cout << "Error on line " << i+1 << ": Unknown variable" << endl;
                return 0;
            }
            sig.push_back(of[vs[k]]);
        }
        if(fs.count(sig)==0) {
            cout << "Error on line " << i+1 << ": No such function" << endl;
            return 0;
        }
        string type(fs[sig]);
        if(vs[0]=="auto") {
            ans.push_back(vs[1]);
            vs[0] = type;
        }
        if(vs[0]!=type) {
            cout << "Error on line " << i+1 << ": Invalid initialization" << endl;
            return 0;
        }
        of[vs[1]] = type;
    }
    rep(i, ans.size()) {
        cout << ans[i] << " : " << of[ans[i]] << endl;
    }
    return 0;
}

