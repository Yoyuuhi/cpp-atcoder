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

  vector<ll> mem(1000002, 0);
  for (auto a : as) mem[a]++;
  for (int i = 1000000; i >= 0; i--) mem[i] += mem[i + 1];

  ll ans = 0;
  vector<bool> finished(1000001, false);
  for (auto a : as) {
    if (finished[a]) continue;
    finished[a] = true;
    ll cnt = mem[a] - mem[a + 1];

    // t = 1
    ans += cnt * (cnt - 1) / 2;
    ans += cnt * (mem[a + 1] - mem[min(a * 2, ll(1000001))]);

    for (ll t = 2; a * t <= as[as.size() - 1]; t++) {
      ans += cnt * t * (mem[a * t] - mem[min(a * (t + 1), ll(1000001))]);
    }
    // DBG(a);
    // DBG(ans);
  }
  out(ans);
}
