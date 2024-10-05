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

  ll n, s, t;
  cin >> n >> s >> t;
  vector<vector<ll>> abcds;
  rep(i, n) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    abcds.push_back({a, b, c, d});
  }

  vector<int> vs;
  rep(i, n) vs.push_back(i);

  double ans = INFLL;
  do {
    rep(bit, 1 << n) {
      double ta = 0;
      ll x = 0, y = 0;
      rep(i, n) {
        ll aa = abcds[vs[i]][0], bb = abcds[vs[i]][1];
        ll cc = abcds[vs[i]][2], dd = abcds[vs[i]][3];
        if (bit & (1 << i)) {
          swap(aa, cc);
          swap(bb, dd);
        }

        ta += sqrt(tpow(x - aa, 2) + tpow(y - bb, 2)) / s;
        ta += sqrt(tpow(cc - aa, 2) + tpow(dd - bb, 2)) / t;
        x = cc;
        y = dd;
      }
      ans = min(ans, ta);
    }
  } while (next_permutation(all(vs)));

  cout << fixed << setprecision(16) << ans << endl;
}
