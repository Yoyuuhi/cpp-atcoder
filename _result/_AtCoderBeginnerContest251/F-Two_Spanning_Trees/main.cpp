#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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
      cout << v << ' ' << next << endl;
    }
  }
}

void bfs(const Graph &G, int v) {
  seen[v] = true;
  vector<int> stack;
  stack.push_back(v);
  while (stack.size() > 0) {
    int from = stack[stack.size() - 1];
    stack.pop_back();
    for (auto to : G[from]) {
      if (!seen[to]) {
        seen[to] = true;
        stack.push_back(to);
        cout << from << ' ' << to << endl;
      }
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  Graph g(n + 1);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  seen.assign(n + 1, false);
  dfs(g, 1);
  seen.assign(n + 1, false);
  bfs(g, 1);
}
