#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int t, salary = 3500, s;
    cin >> t;
    s = t - 3500;
    if(s <= 0) {
        salary += s;
    } else if(0 < s && s <= 1455) {
        salary += (int)(s / 97)*100;
    } else if(1455 < s && s <= 4155) {
        salary += 1500 + (s - 1455) / 90 * 100;
    } else if(4155 < s && s <=7755) {
        salary += 1500 + 3000 + (s - 4155) / 80 * 100;
    } else if(7755 < s && s <= 27255) {
        salary += 1500 + 3000 + 4500 + (s - 7755) / 75*100;
    } else if(27255 < s && s <= 41255) {
        salary += 1500 + 3000 + 4500 + 26000 + (s - 27255) / 70 * 100;
    } else if(41255 < s && s <= 57505) {
        salary += 1500 + 3000 + 4500 + 26000 + 20000 +(s - 41255) / 65 * 100;
    } else if(57505 < s){
        salary += 1500 + 3000 + 4500 + 26000 + 20000 + 25000 + (s - 57505) / 55 * 100;
    }
    cout << salary << endl;
    return 0;
}
