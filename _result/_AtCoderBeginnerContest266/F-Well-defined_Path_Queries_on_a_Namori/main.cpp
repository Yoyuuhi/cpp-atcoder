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

using Graph = vector<vector<int>>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  Graph g(n);
  vector<int> ind(n, 0);
  rep(i, n) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    ind[u]++;
    ind[v]++;
  }

  queue<int> que;
  rep(i, n) {
    if (ind[i] == 1) que.push(i);
  }
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    ind[now]--;
    for (auto e : g[now]) {
      if (!ind[e]) continue;
      ind[e]--;
      if (ind[e] == 1) {
        que.push(e);
      }
    }
  }

  dsu d(n);
  rep(i, n) {
    if (ind[i]) continue;
    for (auto e : g[i]) {
      if (!ind[e]) d.merge(e, i);
    }
  }

  for (auto e : ind) {
    DBG(e);
  }

  vector<int> mem(n, -1);
  rep(i, n) {
    if (!ind[i]) continue;
    for (auto e : g[i]) {
      if (!ind[e]) mem[d.leader(e)] = i;
    }
  }

  int q;
  cin >> q;
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (d.same(x, y)) {
      out("Yes");
      continue;
    }
    if (mem[d.leader(x)] == y || mem[d.leader(y)] == x ||
        mem[d.leader(x)] == mem[d.leader(y)] && mem[d.leader(x)] != -1) {
      out("Yes");
      continue;
    }
    out("No");
  }
}
