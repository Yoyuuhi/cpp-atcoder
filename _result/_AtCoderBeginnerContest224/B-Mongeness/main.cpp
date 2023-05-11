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

  int h, w;
  cin >> h >> w;
  vector<vector<int>> ax(h);
  rep(i, h) {
    vector<int> as(w);
    rep(j, w) { cin >> as[j]; }
    ax[i] = as;
  }

  rep(i1, h) {
    rep2(i2, i1 + 1, h) {
      rep(j1, w) {
        rep2(j2, j1 + 1, w) {
          if (ax[i1][j1] + ax[i2][j2] > ax[i2][j1] + ax[i1][j2]) {
            out("No");
            return 0;
          }
        }
      }
    }
  }
  out("Yes");
}
