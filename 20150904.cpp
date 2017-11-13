#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define MAXN 10005
#define MAXM 100005

using namespace std;

vector<int> G[MAXN];
vector<int> rG[MAXN];//�ѱ߷����ʾ��ͼ
vector<int> post;//�������˳��Ķ����б�
map<int,int> mp;//��¼ÿ��ǿ��ͨ�����������Ķ�����
bool vis[MAXN];//���ʱ��
int cmp[MAXN];//����ǿ��ͨ�������ز�����
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
    return k;//����ǿ��ͨ����������
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
