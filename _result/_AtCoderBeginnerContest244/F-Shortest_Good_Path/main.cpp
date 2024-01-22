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

using Graph = vector<vector<int>>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  Graph g(n);

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<vector<ll>> as(1 << n, vector<ll>(n, INFLL));
  as[0][0] = 0;
  queue<pair<ll, ll>> que;
  rep(i, n) {
    as[1 << i][i] = 1;
    que.emplace(1 << i, i);
  }

  while (!que.empty()) {
    auto q = que.front();
    que.pop();
    ll bit = q.first, v = q.second;
    for (auto to : g[v]) {
      ll val = as[bit][v];
      ll bit1 = bit ^ (1 << to);
      if (as[bit1][to] > val + 1) {
        as[bit1][to] = val + 1;
        que.emplace(bit1, to);
      }
    }
  }

  ll ans = 0;
  rep(i, 1 << n) {
    ll a = INFLL;
    for (auto a0 : as[i]) a = min(a, a0);
    ans += a;
  }
  out(ans);
}
