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

  int n, k;
  cin >> n >> k;
  vector<vector<int>> tx(n, vector<int>(n));
  rep(i, n) { rep(j, n) cin >> tx[i][j]; }
  vector<int> route;
  rep2(i, 1, n) route.push_back(i);
  int ans = 0;
  do {
    int now = 0;
    int dis = 0;
    for (auto next : route) {
      dis += tx[now][next];
      now = next;
    }
    dis += tx[now][0];
    if (dis == k) ans++;
  } while (next_permutation(all(route)));
  out(ans);
}
