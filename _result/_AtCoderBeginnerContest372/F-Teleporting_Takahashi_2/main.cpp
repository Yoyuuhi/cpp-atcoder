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

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> xys;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    xys.push_back({x, y});
  }

  vector<mint> dp(n, 0);
  dp[0] = 1;
  rep(i, k) {
    vector<pair<int, mint>> mem;
    for (auto xy : xys) {
      int x = xy[0], y = xy[1];
      int xx = ((x - i) % n + n) % n;
      int yy = ((y - i - 1) % n + n) % n;
      mem.push_back({yy, dp[xx]});
    }

    for (auto pp : mem) dp[pp.first] += pp.second;
  }

  mint ans = 0;
  for (auto p : dp) ans += p;
  out(ans.val());
}
