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
T POW(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

ll N, D, WSUM;
vector<ll> WS;
double calc(int bit) {
  ll sum = 0;
  rep(i, N) {
    if (((1 << i) & bit) == 0) continue;
    sum += WS[i];
  }
  return POW(sum - WSUM / double(D), 2);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> N >> D;
  WS = nis(N);
  for (auto W : WS) WSUM += W;

  vector<vector<double>> dp(D + 1, vector<double>(1 << N, INFLL));
  rep2(bit, 1, 1 << N) dp[1][bit] = calc(bit);

  rep2(d, 2, D + 1) {
    rep2(bit2, 1, 1 << N) {
      ll bit1 = bit2;
      while (bit1 > 0) {
        ll diff = bit1 ^ bit2;
        if (diff > 0)
          dp[d][bit2] = min(dp[d][bit2], dp[d - 1][bit1] + dp[1][diff]);
        bit1 = (bit1 - 1) & bit2;
      }
    }
  }
  cout << fixed << setprecision(10) << dp[D][(1 << N) - 1] / double(D) << endl;
}
