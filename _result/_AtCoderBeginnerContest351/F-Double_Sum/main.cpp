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

using S = array<ll, 2>;

S op(S a, S b) { return S{a[0] + b[0], a[1] + b[1]}; }
S e() { return S{0, 0}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto as = nis(n);

  map<ll, bool> am;
  for (auto a : as) am[a] = true;

  map<ll, int> mem;
  int idx = 0;
  for (auto m : am) {
    mem[m.first] = idx;
    idx++;
  }

  segtree<S, op, e> st(idx + 1);
  ll ans = 0;
  for (int I = n - 1; I >= 0; I--) {
    auto a = as[I];
    auto i = mem[a];
    auto s = st.prod(i + 1, idx + 1);

    if (s[1] > 0) ans += s[0] - s[1] * a;
    auto b = st.get(i);
    st.set(i, {b[0] + a, b[1] + 1});
  }
  out(ans);
}
