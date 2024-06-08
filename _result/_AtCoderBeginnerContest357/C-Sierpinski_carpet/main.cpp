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

  int n;
  cin >> n;

  int t = 0;
  vector<vector<char>> g(1, vector<char>(1, '#'));
  while (t < n) {
    int s = tpow(3, t + 1);
    vector<vector<char>> gt(s, vector<char>(s, '.'));
    int d = s / 3;
    vector<vector<int>> xys = {
        {0, 0},     {0, d},     {0, 2 * d}, {d, 0},
        {d, 2 * d}, {2 * d, 0}, {2 * d, d}, {2 * d, 2 * d},
    };
    for (auto xy : xys) {
      auto x = xy[0], y = xy[1];
      rep(i, g.size()) {
        rep(j, g.size()) { gt[x + i][y + j] = g[i][j]; }
      }
    }

    g = gt;
    t++;
  }

  for (auto l : g) {
    for (auto c : l) cout << c;
    outl;
  }
}
