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

int h, w;
vector<string> ax;
bool poss(int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w;
  ax.resize(h);
  rep(i, h) cin >> ax[i];
  vector<string> mem = ax;

  int sx, sy;
  rep(i, h) {
    rep(j, w) {
      if (ax[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (ax[i][j] == '#') {
        mem[i][j] = 'x';
      }
      if (ax[i][j] == '>') {
        mem[i][j] = 'x';
        int k = j + 1;
        while (k < w &&
               (ax[i][k] == '.' || ax[i][k] == 'S' || ax[i][k] == 'G')) {
          mem[i][k] = 'x';
          k++;
        }
      }
      if (ax[i][j] == 'v') {
        mem[i][j] = 'x';
        int k = i + 1;
        while (k < h &&
               (ax[k][j] == '.' || ax[k][j] == 'S' || ax[k][j] == 'G')) {
          mem[k][j] = 'x';
          k++;
        }
      }
      if (ax[i][j] == '<') {
        mem[i][j] = 'x';
        int k = j - 1;
        while (k >= 0 &&
               (ax[i][k] == '.' || ax[i][k] == 'S' || ax[i][k] == 'G')) {
          mem[i][k] = 'x';
          k--;
        }
      }
      if (ax[i][j] == '^') {
        mem[i][j] = 'x';
        int k = i - 1;
        while (k >= 0 &&
               (ax[k][j] == '.' || ax[k][j] == 'S' || ax[k][j] == 'G')) {
          mem[k][j] = 'x';
          k--;
        }
      }
    }
  }

  vector<vector<int>> memd(h, vector<int>(w, INF));
  memd[sx][sy] = 0;
  queue<vector<int>> que;
  que.push({sx, sy});
  vector<vector<int>> vs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while (!que.empty()) {
    vector<int> now = que.front();
    que.pop();
    for (auto v : vs) {
      int xx = now[0] + v[0];
      int yy = now[1] + v[1];
      if (!poss(xx, yy) || memd[xx][yy] != INF || mem[xx][yy] == 'x') continue;
      memd[xx][yy] = memd[now[0]][now[1]] + 1;
      if (mem[xx][yy] == 'G') {
        out(memd[xx][yy]);
        return 0;
      }
      que.push({xx, yy});
    }
  }
  out(-1);
}
