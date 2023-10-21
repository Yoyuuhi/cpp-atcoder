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

  dsu d(h * w);
  rep(i, h) {
    rep(j, w) {
      char c = ss[i][j];
      if (c != '#') continue;

      rep2(ii, -1, 2) {
        rep2(jj, -1, 2) {
          int x = i + ii;
          int y = j + jj;
          if (!(x >= 0 && x < h && y >= 0 && y < w) || (ii == 0 && jj == 0))
            continue;
          if (ss[x][y] != '#') continue;
          d.merge(i * w + j, x * w + y);
        }
      }
    }
  }
  vector<bool> mem(h * w);
  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') {
        mem[d.leader(i * w + j)] = true;
      }
    }
  }
  int ans = 0;
  for (auto m : mem)
    if (m) ans++;
  out(ans);
}
