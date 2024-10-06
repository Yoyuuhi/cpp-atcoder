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

ll n, x;
vector<vector<ll>> apbqs;

ll bs(ll ok, ll ng, bool f(ll)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

bool f(ll targetW) {
  ll ans = 0;

  ll totalPrice = 0;
  for (auto apbq : apbqs) {
    ll a = apbq[0], p = apbq[1], b = apbq[2], q = apbq[3];
    ll minPrice = INFLL;
    rep(i, a) {
      ll tempPrice = q * i;
      ll res = max(ll(0), targetW - b * i);
      tempPrice += res / a * p;
      if (res % a) tempPrice += p;
      minPrice = min(minPrice, tempPrice);
    }
    totalPrice += minPrice;
  }
  return totalPrice <= x;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> x;
  rep(i, n) {
    ll a, p, b, q;
    cin >> a >> p >> b >> q;
    if (p * b >= q * a) {
      swap(a, b);
      swap(p, q);
    }
    apbqs.push_back({a, p, b, q});
  }

  out(bs(0, 1000000000, f));
}
