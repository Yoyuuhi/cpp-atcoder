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
vector<bool> mem;

struct P {
  ll depth;
  ll idx;
};

P lp;
vector<bool> seen;
vector<bool> memTo;
bool dfs(const Graph &G, int v) {
  seen[v] = true;
  bool toV = false;
  for (auto next : G[v]) {
    if (seen[next]) continue;
    if (dfs(G, next)) toV = true;
  }

  memTo[v] = toV || mem[v];
  return memTo[v];
}

void findS(const Graph &G, int v, int depth) {
  seen[v] = true;
  int count = 0;
  for (auto next : G[v]) {
    if (!seen[next]) {
      if (memTo[next]) count++;
      findS(G, next, depth + 1);
    }
  }

  if (count > 1 || mem[v]) {
    if (lp.depth > depth) {
      lp = P{depth, v};
    }
  }
}

int ans = 0;
void calc(const Graph &G, int v) {
  seen[v] = true;
  ans++;

  for (auto next : G[v]) {
    if (seen[next] || !memTo[next]) continue;
    calc(G, next);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  Graph g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  mem.assign(n + 1, false);
  rep(i, k) {
    int v;
    cin >> v;
    v--;
    mem[v] = true;
  }

  // 0 を起点に、下位に目標点の有無 memTo をマーク
  lp = P{INF, -1};
  seen.assign(n, false);
  memTo.assign(n, false);
  dfs(g, 0);

  // 最近共通祖先を探す
  seen.assign(n, false);
  findS(g, 0, 0);

  // LCP を起点に、下位に目標点の有無 memTo をマーク
  seen.assign(n, false);
  memTo.assign(n, false);
  dfs(g, lp.idx);

  // LCP を起点に、目標点までカウント
  seen.assign(n, false);
  calc(g, lp.idx);
  out(ans);
}
