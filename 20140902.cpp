#include <iostream>

using namespace std;

const int maxn = 105;
int maze[maxn][maxn];

int main(void) {
    int n, x1, y1, x2, y2;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                maze[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (maze[i][j] == 1)cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
