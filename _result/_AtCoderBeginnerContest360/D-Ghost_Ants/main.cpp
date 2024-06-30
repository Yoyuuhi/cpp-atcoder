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

  ll n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  auto xs = nis(n);

  vector<ll> mem;
  rep(i, n) {
    char dir = s[i];
    ll pos = xs[i];
    if (dir == '0') mem.push_back(pos);
  }

  sort(all(mem));
  ll ans = 0;
  rep(i, n) {
    char dir = s[i];
    ll pos = xs[i];
    if (dir == '0') continue;

    ll r = lower_bound(all(mem), pos + 2 * t + 1) - mem.begin();
    ll l = lower_bound(all(mem), pos) - mem.begin();
    // DBG(i + 1)
    // DBG(r - l)
    // outl;
    ans += r - l;
  }
  out(ans);
}
