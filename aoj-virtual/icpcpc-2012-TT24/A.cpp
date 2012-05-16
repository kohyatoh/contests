#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char f[32][32];

int main() {
    int T;
    cin >> T;
    rep (_q, T) {
        printf("Bitmap #%d\n", _q+1);
        memset(f, '.', sizeof(f));
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        rep (i, s.size()) {
            if (s[i] == 'E') {
                f[x][y-1] =  'X';
                x++;;
            }
            else if (s[i] == 'W') {
                f[x-1][y] = 'X';
                x--;
            }
            else if (s[i] == 'N') {
                f[x][y] = 'X';
                y++;
            }
            else if (s[i] == 'S') {
                f[x-1][y-1] = 'X';
                y--;
            }
        }
        rep (i, 32) {
            rep (j, 32) putchar(f[j][31-i]);
            putchar('\n');
        }
        puts("");
    }
    return 0;
}
