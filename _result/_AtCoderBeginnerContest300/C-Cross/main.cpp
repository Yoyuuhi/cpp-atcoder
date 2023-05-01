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

int h, w;
vector<int> ans(100, 0);
vector<vector<char>> cx(100, vector<char>(100, '.'));
vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void calc(int i, int j) {
  int count = 0;
  vector<pair<int, int>> ds(4, pair<int, int>{i, j});
  while (true) {
    rep(i, 4) {
      int ii = ds[i].first + dirs[i].first;
      int jj = ds[i].second + dirs[i].second;

      if (ii < 0 || ii >= 100 || jj < 0 || jj >= 100 || cx[ii][jj] != '#') {
        goto c;
      }
      ds[i] = {ii, jj};
    }
    count++;
  }
c:
  if (count > 0) ans[count - 1]++;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w;
  rep(i, h) {
    rep(j, w) { cin >> cx[i][j]; }
  }

  rep(i, 100) {
    rep(j, 100) {
      if (cx[i][j] != '#') continue;
      calc(i, j);
    }
  }
  int n = min(h, w);
  cout << ans[0];
  rep2(i, 1, n) cout << ' ' << ans[i];
  cout << endl;
}
