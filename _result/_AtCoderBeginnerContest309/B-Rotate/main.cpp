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
  vector<vector<int>> ax(n, vector<int>(n, 0));
  rep(i, n) {
    string as;
    cin >> as;
    rep(j, n) {
      if (as[j] == '1') ax[i][j] = 1;
    }
  }
  vector<vector<int>> bx(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) {
      if (i && i < n - 1 && j && j < n - 1) {
        bx[i][j] = ax[i][j];
        cout << bx[i][j];
        continue;
      }

      if (!i && !j) {
        bx[i][j] = ax[i + 1][j];
      } else if (!i && j == n - 1) {
        bx[i][j] = ax[i][j - 1];
      } else if (i == n - 1 && !j) {
        bx[i][j] = ax[i][j + 1];
      } else if (i == n - 1 && j == n - 1) {
        bx[i][j] = ax[i - 1][j];
      } else if (!i) {
        bx[i][j] = ax[i][j - 1];
      } else if (!j) {
        bx[i][j] = ax[i + 1][j];
      } else if (i == n - 1) {
        bx[i][j] = ax[i][j + 1];
      } else if (j == n - 1) {
        bx[i][j] = ax[i - 1][j];
      }
      cout << bx[i][j];
    }
    cout << endl;
  }
}
