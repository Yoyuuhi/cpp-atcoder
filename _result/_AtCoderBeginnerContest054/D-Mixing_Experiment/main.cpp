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

  int n, ma, mb;
  cin >> n >> ma >> mb;

  int l = 401 * 401;
  vector<vector<int>> dp(n + 1, vector<int>(l, INF));
  dp[0][0] = 0;
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    rep(j, l) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 401 * a + b] =
          min(dp[i + 1][j + 401 * a + b], dp[i][j] + c);
    }
  }

  int ans = INF;
  rep2(i, 1, l) {
    int ia = i / 401;
    int ib = i % 401;
    if (ia * mb == ib * ma) ans = min(ans, dp[n][i]);
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
