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

bool comp(pair<ll, ll> &a1, pair<ll, ll> &a2) {
  return a2.second * (a1.first - 1) < a1.second * (a2.first - 1);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, k;
  cin >> n >> k;

  vector<pair<ll, ll>> abs;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    abs.push_back({a, b});
  }
  sort(all(abs), comp);

  ll ans = -1;
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
  dp[0][0] = 1;
  rep(i, n) {
    auto a = abs[i].first, b = abs[i].second;
    rep(j, k) {
      if (dp[i][j] == 0) continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], a * dp[i][j] + b);
      if (j + 1 == k) ans = max(ans, dp[i + 1][j + 1]);
    }
  }

  out(ans);
}
