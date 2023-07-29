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

  string s;
  cin >> s;
  if (s[0] == ')') {
    out(0);
    return 0;
  }
  int n = s.size();
  vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
  dp[1][1] = 1;
  rep2(i, 1, n) {
    rep(j, n) {
      char c = s[i];
      if (c == ')') {
        if (!j) continue;
        dp[i + 1][j - 1] += dp[i][j];
      } else if (c == '(') {
        dp[i + 1][j + 1] += dp[i][j];
      } else {
        if (j) dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j + 1] += dp[i][j];
      }
    }
  }
  out(dp[n][0].val());
}
