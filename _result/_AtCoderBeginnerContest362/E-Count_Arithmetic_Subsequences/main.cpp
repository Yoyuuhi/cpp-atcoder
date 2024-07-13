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

  int n;
  cin >> n;
  auto as = nis(n);

  vector<vector<map<ll, mint>>> dp(n, vector<map<ll, mint>>(n + 1));
  vector<mint> ans(n + 1, 0);
  ans[1] = n;
  rep(i, n) {
    rep(j, i) {
      dp[i][2][as[i] - as[j]]++;
      ans[2]++;
    }
  }

  rep2(i, 2, n) {
    rep(j, i) {
      ll diff = as[i] - as[j];
      rep(num, n) {
        if (dp[j][num].find(diff) == dp[j][num].end()) continue;
        dp[i][num + 1][diff] += dp[j][num][diff];
        ans[num + 1] += dp[j][num][diff];
      }
    }
  }

  rep2(i, 1, n + 1) cout << ans[i].val() << ' ';
  outl;
}
