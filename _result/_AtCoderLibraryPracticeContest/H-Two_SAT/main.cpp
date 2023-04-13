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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, d;
  cin >> n >> d;
  two_sat ts(n);
  ll xs[n], ys[n];
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xs[i] = x;
    ys[i] = y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll d1 = abs(xs[i] - xs[j]);
      ll d2 = abs(xs[i] - ys[j]);
      ll d3 = abs(ys[i] - xs[j]);
      ll d4 = abs(ys[i] - ys[j]);
      if (d1 < d) ts.add_clause(i, true, j, true);
      if (d2 < d) ts.add_clause(i, true, j, false);
      if (d3 < d) ts.add_clause(i, false, j, true);
      if (d4 < d) ts.add_clause(i, false, j, false);
    }
  }

  if (!ts.satisfiable()) {
    out("No");
    return 0;
  }
  out("Yes");
  std::vector<bool> ans = ts.answer();
  rep(i, n) {
    if (!ans[i]) {
      out(xs[i]);
    } else {
      out(ys[i]);
    }
  }
}
