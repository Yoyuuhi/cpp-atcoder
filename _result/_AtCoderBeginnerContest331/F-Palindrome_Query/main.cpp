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
T pow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

vector<ll> ps = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
ll x;

struct Hash {
  ll h1;
  ll h2;
  ll xx;
};
using T = array<Hash, 5>;
T op(T l, T r) {
  T res;
  rep(i, 5) {
    res[i].h1 = (l[i].h1 * r[i].xx + r[i].h1) % ps[i];
    res[i].h2 = (l[i].h2 + l[i].xx * r[i].h2) % ps[i];
    res[i].xx = l[i].xx * r[i].xx % ps[i];
  }
  return res;
}
T e() {
  T res;
  rep(i, 5) res[i] = {0, 0, 1};
  return res;
}

T calcT(char c) {
  T res;
  rep(i, 5) res[i].h1 = res[i].h2 = c, res[i].xx = x % ps[i];
  return res;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  mt19937_64 rng(time(0));
  x = rng();
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<T> init(n);
  rep(i, n) init[i] = calcT(s[i]);
  segtree<T, op, e> st(init);
  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      st.set(x, calcT(c));
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      T h = st.prod(l, r + 1);
      bool poss = true;
      rep(i, 5) if (h[i].h1 != h[i].h2) poss = false;
      cout << (poss ? "Yes" : "No") << endl;
    }
  }
}
