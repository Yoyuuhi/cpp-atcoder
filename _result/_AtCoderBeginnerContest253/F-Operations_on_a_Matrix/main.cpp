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

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> QS(q);
  rep(ii, q) {
    int que;
    cin >> que;
    if (que == 1) {
      ll l, r, x;
      cin >> l >> r >> x;
      l--;
      r--;
      QS[ii] = {que, l, r, x};
    }
    if (que == 2) {
      ll i, x;
      cin >> i >> x;
      i--;
      QS[ii] = {que, i, x};
    }
    if (que == 3) {
      ll i, j;
      cin >> i >> j;
      i--;
      j--;
      QS[ii] = {que, i, j};
    }
  }

  vector<vector<int>> memQ3(n), memQ2(q);
  for (int ii = q - 1; ii >= 0; ii--) {
    int que = QS[ii][0];
    if (que == 3) {
      int i = QS[ii][1], j = QS[ii][2];
      memQ3[i].push_back(j);
    }
    if (que == 2) {
      int i = QS[ii][1];
      while (memQ3[i].size() > 0) {
        int j = memQ3[i][memQ3[i].size() - 1];
        memQ2[ii].push_back(j);
        memQ3[i].pop_back();
      }
    }
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(m);
  map<pair<int, int>, pair<ll, ll>> mem2;
  rep(ii, q) {
    int que = QS[ii][0];
    if (que == 1) {
      ll l = QS[ii][1], r = QS[ii][2], x = QS[ii][3];
      seg.apply(l, r + 1, x);
    }
    if (que == 2) {
      int i = QS[ii][1];
      ll x = QS[ii][2];
      while (memQ2[ii].size() > 0) {
        int j = memQ2[ii][memQ2[ii].size() - 1];
        ll val = seg.prod(j, j + 1);
        mem2[{i, j}] = {val, x};
        memQ2[ii].pop_back();
      }
    }
    if (que == 3) {
      int i = QS[ii][1], j = QS[ii][2];
      ll val = seg.prod(j, j + 1);
      if (mem2.find({i, j}) != mem2.end()) {
        val -= mem2[{i, j}].first;
        val += mem2[{i, j}].second;
      }
      out(val);
    }
  }
}
