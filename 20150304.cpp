#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 20005

using namespace std;
vector<int> G[MAXN];
queue<int> que;
int dis[MAXN];
bool vis[MAXN];
int n,m;

void init() {
    for(int i = 0; i < n+m; i++) {
        G[i].clear();
    }
}

void add_edge(int from, int to) {
    G[from].push_back(to);
    G[to].push_back(from);
}

int bfs(int &s) {
    while(que.size())que.pop();
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    que.push(s);
    vis[s] = true;
    int ans = 0;
    while(que.size()) {
        int u = que.front();
        que.pop();
        for(int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            if(!vis[v]) {
                que.push(v);
                vis[v] = true;
                dis[v] = dis[u] + 1;
                if(dis[v] > ans) {
                    ans = dis[v];
                    s = v;
                }
            }
        }
    }
    return ans;
}

int main(void) {
    while(scanf("%d %d",&n,&m) != EOF) {
        int x;
        init();
        for(int i = 2; i <=n; i++) {
            scanf("%d",&x);
            add_edge(i,x);
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d",&x);
            add_edge(x,i+n);
        }
        int s = 1;
        int ans = max(bfs(s),bfs(s));
        printf("%d\n",ans);
    }
    return 0;
}
