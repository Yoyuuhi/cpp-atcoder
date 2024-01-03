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

  int s, t, m;
  cin >> s >> t >> m;
  vector<vector<int>> g(s + 1);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  vector<vector<int>> mem(t + 1, vector<int>(t + 1, 0));
  rep2(u, 1, s + 1) {
    int n = g[u].size();
    rep(i, n) {
      rep(j, n) {
        if (i == j) continue;
        int vi = g[u][i], vj = g[u][j];
        if (mem[vi - s][vj - s] == 0) {
          mem[vi - s][vj - s] = u;
        } else {
          cout << u << " " << vi << " " << mem[vi - s][vj - s] << " " << vj
               << endl;
          return 0;
        }
      }
    }
  }
  out(-1);
}
