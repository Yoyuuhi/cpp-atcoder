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
};
using Graph = vector<vector<Edge>>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;

  Graph g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(Edge{v});
    g[v].push_back(Edge{u});
  }

  vector<bool> passed(n, false);
  vector<int> ans;
  vector<int> SS;
  rep(i, n) {
    if (g[i].size() == 1) {
      SS.push_back(i);
    }
  }
  int idx = 0;
  while (idx < SS.size()) {
    int s = SS[idx];
    idx++;
    if (passed[s]) continue;
    int t;
    int ta = 0;
    for (auto tt : g[s]) {
      if (!passed[tt.to]) t = tt.to;
    }

    passed[t] = true;
    for (auto to : g[t]) {
      if (!passed[to.to]) {
        passed[to.to] = true;
        ta++;

        for (auto tt : g[to.to]) {
          if (!passed[tt.to]) SS.push_back(tt.to);
        }
      }
    }
    ans.push_back(ta);
  }

  sort(all(ans));
  cout << ans[0];
  rep2(i, 1, ans.size()) cout << " " << ans[i];
  cout << endl;
}
