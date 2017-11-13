#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Buy {
    double price;
    long long nums;
    Buy(double p, long long  n):price(p),nums(n) {}
    bool operator<(const Buy& rhs) const {
        return price < rhs.price;
    }
};

struct Sell {
    double price;
    long long  nums;
    Sell(double p, long long  n): price(p), nums(n) {}
    bool operator<(const Sell& rhs) const {
        return price > rhs.price;
    }
};

struct Tran {
    string op;
    double p;
    long long  n;
    Tran(string _op, double _p, long long  _n):op(_op), p(_p),n(_n) {}
};

priority_queue<Buy> buy;
priority_queue<Sell> sell;
vector<Tran> data;
int main(void) {
    string op;
    double p, maxPrice = 0;
    long long  n;
	long long maxNums = 0;
    while(cin >> op) {
        if(op == "cancel") {
            cin >> n;
            data[n-1].op = " ";
        } else {
            cin >> p >> n;
            data.push_back(Tran(op, p, n));
        }
    }
    for(vector<Tran>::iterator it = data.begin(); it != data.end(); it++) {
        if(it->op == "buy") {
            buy.push(Buy(it->p, it->n));
        } else if(it->op == "sell"){
            sell.push(Sell(it->p, it->n));
        } else continue;
    }
    while(!buy.empty() && !sell.empty()) {
        Buy b = buy.top();
        Sell s = sell.top();
        if(b.price >= s.price) {
            maxNums += min(b.nums, s.nums);
            maxPrice = b.price;
            if(b.nums < s.nums) {
                s.nums -= b.nums;
                buy.pop();
                sell.pop();
                sell.push(s);
            } else if(b.nums > s.nums) {
                b.nums -= s.nums;
                buy.pop();
                buy.push(b);
                sell.pop();
            } else {
                buy.pop();
                sell.pop();
            }
        } else break;
    }
    cout << setprecision(2) << fixed << maxPrice << " " << maxNums << endl;;
    return 0;
}
