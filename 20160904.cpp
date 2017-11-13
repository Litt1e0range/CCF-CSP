#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>

const int maxn = 10005;
const int maxm = 100005;
const int INF = 1 << 20;
using namespace std;
struct Edge {
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d) {}
};

struct HeapNode {
    int d,u;
    bool operator<(const HeapNode& rhs) const {
        return d > rhs.d;
    }
};

vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn],p[maxn];
int n,m;

void init(int n) {
    for(int i = 0; i < n; i++)G[i].clear();
    edges.clear();
}

void add_edge(int from, int to, int dist) {
    edges.push_back(Edge(from, to, dist));
    int v = (int)edges.size();
    G[from].push_back(v-1);
}

void dijkstra(int s) {
    priority_queue<HeapNode> pq;
    for(int i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    memset(vis,0,sizeof(vis));
    pq.push((HeapNode) {
        0,s
    });
    while(pq.size()) {
        HeapNode x = pq.top();
        pq.pop();
        int u = x.u;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < G[u].size(); i++) {
            Edge e = edges[G[u][i]];
            if(d[e.to] > d[u] + e.dist) {
                d[e.to] = d[u] + e.dist;
                p[e.to] = e.dist;
                pq.push((HeapNode) {
                    d[e.to],e.to
                });
            }
            if(d[e.to] == d[u] + e.dist) {
                p[e.to] = min(e.dist, p[e.to]);
            }
        }
    }
}

int main() {
    while(scanf("%d %d",&n,&m) != EOF) {

        int from, to, dist;
        init(n);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d",&from,&to,&dist);
            add_edge(from,to,dist);
            add_edge(to,from,dist);
        }
        dijkstra(1);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += p[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
