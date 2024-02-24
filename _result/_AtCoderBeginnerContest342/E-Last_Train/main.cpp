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

struct Edge {
  ll l;
  ll d;
  ll k;
  ll c;
  ll to;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
vector<vector<ll>> mem;
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
  int N = G.size();
  dis.resize(N, -INFLL);
  priority_queue<P, vector<P>, less<P>> pq;
  dis[s] = INFLL;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] > p.first) {
      continue;
    }
    for (auto &e : G[v]) {
      auto t = p.first;
      auto to = e.to;

      ll l = e.l, d = e.d, k = e.k, c = e.c;
      if (l + c > t) continue;
      ll times = (t - c - l) / d;
      times = min(times, k - 1);
      auto t0 = l + times * d;

      if (dis[e.to] < t0) {
        dis[e.to] = t0;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    ll l, d, k, c, a, b;
    cin >> l >> d >> k >> c >> a >> b;
    a--;
    b--;
    g[b].push_back({l, d, k, c, a});
  }

  vector<ll> dis;
  dijkstra(g, n - 1, dis);
  rep(i, n - 1) {
    if (dis[i] == -INFLL) {
      out("Unreachable");
    } else {
      out(dis[i]);
    }
  }
}
