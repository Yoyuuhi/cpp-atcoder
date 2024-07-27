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
  int i, j;
  cin >> i >> j;
  i--;
  j--;
  vector<string> cx(h);
  rep(ii, h) {
    string str;
    cin >> str;
    cx[ii] = str;
  }
  string X;
  cin >> X;
  vector<vector<int>> vs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  for (auto x : X) {
    int idx;
    if (x == 'L') {
      idx = 0;
    }
    if (x == 'R') {
      idx = 1;
    }
    if (x == 'U') {
      idx = 2;
    }
    if (x == 'D') {
      idx = 3;
    }
    auto v = vs[idx];
    int ii = i + v[0], jj = j + v[1];
    if (ii >= 0 && ii < h && jj >= 0 && jj < w && cx[ii][jj] == '.') {
      i = ii;
      j = jj;
    }
  }
  cout << i + 1 << ' ' << j + 1 << endl;
}
