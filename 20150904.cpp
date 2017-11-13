#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define MAXN 10005
#define MAXM 100005

using namespace std;

vector<int> G[MAXN];
vector<int> rG[MAXN];//把边反向表示的图
vector<int> post;//后序遍历顺序的定点列表
map<int,int> mp;//记录每个强连通分量所包括的顶点数
bool vis[MAXN];//访问标记
int cmp[MAXN];//所属强连通分量的拓补排序
int n,m;

void init() {
    for(int i = 0; i <= n; i++) {
        G[i].clear();
        rG[i].clear();
    }
}

void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < (int)G[u].size(); i++) {
        if(!vis[G[u][i]]) dfs(G[u][i]);
    }
    post.push_back(u);
}

void rdfs(int u, int k) {
    vis[u] = true;
    cmp[u] = k;
    for(int i = 0; i < rG[u].size(); i++) {
        if(!vis[rG[u][i]]) rdfs(rG[u][i],k);
    }
}

int scc() {
    memset(vis,0,sizeof(vis));
    post.clear();
    for(int u = 0; u < n; u++) {
        if(!vis[u]) dfs(u);
    }
    memset(vis,0,sizeof(vis));
    int k = 0;
    for(int i = (int)post.size()-1; i>=0; i--) {
        if(!vis[post[i]])rdfs(post[i],k++);
    }
    return k;//返回强连通分量的数量
}

int main(void) {
    while(scanf("%d %d",&n,&m) != EOF) {
        init();
        int from,to;
        int ans = 0;
        mp.clear();
        for(int i = 0; i < m; i++) {
            scanf("%d %d",&from,&to);
            add_edge(from-1, to-1);
        }
        scc();
        for(int i = 0; i < n; i++) {
            mp[cmp[i]]++;
        }
        for(int i = 0; i < MAXN; i++) {
            if(mp[i] > 1) {
                ans += (mp[i] * (mp[i] - 1)) / 2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
