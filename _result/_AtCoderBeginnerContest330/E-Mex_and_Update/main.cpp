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

struct mem {
  int pos;
  int val;
};

mem op(mem a, mem b) {
  if (a.val == 0 && b.val == 0) {
    if (a.pos < b.pos) {
      return a;
    } else {
      return b;
    }
  }
  if (a.val == 0) return a;
  return b;
}
mem e() { return {0, 1}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  auto as = nis(n);

  int mn = 200002;
  vector<int> num(mn, 0);
  for (auto a : as) {
    if (a < mn) num[a]++;
  }
  vector<mem> ms(mn);
  rep(i, mn) { ms[i] = {i, num[i]}; }

  segtree<mem, op, e> st(ms);
  rep(ii, q) {
    int i, x;
    cin >> i >> x;
    i--;
    int oa = as[i];
    int na = x;
    as[i] = na;
    if (oa < mn) {
      auto s = st.get(oa);
      s.val--;
      st.set(oa, s);
    }
    if (na < mn) {
      auto s = st.get(na);
      s.val++;
      st.set(na, s);
    }
    auto s = st.all_prod();
    out(s.pos);
  }
}
