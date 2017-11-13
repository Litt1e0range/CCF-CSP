#include <iostream>
#include <queue>

using namespace std;
const int maxn = 105;
const int maxt = 10000;
typedef pair<int, int> P;

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int maze[maxn][maxn], start[maxn][maxn], end[maxn][maxn], step[maxn][maxn];
int n, m, t;

int bfs() {
    queue<P> que;
    que.push(P(1, 1));
    int time = 1;
    step[1][1] = 0;
    while(que.size()) {
        P p = que.front();
        que.pop();
        if(p.first == n && p.second == m) {
            return step[p.first][p.second];
        }
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dir[i][0];
            int ny = p.second + dir[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m || maze[nx][ny] == time)
                continue;
            time = step[p.first][p.second] + 1;
            if((start[nx][ny] == 0 && end[nx][ny] == 0) || !(start[nx][ny] <= time && time <= end[nx][ny])) {
                que.push(P(nx, ny));
                step[nx][ny] = step[p.first][p.second] + 1;
				maze[nx][ny] = time;//保存上一次被访问的时间
            }
        }
    }
    return -1;
}

int main(void) {
    cin >> n >> m >> t;
    int r, c, a, b;
    for(int i = 0; i < t; i++) {
        cin >> r >> c >> a >> b;
        start[r][c] = a;
        end[r][c] = b;
    }
    cout << bfs() << endl;
    return 0;
}
