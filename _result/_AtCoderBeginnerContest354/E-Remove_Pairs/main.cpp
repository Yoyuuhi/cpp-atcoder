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

int n;
vector<int> dp;
vector<vector<int>> as;

void calc(ll bit, int p) {
  int pp = (p + 1) % 2;

  rep(i, n) {
    rep2(j, i + 1, n) {
      if ((bit & (1 << i)) || (bit & (1 << j))) continue;
      if (as[i][0] != as[j][0] && as[i][1] != as[j][1]) continue;
      ll to = bit + (1 << i) + (1 << j);
      if (dp[to] == -1) calc(to, pp);
      if (dp[to] == p) {
        dp[bit] = p;
        return;
      }
    }
  }
  dp[bit] = pp;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    as.push_back({a, b});
  }

  dp.assign(1 << n, -1);
  calc(0, 0);
  cout << (dp[0] == 0 ? "Takahashi" : "Aoki") << endl;
}
