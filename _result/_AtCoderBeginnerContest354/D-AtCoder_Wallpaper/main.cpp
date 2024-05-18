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

ll X = 4, Y = 2, S = 8;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll k1 = a / 4, k2 = b / 2;
  c -= 4 * k1;
  a = a % 4;
  if (a < 0) {
    a += 4;
    c += 4;
  }

  d -= 2 * k2;
  b = b % 2;
  if (b < 0) {
    b += 2;
    d += 2;
  }

  ll ans = 0;
  vector<vector<ll>> mem1 = {
      {2, 3, 3, 4},
      {1, 1, 2, 4},
      {0, 1, 3, 4},
      {1, 3, 4, 4},
  };
  vector<vector<ll>> mem2 = {
      {3, 6, 7, 8},
      {3, 4, 5, 8},
      {1, 2, 5, 8},
      {1, 4, 7, 8},
  };

  ll h = d - b, w = c - a;
  ans += h / ll(2) * (w / ll(4)) * ll(8);
  if (w % 4) ans += h / ll(2) * mem2[a][w % ll(4) - 1];

  int ix = a;
  if (b == 1) ix = (ix + 3) % ll(4);
  ans += (h % ll(2)) * (w / ll(4)) * ll(4);
  if (w % 4) ans += (h % ll(2)) * mem1[ix][w % ll(4) - 1];

  out(ans);
}
