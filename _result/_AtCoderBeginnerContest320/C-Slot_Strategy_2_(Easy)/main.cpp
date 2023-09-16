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

  int m;
  cin >> m;
  vector<string> ss(3);
  rep(i, 3) cin >> ss[i];
  rep(i, 3) {
    string tss = ss[i];
    rep(j, 2) { tss += ss[i]; }
    ss[i] = tss;
  }

  int ans = INF;
  rep(i, 10) {
    char c = '0' + i;
    vector<vector<int>> dp(3 * m + 1, vector<int>(8, -1));
    dp[0][0] = 0;
    rep(j, 3 * m) {
      rep(bit, 8) {
        if (dp[j][bit] == -1) continue;
        dp[j + 1][bit] = max(dp[j + 1][bit], dp[j][bit]);
        rep(k, 3) {
          if (bit & (1 << k)) continue;
          if (ss[k][j] == c) {
            if (bit + (1 << k) == 7) {
              ans = min(ans, j);
              break;
            }
            dp[j + 1][bit + (1 << k)] =
                max(dp[j + 1][bit + (1 << k)], dp[j][bit] + 1);
          }
        }
      }
    }
  }

  if (ans != INF) {
    out(ans);
  } else {
    out(-1);
  }
}
