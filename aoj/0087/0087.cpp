#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        istringstream sin(s);
        vector<double> v;
        string w;
        while (sin >> w) {
            if (w.size() > 1 || isdigit(w[0])) v.push_back(atof(w.c_str()));
            else {
                const double a = v[v.size()-2];
                const double b = v[v.size()-1];
                v.pop_back();
                v.pop_back();
                if (w[0] == '+') v.push_back(a+b);
                if (w[0] == '-') v.push_back(a-b);
                if (w[0] == '*') v.push_back(a*b);
                if (w[0] == '/') v.push_back(a/b);
            }
        }
        printf("%.6f\n", v[0]);
    }
    return 0;
}
