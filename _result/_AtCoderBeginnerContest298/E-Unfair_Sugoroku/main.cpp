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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  Modint dp[n + 1][n + 1][2];
  rep(i, n) {
    dp[n][i][0] = 1;
    dp[n][i][1] = 1;
    dp[i][n][0] = 0;
    dp[i][n][1] = 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      rep2(k, 1, p + 1) { dp[i][j][0] += dp[min(i + k, n)][j][1]; }
      dp[i][j][0] /= p;
      rep2(k, 1, q + 1) { dp[i][j][1] += dp[i][min(j + k, n)][0]; }
      dp[i][j][1] /= q;
    }
  }
  out(dp[a][b][0].val());
}
