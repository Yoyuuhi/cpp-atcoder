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
T pow(T x, T n) {
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
int c;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  c++;
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

  int n;
  cin >> n;
  Graph g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  seen.assign(n, false);
  seen[0] = true;
  if (g[0].size() == 1) {
    out(1);
    return 0;
  }

  vector<ll> mem;
  for (auto to : g[0]) {
    c = 0;
    dfs(g, to);
    mem.push_back(c);
  }
  sort(all(mem));
  ll ans = 0;
  for (auto m : mem) ans += m;
  ans -= mem[mem.size() - 1];

  out(ans + 1);
}
