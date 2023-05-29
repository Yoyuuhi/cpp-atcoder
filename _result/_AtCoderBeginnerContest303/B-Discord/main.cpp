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

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> mem(n, vector<bool>(n, false));

  rep(i, m) {
    vector<int> as(n);
    rep(j, n) {
      cin >> as[j];
      if (!j) continue;
      int a1 = as[j];
      int a2 = as[j - 1];
      if (a1 > a2) swap(a1, a2);
      mem[a1 - 1][a2 - 1] = true;
    }
  }
  int ans = 0;
  rep(i, n) {
    rep2(j, i + 1, n) {
      if (!mem[i][j]) ans++;
    }
  }
  out(ans);
}
