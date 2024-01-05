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

  int n, m;
  cin >> n >> m;
  Graph g(n);
  vector<int> vs;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (u == -1) {
      vs.push_back(v);
      continue;
    }
    g[u].push_back(Edge{v, 1});
    g[v].push_back(Edge{u, 1});
  }

  vector<ll> dis1, dis2;
  dijkstra(g, 0, dis1);
  dijkstra(g, n - 1, dis2);

  ll uv = dis1[n - 1];
  ll du = INFLL, dv = INFLL;
  for (auto v : vs) {
    du = min(du, dis1[v]);
    dv = min(dv, dis2[v]);
  }

  vector<ll> ans;
  rep(i, n) {
    ll a = uv;
    if (du != INFLL && dv != INFLL) a = min(a, du + dv + 2);
    if (dis1[i] != INFLL && dv != INFLL) a = min(a, dis1[i] + dv + 1);
    if (du != INFLL && dis2[i] != INFLL) a = min(a, du + dis2[i] + 1);
    if (a == INFLL) {
      ans.push_back(-1);
    } else {
      ans.push_back(a);
    }
  }
  outs(ans);
}
