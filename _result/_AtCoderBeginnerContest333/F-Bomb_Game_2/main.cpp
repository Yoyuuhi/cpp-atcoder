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
T pow(T x, int n) {
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

  int n;
  cin >> n;
  mint x = mint(1) / 2;

  vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
  dp[1][1] = 1;
  rep2(i, 2, n + 1) {
    rep2(j, 1, i + 1) {
      if (j == 1) {
        rep2(k, 1, i) dp[i][j] += dp[i - 1][k] * pow(x, i + 1 - k);
        dp[i][j] /= (1 - pow(x, i));
      } else {
        dp[i][j] = x * dp[i][j - 1] + x * dp[i - 1][j - 1];
      }
    }
  }
  rep2(i, 1, n + 1) cout << dp[n][i].val() << " ";
  outl;
}
