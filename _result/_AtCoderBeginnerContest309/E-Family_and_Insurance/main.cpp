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
int ans = 0;
vector<int> mem;
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  if (mem[v] > -1) ans++;
  for (auto next : G[v]) {
    if (!seen[next]) {
      mem[next] = max(mem[next], mem[v] - 1);
      dfs(G, next);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  Graph es(n);
  rep(i, n - 1) {
    int p;
    cin >> p;
    es[p - 1].push_back(i + 1);
  }
  mem.assign(n, -1);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    mem[x] = max(mem[x], y);
  }

  seen.assign(n, false);
  dfs(es, 0);
  out(ans);
}
