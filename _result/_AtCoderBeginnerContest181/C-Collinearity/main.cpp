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

vector<pair<int, int>> xys;
bool poss(int i, int j, int k) {
  int x1 = xys[j].first - xys[i].first;
  int y1 = xys[j].second - xys[i].second;
  int x2 = xys[k].first - xys[i].first;
  int y2 = xys[k].second - xys[i].second;
  return x1 * y2 == y1 * x2;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  xys.resize(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xys[i] = {x, y};
  }
  rep(i, n) {
    rep2(j, i + 1, n) {
      rep2(k, j + 1, n) {
        if (poss(i, j, k)) {
          out("Yes");
          return 0;
        }
      }
    }
  }
  out("No");
}
