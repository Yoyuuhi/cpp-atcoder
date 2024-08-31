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

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator()
      : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) {  // [a, b)
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) {  // [0, b)
    return (*this)(0, b);
  }
};

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
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

  int n, m;
  cin >> n >> m;

  vector<vector<ll>> uvt;
  vector<vector<ll>> dist(n, vector<ll>(n, INFLL));

  rep(i, m) {
    int u, v;
    ll t;
    cin >> u >> v >> t;
    u--;
    v--;
    uvt.push_back({u, v, t});
    dist[u][v] = min(dist[u][v], t);
    dist[v][u] = min(dist[v][u], t);
  }
  rep(i, n) dist[i][i] = 0;
  warshall_floyd(dist);

  int q;
  cin >> q;
  rep(I, q) {
    int k;
    cin >> k;
    auto bs = nis(k);
    sort(all(bs));
    rep(i, k) bs[i]--;

    ll ans = INFLL;
    do {
      vector<vector<ll>> dp(k, vector<ll>(2, INFLL));
      int i = bs[0];
      int u = uvt[i][0], v = uvt[i][1], t = uvt[i][2];

      dp[0][0] = dist[0][v] + t;
      dp[0][1] = dist[0][u] + t;
      rep(i, k - 1) {
        int i0 = bs[i];
        int ii = bs[i + 1];
        int u0 = uvt[i0][0], v0 = uvt[i0][1], t0 = uvt[i0][2];
        int u1 = uvt[ii][0], v1 = uvt[ii][1], t1 = uvt[ii][2];

        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + dist[u0][v1] + t1);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + dist[v0][v1] + t1);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + dist[u0][u1] + t1);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + dist[v0][u1] + t1);
      }

      int i1 = bs[k - 1];
      int u1 = uvt[i1][0], v1 = uvt[i1][1], t0 = uvt[i1][2];

      ans = min(ans, dp[k - 1][0] + dist[u1][n - 1]);
      ans = min(ans, dp[k - 1][1] + dist[v1][n - 1]);
    } while (next_permutation(all(bs)));

    out(ans);
  }
}
