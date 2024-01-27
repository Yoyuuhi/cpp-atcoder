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
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;

void warshall_floyd(vector<vector<long long>> &dist) {
  int V = dist.size();
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] == INFLL || dist[k][j] == INFLL) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
  vector<vector<ll>> dist(n, vector<ll>(n, INFLL));
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    dist[u][v] = w;
  }
  rep(i, n) dist[i][i] = 0;
  warshall_floyd(dist);

  vector<vector<ll>> dp(1 << n, vector<ll>(n, INFLL));
  queue<pair<ll, ll>> que;
  rep(i, n) {
    dp[1 << i][i] = 0;
    que.emplace(1 << i, i);
  }

  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    rep(to, n) {
      if ((p.first & (1 << to)) != 0) continue;
      if (dp[p.first][p.second] == INFLL || dist[p.second][to] == INFLL)
        continue;
      ll bit = p.first | (1 << to),
         val = dp[p.first][p.second] + dist[p.second][to];
      if (dp[bit][to] > val) {
        que.emplace(bit, to);
        dp[bit][to] = val;
      }
    }
  }

  ll ans = INFLL;
  rep(i, n) ans = min(ans, dp[(1 << n) - 1][i]);
  if (ans == INFLL) {
    out("No");
  } else {
    out(ans);
  }
}
