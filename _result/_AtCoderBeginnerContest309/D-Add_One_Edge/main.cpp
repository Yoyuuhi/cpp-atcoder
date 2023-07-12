#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
  int N = G.size();
  dis.resize(N, INF);
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  Graph g(n1 + n2);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back({b, 1});
    g[b].push_back({a, 1});
  }
  vector<long long> dis1, dis2;
  dijkstra(g, 0, dis1);
  dijkstra(g, n1 + n2 - 1, dis2);
  ll md1 = 0;
  ll md2 = 0;
  rep(i, n1) md1 = max(md1, dis1[i]);
  rep2(i, n1, n1 + n2) md2 = max(md2, dis2[i]);
  out(md1 + md2 + 1);
}
