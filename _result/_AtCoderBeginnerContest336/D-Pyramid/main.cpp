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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto as = nis(n);

  vector<ll> dp1(n, 0), dp2(n, 0);
  dp1[0] = 1, dp2[n - 1] = 1;
  rep2(i, 1, n) {
    if (as[i] > dp1[i - 1]) {
      dp1[i] = dp1[i - 1] + 1;
    } else {
      dp1[i] = as[i];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (as[i] > dp2[i + 1]) {
      dp2[i] = dp2[i + 1] + 1;
    } else {
      dp2[i] = as[i];
    }
  }
  ll ans = 0;
  rep(i, n) ans = max(ans, min(dp1[i], dp2[i]));
  out(ans);
}
