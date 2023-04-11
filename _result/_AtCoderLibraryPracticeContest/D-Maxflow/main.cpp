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
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
bool isA(int i, int j) { return i % 2 == 0 ? j % 2 == 1 : j % 2 == 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  string sx[n];
  rep(i, n) { cin >> sx[i]; }

  mf_graph<int> mfg(n * m + 2);
  int s = n * m;
  int t = n * m + 1;
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  rep(i, n) {
    rep(j, m) {
      if (sx[i][j] == '#') {
        continue;
      }

      int u = i * m + j;
      if (isA(i, j)) {
        mfg.add_edge(u, t, 1);
        continue;
      }

      mfg.add_edge(s, u, 1);
      for (auto dir : dirs) {
        int ii = i + dir.first;
        int jj = j + dir.second;
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
          continue;
        }
        if (sx[ii][jj] == '#') {
          continue;
        }
        int v = ii * m + jj;
        mfg.add_edge(u, v, 1);
      }
    }
  }

  int maxFlow = mfg.flow(s, t);
  for (auto edge : mfg.edges()) {
    if (edge.from == s || edge.to == t || edge.flow == 0) {
      continue;
    }

    int ui = edge.from / m;
    int uj = edge.from % m;
    int vi = edge.to / m;
    int vj = edge.to % m;
    if (uj == vj) {
      if (ui < vi) {
        sx[ui][uj] = 'v';
        sx[vi][vj] = '^';
      } else {
        sx[vi][vj] = 'v';
        sx[ui][uj] = '^';
      }
    } else {
      if (uj < vj) {
        sx[ui][uj] = '>';
        sx[vi][vj] = '<';
      } else {
        sx[vi][vj] = '>';
        sx[ui][uj] = '<';
      }
    }
  }
  out(maxFlow);
  rep(i, n) { out(sx[i]); }
}
