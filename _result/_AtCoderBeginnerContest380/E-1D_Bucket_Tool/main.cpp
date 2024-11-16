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
  int l;
  int r;
  int c;
};
using F = S;

S op(S a, S b) { return a; }
S e() { return S{-1, -1, -1}; }
S mapping(F f, S x) { return (f.l == -1 ? x : f); }
F composition(F f, F g) { return (f.l == -1 ? g : f); }
F id() { return S{-1, -1, -1}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  vector<S> init;
  map<int, int> mem;
  rep(i, n) {
    init.push_back({i, i, i + 1});
    mem[i + 1] = 1;
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int x, c;
      cin >> x >> c;
      x--;

      auto s = seg.get(x);
      auto l = s.l, r = s.r;
      auto L = l, R = r;
      int num = r - l + 1;
      mem[s.c] -= num;
      mem[c] += num;

      if (l > 0) {
        auto ss = seg.get(l - 1);
        if (ss.c == c) L = ss.l;
      }
      if (r + 1 < n) {
        auto ss = seg.get(r + 1);
        if (ss.c == c) R = ss.r;
      }
      seg.apply(L, R + 1, S{L, R, c});
    } else {
      int c;
      cin >> c;
      out(mem[c]);
    }
  }
}
