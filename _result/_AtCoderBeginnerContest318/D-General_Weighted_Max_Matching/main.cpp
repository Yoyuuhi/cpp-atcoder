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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<vector<ll>> dx(n, vector<ll>(n));
  rep(i, n - 1) {
    rep(j, n - 1 - i) {
      ll d;
      cin >> d;

      int a = i;
      int b = i + 1 + j;
      dx[a][b] = d;
      dx[b][a] = d;
    }
  }

  int bit = 0;
  ll ans = 0;
  while (bit < (1 << n)) {
    vector<int> sel;
    vector<int> rest;
    rep(i, n) {
      if (!(bit & (1 << i))) {
        rest.push_back(i);
      } else {
        sel.push_back(i);
      }
    }
    if (sel.size() != n / 2) {
      bit++;
      continue;
    }

    ll ma = 1000000000;

    mcf_graph<ll, ll> g(n + 2);
    int s = n;
    int t = n + 1;

    for (auto a : sel) {
      for (auto b : rest) {
        g.add_edge(a, b, 1, ma - dx[a][b]);
      }
    }
    for (auto a : sel) {
      g.add_edge(s, a, 1, 0);
    }
    for (auto b : rest) {
      g.add_edge(b, t, 1, 0);
    }

    auto a = g.flow(s, t);
    ans = max(ans, ma * a.first - a.second);

    bit++;
  }
  out(ans);
}
