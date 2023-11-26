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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int w, h, n;
  cin >> w >> h >> n;
  int x1 = 0;
  int x2 = w;
  int y1 = 0;
  int y2 = h;
  rep(i, n) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) x1 = max(x1, x);
    if (a == 2) x2 = min(x2, x);
    if (a == 3) y1 = max(y1, y);
    if (a == 4) y2 = min(y2, y);
  }
  if (x1 > x2 || y1 > y2) {
    out(0);
    return 0;
  }
  out((x2 - x1) * (y2 - y1));
}
