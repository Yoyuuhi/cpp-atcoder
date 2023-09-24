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

  string n;
  cin >> n;
  int sn = 0;
  for (auto num : n) {
    sn += num - '0';
  }
  if (!(sn % 3)) {
    out(0);
    return 0;
  }

  vector<vector<int>> dp(n.size() + 1, vector<int>(163, INF));
  dp[0][sn] = 0;
  rep(i, n.size()) {
    rep(j, 163) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      int num = n[i] - '0';
      dp[i + 1][j - num] = min(dp[i + 1][j - num], dp[i][j] + 1);
    }
  }
  int ans = INF;
  rep2(i, 1, 163) {
    if (i % 3) continue;
    ans = min(ans, dp[n.size()][i]);
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
