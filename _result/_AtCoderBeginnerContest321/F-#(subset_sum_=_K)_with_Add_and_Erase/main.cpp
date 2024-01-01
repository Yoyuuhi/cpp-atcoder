#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                            \
  for (auto X : XS) cout << X.val() << " "; \
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

  int q, k;
  cin >> q >> k;

  vector<vector<mint>> dp(q + 1, vector<mint>(k + 1, 0));
  vector<mint> mem(k + 1, 0);
  dp[0][0] = 1;
  rep(i, q) {
    char c;
    int x;
    cin >> c >> x;
    rep(j, k + 1) dp[i + 1][j] += dp[i][j];
    rep(j, k + 1) {
      if (c == '+' && j + x <= k) {
        mem[k]++;
        dp[i + 1][j + x] += dp[i][j];
      }
      if (c == '-' && j + x <= k) {
        dp[i][j + x] -= dp[i][j];
        dp[i + 1][j + x] -= dp[i][j];
      }
    }
    out(dp[i + 1][k].val());
  }
}
