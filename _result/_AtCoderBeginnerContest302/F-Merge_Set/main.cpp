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
#define rep3(i, s, n) for (int i = (s); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
  int N = G.size();
  dis.resize(N, INF);
  priority_queue<P, vector<P>, greater<P>>
      pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {  // 最短距離で無ければ無視
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] >
          dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> sx(n);
  rep(i, n) {
    int a;
    cin >> a;
    vector<int> ss(a);
    rep(j, a) cin >> ss[j];
    sx[i] = ss;
  }

  Graph g(m + n);
  rep(i, n) {
    for (auto s : sx[i]) {
      s--;
      int t = i + m;
      g[s].push_back(Edge{t, 1});
      g[t].push_back(Edge{s, 1});
    }
  }
  vector<long long> dis;
  dijkstra(g, 0, dis);
  if (dis[m - 1] == INF) {
    out(-1);
    return 0;
  }
  out(dis[m - 1] / 2 - 1);
}
