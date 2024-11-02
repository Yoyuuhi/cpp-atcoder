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

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  auto as = nis(n);
  rep(i, n) as[i] = as[i] % m;

  segtree<ll, op, e> st(m);
  ll ans = 0, ta = 0;
  ll offset = 0;
  rep(i, n) {
    auto a = as[i];
    ta += (i + 1) * a;

    ll cm = 0;
    int l = (2 * m - a - offset) % m, r = (m - offset) % m;
    if (l <= r) {
      cm += st.prod(l, r);
    } else {
      cm += st.prod(l, m);
      cm += st.prod(0, r);
    }

    ta -= cm * m;
    ans += ta;

    offset = (offset + a) % m;
    st.set((a - offset + m) % m, st.get((a - offset + m) % m) + 1);
  }
  out(ans);
}
