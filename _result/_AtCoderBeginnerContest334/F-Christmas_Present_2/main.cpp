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

using T = double;
T op(T a, T b) { return min(a, b); }
T e() { return INFLL; }

double dis(vector<ll> xy1, vector<ll> xy2) {
  return sqrt(pow(double(xy1[0] - xy2[0]), 2) +
              pow(double(xy1[1] - xy2[1]), 2));
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  ll sx, sy;
  cin >> sx >> sy;
  vector<vector<ll>> xys;
  xys.push_back({sx, sy});
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xys.push_back({x, y});
  }
  xys.push_back({sx, sy});

  vector<double> d1(n + 2, 0), d2(n + 2, 0);
  double sumd1 = 0;
  rep2(i, 1, n + 2) {
    d1[i] = dis(xys[i], xys[i - 1]);
    d2[i] = dis(xys[i - 1], xys[0]) + dis(xys[i], xys[0]);
    sumd1 += d1[i];
  }
  segtree<T, op, e> st(n + 2);
  st.set(0, 0);
  rep2(i, 1, n + 2) {
    int l = max(0, i - k);
    auto val = st.prod(l, i);
    st.set(i, val + d2[i] - d1[i]);
  }
  cout << fixed << setprecision(15) << sumd1 + st.get(n + 1) << endl;
}
