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
const ll INF = numeric_limits<ll>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  vector<vector<ll>> xyzs(n, vector<ll>(3));
  rep(i, n) {
    ll x, y, z;
    cin >> x >> y >> z;
    xyzs[i] = {x, y, z};
  }

  ll ztotal = 0;
  ll zt = 0;
  vector<vector<ll>> mem;
  rep(i, n) {
    ztotal += xyzs[i][2];
    if (xyzs[i][0] > xyzs[i][1]) {
      zt += xyzs[i][2];
      continue;
    }
    mem.push_back({(xyzs[i][0] + xyzs[i][1] + 1) / 2 - xyzs[i][0], xyzs[i][2]});
  }
  vector<vector<ll>> dp(mem.size() + 1, vector<ll>(100001, INF));
  dp[0][zt] = 0;
  rep(i, mem.size()) {
    rep(j, 100001) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + mem[i][1]] =
          min(dp[i + 1][j + mem[i][1]], dp[i][j] + mem[i][0]);
    }
  }

  ll ans = INF;
  rep2(i, (ztotal + 1) / 2, 100001) { ans = min(ans, dp[mem.size()][i]); }
  out(ans);
}
