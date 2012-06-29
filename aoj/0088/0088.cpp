#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const char dat[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

int main() {
    map<char, string> of;
    of[' '] = "101";
    of['\''] = "000000";
    of[','] = "000011";
    of['-'] = "10010001";
    of['.'] = "010001";
    of['?'] = "000001";
    of['A'] = "100101";
    of['B'] = "10011010";
    of['C'] = "0101";
    of['D'] = "0001";
    of['E'] = "110";
    of['F'] = "01001";
    of['G'] = "10011011";
    of['H'] = "010000";
    of['I'] = "0111";
    of['J'] = "10011000";
    of['K'] = "0110";
    of['L'] = "00100";
    of['M'] = "10011001";
    of['N'] = "10011110";
    of['O'] = "00101";
    of['P'] = "111";
    of['Q'] = "10011111";
    of['R'] = "1000";
    of['S'] = "00110";
    of['T'] = "00111";
    of['U'] = "10011100";
    of['V'] = "10011101";
    of['W'] = "000010";
    of['X'] = "10010010";
    of['Y'] = "10010011";
    of['Z'] = "10010000";
    string s;
    while (getline(cin, s)) {
        string w;
        rep (i, s.size()) if (s[i] != '\r') w += of[s[i]];
        while (w.size() % 5) w += '0';
        for (int k = 0; k < (int)w.size(); k+=5) {
            int a = 0;
            rep (i, 5) a = a*2 + (w[k+i] == '1');
            putchar(dat[a]);
        }
        putchar('\n');
    }
}

