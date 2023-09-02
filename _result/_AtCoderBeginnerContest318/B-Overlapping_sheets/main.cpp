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

  int n;
  cin >> n;
  vector<vector<bool>> mem(101, vector<bool>(101, false));
  rep(i, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    rep2(x, a, b) {
      rep2(y, c, d) { mem[x][y] = true; }
    }
  }
  int ans = 0;
  rep(i, 101) {
    rep(j, 101) {
      if (mem[i][j]) ans++;
    }
  }
  out(ans);
}
