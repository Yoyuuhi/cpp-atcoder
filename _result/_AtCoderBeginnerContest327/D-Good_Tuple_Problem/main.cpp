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

  int n, m;
  cin >> n >> m;
  vector<int> as(m), bs(m);
  rep(i, m) cin >> as[i];
  rep(i, m) cin >> bs[i];

  dsu d(n);
  Graph g(n);
  rep(i, m) {
    int a = as[i] - 1;
    int b = bs[i] - 1;
    g[a].push_back(b);
    g[b].push_back(a);
    d.merge(a, b);
  }
  vector<int> mem(n, -1);
  vector<bool> passed(n, false);
  queue<int> que;

  rep(i, n) {
    int l = d.leader(i);
    if (passed[l]) continue;
    passed[l] = true;
    que.push(l);
  }

  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto to : g[now]) {
      if (mem[to] == -1) {
        mem[to] = (mem[now] + 1) % 2;
      } else if (mem[to] == mem[now]) {
        out("No");
        return 0;
      }
      if (!passed[to]) que.push(to);
      passed[to] = true;
    }
  }
  out("Yes");
}
