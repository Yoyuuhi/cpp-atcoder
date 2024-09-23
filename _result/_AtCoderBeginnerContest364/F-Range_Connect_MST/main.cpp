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

struct S {
  long long value;
  int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
  if (f != ID) x.value = f * x.size;
  return x;
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, q;
  cin >> n >> q;
  vector<vector<ll>> clrs;

  ll ans = 0;
  rep(i, q) {
    int l, r, c;
    cin >> l >> r >> c;
    l--;
    r--;
    clrs.push_back({c, l, r});
    ans += c;
  }
  sort(all(clrs));

  vector<S> v(n, {0, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (auto clr : clrs) {
    auto c = clr[0], l = clr[1], r = clr[2];
    auto p = seg.prod(l + 1, r + 1);
    ans += c * (r - l - p.value);
    seg.apply(l + 1, r + 1, 1);
  }

  auto p = seg.all_prod();
  if (p.value != n - 1) {
    out(-1);
    return 0;
  }

  out(ans);
}
