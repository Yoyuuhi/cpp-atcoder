#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  vector<vector<int>> cx(3, vector<int>(3));
  rep(i, 3) { rep(j, 3) cin >> cx[i][j]; }

  rep(i, 2) {
    rep2(j, 1, 3) {
      if (cx[i][j] - cx[i + 1][j] != cx[i][0] - cx[i + 1][0]) {
        out("No");
        return 0;
      }
    }
  }
  rep(j, 2) {
    rep2(i, 1, 3) {
      if (cx[i][j] - cx[i][j + 1] != cx[0][j] - cx[0][j + 1]) {
        out("No");
        return 0;
      }
    }
  }
  out("Yes");
}
