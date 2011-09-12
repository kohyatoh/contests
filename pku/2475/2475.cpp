#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

char s[256];
int memo_set[256][256];
int memo_list[256][256];

bool is_set(int l, int r);
bool is_list(int l, int r);

bool is_set(int l, int r) {
    if(memo_set[l][r]!=-1) return memo_set[l][r];
    bool ans = false;
    if(s[l]!='{' || s[r]!='}') ans = false;
    else if(l+1==r) ans = true;
    else ans = is_list(l+1, r-1);
    return (memo_set[l][r] = ans);
}

bool is_list(int l, int r) {
    if(memo_list[l][r]!=-1) return memo_list[l][r];
    bool ans = false;
    if(l==r) ans = true;
    else if(is_set(l, r)) ans = true;
    else {
        for(int i=l+1; i<r; i++) if(s[i]==',') {
            if(is_list(l, i-1) && is_list(i+1, r)) {
                ans = true;
                break;
            }
        }
    }
    return (memo_list[l][r] = ans);
}

int main() {
    gets(s);
    int T = atoi(s);
    rep(q, T) {
        gets(s);
        memset(memo_set, -1, sizeof(memo_set));
        memset(memo_list, -1, sizeof(memo_list));
        printf("Word #%d: %sSet\n", q+1, is_set(0, strlen(s)-1) ? "" : "No ");
    }
    return 0;
}


