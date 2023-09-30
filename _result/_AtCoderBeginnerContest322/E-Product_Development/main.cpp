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

  ll n, k, p;
  cin >> n >> k >> p;
  vector<vector<ll>> cas(n, vector<ll>(k + 1));
  rep(i, n) {
    rep(j, k + 1) { cin >> cas[i][j]; }
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(pow(6, k), INF));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, pow(6, k)) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      auto ca = cas[i];
      ll c = ca[0];
      vector<ll> ks(k, 0);
      int jj = j;
      int idx = 0;
      while (jj) {
        ks[idx] = jj % 6;
        jj /= 6;
        idx++;
      }
      rep2(i, 1, k + 1) { ks[i - 1] = min(ll(5), ks[i - 1] + ca[i]); }
      ll nj = 0;
      ll six = 1;
      rep(i, k) {
        nj += six * ks[i];
        six *= 6;
      }
      dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + c);
    }
  }

  ll ans = INF;
  rep(j, pow(6, k)) {
    if (dp[n][j] == INF) continue;
    vector<ll> ks(k, 0);
    int jj = j;
    int idx = 0;
    while (jj) {
      ks[idx] = jj % 6;
      jj /= 6;
      idx++;
    }

    bool poss = true;
    for (auto k : ks) {
      if (k < p) {
        poss = false;
        break;
      }
    }
    if (poss) ans = min(ans, dp[n][j]);
  }
  if (ans == INF) {
    out(-1);
  } else {
    out(ans);
  }
}
