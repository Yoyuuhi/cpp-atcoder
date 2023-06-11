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
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m, k;
  cin >> n >> m >> k;
  Graph g(n);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    g[s].push_back(Edge{t, 1});
    g[t].push_back(Edge{s, 1});
  }
  vector<long long> dis;
  int N = g.size();
  dis.resize(N, -1);
  priority_queue<P, vector<P>, less<P>> pq;
  set<int> ans;
  rep(i, k) {
    int p, h;
    cin >> p >> h;
    p--;
    pq.emplace(h, p);
    ans.insert(p);
    dis[p] = h;
  }

  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;

    if (dis[v] > p.first) continue;
    for (auto &e : g[v]) {
      if (dis[e.to] < dis[v] - e.cost) {
        dis[e.to] = dis[v] - e.cost;
        pq.emplace(dis[e.to], e.to);
        ans.insert(e.to);
      }
    }
  }
  out(ans.size());
  for (auto itr = ans.begin(); itr != ans.end(); itr++) {
    if (itr != ans.begin()) cout << " ";
    cout << *itr + 1;
  }
  cout << endl;
}
