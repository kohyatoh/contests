#include <iostream>
using namespace std;
typedef long long Int;

int main() {
    Int w, h;
    cin >> w >> h;
    Int wh = (w-1)/2, hh = (h-1)/2;
    Int ans = wh*(wh+1) * hh*(hh+1);
    if (w%2 == 0) ans += (wh+1)*hh*(hh+1);
    if (h%2 == 0) ans += (hh+1)*wh*(wh+1);
    if (w%2 == 0 && h%2 == 0) ans += (wh+1)*(hh+1);
    cout << ans << endl;
    return 0;
}
