#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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

int n;
vector<int> as;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  as.resize(n);
  rep(i, n) cin >> as[i];
  mint total = 1;
  rep(i, n) total *= as[i];

  vector<vector<mint>> dp(n + 1, vector<mint>(1 << 11, 0));
  dp[0][1] = 1;
  rep(i, n) {
    rep(j, 1 << 11) {
      if (!dp[i][j].val()) continue;
      if (as[i] > 10) dp[i + 1][j] += dp[i][j] * (as[i] - 10);
      rep2(k, 1, min(as[i], 10) + 1) {
        int bit = j;
        rep(l, 10) {
          if (!(j & (1 << l)) || k + l > 10) continue;
          bit |= (1 << (k + l));
        }
        dp[i + 1][bit] += dp[i][j];
      }
    }
  }

  mint count = 0;
  rep2(i, 1 << 10, 1 << 11) count += dp[n][i];
  cout << (count / total).val() << endl;
}
