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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m, p;
  cin >> n >> m >> p;
  vector<ll> as(n);
  rep(i, n) cin >> as[i];
  vector<ll> bs(m);
  rep(i, m) cin >> bs[i];
  sort(all(bs));

  vector<ll> sumb(m, 0);
  rep(i, m) {
    sumb[i] += bs[i];
    if (i) sumb[i] += sumb[i - 1];
  }

  ll ans = 0;
  for (auto a : as) {
    ll res = p - a;
    ll idx = lower_bound(all(bs), res + 1) - bs.begin();
    if (idx) ans += idx * a + sumb[idx - 1];
    ans += p * (ll(bs.size()) - idx);
  }
  out(ans);
}
