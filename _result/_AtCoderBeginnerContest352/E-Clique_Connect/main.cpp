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

bool comp(vector<ll> &a1, vector<ll> &a2) { return a1[1] < a2[1]; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;

  dsu d(n + 1);
  vector<vector<ll>> mem;
  rep(i, m) {
    ll k, c;
    cin >> k >> c;

    vector<ll> me = {k, c};
    rep(i, k) {
      ll a;
      cin >> a;
      me.push_back(a);
    }
    mem.push_back(me);
  }

  sort(all(mem), comp);
  ll ans = 0;
  for (auto me : mem) {
    ll k = me[0], c = me[1];
    rep2(i, 3, me.size()) {
      if (!d.same(me[2], me[i])) {
        d.merge(me[2], me[i]);
        ans += c;
      }
    }
  }

  if (d.size(1) != n) {
    out(-1);
  } else {
    out(ans);
  }
}
