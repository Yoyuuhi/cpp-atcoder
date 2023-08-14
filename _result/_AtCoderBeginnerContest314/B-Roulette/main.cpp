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
  vector<vector<int>> ax(n);
  rep(i, n) {
    int c;
    cin >> c;
    rep(j, c) {
      int a;
      cin >> a;
      ax[i].push_back(a);
    }
  }
  int x;
  cin >> x;

  vector<pair<int, int>> ans;
  rep(i, n) {
    for (auto a : ax[i]) {
      if (a == x) {
        ans.push_back({ax[i].size(), i + 1});
        break;
      }
    }
  }
  sort(all(ans));

  if (!ans.size()) {
    out(0);
    return 0;
  }

  int k =
      lower_bound(all(ans), pair<int, int>{ans[0].first + 1, 0}) - begin(ans);
  out(k);
  rep(i, k) cout << ans[i].second << ' ';
  cout << endl;
}
