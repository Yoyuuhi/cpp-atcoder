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

int h, w, x, y;
bool valid(int xx, int yy) { return xx >= 0 && xx < h && yy >= 0 && yy < w; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w >> x >> y;
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];
  x--;
  y--;

  vector<pair<int, int>> vs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int ans = 1;
  for (auto v : vs) {
    int xx = x + v.first;
    int yy = y + v.second;
    while (valid(xx, yy) && ss[xx][yy] == '.') {
      ans++;
      xx += v.first;
      yy += v.second;
    }
  }
  out(ans);
}
