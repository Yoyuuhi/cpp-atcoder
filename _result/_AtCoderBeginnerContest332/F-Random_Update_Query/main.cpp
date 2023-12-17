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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T pow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

struct S {
  mint a;
  int size;
};
struct F {
  mint a, b;
};
S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }
S e() { return S{0, 0}; }
S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }
F id() { return F{1, 0}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  vector<S> as;
  rep(i, n) {
    int a;
    cin >> a;
    as.push_back(S{a, 1});
  }

  vector<mint> ans(n, 0);
  lazy_segtree<S, op, e, F, mapping, composition, id> st(as);
  rep(i, m) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    st.apply(l, r + 1, F{mint(r - l) / (r - l + 1), mint(x) / (r - l + 1)});
  }
  st.all_prod();
  rep(i, n) cout << st.get(i).a.val() << " ";
  outl
}
