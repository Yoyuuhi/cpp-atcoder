#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (!seen[next]) {
      dfs(G, next);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll h, w;
  cin >> h >> w;
  vector<string> ax(h);
  rep(i, h) cin >> ax[i];
  ll n;
  cin >> n;

  Graph g(40001);
  ll s = -1, t = -1;
  rep(i, h) {
    rep(j, w) {
      if (ax[i][j] == 'S') s = i * w + j;
      if (ax[i][j] == 'T') t = i * w + j;
    }
  }

  vector<pair<int, int>> vs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  rep(i, n) {
    int R, C, E;
    cin >> R >> C >> E;
    R--;
    C--;

    vector<bool> seenXY(40001, false);
    queue<vector<int>> que;
    que.push({R, C, E});
    while (!que.empty()) {
      int r = que.front()[0], c = que.front()[1], e = que.front()[2];
      que.pop();
      if (seenXY[r * w + c] || e == 0) continue;
      seenXY[r * w + c] = true;
      for (auto v : vs) {
        int rr = r + v.first, cc = c + v.second, ee = e - 1;
        if (rr < 0 || rr >= h || cc < 0 || cc >= w || ax[rr][cc] == '#')
          continue;
        que.push({rr, cc, ee});
        g[R * w + C].push_back(rr * w + cc);
      }
    }
  }

  seen.assign(40001, false);
  dfs(g, s);
  cout << (seen[t] ? "Yes" : "No") << endl;
}
