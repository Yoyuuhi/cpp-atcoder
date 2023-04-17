#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

struct S {
  ll zero, one, inversion;
};

using F = bool;
S op(S l, S r) {
  return S{
      l.zero + r.zero,
      l.one + r.one,
      l.inversion + r.inversion + l.one * r.zero,
  };
};
S e() { return S{0, 0, 0}; };
S mapping(F l, S r) {
  if (!l) return r;
  return S{r.one, r.zero, r.one * r.zero - r.inversion};
};
F composition(F l, F r) { return (l && !r) || (!l && r); }
F id() { return false; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  vector<S> as;
  rep(i, n) {
    int a;
    cin >> a;
    if (a) {
      as.push_back(S{0, 1, 0});
    } else {
      as.push_back(S{1, 0, 0});
    }
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> st(as);
  rep(i, q) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    if (t == 1) {
      st.apply(l, r, true);
    } else {
      out(st.prod(l, r).inversion);
    }
  }
}
