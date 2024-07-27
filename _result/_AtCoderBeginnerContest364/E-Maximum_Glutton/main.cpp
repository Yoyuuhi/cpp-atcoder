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

  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int>> abv(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    abv[i] = {a, b};
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, INF));
  dp[0][0] = 0;
  for (auto ab : abv) {
    int a = ab[0], b = ab[1];
    for (int num = n; num >= 0; num--) {
      for (int xx = x; xx >= 0; xx--) {
        if (dp[num][xx] == INF) continue;
        if (xx + a <= x && dp[num][xx] + b <= y)
          dp[num + 1][xx + a] = min(dp[num + 1][xx + a], dp[num][xx] + b);
      }
    }
  }

  int ans = 1;
  rep(num, n + 1) {
    rep(xx, x + 1) {
      if (dp[num][xx] != INF) ans = max(ans, min(n, num + 1));
    }
  }
  out(ans);
}
