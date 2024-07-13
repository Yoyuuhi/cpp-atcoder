#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

void dijkstra(const Graph &G, int s, vector<long long> &dis) {
  int N = G.size();
  dis.resize(N, INFLL);
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

  ll n, m;
  cin >> n >> m;
  auto as = nis(n);

  Graph g(n);
  rep(i, m) {
    ll u, v, b;
    cin >> u >> v >> b;
    u--;
    v--;

    g[u].push_back({v, b + as[v]});
    g[v].push_back({u, b + as[u]});
  }
  vector<ll> dis;
  dijkstra(g, 0, dis);
  rep2(i, 1, n) { cout << dis[i] + as[0] << ' '; }
  outl;
}
