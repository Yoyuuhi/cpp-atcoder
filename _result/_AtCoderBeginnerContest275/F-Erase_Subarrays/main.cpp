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
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(m + 1, vector<int>(2, INF)));
  dp[0][0][1] = 0;
  rep(i, n) {
    rep(j, m + 1) {
      rep(k, 2) {
        if (dp[i][j][k] == INF) continue;
        dp[i + 1][j][0] =
            min(dp[i + 1][j][0], !k ? dp[i][j][k] : dp[i][j][k] + 1);
        if (j + as[i] > m) continue;
        dp[i + 1][j + as[i]][1] = min(dp[i + 1][j + as[i]][1], dp[i][j][k]);
      }
    }
  }
  rep2(i, 1, m + 1) {
    int ans = min(dp[n][i][0], dp[n][i][1]);
    if (ans == INF) {
      out(-1);
    } else {
      out(ans);
    }
  }
}
