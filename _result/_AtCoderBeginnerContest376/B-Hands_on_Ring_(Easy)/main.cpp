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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, q;
  cin >> n >> q;
  ll ans = 0;

  ll l = 0, r = 1;
  rep(i, q) {
    char h;
    ll t;
    cin >> h >> t;
    t--;

    ll ta = INFLL;
    ll t0, t1, l0, l1, r0, r1;
    if (h == 'L') {
      t0 = t, t1 = t + n;
      l0 = l, l1 = l + n;
      r0 = r, r1 = r + n;
    } else {
      t0 = t, t1 = t + n;
      l0 = r, l1 = r + n;
      r0 = l, r1 = l + n;
    }

    rep2(s, l0, 2 * n) {
      if (s == t0 || s == t1) ta = min(ta, s - l0);
      if (s == r0 || s == r1) break;
    }
    rep2(s, l1, 2 * n) {
      if (s == t0 || s == t1) ta = min(ta, s - l1);
      if (s == r0 || s == r1) break;
    }
    for (ll s = l0; s >= 0; s--) {
      if (s == t0 || s == t1) ta = min(ta, l0 - s);
      if (s == r0 || s == r1) break;
    }
    for (ll s = l1; s >= 0; s--) {
      if (s == t0 || s == t1) ta = min(ta, l1 - s);
      if (s == r0 || s == r1) break;
    }

    if (h == 'L') {
      l = t;
    } else {
      r = t;
    }
    ans += ta;
  }

  out(ans);
}
