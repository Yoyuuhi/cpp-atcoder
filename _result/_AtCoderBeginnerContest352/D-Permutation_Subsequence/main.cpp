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

using S = long long;
using F = long long;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  auto ps = nis(n);
  if (k == 1) {
    out(0);
    return 0;
  }

  vector<S> v(n + 1);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  int R = -1;
  int ans = INF;
  rep(i, n) {
    while (seg.all_prod() < k && R + 1 < n) {
      R++;
      int l = ps[R];
      int r = min(ps[R] + k - 1, n);
      seg.apply(l, r + 1, 1);
    }
    if (seg.all_prod() == k) {
      ans = min(ans, R - i);
    }
    int l = ps[i];
    int r = min(ps[i] + k - 1, n);
    seg.apply(l, r + 1, -1);
  }
  out(ans);
}
