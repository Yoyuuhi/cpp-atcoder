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

  int h, w;
  cin >> h >> w;
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];

  int bl = w, br = -1, bt = h, bd = -1;
  vector<vector<int>> memWhite(h + 1, vector<int>(w + 1, 0));
  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') {
        bl = min(bl, j);
        br = max(br, j);
        bt = min(bt, i);
        bd = max(bd, i);
      }
      if (ss[i][j] == '.') memWhite[i + 1][j + 1] = 1;
    }
  }

  rep(i, h) rep(j, w) memWhite[i + 1][j + 1] += memWhite[i + 1][j];
  rep(i, h) rep(j, w) memWhite[i + 1][j + 1] += memWhite[i][j + 1];

  if (memWhite[bd + 1][br + 1] - memWhite[bd + 1][bl] - memWhite[bt][br + 1] +
          memWhite[bt][bl] ==
      0) {
    out("Yes");
  } else {
    out("No");
  }
}
