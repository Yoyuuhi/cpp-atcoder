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
const ll INF = numeric_limits<ll>::max() / 2;

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;

void dijkstra(const Graph &G, ll s, vector<ll> &dis) {
  ll N = G.size();
  dis.resize(N, INF);
  priority_queue<P, vector<P>, greater<P>>
      pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    ll v = p.second;
    if (dis[v] < p.first) {  // 最短距離で無ければ無視
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] >
          dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<vector<ll>> dx(n, vector<ll>(n));
  rep(i, n) { rep(j, n) cin >> dx[i][j]; }

  vector<vector<ll>> dx1(n, vector<ll>(n));
  rep(i, n) { rep(j, n) dx1[i][j] = dx[i][j] * a; }
  vector<vector<ll>> dx2(n, vector<ll>(n));
  rep(i, n) { rep(j, n) dx2[i][j] = dx[i][j] * b + c; }

  Graph g1(n);
  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;
      auto c = dx1[i][j];
      g1[i].push_back({j, c});
    }
  }
  Graph g2(n);
  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;
      auto c = dx2[i][j];
      g2[i].push_back({j, c});
    }
  }

  vector<long long> dis11, dis21, dis22;
  dijkstra(g1, 0, dis11);
  dijkstra(g2, 0, dis21);
  dijkstra(g2, n - 1, dis22);

  ll ans = min(dis11[n - 1], dis21[n - 1]);
  rep2(i, 1, n - 1) { ans = min(ans, dis11[i] + dis22[i]); }
  out(ans);
}
