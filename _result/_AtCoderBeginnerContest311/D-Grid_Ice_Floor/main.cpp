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
  int n, m;
  cin >> n >> m;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  vector<pair<int, int>> vs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  set<vector<int>> seen;
  queue<pair<int, int>> que;
  vector<vector<bool>> mem(n, vector<bool>(m, false));
  mem[1][1] = true;
  que.push({1, 1});
  while (!que.empty()) {
    pair<int, int> now = que.front();
    que.pop();

    rep(i, 4) {
      if (seen.find({now.first, now.second, i}) != seen.end()) continue;
      seen.insert({now.first, now.second, i});
      auto v = vs[i];
      pair<int, int> tnow = now;
      while (ss[tnow.first + v.first][tnow.second + v.second] != '#') {
        tnow = {tnow.first + v.first, tnow.second + v.second};
        mem[tnow.first][tnow.second] = true;
      }
      if (tnow != now) seen.insert({tnow.first, tnow.second, (i + 2) % 4});
      que.push(tnow);
    }
  }

  int ans = 0;
  rep(i, n) {
    rep(j, m) {
      if (mem[i][j]) ans++;
    }
  }
  out(ans);
}
