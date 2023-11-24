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

int n, m;
vector<string> ax;
vector<string> bx;
bool judge(int i, int j) {
  rep(ii, m) {
    rep(jj, m) {
      if (ax[i + ii][j + jj] != bx[ii][jj]) return false;
    }
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  ax.resize(n);
  rep(i, n) cin >> ax[i];
  bx.resize(m);
  rep(i, m) cin >> bx[i];

  rep(i, n - m + 1) {
    rep(j, n - m + 1) {
      if (judge(i, j)) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}
