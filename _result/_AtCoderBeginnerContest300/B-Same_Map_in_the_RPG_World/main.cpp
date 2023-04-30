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
  char ax[h][w];
  rep(i, h) {
    rep(j, w) { cin >> ax[i][j]; }
  }
  char bx[2 * h][2 * w];
  rep(i, h) {
    rep(j, w) { cin >> bx[i][j]; }
  }

  rep(i, h) {
    rep(j, w) {
      bool poss = true;
      rep(ii, h) {
        rep(jj, w) {
          int i1 = (ii - i + h) % h;
          int j1 = (jj - j + w) % w;
          if (ax[ii][jj] != bx[i1][j1]) {
            poss = false;
            goto judge;
          }
        }
      }
    judge:
      if (poss) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}
