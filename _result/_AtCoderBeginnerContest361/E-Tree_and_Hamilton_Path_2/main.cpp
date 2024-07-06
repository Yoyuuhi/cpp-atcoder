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
T tpow(T x, ll n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

pair<ll, ll> dfs(const Graph &G, ll u,
                 ll par) {  // 最遠点間距離と最遠点を求める
  pair<ll, ll> ret = make_pair(0, u);
  for (auto e : G[u]) {
    if (e.to == par) continue;
    auto next = dfs(G, e.to, u);
    next.first += e.cost;
    ret = max(ret, next);
  }
  return ret;
}

ll tree_diamiter(const Graph &G) {
  pair<ll, ll> p = dfs(G, 0, -1);
  pair<ll, ll> q = dfs(G, p.second, -1);
  return q.first;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  Graph g(n);
  ll ss = 0;
  rep(i, n - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    ss += c * 2;
  }

  ll d = tree_diamiter(g);
  out(ss - d);
}
