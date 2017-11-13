#include <list>
#include <iostream>

using namespace std;

struct Attend {
    int health, attack;
    Attend(int h, int a):health(h), attack(a) {}
};

list<Attend> player[2];

void print(list<Attend>& lt) {
    for(list<Attend>::iterator it = lt.begin(); it != lt.end(); it++) {
        if(it == lt.begin()) {
            cout << it->health << endl;
            cout << lt.size() - 1;
        } else cout << " " << it->health;
    }
}

int main(void) {
    int n, process = 0;
    int a, d, h, p;
    player[0].push_back(Attend(30, 0));
    player[1].push_back(Attend(30, 0));
    cin >> n;
    string op;
    while(n--) {
        cin >> op;
        switch(op[0]) {
            case's' : {
                    cin >> p >> a >> h;
                    list<Attend>::iterator it = player[process].begin();
                    advance(it, p);
                    player[process].insert(it, Attend(h, a));
                    break;
                }
            case 'a' : {
                    cin >> a >> d;
                    list<Attend>::iterator it1 = player[process].begin();
                    list<Attend>::iterator it2 = player[process^1].begin();
                    advance(it1, a);
                    advance(it2, d);
                    it1->health -= it2->attack;
                    it2->health -= it1->attack;
                    if(it1->health <= 0) player[process].erase(it1);
                    if(d && it2->health <= 0) player[process^1].erase(it2);
                    break;
                }
            case 'e' :
                process ^= 1;
                break;
        }
    }
    if(player[0].begin()->health <= 0) cout << "-1" << endl;
    else if(player[1].begin()->health <= 0) cout << "1" << endl;
    else cout << "0" <<endl;

    print(player[0]);
    cout << endl;
    print(player[1]);
    return 0;
}
