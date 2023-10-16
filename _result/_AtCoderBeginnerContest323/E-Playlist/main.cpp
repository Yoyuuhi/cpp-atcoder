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

  int n, x;
  cin >> n >> x;
  vector<int> ts(n);
  rep(i, n) cin >> ts[i];

  vector<mint> dp(x + 1, 0);
  dp[0] = 1;
  mint ans = 0;
  rep(i, x + 1) {
    if (!dp[i].val()) continue;
    if (i + ts[0] > x) ans += dp[i] / n;
    for (auto t : ts) {
      if (i + t <= x) dp[i + t] += dp[i] / n;
    }
  }
  out(ans.val());
}
