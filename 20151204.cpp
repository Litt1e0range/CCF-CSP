#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10005;
const int maxm = 100005;

struct Edge {
    int from, to;
    Edge(int f, int t):from(f), to(t) {}
};
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn][maxn], conn[maxn];
vector<int> ans;
int n, m;

void dfs(int u) {
    for(int v = 0; v < G[u].size(); v++) {
        Edge e = edges[G[u][v]];
        if(!conn[e.to]) {
			conn[e.to] = true;
			dfs(e.to);
        }
    }
}

bool isConnected(){
	dfs(1);
	for(int i = 1;i <= n;i++){
		if(conn[i] == false) return false;
	}
	return true;
}

void addEdge(int from, int to) {
    edges.push_back(Edge(from, to));
    G[from].push_back(edges.size()-1);
}

void euler(int u) {
    ans.push_back(u);
    for(int v = 0; v < G[u].size(); v++) {
        Edge e = edges[G[u][v]];
        if(!vis[u][e.to]) {
            vis[u][e.to] = vis[e.to][u] = true;
            euler(e.to);
        }
    }
    return;
}

void print() {
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
}

int main(void) {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(G[i].size() & 1) cnt++;
        sort(G[i].begin(), G[i].end(), less<int>());
    }

    if(!isConnected || cnt > 2) cout << -1 << endl;
    else {
        euler(1);
        print();
    }
    return 0;
}
