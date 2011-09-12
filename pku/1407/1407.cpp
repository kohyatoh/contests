#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct item {
    int p, i;
    string d;
    item(int p, int i, const string& d) : p(p), i(i), d(d) {}
};
bool operator<(const item& l, const item& r) { return l.p!=r.p?l.p<r.p:l.i<r.i; }

int n;
map<string, set<item> > sell, buy;
map<string, vector<int> > items;
set<string> dealers;
map<string, int> paid, received;

int main() {
    for(;;) {
        cin >> n;
        if(n==0) return 0;
        sell.clear(); buy.clear(); items.clear();
        dealers.clear(); paid.clear(); received.clear();
        string dealer, type, name;
        int price;
        rep(i, n) {
            cin >> dealer >> type >> name >> price;
            dealers.insert(dealer);
            if(type=="SELL") {
                set<item>::iterator it=buy[name].begin();
                for(; it!=buy[name].end(); it++) {
                    if(-it->p<price) { it=buy[name].end(); break; }
                    if(it->d!=dealer) break;
                }
                if(it==buy[name].end()) {
                    sell[name].insert(item(price, i, dealer));
                }
                else {
                    int c=(price-it->p)/2;
                    items[name].push_back(c);
                    paid[it->d]+=c;
                    received[dealer]+=c;
                    buy[name].erase(it);
                }
            }
            else {
                set<item>::iterator it=sell[name].begin();
                for(; it!=sell[name].end(); it++) {
                    if(it->p>price) { it=sell[name].end(); break; }
                    if(it->d!=dealer) break;
                }
                if(it==sell[name].end()) {
                    buy[name].insert(item(-price, i, dealer));
                }
                else {
                    int c=(price+it->p)/2;
                    items[name].push_back(c);
                    paid[dealer]+=c;
                    received[it->d]+=c;
                    sell[name].erase(it);
                }
            }
        }
        for(std::map<string, vector<int> >::iterator it=items.begin();
                it!=items.end(); it++) {
            int s=0, mn=10000, mx=0;
            rep(i, it->second.size()) {
                s+=it->second[i];
                mn=min(mn, it->second[i]);
                mx=max(mx, it->second[i]);
            }
            cout << it->first << ' ' << mn << ' ' << s/it->second.size() << ' ' << mx << endl;
        }
        cout << "--" << endl;
        for(std::set<string>::iterator it=dealers.begin();
                it!=dealers.end(); it++) {
            cout << *it << ' ' << paid[*it] << ' ' << received[*it] << endl;
        }
        cout << "----------" << endl;
    }
}

