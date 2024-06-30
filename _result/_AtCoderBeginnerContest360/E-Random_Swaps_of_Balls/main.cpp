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
using mint = atcoder::modint998244353;
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

  ll n, k;
  cin >> n >> k;

  if (n == 1) {
    out(1);
    return 0;
  }

  vector<mint> ps(2, 0);
  mint K = mint(n * n - 2 * (n - 1)) / (n * n);
  ps[0] = K;
  ps[1] = 1 - K;

  rep(i, k - 1) {
    vector<mint> tps(2, 0);
    tps[0] = ps[0] * K + ps[1] * (1 - K) / (n - 1);
    tps[1] = 1 - tps[0];

    ps = tps;
  }
  mint ans = 0;
  ans += ps[0];
  ans += ps[1] / (n - 1) * mint(2 + n) * (n - 1) / 2;
  out(ans.val());
}
