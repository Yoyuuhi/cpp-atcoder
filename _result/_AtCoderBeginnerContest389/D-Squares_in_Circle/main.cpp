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

double r, rr;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> r;
  ll ans = 0;
  rep2(i, -r, r + 1) {
    rr = abs(i);

    vector<vector<double>> vs = {
        {0.5, -0.5},
        {0.5, 0.5},
    };

    int x = r;
    for (auto v : vs) {
      auto res = sqrt(tpow(r, 2) - tpow(rr + v[1], 2)) - v[0];
      if (res >= 0) {
        x = min(x, int(res));
      } else {
        x = -1;
      }
    }
    if (x >= 0) ans += x * 2 + 1;
  }
  out(ans);
}
