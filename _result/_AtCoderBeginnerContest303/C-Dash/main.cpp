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

  int n, m, h, k;
  cin >> n >> m >> h >> k;
  string ss;
  cin >> ss;
  set<pair<int, int>> st;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    st.insert({x, y});
  }

  int x = 0;
  int y = 0;
  rep(i, n) {
    char s = ss[i];
    h--;
    if (h < 0) {
      out("No");
      return 0;
    }
    if (s == 'R') x++;
    if (s == 'L') x--;
    if (s == 'U') y++;
    if (s == 'D') y--;
    if (h < k && st.find({x, y}) != st.end()) {
      h = k;
      st.erase({x, y});
    }
  }
  out("Yes");
}
