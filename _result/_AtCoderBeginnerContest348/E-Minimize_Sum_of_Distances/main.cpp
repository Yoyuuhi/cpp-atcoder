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
vector<ll> nis(T n) {
  vector<ll> ret(n);
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
ll sum = 0;
ll ans = INFLL;
vector<ll> mem;
vector<ll> cs;
ll sumc = 0;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (!seen[next]) {
      dfs(G, next);
      mem[v] += mem[next];
      mem[v] += cs[next];
    }
  }
  sum += mem[v];
}

void calc(const Graph &G, int v) {
  ans = min(ans, sum);
  seen[v] = true;
  for (auto next : G[v]) {
    if (!seen[next]) {
      auto diff = -mem[next] - cs[next] + (sumc - mem[next] - cs[next]);
      sum += diff;
      calc(G, next);
      sum -= diff;
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
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cs = nis(n);
  for (auto c : cs) sumc += c;

  seen.assign(n, false);
  mem.assign(n, 0);
  dfs(g, 0);

  seen.assign(n, false);
  calc(g, 0);
  out(ans);
}
