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

vector<ll> ans;
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (!seen[next.to]) {  // 訪問済みでなければ探索
      ans[next.to] = ans[v] + next.cost;
      dfs(G, next.to);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;

  ans.assign(n, 0);
  seen.assign(n, false);
  Graph g(n);
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].push_back({v, w});
    g[v].push_back({u, -w});
  }

  rep(i, n) {
    if (seen[i]) continue;
    dfs(g, i);
  }
  outs(ans);
}
