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

  ll n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> xhs;
  rep(i, n) {
    ll x, h;
    cin >> x >> h;
    xhs.push_back({x, h});
  }
  sort(all(xhs));

  vector<ll> memD(n + 1, 0);
  ll ans = 0;
  rep(i, n) {
    if (i) memD[i] += memD[i - 1];
    xhs[i].second += memD[i];
    if (xhs[i].second > 0) {
      ll t = xhs[i].second / a + (xhs[i].second % a ? 1 : 0);
      ans += t;
      int it =
          lower_bound(all(xhs), pair<ll, ll>{xhs[i].first + 1 + 2 * d, 0}) -
          xhs.begin();
      memD[i] -= a * t;
      memD[it] += a * t;
    }
  }
  out(ans);
}
