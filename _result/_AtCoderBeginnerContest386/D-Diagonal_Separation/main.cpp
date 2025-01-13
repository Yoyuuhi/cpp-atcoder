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

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> bxy, wxy;
  rep(i, m) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'B') bxy.push_back({x - 1, y - 1});
    if (c == 'W') wxy.push_back({x - 1, y - 1});
  }
  sort(all(bxy));
  sort(all(wxy));
  int idx = 0, yl = n;
  for (auto xy : bxy) {
    auto x = xy.first, y = xy.second;
    while (idx < wxy.size() && x >= wxy[idx].first) {
      yl = min(yl, wxy[idx].second);
      idx++;
    }
    if (y >= yl) {
      out("No");
      return 0;
    }
  }
  out("Yes");
}
