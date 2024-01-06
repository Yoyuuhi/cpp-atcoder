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
using Graph = vector<vector<int>>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  auto as = nis(n);
  dsu d(n);
  vector<vector<int>> uvs;

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    uvs.push_back({u, v});
    if (as[u] == as[v]) d.merge(u, v);
  }

  Graph g(n);
  set<pair<int, int>> st;
  for (auto uv : uvs) {
    int u = uv[0], v = uv[1];
    u = d.leader(u);
    v = d.leader(v);
    if (st.find({u, v}) != st.end()) continue;
    st.insert({u, v});
    if (as[u] < as[v]) g[u].push_back(v);
    if (as[v] < as[u]) g[v].push_back(u);
  }

  vector<int> memLeaderCount(200001, 0);
  memLeaderCount[d.leader(0)] = 1;
  vector<vector<int>> dp(200001);
  dp[as[0]].push_back(d.leader(0));
  set<int> st1;
  rep(i, 200001) {
    if (dp[i].size() == 0) continue;
    for (auto v : dp[i]) {
      for (auto to : g[v]) {
        memLeaderCount[to] = max(memLeaderCount[to], memLeaderCount[v] + 1);
        if (st1.find(to) == st1.end()) {
          dp[as[to]].push_back(to);
          st1.insert(to);
        }
      }
    }
  }
  out(memLeaderCount[d.leader(n - 1)]);
}
