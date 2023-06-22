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
  vector<pair<ll, ll>> dp(n + 1, {-1, -1});
  dp[0].first = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x) {
      dp[i + 1].second = dp[i].first + y;
    } else {
      dp[i + 1].first = dp[i].first + y;
      if (dp[i].second != -1) {
        dp[i + 1].first = max(dp[i + 1].first, dp[i].second + y);
      }
    }
    dp[i + 1].first = max(dp[i + 1].first, dp[i].first);
    dp[i + 1].second = max(dp[i + 1].second, dp[i].second);
  }
  out(max(dp[n].first, dp[n].second));
}
