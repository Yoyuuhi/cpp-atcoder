#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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
  int to;
};
using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G) {
  vector<int> ans;
  int n = (int)G.size();
  vector<int> ind(n);
  for (int i = 0; i < n; i++) {
    for (auto e : G[i]) {
      ind[e.to]++;
    }
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (ind[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int now = que.front();
    ans.push_back(now);
    que.pop();
    for (auto e : G[now]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        que.push(e.to);
      }
    }
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;

  vector<vector<int>> uvs;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    uvs.push_back({u, v});
  }
  auto ws = nis(n);
  auto as = nis(n);

  Graph g(n);
  for (auto uv : uvs) {
    int u = uv[0], v = uv[1];
    if (ws[u] > ws[v]) g[u].push_back({v});
    if (ws[v] > ws[u]) g[v].push_back({u});
  }

  auto ts = topo_sort(g);
  vector<ll> mem(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    int t = ts[i];

    vector<ll> dp(ws[t], -INFLL);
    dp[0] = 0;
    ll ans = 0;
    for (auto e : g[t]) {
      int to = e.to;
      for (int ii = ws[t] - 1; ii >= 0; ii--) {
        if (dp[ii] == -INFLL) continue;
        if (ws[to] + ii < ws[t]) {
          dp[ws[to] + ii] = max(dp[ws[to] + ii], dp[ii] + mem[to]);
          ans = max(ans, dp[ws[to] + ii]);
        }
      }
    }
    mem[t] = ans + 1;
  }
  ll ans = 0;
  rep(i, n) ans += as[i] * mem[i];

  out(ans);
}
