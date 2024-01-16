#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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

int delNum(int j) {
  if (j == 0) return 0;
  if (j < 4) return 1;
  return 2;
}

ll n, p;
void calc(ll &num1, ll num2) { num1 = (num1 + num2) % p; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> p;
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, 0)));

  rep(i, n) {
    rep(j, 2) {
      rep(k, 2) { dp[i][j][k] = 0; }
    }
  }

  dp[0][0][1] = 1;
  dp[1][0][0] = 1;
  dp[1][1][0] = 2;

  rep(i, n - 2) {
    vector<vector<vector<ll>>> dpt(n, vector<vector<ll>>(2, vector<ll>(2, 0)));
    rep(j, n) {
      calc(dpt[j][0][1], dp[j][0][1]);
      if (j + 1 < n) {
        calc(dpt[j + 1][0][1], dp[j][0][1]);
        calc(dpt[j + 1][1][0], dp[j][0][1] * 2);
      }
      if (j + 2 < n) {
        calc(dpt[j + 2][1][0], dp[j][0][1] * 2);
      }

      calc(dpt[j][0][1], dp[j][0][0]);
      if (j + 1 < n) {
        calc(dpt[j + 1][0][0], dp[j][0][0]);
        calc(dpt[j + 1][1][0], dp[j][0][0] * 2);
      }

      calc(dpt[j][0][1], dp[j][1][0]);
      if (j + 1 < n) {
        calc(dpt[j + 1][0][0], dp[j][1][0]);
        calc(dpt[j + 1][1][0], dp[j][1][0] * 2);
      }
    }
    dp = dpt;
  }

  vector<ll> ans(n, 0);
  rep(i, n) {
    calc(ans[i], dp[i][0][1]);
    calc(ans[i], dp[i][0][0]);
    calc(ans[i], dp[i][1][0]);
    if (i + 1 < n) calc(ans[i + 1], dp[i][0][1]);
  }
  rep2(i, 1, n) cout << ans[i] << ' ';
  outl;
}
