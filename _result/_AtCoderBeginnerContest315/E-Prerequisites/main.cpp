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
  Graph g(n + 1);
  rep(i, n) {
    int c;
    cin >> c;
    rep(j, c) {
      int p;
      cin >> p;
      g[i + 1].push_back({p});
    }
  }

  vector<int> ind(n + 1, 0);
  queue<int> que;
  vector<bool> passed(n + 1, false);
  que.push(1);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto e : g[now]) {
      if (!passed[e.to]) que.push(e.to);
      passed[e.to] = true;
      ind[e.to]++;
    }
  }

  que.push(1);
  vector<int> ans;
  while (!que.empty()) {
    int now = que.front();
    ans.push_back(now);
    que.pop();
    for (auto e : g[now]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        que.push(e.to);
      }
    }
  }
  for (int i = ans.size() - 1; i > 0; i--) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
