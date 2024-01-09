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

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

ll op(ll a, ll b) { return gcd(a, b); }
int e() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  auto as = nis(n), bs = nis(n);

  vector<ll> diffas(n, 0), diffbs(n, 0);
  rep(i, n - 1) {
    diffas[i] = abs(as[i + 1] - as[i]);
    diffbs[i] = abs(bs[i + 1] - bs[i]);
  }
  segtree<ll, op, e> sta(diffas), stb(diffbs);

  rep(i, q) {
    int h1, h2, w1, w2;
    cin >> h1 >> h2 >> w1 >> w2;
    h1--;
    h2--;
    w1--;
    w2--;

    ll g = gcd(as[h1] + bs[w1], gcd(sta.prod(h1, h2), stb.prod(w1, w2)));
    out(g);
  }
}
