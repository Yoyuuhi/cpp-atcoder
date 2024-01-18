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

  ll n;
  cin >> n;
  auto ps = nis(n);
  auto qs = nis(n);

  vector<mint> dp(n + 1);
  dp[1] = 1;
  dp[2] = 3;
  rep2(i, 3, n + 1) dp[i] = dp[i - 1] + dp[i - 2];

  dsu d(n + 1);
  rep(i, n) d.merge(ps[i], qs[i]);

  vector<bool> passed(n + 1, false);
  mint ans = 1;
  rep2(i, 1, n + 1) {
    if (passed[d.leader(i)]) continue;
    passed[d.leader(i)] = true;
    ans *= dp[d.size(i)];
  }
  out(ans.val());
}
