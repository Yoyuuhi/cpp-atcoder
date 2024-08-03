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

  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> vs = {{'R', 0}, {'P', 1}, {'S', 2}};

  vector<vector<int>> dp(n, vector<int>(3, -1));
  int ii = vs[s[0]];
  dp[0][ii] = 0;
  dp[0][(ii + 1) % 3] = 1;
  rep(i, n - 1) {
    auto c = s[i + 1];
    int v1 = vs[c];
    int v2 = (v1 + 1) % 3;

    rep(j, 3) {
      if (dp[i][j] == -1) continue;

      if (v1 != j) dp[i + 1][v1] = max(dp[i + 1][v1], dp[i][j]);
      if (v2 != j) dp[i + 1][v2] = max(dp[i + 1][v2], dp[i][j] + 1);
    }
  }

  out(max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));
}
