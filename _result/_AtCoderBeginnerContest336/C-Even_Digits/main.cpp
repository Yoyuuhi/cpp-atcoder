#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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
  if (n == 1) {
    out(0);
    return 0;
  }

  ll count = 1;
  ll level = 1;
  while (count < n) {
    count += 4 * tpow(ll(5), level - 1);
    level++;
  }
  level--;

  vector<ll> cs1 = {2, 4, 6, 8};
  vector<ll> cs2 = {0, 2, 4, 6, 8};
  ll res = n - (count - 4 * tpow(ll(5), level - 1));
  if (res == 0) {
    level--;
    rep(i, level) cout << '8';
    outl;
    return 0;
  }

  ll d = tpow(ll(5), level - 1);
  ll t = res / d;
  res -= t * d;
  ll r = res % d;
  if (r == 0) {
    t--;
    cout << cs1[t];
    rep(i, level - 1) cout << '8';
    outl;
    return 0;
  }
  cout << cs1[t];

  rep2(i, 1, level) {
    d = tpow(ll(5), level - i - 1);
    t = res / d;
    res -= t * d;
    r = res % d;
    if (r == 0) {
      t--;
      cout << cs2[t];
      rep(j, level - i - 1) cout << '8';
      outl;
      return 0;
    }
    cout << cs2[t];
  }
  outl;
}
