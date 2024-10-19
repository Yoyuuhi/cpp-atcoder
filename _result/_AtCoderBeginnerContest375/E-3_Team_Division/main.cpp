#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<vector<int>> aps;
  int sb = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    aps.push_back({a, b});
    sb += b;
  }
  if (sb % 3 != 0) {
    out(-1);
    return 0;
  }

  auto p = sb / 3;
  vector<vector<int>> dp(n + 1, vector<int>(1000001, INF));
  dp[0][0] = 0;
  rep(i, n) {
    int a = aps[i][0], b = aps[i][1];
    rep(j, dp[i].size()) {
      if (dp[i][j] == INF) continue;
      vector<int> ts(3, INF);
      if (j + b < dp[i].size()) ts[0] = dp[i][j] + 1;
      if (j + b * 1000 < dp[i].size()) ts[1] = dp[i][j] + 1;
      ts[2] = dp[i][j] + 1;
      if (ts[a] != INF) ts[a]--;

      if (j + b < dp[i].size()) dp[i + 1][j + b] = min(dp[i + 1][j + b], ts[0]);
      if (j + b * 1000 < dp[i].size())
        dp[i + 1][j + b * 1000] = min(dp[i + 1][j + b * 1000], ts[1]);
      dp[i + 1][j] = min(dp[i + 1][j], ts[2]);
    }
  }

  if (dp[n][p * 1000 + p] == INF) {
    out(-1);
  } else {
    out(dp[n][p * 1000 + p]);
  }
}
