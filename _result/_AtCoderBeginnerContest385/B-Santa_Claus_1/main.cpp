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

  int h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<string> ss;
  rep(i, h) {
    string s;
    cin >> s;
    ss.push_back(s);
  }
  string t;
  cin >> t;

  int ans = 0;
  x--;
  y--;
  if (ss[x][y] == '@') {
    ans++;
    ss[x][y] = '.';
  }
  for (auto c : t) {
    int xx = x, yy = y;
    if (c == 'U') xx--;
    if (c == 'D') xx++;
    if (c == 'L') yy--;
    if (c == 'R') yy++;
    if (xx >= 0 && xx < h && yy >= 0 && yy < w && ss[xx][yy] != '#') {
      x = xx;
      y = yy;
    }
    if (ss[x][y] == '@') {
      ans++;
      ss[x][y] = '.';
    }
    // DBG(x)
    // DBG(y)
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << ans << endl;
}
