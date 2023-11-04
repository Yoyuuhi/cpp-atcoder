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
  vector<int> ps(n);
  rep(i, n) cin >> ps[i];

  vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
  rep(i, n) dp[i][1] = ps[i];

  vector<double> ss(n);
  ss[0] = 1;
  rep2(i, 1, n) ss[i] = 0.9 * ss[i - 1];
  rep2(i, 1, n) ss[i] += ss[i - 1];

  double ans = ps[n - 1] - 1200;
  vector<double> memMax(n + 1, 0);
  memMax[1] = ps[n - 1];
  for (int idx = n - 1; idx >= 0; idx--) {
    for (int level = n - idx; level >= 1; level--) {
      dp[idx][level] = pow(0.9, level - 1) * ps[idx] + memMax[level - 1];
      ans = max(ans, dp[idx][level] / ss[level - 1] - 1200.0 / sqrt(level));
      memMax[level] = max(memMax[level], dp[idx][level]);
    }
  }
  cout << fixed << setprecision(8) << ans << endl;
}
