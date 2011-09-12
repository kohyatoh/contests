#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

bool win(const string& s, char p) {
    rep(i, 3) if(s[i]==p && s[i+3]==p && s[i+6]==p) return true;
    rep(i, 3) if(s[i*3]==p && s[i*3+1]==p && s[i*3+2]==p) return true;
    if(s[0]==p && s[4]==p && s[8]==p) return true;
    if(s[2]==p && s[4]==p && s[6]==p) return true;
    return false;
}

string s;
set<string> terms;
set<string> visited;
void visit(char p) {
    if(visited.find(s)!=visited.end()) return;
    visited.insert(s);
    if(win(s, 'X') || win(s, 'O')) {
        terms.insert(s);
        return ;
    }
    bool draw = true;
    rep(i, 9) if(s[i]=='.') {
        draw = false;
        s[i] = p;
        visit(p=='X' ? 'O' : 'X');
        s[i] = '.';
    }
    if(draw) terms.insert(s);
}

int main() {
    s = ".........";
    visit('X');
    for(;;) {
        string f;
        cin >> f;
        if(f=="end") return 0;
        if(terms.find(f)!=terms.end()) printf("valid\n");
        else printf("invalid\n");
    }
}

