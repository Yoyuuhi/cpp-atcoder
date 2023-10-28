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

vector<vector<char>> ans;
vector<int> ds;
int n;
string r, c;
bool solve() {
  ans.assign(n, vector<char>(n, '.'));
  rep(i, n) {
    rep(j, n) {
      if (ds[i * n + j] == 1) ans[i][j] = 'X';
    }
  }
  rep(i, n) {
    int count = 0;
    rep(j, n) {
      if (ans[i][j] == 'X') count++;
    }
    if (count != 3) return false;
  }
  rep(j, n) {
    int count = 0;
    rep(i, n) {
      if (ans[i][j] == 'X') count++;
    }
    if (count != 3) return false;
  }

  rep(i, n) {
    char ri = r[i];
    rep(j, n) {
      if (ans[i][j] == '.') continue;
      if (ans[i][j] != 'X' && ans[i][j] != ri) return false;
      ans[i][j] = ri;
      break;
    }
  }
  rep(j, n) {
    char cj = c[j];
    rep(i, n) {
      if (ans[i][j] == '.') continue;
      if (ans[i][j] != 'X' && ans[i][j] != cj) return false;
      ans[i][j] = cj;
      break;
    }
  }
  rep(i, n) {
    rep(j, n) {
      vector<bool> mem(3, false);
      if (ans[i][j] == '.') continue;
      if (ans[i][j] == 'X') {
        rep(x, n) {
          if (ans[x][j] != '.' && ans[x][j] != 'X') {
            mem[ans[x][j] - 'A'] = true;
          }
        }
        rep(y, n) {
          if (ans[i][y] != '.' && ans[i][y] != 'X') {
            mem[ans[i][y] - 'A'] = true;
          }
        }
        int poss = 0;
        int idx = 0;
        rep(a, 3) {
          if (!mem[a]) {
            poss++;
            idx = a;
          }
        }
        if (poss == 0) return false;
        if (poss == 1) {
          ans[i][j] = 'A' + idx;
        }
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      vector<bool> mem(3, false);
      if (ans[i][j] == '.') continue;
      if (ans[i][j] == 'X') {
        rep(x, n) {
          if (ans[x][j] != '.' && ans[x][j] != 'X') {
            mem[ans[x][j] - 'A'] = true;
          }
        }
        rep(y, n) {
          if (ans[i][y] != '.' && ans[i][y] != 'X') {
            mem[ans[i][y] - 'A'] = true;
          }
        }
        bool poss = false;
        rep(a, 3) {
          if (!mem[a]) {
            ans[i][j] = 'A' + a;
            poss = true;
            break;
          }
        }
        if (!poss) return false;
      }
    }
  }
  rep(i, n) {
    vector<int> mem(3, 0);
    rep(j, n) {
      if (ans[i][j] != '.') mem[ans[i][j] - 'A']++;
      if (mem[ans[i][j] - 'A'] > 1) return false;
    }
  }
  rep(j, n) {
    vector<int> mem(3, 0);
    rep(i, n) {
      if (ans[i][j] != '.') mem[ans[i][j] - 'A']++;
      if (mem[ans[i][j] - 'A'] > 1) return false;
    }
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;

  cin >> r >> c;

  ds.assign(n * n, 0);
  rep2(i, n * n - 3 * n, n * n) ds[i] = 1;
  do {
    if (solve()) {
      out("Yes");
      for (auto as : ans) {
        for (auto a : as) {
          cout << a;
        }
        cout << endl;
      }
      return 0;
    }
  } while (next_permutation(all(ds)));
  out("No");
}
