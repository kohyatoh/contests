#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define mp make_pair

typedef pair<char, char> dia;

int n;
char s[6400], b[100];

int main() {
    for(;;) {
        n = atoi(gets(s));
        if(n==0) return 0;
        s[0] = 0;
        while(n--) {
            gets(b);
            strcat(s, b);
        }
        int c=0;
        map<dia, int> m;
        for(char *p=s; *(p+1); p++) m[mp(*p, *(p+1))]++, c++;
        vector<pair<int, dia> > v;
        for(map<dia, int>::iterator it=m.begin(); it!=m.end(); it++) {
            v.push_back(mp(-it->second, it->first));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<5; i++) {
            printf("%c%c %d %.6f\n",
                    v[i].second.first, v[i].second.second,
                    -v[i].first, (double)-v[i].first/c);
        }
        printf("\n");
    }
}
