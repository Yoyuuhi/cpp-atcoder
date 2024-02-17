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

int h, w, n;
string t;
vector<string> ss;
bool poss(int x, int y) {
  return x >= 0 && x < h && y >= 0 && y < w && ss[x][y] == '.';
}
bool calc(int x, int y) {
  if (ss[x][y] != '.') return false;

  rep(i, n) {
    char c = t[i];
    if (c == 'L') y--;
    if (c == 'R') y++;
    if (c == 'U') x--;
    if (c == 'D') x++;
    if (!poss(x, y)) return false;
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w >> n;
  cin >> t;
  ss.resize(h);
  rep(i, h) cin >> ss[i];

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (calc(i, j)) ans++;
    }
  }
  out(ans);
}
