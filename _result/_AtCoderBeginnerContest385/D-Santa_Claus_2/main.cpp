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

  ll n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  map<ll, set<ll>> xys, yxs;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xys[x].emplace(y);
    yxs[y].emplace(x);
  }

  int ans = 0;
  rep(i, m) {
    char d;
    ll c;
    cin >> d >> c;
    ll tx = sx, ty = sy;
    if (d == 'U') ty += c;
    if (d == 'D') ty -= c;
    if (d == 'L') tx -= c;
    if (d == 'R') tx += c;
    ll x1 = sx, x2 = tx, y1 = sy, y2 = ty;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    if (x1 == x2) {
      auto it = xys[x1].lower_bound(y1);
      while (it != xys[x1].end() && *it <= y2) {
        ans++;
        yxs[*it].erase(x1);
        it = xys[x1].erase(it);
      }
    }
    if (y1 == y2) {
      auto it = yxs[y1].lower_bound(x1);
      while (it != yxs[y1].end() && *it <= x2) {
        ans++;
        xys[*it].erase(y1);
        it = yxs[y1].erase(it);
      }
    }

    sx = tx;
    sy = ty;
  }

  cout << sx << ' ' << sy << ' ' << ans << endl;
}
