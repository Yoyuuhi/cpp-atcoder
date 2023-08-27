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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<pair<float, float>> xys(n + 1);
  rep(i, n) {
    float x, y;
    cin >> x >> y;
    xys[i + 1] = {x, y};
  }

  vector<vector<float>> dp(n + 1, vector<float>(29, INF));
  dp[1][0] = 0;
  rep2(i, 1, n) {
    rep(j, 29) {
      if (dp[i][j] == INF) continue;
      for (int k = 0; j + k <= 28 && i + 1 + k <= n; k++) {
        float v = sqrt(pow(xys[i + 1 + k].first - xys[i].first, 2) +
                       pow(xys[i + 1 + k].second - xys[i].second, 2));
        dp[i + 1 + k][j + k] = min(dp[i + 1 + k][j + k], dp[i][j] + v);
      }
    }
  }

  float ans = dp[n][0];
  rep2(i, 1, 29) { ans = min(ans, dp[n][i] + (1 << (i - 1))); }
  cout << fixed << setprecision(16) << ans << endl;
}
