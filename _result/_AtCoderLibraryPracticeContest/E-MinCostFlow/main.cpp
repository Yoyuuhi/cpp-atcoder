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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  vector<ll> ax[n];
  rep(i, n) {
    rep(j, n) {
      ll a;
      cin >> a;
      ax[i].push_back(a);
    }
  }
  ll ma = 1000000000;

  mcf_graph<ll, ll> mcf(2 * n + 2);
  int s = 2 * n;
  int t = 2 * n + 1;
  rep(i, n) {
    rep(j, n) { mcf.add_edge(i, n + j, 1, ma - ax[i][j]); }
  }
  rep(i, n) {
    mcf.add_edge(s, i, k, 0);
    mcf.add_edge(n + i, t, k, 0);
  }
  mcf.add_edge(s, t, ma, ma);

  ll ans = 0;
  mcf.flow(s, t, n * k);
  vector<vector<char>> ansx(n, vector<char>(n, '.'));
  for (auto edge : mcf.edges()) {
    if (edge.from == s || edge.to == t || edge.flow == 0) {
      continue;
    }
    int i = edge.from;
    int j = edge.to - n;
    ansx[i][j] = 'X';
    ans += ma - edge.cost;
  }
  out(ans);
  rep(i, n) {
    rep(j, n) { cout << ansx[i][j]; }
    out("");
  }
}
