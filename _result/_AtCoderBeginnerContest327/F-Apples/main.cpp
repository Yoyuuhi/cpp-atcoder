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

using S = int;
using F = int;

S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, d, w;
  cin >> n >> d >> w;
  vector<vector<int>> txs;
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    txs.push_back({t, x});
  }
  sort(all(txs));

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(400001);
  int il = 0;
  int ans = 0;
  rep(i, n) {
    int t = txs[i][0], x = txs[i][1];
    seg.apply(x, x + w, 1);
    while (il <= n && txs[il][0] + d <= t) {
      int xl = txs[il][1];
      seg.apply(xl, xl + w, -1);
      il++;
    }
    ans = max(ans, seg.all_prod());
  }
  out(ans);
}
