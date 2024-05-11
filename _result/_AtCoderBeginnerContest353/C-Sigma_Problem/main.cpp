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

  ll n;
  cin >> n;
  auto as = nis(n);

  sort(all(as));
  vector<ll> bs, ss;
  bs.push_back(as[0]);
  ll ans = 0;
  ss.push_back(as[0]);
  rep2(i, 1, n) {
    ll a = as[i];
    ll res = 100000000 - a;

    int idx = lower_bound(all(bs), res) - bs.begin();
    if (idx == -1) {
      ans += a * ss.size() + ss[ss.size() - 1];
    } else {
      ans += a * ss.size() + ss[ss.size() - 1] - 100000000 * (ss.size() - idx);
    }
    bs.push_back(a);
    ss.push_back(ss[ss.size() - 1] + a);
  }
  out(ans);
}
