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

  ll n;
  cin >> n;
  vector<vector<vector<ll>>> ax(
      n, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));
  rep(i, n) {
    rep(j, n) {
      rep(k, n) {
        int a;
        cin >> a;
        ax[i][j + 1][k + 1] = a;
      }
    }
  }
  rep(i, n) {
    rep2(j, 1, n + 1) {
      rep2(k, 1, n + 1) { ax[i][j][k] += ax[i][j][k - 1]; }
    }
  }
  rep(i, n) {
    rep2(j, 1, n + 1) {
      rep2(k, 1, n + 1) { ax[i][j][k] += ax[i][j - 1][k]; }
    }
  }

  int q;
  cin >> q;
  rep(i, q) {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;

    lx--;
    rx--;
    ll ans = 0;
    rep2(i, lx, rx + 1) ans += ax[i][ry][rz] - ax[i][ly - 1][rz] -
                               ax[i][ry][lz - 1] + ax[i][ly - 1][lz - 1];
    out(ans);
  }
}
