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
bool judge(int i, int j, vector<string> ss) {
  if (i + 8 >= n || j + 8 >= m) return false;
  bool ans = true;
  rep2(ii, i, i + 9) {
    rep2(jj, j, j + 9) {
      if (ii < i + 3 && jj < j + 3 && ss[ii][jj] == '.') ans = false;
      if (ii > i + 5 && jj > j + 5 && ss[ii][jj] == '.') ans = false;
      if (ii == i + 3 && jj <= j + 3 && ss[ii][jj] == '#') ans = false;
      if (ii <= i + 3 && jj == j + 3 && ss[ii][jj] == '#') ans = false;
      if (ii == i + 5 && jj >= j + 5 && ss[ii][jj] == '#') ans = false;
      if (ii >= i + 5 && jj == j + 5 && ss[ii][jj] == '#') ans = false;
    }
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];
  rep(i, n) {
    rep(j, m) {
      if (judge(i, j, ss)) {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
}
