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

  ll n, m;
  cin >> n >> m;

  if (n == 0 || m == 0) {
    out(0);
    return 0;
  }

  vector<vector<vector<mint>>> dp(64,
                                  vector<vector<mint>>(64, vector<mint>(2, 0)));
  int b = -1;
  rep(i, 62) if (((ll(1) << i) & n) > 0) { b = i; }
  int flag = ((ll(1) << b) & m) > 0;
  // 0
  dp[b][0][0] = 1;
  // 1
  if (flag) {
    dp[b][1][1] = 1;
  } else {
    dp[b][0][1] = 1;
  }
  // DBG(b);
  // DBG(flag);

  for (int i = b - 1; i >= 0; i--) {
    // 0
    rep(j, 61) {
      dp[i][j][0] += dp[i + 1][j][0];
      if (((ll(1) << i) & n) > 0) {
        dp[i][j][0] += dp[i + 1][j][1];
      } else {
        dp[i][j][1] += dp[i + 1][j][1];
      }
    }

    // 1
    rep(j, 61) {
      if (((ll(1) << i) & m) > 0) {
        dp[i][j + 1][0] += dp[i + 1][j][0];
      } else {
        dp[i][j][0] += dp[i + 1][j][0];
      }

      if (((ll(1) << i) & m) > 0) {
        if (((ll(1) << i) & n) > 0) dp[i][j + 1][1] += dp[i + 1][j][1];
      } else {
        if (((ll(1) << i) & n) > 0) dp[i][j][1] += dp[i + 1][j][1];
      }
    }
  }

  mint ans = 0;
  rep(j, 61) ans += (dp[0][j][0] + dp[0][j][1]) * j;
  out(ans.val());
}
