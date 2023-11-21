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
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

struct Edge {
  long long to;
  long long cost;
};
struct EN {
  long long from;
  long long to;
  long long cost;
  long long num;
};

using Graph = vector<vector<Edge>>;

vector<ll> mem;
void dfs(const Graph &G, int v) {
  for (auto next : G[v]) {
    if (mem[next.to] == INFLL) {
      mem[next.to] = mem[v] + next.cost;
      dfs(G, next.to);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, q;
  cin >> n >> q;
  Graph g(n);
  dsu ds(n + 1);
  queue<EN> qe;

  vector<int> ans;
  rep(i, q) {
    int a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    if (!ds.same(a, b)) {
      ds.merge(a, b);
      g[b].push_back({a, d});
      g[a].push_back({b, -d});
      ans.push_back(i + 1);
    } else {
      qe.push({b, a, d, i + 1});
    }
  }

  mem.assign(n, INFLL);
  rep(i, n) {
    if (mem[i] != INFLL) continue;
    mem[i] = 0;
    dfs(g, i);
  }

  while (!qe.empty()) {
    auto e = qe.front();
    qe.pop();
    if (mem[e.from] + e.cost == mem[e.to]) ans.push_back(e.num);
  }
  sort(all(ans));
  outs(ans);
}
