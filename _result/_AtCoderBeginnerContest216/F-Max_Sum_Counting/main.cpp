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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int n;
vector<pair<int, int>> ps;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  auto as = nis(n);
  auto bs = nis(n);
  ps.resize(n);
  rep(i, n) ps[i] = {as[i], bs[i]};
  sort(all(ps));

  vector<vector<mint>> dp(n + 1, vector<mint>(5001, 0));
  dp[0][0] = 1;
  mint ans = 0;
  rep(i, n) {
    int a = ps[i].first;
    int b = ps[i].second;
    rep(j, 5001) {
      if (a - b >= j) ans += dp[i][j];
      if (dp[i][j] == 0) continue;
      dp[i + 1][j] += dp[i][j];
      if (j + b <= 5000) dp[i + 1][j + b] += dp[i][j];
    }
  }
  out(ans.val());
}
