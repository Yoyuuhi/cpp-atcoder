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

int main()
{
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w;
  cin >> h >> w;
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];

  int sx = -1, sy = -1, gx = -1, gy = -1;
  rep(i, h)
      rep(j, w)
  {
    if (ss[i][j] == 'S')
    {
      sx = i;
      sy = j;
    }

    if (ss[i][j] == 'G')
    {
      gx = i;
      gy = j;
    }
  }

  vector<vector<vector<int>>> vs = {
      {{-1, 0},
       {1, 0}},
      {{0, -1},
       {0, 1}}};

  vector<vector<vector<int>>> mem(h, vector<vector<int>>(w, vector<int>(2, -1)));
  mem[sx][sy][0] = 0, mem[sx][sy][1] = 0;
  queue<pair<int, int>> que;
  que.push({0, sx * w + sy});
  que.push({1, sx * w + sy});
  while (!que.empty())
  {
    int flag = (que.front().first + 1) % 2, now = que.front().second;
    que.pop();
    int x = now / w, y = now % w;
    auto tvs = vs[flag];

    for (auto v : tvs)
    {
      int xx = x + v[0], yy = y + v[1];
      if (!(xx >= 0 && xx < h && yy >= 0 && yy < w))
        continue;
      if (mem[xx][yy][flag] != -1 || ss[xx][yy] == '#')
        continue;
      mem[xx][yy][flag] = mem[x][y][(flag + 1) % 2] + 1;
      if (ss[xx][yy] == 'G')
      {
        out(mem[xx][yy][flag]);
        return 0;
      }

      auto next = xx * w + yy;
      que.push({flag, next});
    }
  }

  int ans = INF;
  if (mem[gx][gy][0] != -1)
    ans = min(ans, mem[gx][gy][0]);
  if (mem[gx][gy][1] != -1)
    ans = min(ans, mem[gx][gy][1]);
  if (ans != INF)
  {
    out(ans);
    return 0;
  }
  out(-1);
}
