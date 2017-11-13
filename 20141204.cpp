#include <cstdio>
#include <algorithm>

#define MAXN 1005
#define MAXM 1000005
#define LLONG long long

using std::sort;

typedef struct {
    int from,to;
    LLONG cost;
} Edge;

Edge edges[MAXM];
int par[MAXN],rank[MAXN];
int n,m;

void init() {
    for(int i = 0; i <= n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x,int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if(rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}

int same(int x, int y) {
    return find(x) == find(y);
}

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

LLONG Kruskal() {
    sort(edges, edges + m,cmp);
    LLONG res = 0;
    for(int i = 0; i < m; i++) {
        Edge e = edges[i];
        if(same(e.from, e.to)) continue;
        unite(e.from, e.to);
        res += e.cost;
    }
    return res;
}

int main(void) {
    while(scanf("%d %d",&n, &m) != EOF) {
        init();
		for(int i = 0; i < m; i++) {
            scanf("%d %d %lld",&edges[i].from, &edges[i].to, &edges[i].cost);
        }
        printf("%lld\n", Kruskal());
    }
    return 0;
}
