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

void warshall_floyd(vector<vector<long long>> &dist) {
  int V = dist.size();
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] == INFLL || dist[k][j] == INFLL) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
  vector<vector<ll>> dist(n, vector<ll>(n, INFLL));
  vector<vector<ll>> abcs;
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    dist[a][b] = c;
    dist[b][a] = c;
    abcs.push_back({a, b, c});
  }
  warshall_floyd(dist);

  int ans = 0;
  for (auto abc : abcs) {
    ll a = abc[0], b = abc[1], c = abc[2];
    if (dist[a][b] < c) {
      ans++;
      continue;
    }
    rep(i, n) {
      if (i == a || i == b) continue;
      if (dist[a][b] == dist[a][i] + dist[b][i]) {
        ans++;
        break;
      }
    }
  }
  out(ans);
}
