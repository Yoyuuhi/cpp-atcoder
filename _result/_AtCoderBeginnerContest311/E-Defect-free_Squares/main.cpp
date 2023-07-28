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

  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<bool>> grid(h, vector<bool>(w, false));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    grid[a][b] = true;
  }

  vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, 0));
  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (grid[i][j]) continue;
      dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
      ans += dp[i + 1][j + 1];
    }
  }
  out(ans);
}
