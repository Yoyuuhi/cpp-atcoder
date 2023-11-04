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

vector<vector<int>> ax;
bool judge() {
  rep(i, 9) {
    set<int> s;
    rep(j, 9) { s.insert(ax[i][j]); }
    if (s.size() != 9) return false;
  }
  rep(j, 9) {
    set<int> s;
    rep(i, 9) { s.insert(ax[i][j]); }
    if (s.size() != 9) return false;
  }

  int i = 0;
  int j = 0;
  rep(t, 9) {
    set<int> s;
    s.insert(ax[i][j]);
    rep(u, 8) {
      if ((j + 1) % 3 == 0) {
        i++;
        j++;
        j -= 3;
      } else {
        j++;
      }
      s.insert(ax[i][j]);
    }
    DBG(s.size() != 9);
    if (s.size() != 9) return false;

    if (j + 1 == 9) {
      i++;
      j = 0;
    } else {
      i -= 2;
      j++;
    }
  }

  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ax.resize(9, vector<int>(9));
  rep(i, 9) {
    rep(j, 9) { cin >> ax[i][j]; }
  }
  if (judge()) {
    out("Yes");
  } else {
    out("No");
  }
}
