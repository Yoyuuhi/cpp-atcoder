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

using Graph = vector<vector<int>>;

vector<int> seen1, seen2;
void dfs(const Graph &G, int v, vector<int> &seen) {
  for (auto next : G[v]) {
    if (seen[next] == -1) {
      seen[next] = seen[v] + 1;
      dfs(G, next, seen);
    }
  }
}

int n, u, v;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> u >> v;
  u--;
  v--;
  Graph g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  seen1.assign(n, -1);
  seen1[u] = 0;
  dfs(g, u, seen1);
  seen2.assign(n, -1);
  seen2[v] = 0;
  dfs(g, v, seen2);

  int ans = 0;
  rep(i, n) {
    int dis1 = seen1[i];
    int dis2 = seen2[i];
    if (dis1 >= dis2) continue;
    ans = max(ans, dis2 - 1);
  }
  out(ans);
}
