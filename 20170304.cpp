#include <cstdio>
#include <algorithm>
#define MAXM 200005
#define MAXN 100005

using std::sort;
using std::min;
using std::max;

struct Edge {
	int from,to;
	int cost;
} edge[MAXM];
struct DisjointSet {
	int par;
	int rank;
} ds[MAXN];

int n,m;

void init() {
	for(int i = 0; i <= n; i++) {
		ds[i].par = i;
		ds[i].rank = 0;
	}
}

int find(int x) {
	if(ds[x].par == x) {
		return x;
	} else {
		return ds[x].par = find(ds[x].par);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return ;
	if(ds[x].rank < ds[y].rank) {
		ds[x].par = y;
	} else {
		ds[y].par = x;
		if(ds[x].rank == ds[y].rank) {
			ds[x].rank++;
		}
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

bool cmp(struct Edge a, struct Edge b) {
	return a.cost < b.cost;
}

int Kruskal() {
	std::sort(edge,edge+m,cmp);
	int res = 0;
	for(int i = 0; i < m; i++) {
		struct Edge e = edge[i];
		if(!same(1, n) && !same(e.from,e.to)) {
			unite(e.from, e.to);
			res = e.cost;
		}
	}
	return res;
}

int main(void) {
	while(scanf("%d %d",&n,&m) != EOF) {
		init();
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost);
		}
		printf("%d\n", Kruskal());
	}
	return 0;
}
