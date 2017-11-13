#include <iostream>

using namespace std;
const int maxn = 105;
const int maxm = 105;
char maze[maxm][maxn];
int m, n, q;

void init() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            maze[i][j] = '.';
        }
    }
}
//将坐标转换为数组下标
void transform(int &x, int &y) {
    int a = x, b= y;
    x = n - b - 1;
    y = a;
    return ;
}

void printLine(int x1, int y1, int x2, int y2) {
    //按照数组下标操作
    if(x1 == x2) {
        if(y1 > y2) swap(y1, y2);
        for(int j = y1; j <= y2; j++) {
            if(maze[x1][j] == '|' || maze[x1][j] == '+') maze[x1][j] = '+';
            else maze[x1][j] = '-';
        }
    }
    if(y1 == y2) {
        if(x2 > x1) swap(x1, x2);
        for(int i = x2; i <= x1; i++) {
            if(maze[i][y1] == '-' || maze[i][y1] == '+') maze[i][y1] = '+';
            else maze[i][y1] = '|';
        }
    }
    return ;
}

void fillArea(int x, int y, char ch) {
    if(x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == ch ||
            maze[x][y] == '+' || maze[x][y] == '|' || maze[x][y] == '-')
        return ;
    maze[x][y] = ch;
    fillArea(x + 1, y, ch);
    fillArea(x, y + 1, ch);
    fillArea(x - 1, y, ch);
    fillArea(x, y - 1, ch);
    return ;
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    cin >> m >> n >> q;
    int x1, x2, y1, y2, op;
    char ch;
    init();
    while(q--) {
        cin >> op;
        if(op == 0) {
            cin >> x1 >> y1 >> x2 >> y2;
            transform(x1, y1);
            transform(x2, y2);
            printLine(x1, y1, x2, y2);
        } else {
            cin >> x1 >> y1 >>ch;
            transform(x1, y1);
            fillArea(x1, y1, ch);
        }
    }
    print();
    return 0;
}
