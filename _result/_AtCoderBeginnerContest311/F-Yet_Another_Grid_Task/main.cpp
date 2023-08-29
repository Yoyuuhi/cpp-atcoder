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

  int n, m;
  cin >> n >> m;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];
  vector<int> mini(m, n);
  rep(i, n) {
    rep(j, m) {
      if (ss[i][j] == '#') mini[j] = min(mini[j], i);
    }
  }

  vector<vector<mint>> dp(n + 1, vector<mint>(m, 0));
  rep(i, mini[m - 1] + 1) dp[i][m - 1] = 1;
  for (int j = m - 2; j >= 0; j--) {
    for (int i = 0; i <= n; i++) {
      if (i > mini[j]) break;
      dp[i][j] += dp[i][j + 1];
      if (i) dp[i][j] += dp[i - 1][j] - dp[i][j + 1];
      if (i + 1 <= n) dp[i][j] += dp[i + 1][j + 1];
    }
  }

  mint ans = 0;
  rep(i, n + 1) ans += dp[i][0];
  out(ans.val());
}
