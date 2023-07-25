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

vector<int> seen;
vector<int> ans;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  seen.assign(n, 0);
  rep(i, n) {
    if (seen[i]) continue;
    int v = i;
    while (seen[v] <= 2) {
      if (seen[v] == 2) ans.push_back(v + 1);

      seen[v] += 1;
      v = as[v] - 1;
    }
    if (ans.size()) {
      out(ans.size());
      rep(j, ans.size()) cout << ans[j] << " ";
      cout << endl;
      return 0;
    }
  }
}
