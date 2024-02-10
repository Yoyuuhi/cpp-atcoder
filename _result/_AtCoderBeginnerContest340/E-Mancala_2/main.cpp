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

using S = long long;
using F = long long;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INFLL; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  auto as = nis(n), bs = nis(m);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(as);

  for (auto b : bs) {
    ll num = seg.get(b);
    if (num == 0) continue;
    ll t = num / n;
    ll res = num % n;
    int l = (b + 1) % n, r = (b + res) % n;
    seg.apply(b, -num);
    seg.apply(0, n, t);
    if (res == 0) continue;
    if (l <= r) {
      seg.apply(l, r + 1, 1);
    } else {
      seg.apply(0, n, 1);
      seg.apply(r + 1, l, -1);
    }
  }
  rep(i, n) cout << seg.get(i) << ' ';
  outl;
}
