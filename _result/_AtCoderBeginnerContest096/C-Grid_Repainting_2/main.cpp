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
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];

  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') {
        if (i > 0 && ss[i - 1][j] == '#') continue;
        if (i + 1 < h && ss[i + 1][j] == '#') continue;
        if (j > 0 && ss[i][j - 1] == '#') continue;
        if (j + 1 < w && ss[i][j + 1] == '#') continue;
        out("No");
        return 0;
      }
    }
  }
  out("Yes");
}
