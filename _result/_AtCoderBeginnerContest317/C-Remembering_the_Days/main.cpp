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

struct Edge {
  int to;
  int cost;
};
using Graph = vector<vector<Edge>>;
Graph g;

vector<bool> passed;
ll dfs(int now) {
  passed[now] = true;
  ll ans = 0;
  for (auto e : g[now]) {
    if (passed[e.to]) continue;
    ans = max(ans, e.cost + dfs(e.to));
  }
  passed[now] = false;
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  g.resize(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  ll ans = 0;
  rep(i, n) {
    passed.assign(n, false);
    ans = max(ans, dfs(i));
  }
  out(ans);
}
