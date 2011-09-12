#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
using namespace std;

string token;
pair<int, int> factor();
pair<int, int> term();
pair<int, int> expr();

string s;
unsigned ix;

string nextToken() {
    if(ix==s.size()) return "";
    unsigned k=1;
    if('0'<=s[ix] && s[ix]<='9') {
        while(ix+k<s.size() && '0'<=s[ix+k] && s[ix+k]<='9') k++;
    }
    string r(s.substr(ix, k));
    ix += k;
    return r;
}

pair<int, int> expr() {
    pair<int, int> r = term();
    while(token=="+" || token=="-") {
        int t = token=="+" ? 1 : -1;
        pair<int, int> v = term();
        r.first += t * v.first;
        r.second += t * v.second;
    }
    return r;
}

pair<int, int> term() {
    pair<int, int> r = factor();
    while(token=="*") {
        pair<int, int> v = factor();
        if(v.second) swap(r, v);
        r.first *= v.first;
        r.second *= v.first;
    }
    return r;
}

pair<int, int> factor() {
    pair<int, int> r;
    token = nextToken();
    if(token=="(") r = expr();
    else if(token=="x") r = make_pair(0, 1);
    else r = make_pair(atoi(token.c_str()), 0);
    token = nextToken();
    return r;
}

int main() {
    string r;
    int q=0;
    while(getline(cin, r)) {
        int i = r.find('=');
        s = "(" + r.substr(0, i) + ")-(" + r.substr(i+1) + ")";
        ix = 0;
        pair<int, int> v = expr();
        cout << "Equation #" << q+1 << endl;
        if(v.second==0) {
            if(v.first==0) cout << "Infinitely many solutions." << endl;
            else cout << "No solution." << endl;
        }
        else {
            double val = (double)-v.first/v.second;
            cout << "x = " << fixed << setprecision(6) << val << endl;
        }
        cout << endl;
        q++;
    }
    return 0;
}
