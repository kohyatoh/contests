#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

char org[9][7][8] = {
    { "#######", "#.....#", "#...|.#", "#.....#", "#...|.#", "#..-..#", "#######", },
    { "#######", "#..-..#", "#...|.#", "#..-..#", "#.|...#", "#..-..#", "#######", },
    { "#######", "#..-..#", "#...|.#", "#..-..#", "#...|.#", "#..-..#", "#######", },
    { "#######", "#.....#", "#.|.|.#", "#..-..#", "#...|.#", "#.....#", "#######", },
    { "#######", "#..-..#", "#.|...#", "#..-..#", "#...|.#", "#..-..#", "#######", },
    { "#######", "#..-..#", "#.|...#", "#..-..#", "#.|.|.#", "#..-..#", "#######", },
    { "#######", "#..-..#", "#...|.#", "#.....#", "#...|.#", "#.....#", "#######", },
    { "#######", "#..-..#", "#.|.|.#", "#..-..#", "#.|.|.#", "#..-..#", "#######", },
    { "#######", "#..-..#", "#.|.|.#", "#..-..#", "#...|.#", "#..-..#", "#######", }};
char digs[9][6][8][8];
char f[21][57];

void vflip(char (*a)[8]) {
    static char t[8][8];
    memcpy(t, a, sizeof(t));
    rep(i, 7) rep(j, 7) a[6-i][j] = t[i][j];
}

void hflip(char (*a)[8]) {
    static char t[8][8];
    memcpy(t, a, sizeof(t));
    rep(i, 7) rep(j, 7) a[i][6-j] = t[i][j];
}

void rot(char (*a)[8]) {
    static char t[8][8];
    memcpy(t, a, sizeof(t));
    rep(i, 7) rep(j, 7) a[6-j][i] = t[i][j];
    rep(i, 7) rep(j, 7) {
        if(a[i][j]=='|') a[i][j] = '-';
        else if(a[i][j]=='-') a[i][j] = '|';
    }
}

bool match(const char (*f)[57], int x, int y, const char (*a)[8]) {
    rep(i, 7) rep(j, 7) if(f[x+i][y+j]!=a[i][j]) return false;
    return true;
}

const int xs[6] = {0, 7, 7, 7, 7, 14};
const int ys[6] = {7, 0, 7, 14, 21, 7};

vector<int> scan(const char (*f)[57], int os) {
    vector<int> ans;
    rep(k, 9) {
        rep(i, 6) if(match(f, xs[i], ys[i]+os, digs[k][i])) ans.push_back(k+1);
    }
    return ans;
}

int main() {
    rep(d, 9) {
        rep(k, 6) rep(i, 7) rep(j, 7) digs[d][k][i][j] = org[d][i][j];
        hflip(digs[d][0]);
        hflip(digs[d][1]); rot(digs[d][1]);
        hflip(digs[d][2]);
        hflip(digs[d][3]); rot(digs[d][3]); rot(digs[d][3]); rot(digs[d][3]);
        hflip(digs[d][4]);
        vflip(digs[d][5]); hflip(digs[d][5]);
    }
    for(;;) {
        scanf(" %c", &f[0][0]);
        if(f[0][0]=='0') return 0;
        rep(i, 21) rep(j, 57) if(i || j) scanf(" %c", &f[i][j]);
        vector<int> u(scan(f, 0)), v(scan(f, 29));
//        rep(i, u.size()) cerr << "u:" << u[i] << endl;
//        rep(i, v.size()) cerr << "v:" << v[i] << endl;
        int hc=0, lc=0;
        rep(i, u.size()) rep(j, v.size()) {
            if(u[i]<v[j]) lc++;
            if(u[i]>v[j]) hc++;
        }
        puts(lc>hc ? "LOW" : "HIGH");
    }
}

