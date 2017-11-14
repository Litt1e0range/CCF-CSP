#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int main(void) {
    int n, arr[maxn];
    int maxAbs = 0;
    cin >> n >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        maxAbs = max(maxAbs, abs(arr[i] - arr[i-1]));
    }
    cout << maxAbs << endl;
    return 0;
}
