#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

vector<int> dat[4];
const char names[4][8] = { "meiji", "taisho", "showa", "heisei" };

int main() {
    dat[0].push_back(1868); dat[0].push_back(9); dat[0].push_back(8);
    dat[1].push_back(1912); dat[1].push_back(7); dat[1].push_back(30);
    dat[2].push_back(1926); dat[2].push_back(12); dat[2].push_back(25);
    dat[3].push_back(1989); dat[3].push_back(1); dat[3].push_back(8);
    int y, m, d;
    while (scanf("%d%d%d", &y, &m, &d) != EOF) {
        vector<int> v;
        v.push_back(y); v.push_back(m); v.push_back(d);
        if (v < dat[0]) puts("pre-meiji");
        else {
            int cur = 0;
            while (cur < 3 && v >= dat[cur+1]) cur++;
            printf("%s %d %d %d\n", names[cur], y-dat[cur][0]+1, m, d);
        }
    }
    return 0;
}
