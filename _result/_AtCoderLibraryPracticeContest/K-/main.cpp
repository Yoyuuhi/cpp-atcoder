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

  int n, q;
  cin >> n >> q;
  vector<S> as;
  rep(i, n) {
    int a;
    cin >> a;
    as.push_back(S{a, 1});
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> st(as);
  rep(i, q) {
    int que;
    cin >> que;
    if (!que) {
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      st.apply(l, r, F{b, c});
      continue;
    }

    int l, r;
    cin >> l >> r;
    out(st.prod(l, r).a.val());
  }
}
