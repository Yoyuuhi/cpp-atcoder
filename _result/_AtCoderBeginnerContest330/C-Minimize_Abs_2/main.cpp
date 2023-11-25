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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll d;
  cin >> d;
  int n = 1414215;
  vector<ll> xs(n);
  rep(i, n) { xs[i] = ll(i) * ll(i); }

  ll ans = INFLL;
  rep(i, n) {
    ll x = xs[i];
    if (x >= d) {
      ans = min(x - d, ans);
    } else {
      ans = min(d - x, ans);
    }

    ll ty = d - x;
    if (ty < x) continue;
    int iy = lower_bound(all(xs), ty) - xs.begin();
    ll y = xs[iy];
    ans = min(x + y - d, ans);

    if (iy) {
      y = xs[iy - 1];
      ans = min(-(x + y - d), ans);
    }
  }
  out(ans);
}
