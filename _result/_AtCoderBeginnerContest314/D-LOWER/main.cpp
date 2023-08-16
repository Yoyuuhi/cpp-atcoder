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
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<int> mem1(n, 0);
  vector<int> mem23(q, 0);
  rep(i, q) {
    int t, x;
    cin >> t >> x;
    x--;
    char c;
    cin >> c;
    if (t == 1) {
      s[x] = c;
      mem1[x] = i;
    } else {
      mem23[i] = t;
    }
  }

  vector<vector<bool>> dp(q, vector<bool>(2, 0));
  if (mem23[q - 1]) dp[q - 1][mem23[q - 1] % 2] = true;
  for (int i = q - 2; i >= 0; i--) {
    if (!mem23[i]) {
      dp[i] = dp[i + 1];
      continue;
    }
    if (mem23[i] == 2) {
      dp[i][0] = !dp[i + 1][1];
      dp[i][1] = dp[i + 1][1];
    } else {
      dp[i][0] = dp[i + 1][0];
      dp[i][1] = !dp[i + 1][0];
    }
  }
  rep(i, n) {
    if (s[i] <= 'Z') cout << (dp[mem1[i]][0] ? char(s[i] - 'A' + 'a') : s[i]);
    if (s[i] >= 'a') cout << (dp[mem1[i]][1] ? char(s[i] - 'a' + 'A') : s[i]);
  }
  cout << endl;
}
