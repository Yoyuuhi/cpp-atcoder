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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string t;
  cin >> t;
  int n;
  cin >> n;

  vector<int> dp(t.size() + 1, INF);
  dp[0] = 0;
  rep(i, n) {
    int a;
    cin >> a;

    vector<int> tdp = dp;
    rep(j, a) {
      string s;
      cin >> s;

      for (int k = t.size() - 1; k >= 0; k--) {
        if (k + s.size() > t.size() || dp[k] == INF) continue;
        if (t.substr(k, s.size()) != s) continue;
        tdp[k + s.size()] = min(tdp[k + s.size()], dp[k] + 1);
      }
    }
    dp = tdp;
  }
  if (dp[t.size()] == INF) {
    out(-1);
  } else {
    out(dp[t.size()]);
  }
}
