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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> uvs;
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    uvs.push_back({w, u, v});
  }
  sort(all(uvs));

  vector<pair<int, int>> mem(n, pair<int, int>{0, 0});
  rep(i, k) {
    int a;
    cin >> a;
    a--;
    mem[a].first++;
  }
  rep(i, k) {
    int b;
    cin >> b;
    b--;
    mem[b].second++;
  }

  dsu d(n);
  ll ans = 0;
  for (auto uv : uvs) {
    auto w = uv[0], u = uv[1], v = uv[2];
    if (d.same(u, v)) continue;
    auto m1 = mem[d.leader(u)], m2 = mem[d.leader(v)];
    pair<int, int> m = {m1.first + m2.first, m1.second + m2.second};
    if (m.first >= m.second) {
      ans += w * m.second;
      m.first -= m.second;
      m.second = 0;
    } else {
      ans += w * m.first;
      m.second -= m.first;
      m.first = 0;
    }
    d.merge(u, v);
    mem[d.leader(u)] = m;
  }
  out(ans);
}
