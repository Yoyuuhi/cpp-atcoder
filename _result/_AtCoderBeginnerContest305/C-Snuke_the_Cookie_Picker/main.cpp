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
  int l = w;
  int r = -1;
  int t = h;
  int d = -1;

  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') {
        l = min(l, j);
        r = max(r, j);
        t = min(t, i);
        d = max(d, i);
      }
    }
  }
  rep2(i, t, d + 1) {
    rep2(j, l, r + 1) {
      if (ss[i][j] == '.') {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
  }
}
