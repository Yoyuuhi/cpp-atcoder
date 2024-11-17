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

  ll n, m;
  cin >> n >> m;
  auto xs = nis(m), as = nis(m);
  vector<vector<ll>> xas;
  rep(i, m) xas.push_back({xs[i], as[i]});
  sort(all(xas));
  ll ans = 0;

  ll r = n;
  for (ll i = m - 1; i >= 0; i--) {
    auto x = xas[i][0], a = xas[i][1];
    ll l = max(x, r - a + 1);
    if (r - a + 1 < x) {
      out(-1);
      return 0;
    }

    ll num = r - l + 1;
    ans += (r - x + l - x) * num / 2;
    r = l - 1;
  }

  if (r != 0) {
    out(-1);
  } else {
    out(ans);
  }
}
