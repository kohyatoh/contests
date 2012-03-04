#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<string> dirs;
    int n;
    cin >> n;
    rep (_, n) {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'p') {
            cout << '/';
            rep (i, dirs.size()) cout << dirs[i] << '/';
            cout << endl;
        }
        else {
            string path;
            cin >> path;
            if (path[0] == '/') {
                dirs.clear();
                path = path.substr(1);
            }
            if (path.size()) {
                path += '/';
                unsigned ix = 0;
                while (ix < path.size()) {
                    unsigned e = ix;
                    while (path[e] != '/') e++;
                    string dir = path.substr(ix, e-ix);
                    if (dir == "..") dirs.pop_back();
                    else dirs.push_back(dir);
                    ix = e+1;
                }
            }
        }
    }
    return 0;
}
