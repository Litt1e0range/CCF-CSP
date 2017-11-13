#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int maxn = 1005;
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int maze[maxn][maxn],step[maxn][maxn];
int n,m,k,d,x,y;
static ll ans;
queue<P> que;
static void init() {
    memset(step,0,sizeof(step));
    memset(maze,0,sizeof(maze));
}

static void bfs() {
    while(que.size()) {
        P p = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dir[i][0];
            int ny = p.second + dir[i][1];
            if(0 < nx && nx <= n && 0 < ny && ny <= n && maze[nx][ny] != -1) {
                step[nx][ny] = step[p.first][p.second] + 1;
                if(maze[nx][ny] > 0) {
                    ans += maze[nx][ny]*step[nx][ny];
                }
                que.push(P(nx,ny));
                maze[nx][ny] = -1;
            }
        }
    }
    return ;
}

int main(void) {
    while(scanf("%d %d %d %d",&n,&m,&k,&d) != EOF) {
        int x, y,z;
        ans = 0;
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d %d",&x,&y);
            que.push(P(x, y));
            maze[x][y] = -1;//起点
        }
        for(int i = 0; i < k; i++) {
            scanf("%d %d %d",&x, &y, &z);
            maze[x][y] += z;//每个点上面顾客的需求总量
        }
        for(int i = 0; i < d; i++) {
            scanf("%d %d", &x, &y);
        }
        bfs();
        printf("%lld\n",ans);
    }
    return 0;
}
