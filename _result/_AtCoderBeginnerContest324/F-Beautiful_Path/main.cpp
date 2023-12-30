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

template <typename T>
T bs(T ok, T ng, bool f(T)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  rep(i, 100) {
    auto mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

struct Edge {
  int to;
  double b;
  double c;
};
using Graph = vector<vector<Edge>>;

int n, m;
Graph g;
bool f(double x) {
  vector<double> dp(n, -INFLL);
  dp[0] = 0;
  rep(i, n) {
    if (dp[i] == -INFLL) continue;
    for (auto e : g[i]) {
      dp[e.to] = max(dp[e.to], dp[i] + e.b - e.c * x);
    }
  }
  return dp[n - 1] >= 0;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  g.resize(n);
  rep(i, m) {
    int u, v, b, c;
    cin >> u >> v >> b >> c;
    u--;
    v--;
    g[u].push_back({v, double(b), double(c)});
  }

  auto ans = bs(double(0), double(2) * tpow(10, 9), f);
  cout << fixed << setprecision(16) << ans << endl;
}
