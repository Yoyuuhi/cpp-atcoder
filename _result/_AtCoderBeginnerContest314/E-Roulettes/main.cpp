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

int n, m;
vector<double> dp;
vector<int> cs;
vector<vector<int>> ss;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  cs.resize(n);
  ss.resize(n);
  rep(i, n) {
    cin >> cs[i];
    int p;
    cin >> p;
    ss[i].resize(p);
    rep(j, p) cin >> ss[i][j];
  }

  dp.assign(m + 100, 0);
  for (int i = m - 1; i >= 0; i--) {
    double temp1 = INF;
    rep(a, n) {
      double temp2 = 0;
      int count0 = 0;
      rep(b, ss[a].size()) {
        if (!ss[a][b]) count0++;
        temp2 += (dp[i + ss[a][b]] + cs[a]) / ss[a].size();
      }
      temp1 = min(temp1, temp2 * ss[a].size() / (ss[a].size() - count0));
    }
    dp[i] = temp1;
  }
  cout << setprecision(15) << dp[0] << endl;
}
