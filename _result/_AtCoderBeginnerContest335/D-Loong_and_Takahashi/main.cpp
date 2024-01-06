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
  vector<vector<int>> ans(n, vector<int>(n, -1));
  int i = 0, j = 0;
  int val = 1;
  vector<vector<int>> vs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int iv = 0;
  while (!(i == (n + 1) / 2 - 1 && j == (n + 1) / 2 - 1)) {
    ans[i][j] = val;
    val++;

    int ii = i + vs[iv][0];
    int jj = j + vs[iv][1];
    if (!(ii >= 0 && ii < n && jj >= 0 && jj < n && ans[ii][jj] == -1)) {
      iv = (iv + 1) % 4;
      ii = i + vs[iv][0];
      jj = j + vs[iv][1];
    }
    i = ii;
    j = jj;
  }

  for (auto as : ans) {
    for (auto a : as) {
      if (a != -1) {
        cout << a << ' ';
      } else {
        cout << 'T' << ' ';
      }
    }
    outl;
  }
}
