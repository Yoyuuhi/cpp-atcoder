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

int calc(int s, int d, vector<vector<int>> &g, int ta) {
  for (auto t : g[s])
    if (s + d == t) return calc(t, d, g, ta + 1);
  return ta;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto hs = nis(n);

  map<int, vector<int>> mem;
  rep(i, n) {
    int h = hs[i];
    mem[h].push_back(i);
  }

  int ans = 1;
  for (auto m : mem) {
    auto is = m.second;
    vector<vector<int>> g(n);
    rep(i, is.size()) rep2(j, i + 1, is.size()) g[is[i]].push_back(is[j]);

    rep(i, n) {
      int s = i;
      for (auto t : g[s]) ans = max(ans, calc(t, t - s, g, 2));
    }
  }
  out(ans);
}
