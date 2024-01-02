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

  int h, w;
  cin >> h >> w;
  auto rs = nis(h);
  auto cs = nis(w);
  vector<string> as(h);
  rep(i, h) cin >> as[i];

  ll dp[h][w][4];
  rep(i, h) rep(j, w) rep(k, 4) dp[i][j][k] = INFLL;
  dp[0][0][0] = 0;
  dp[0][0][1] = rs[0];
  dp[0][0][2] = cs[0];
  dp[0][0][3] = rs[0] + cs[0];

  rep(i, h) {
    rep(j, w) {
      int ii = i + 1;
      int jj = j + 1;
      char c1 = as[i][j];

      if (ii < h) {
        char c2 = as[ii][j];
        if (c1 == c2) {
          dp[ii][j][0] = min(dp[ii][j][0], dp[i][j][0]);
          dp[ii][j][1] = min(dp[ii][j][1], dp[i][j][1] + rs[ii]);
          dp[ii][j][2] = min(dp[ii][j][2], dp[i][j][2]);
          dp[ii][j][3] = min(dp[ii][j][3], dp[i][j][3] + rs[ii]);
        } else {
          dp[ii][j][1] = min(dp[ii][j][1], dp[i][j][0] + rs[ii]);
          dp[ii][j][0] = min(dp[ii][j][0], dp[i][j][1]);
          dp[ii][j][3] = min(dp[ii][j][3], dp[i][j][2] + rs[ii]);
          dp[ii][j][2] = min(dp[ii][j][2], dp[i][j][3]);
        }
      }
      if (jj < w) {
        char c2 = as[i][jj];
        if (c1 == c2) {
          dp[i][jj][0] = min(dp[i][jj][0], dp[i][j][0]);
          dp[i][jj][1] = min(dp[i][jj][1], dp[i][j][1]);
          dp[i][jj][2] = min(dp[i][jj][2], dp[i][j][2] + cs[jj]);
          dp[i][jj][3] = min(dp[i][jj][3], dp[i][j][3] + cs[jj]);
        } else {
          dp[i][jj][2] = min(dp[i][jj][2], dp[i][j][0] + cs[jj]);
          dp[i][jj][3] = min(dp[i][jj][3], dp[i][j][1] + cs[jj]);
          dp[i][jj][0] = min(dp[i][jj][0], dp[i][j][2]);
          dp[i][jj][1] = min(dp[i][jj][1], dp[i][j][3]);
        }
      }
    }
  }

  ll ans = INFLL;
  rep(i, 4) ans = min(ans, dp[h - 1][w - 1][i]);
  out(ans);
}
