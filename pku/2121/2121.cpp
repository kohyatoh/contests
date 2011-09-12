#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

char dat1[20][16] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", };
char dat2[10][16] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", };

int main() {
    map<string, int> value;
    for(int i=0; i<20; i++) value[dat1[i]]=i;
    for(int i=0; i<10; i++) value[dat2[i]]=i*10;
    string line, w;
    while(getline(cin, line)) {
        if(line.size()==0) break;
        istringstream sin(line);
        int a=0, cur=0;
        while(sin>>w) {
            if(w=="negative") cout << '-';
            else if(w=="million") { a+=cur*1000000; cur=0; }
            else if(w=="thousand") { a+=cur*1000; cur=0; }
            else if(w=="hundred") { cur*=100; }
            else cur+=value[w];
        }
        cout << cur+a << endl;
    }
    return 0;
}
