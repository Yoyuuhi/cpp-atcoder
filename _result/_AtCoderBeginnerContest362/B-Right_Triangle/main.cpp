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

  vector<vector<int>> xys;
  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    xys.push_back({x, y});
  }

  rep(i, 3) {
    int x1 = xys[i][0], y1 = xys[i][1];
    int x2 = xys[(i + 1) % 3][0], y2 = xys[(i + 1) % 3][1];
    int x3 = xys[(i + 2) % 3][0], y3 = xys[(i + 2) % 3][1];

    int d1 = tpow(x1 - x2, 2) + tpow(y1 - y2, 2);
    int d2 = tpow(x1 - x3, 2) + tpow(y1 - y3, 2);
    int d3 = tpow(x3 - x2, 2) + tpow(y3 - y2, 2);

    if (d1 + d2 == d3) {
      out("Yes");
      return 0;
    }
  }
  out("No");
}
