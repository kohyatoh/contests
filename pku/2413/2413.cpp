#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

string normalize(const string& s) {
    int i=0;
    while(i<(int)s.size() && s[i]=='0') i++;
    if(i==(int)s.size()) return "0";
    return s.substr(i);
}

string iadd(string a, string b) {
    int n=max(a.size(), b.size())+1;
    a=string(n-a.size(), '0')+a;
    b=string(n-b.size(), '0')+b;
    string r(n, '0');
    int carr=0;
    for(int i=n-1; i>=0; i--) {
        r[i]=(a[i]-'0'+b[i]-'0'+carr)%10+'0';
        carr=(a[i]-'0'+b[i]-'0'+carr)/10;
    }
    return normalize(r);
}

bool iless(const string& a, const string& b) {
    return a.size()!=b.size() ? a.size()<b.size() : a<b;
}

string fib[500];

int main() {
    fib[0] = "1";
    fib[1] = "2";
    for(int i=2; i<500; i++) fib[i]=iadd(fib[i-1], fib[i-2]);
    for(;;) {
        string a, b;
        cin >> a >> b;
        if(a=="0" && b=="0") return 0;
        LOG(*upper_bound(fib, fib+500, b, iless));
        LOG(*lower_bound(fib, fib+500, a, iless));
        const int ans=upper_bound(fib, fib+500, b, iless)
                        - lower_bound(fib, fib+500, a, iless);
        printf("%d\n", ans);
    }
}


