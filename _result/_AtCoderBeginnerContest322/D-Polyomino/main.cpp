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

vector<vector<int>> mem;

vector<vector<char>> rotate(vector<vector<char>>& matrix) {
  int n = matrix.size();
  vector<vector<char>> rotated(n, vector<char>(n, ' '));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  return rotated;
}

bool solve(vector<vector<vector<char>>>& px, vector<int> ds) {
  mem.assign(4, vector<int>(4, false));
  for (auto d : ds) {
    int ii, jj;
    bool find = false;
    rep(i, 4) {
      if (find) break;
      rep(j, 4) {
        if (find) break;
        if (px[d][i][j] == '#') {
          ii = i;
          jj = j;
          find = true;
        }
      }
    }
    int ii1, jj1;
    find = false;
    rep(i, 4) {
      if (find) break;
      rep(j, 4) {
        if (find) break;
        if (mem[i][j] == false) {
          ii1 = i;
          jj1 = j;
          find = true;
        }
      }
    }

    int i0 = ii1 - ii;
    int j0 = jj1 - jj;
    rep(i, 4) {
      rep(j, 4) {
        if (px[d][i][j] != '#') continue;
        int ii = i + i0;
        int jj = j + j0;
        if (!(ii >= 0 && ii < 4 && jj >= 0 && jj < 4)) return false;
        if (mem[ii][jj]) return false;
        mem[ii][jj] = true;
      }
    }
  }
  return true;
}

bool solves(vector<vector<vector<char>>>& px) {
  vector<int> ds = {0, 1, 2};
  do {
    if (solve(px, ds)) return true;
  } while (next_permutation(all(ds)));
  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  vector<vector<vector<char>>> px(3);
  rep(i, 3) {
    vector<vector<char>> ps(4, vector<char>(4));
    rep(j, 4) rep(k, 4) cin >> ps[j][k];
    px[i] = ps;
  }

  int count = 0;
  rep(i, 3) {
    rep(ii, 4) {
      rep(jj, 4) {
        if (px[i][ii][jj] == '#') count++;
      }
    }
  }
  if (count != 16) {
    out("No");
    return 0;
  }

  rep(i, 4) {
    px[0] = rotate(px[0]);
    rep(j, 4) {
      px[1] = rotate(px[1]);
      rep(k, 4) {
        px[2] = rotate(px[2]);
        if (solves(px)) {
          out("Yes");
          return 0;
        }
      }
    }
  }
  out("No");
}
