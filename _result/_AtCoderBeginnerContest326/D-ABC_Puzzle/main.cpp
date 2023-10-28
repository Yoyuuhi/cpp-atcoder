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

int n;
string r, c;
vector<int> da, db, dc;
vector<vector<char>> ans;
bool judge() {
  rep(i, n) {
    bool find = false;
    int b = 0;
    rep(j, n) {
      if (ans[i][j] == '.') continue;
      if (!find && ans[i][j] != r[i]) return false;
      if (ans[i][j] == r[i]) find = true;
      b += 1 << (ans[i][j] - 'A');
    }
    if (!find || b != 7) return false;
  }
  rep(j, n) {
    bool find = false;
    int b = 0;
    rep(i, n) {
      if (ans[i][j] == '.') continue;
      if (!find && ans[i][j] != c[j]) return false;
      if (ans[i][j] == c[j]) find = true;
      b += 1 << (ans[i][j] - 'A');
    }
    if (!find || b != 7) return false;
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  cin >> r >> c;

  rep(i, n) {
    da.push_back(i);
    db.push_back(i);
    dc.push_back(i);
  }
  do {
    do {
      do {
        ans.assign(n, vector<char>(n, '.'));
        rep(i, n) {
          ans[i][da[i]] = 'A';
          ans[i][db[i]] = 'B';
          ans[i][dc[i]] = 'C';
        }
        if (judge()) {
          out("Yes");
          for (auto as : ans) {
            for (auto a : as) {
              cout << a;
            }
            cout << endl;
          }
          return 0;
        }
      } while (next_permutation(all(da)));
    } while (next_permutation(all(db)));
  } while (next_permutation(all(dc)));

  out("No");
}
