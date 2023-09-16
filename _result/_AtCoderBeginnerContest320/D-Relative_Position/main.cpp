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
  ll to;
  ll x;
  ll y;
};
using Graph = vector<vector<Edge>>;
vector<vector<ll>> mem;
vector<bool> seen;

void dfs(const Graph &G, ll v, ll x, ll y) {
  seen[v] = true;
  mem[v] = vector<ll>{x, y};
  for (auto next : G[v]) {
    if (!seen[next.to]) {
      dfs(G, next.to, x + next.x, y + next.y);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  // dsu d(n);
  Graph g(n);

  rep(i, m) {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    a--;
    b--;
    // d.merge(a, b);
    g[a].push_back({b, x, y});
    g[b].push_back({a, -x, -y});
  }

  seen.assign(n, false);
  mem.resize(n);
  mem[0] = vector<ll>{0, 0};
  dfs(g, 0, 0, 0);
  rep(i, n) {
    if (!mem[i].size()) {
      out("undecidable");
    } else {
      cout << mem[i][0] << ' ' << mem[i][1] << endl;
    }
  }
}
