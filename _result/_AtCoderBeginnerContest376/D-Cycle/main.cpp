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
using P = pair<long, int>;

int ans = INF;
void bfs(const Graph &G, int v) {
  int N = G.size();
  vector<long long> dis;
  dis.resize(N, INF);
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[v] = 0;
  pq.emplace(dis[v], v);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int from = p.second;
    if (dis[from] < p.first) {
      continue;
    }

    for (auto to : G[from]) {
      if (to == v) {
        ans = min(ans, int(dis[from] + 1));
      }

      for (auto &e : G[from]) {
        if (dis[to] > dis[from] + 1) {
          dis[to] = dis[from] + 1;
          pq.emplace(dis[to], to);
        }
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

  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }

  bfs(g, 0);
  if (ans == INF) {
    out(-1);
  } else {
    out(ans);
  }
}
