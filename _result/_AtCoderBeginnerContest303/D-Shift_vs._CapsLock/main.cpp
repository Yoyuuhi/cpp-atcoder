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

  ll X, Y, z;
  cin >> X >> Y >> z;
  string s;
  cin >> s;

  vector<pair<ll, ll>> dp(s.size() + 1, {INF, INF});
  dp[0] = {0, z};
  rep(i, s.size()) {
    int c = s[i] == 'a' ? 0 : 1;
    int x = X;
    int y = Y;
    if (c) swap(x, y);
    dp[i + 1].first = min(min(dp[i].first + x, dp[i].first + z + y + z),
                          min(dp[i].second + y + z, dp[i].second + z + x));
    dp[i + 1].second = min(min(dp[i].first + x + z, dp[i].first + z + y),
                           min(dp[i].second + y, dp[i].second + z + x + z));
  }
  out(min(dp[s.size()].first, dp[s.size()].second));
}
