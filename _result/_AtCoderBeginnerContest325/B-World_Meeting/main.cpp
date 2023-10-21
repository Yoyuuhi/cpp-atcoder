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
  vector<vector<int>> wxs(n);
  rep(i, n) {
    int w, x;
    cin >> w >> x;
    wxs[i] = {w, x};
  }

  ll ans = 0;
  rep(i, 24) {
    ll ta = 0;
    for (auto wx : wxs) {
      int w = wx[0];
      int x = wx[1];

      x = (x + i) % 24;
      if (x >= 9 && x < 18) ta += w;
    }
    ans = max(ans, ta);
  }
  out(ans);
}
