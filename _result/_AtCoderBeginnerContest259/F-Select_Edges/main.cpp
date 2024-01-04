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
struct Edge {
  long long to;
  long long w;
};
using Graph = vector<vector<Edge>>;
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

ll n;
vector<ll> ds;

vector<bool> seen;
vector<vector<ll>> dp;
void dfs(const Graph &G, int v) {
  seen[v] = true;

  vector<ll> ws;
  for (auto next : G[v]) {
    int to = next.to;
    if (seen[to]) continue;
    dfs(G, to);
    ll valTo = max(dp[to][0], dp[to][1]);
    if (ds[v] > 0) {
      dp[v][0] += valTo;
    } else {
      dp[v][1] += valTo;
    }

    if (ds[to] > 0) ws.push_back(next.w + dp[to][0] - valTo);
  }

  ll sum = dp[v][0];
  sort(all(ws), greater<ll>());
  rep(i, min(ll(ws.size()), ds[v])) {
    sum += ws[i];
    if (i < ds[v] - 1) {
      dp[v][0] = max(dp[v][0], sum);
    } else {
      dp[v][1] = max(dp[v][1], sum);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n;
  ds = nis(n);

  Graph g(n);
  rep(i, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  seen.assign(n, false);
  dp.assign(n, vector<ll>(2, 0));
  dfs(g, 0);
  out(max(dp[0][0], dp[0][1]));
}
