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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w;
  cin >> h >> w;
  string sx[h];
  rep(i, h) { cin >> sx[i]; }

  rep(i, h) {
    rep2(j, 1, w) {
      if (sx[i][j] == 'T' && sx[i][j - 1] == 'T') {
        sx[i][j] = 'C';
        sx[i][j - 1] = 'P';
      }
    }
    out(sx[i]);
  }
}
