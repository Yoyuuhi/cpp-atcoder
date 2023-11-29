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

ll calc(ll i, ll h, ll w) {
  ll ret = INFLL;
  ll s = (w - i) * h;
  if (s * 2 >= i * h) ret = min(ret, s - h / 2 * i);
  if (s * 2 <= i * h) ret = min(ret, h / 2 * i + h % 2 * i - s);
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll h, w;
  cin >> h >> w;
  if (!(h % 3) || !(w % 3)) {
    out(0);
    return 0;
  }

  ll ans = min(h, w);
  rep2(i, 1, w) { ans = min(ans, calc(ll(i), h, w)); }
  rep2(i, 1, h) { ans = min(ans, calc(ll(i), w, h)); }
  out(ans);
}
