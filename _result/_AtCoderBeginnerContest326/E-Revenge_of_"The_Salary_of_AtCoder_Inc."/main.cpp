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
  vector<mint> as(n);
  rep(i, n) {
    int a;
    cin >> a;
    as[i] = a;
  }

  vector<mint> dp(n + 1, 0);
  dp[1] = mint(1) / n;
  mint ans = 0;
  rep2(i, 1, n + 1) {
    if (i + 1 <= n) dp[i + 1] += dp[i] + dp[i] / n;
    ans += as[i - 1] * dp[i];
  }
  out(ans.val());
}
