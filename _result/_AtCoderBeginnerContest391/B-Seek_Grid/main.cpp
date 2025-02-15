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
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];
  vector<string> ts(n);
  rep(i, m) cin >> ts[i];

  rep(a, n) {
    rep(b, n) {
      if (a + m - 1 >= n || b + m - 1 >= n) continue;

      bool poss = true;
      rep(i, m) rep(j, m) if (ss[a + i][b + j] != ts[i][j]) poss = false;
      if (poss) {
        cout << a + 1 << ' ' << b + 1 << endl;
        return 0;
      }
    }
  }
}
