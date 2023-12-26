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
T pow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int n;
vector<int> ds;
int l1, c1, k1;
int l2, c2, k2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  ds = nis(n);
  cin >> l1 >> c1 >> k1;
  cin >> l2 >> c2 >> k2;

  vector<vector<int>> dp(n + 1, vector<int>(k1 + 1, INF));
  dp[0][0] = 0;
  rep(i, n) {
    int d = ds[i];
    rep(j, k1 + 1) {
      if (dp[i][j] == INF) continue;
      rep2(k, j, k1 + 1) {
        int res = max(d - (k - j) * l1, 0);
        int num = res / l2 + (res % l2 ? 1 : 0);
        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + num);
      }
    }
  }

  ll ans = INFLL;
  rep(i, k1 + 1) {
    if (dp[n][i] > k2) continue;
    ans = min(ans, ll(i) * c1 + ll(dp[n][i]) * c2);
  }
  cout << (ans == INFLL ? -1 : ans) << endl;
}
