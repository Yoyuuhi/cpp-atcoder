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
  int oneLeft;
  int oneRight;
  int oneMax;
  int zeroLeft;
  int zeroRight;
  int zeroMax;
  int size;
};
S op(S a, S b) {
  S s = {
      a.oneLeft,
      b.oneRight,
      max(max(a.oneMax, b.oneMax), a.oneRight + b.oneLeft),
      a.zeroLeft,
      b.zeroRight,
      max(max(a.zeroMax, b.zeroMax), a.zeroRight + b.zeroLeft),
      a.size + b.size,
  };
  if (a.oneLeft > 0 && a.oneLeft == a.size) s.oneLeft = a.oneLeft + b.oneLeft;
  if (a.zeroLeft > 0 && a.zeroLeft == a.size)
    s.zeroLeft = a.zeroLeft + b.zeroLeft;
  if (b.oneRight > 0 && b.oneRight == b.size)
    s.oneRight = b.oneRight + a.oneRight;
  if (b.zeroRight > 0 && b.zeroRight == b.size)
    s.zeroRight = b.zeroRight + a.zeroRight;
  return s;
}
S e() { return S{0, 0, 0, 0, 0, 0, 0}; }

using F = bool;
S mapping(F f, S x) {
  if (f) {
    return S{x.zeroLeft, x.zeroRight, x.zeroMax, x.oneLeft,
             x.oneRight, x.oneMax,    x.size};
  }
  return x;
}
F composition(F f, F g) { return f ^ g; }
F id() { return false; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<S> ss;
  rep(i, n) {
    char c = s[i];
    S ts = {1, 1, 1, 0, 0, 0, 1};
    if (c == '0') ts = mapping(true, ts);
    ss.push_back(ts);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> st(ss);

  rep(i, q) {
    int c, l, r;
    cin >> c >> l >> r;
    l--;
    if (c == 1) {
      st.apply(l, r, true);
    } else {
      out(st.prod(l, r).oneMax);
    }
  }
}
