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

ll calc(vector<vector<int>> xpcs) {
  ll ans = 0;
  vector<ll> ps;
  for (auto xpc : xpcs) ps.push_back(xpc[1]);
  sort(all(ps));
  map<int, int> mapP;
  rep(i, ps.size()) mapP[ps[i]] = i + 1;

  fenwick_tree<ll> cCount(ps.size() + 1);
  rep(i, ps.size()) cCount.add(i + 1, 1);
  rep(i, xpcs.size()) {
    int p = xpcs[i][1];
    ans += cCount.sum(0, mapP[p]);
    cCount.add(mapP[p], -1);
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> cs(n);
  rep(i, n) cin >> cs[i];
  vector<int> xs(n);
  rep(i, n) cin >> xs[i];

  vector<vector<int>> xpcs(n);
  rep(i, n) xpcs[i] = {xs[i], i, cs[i]};
  sort(all(xpcs));

  ll ans = calc(xpcs);
  vector<vector<vector<int>>> txpcs(n + 1);
  for (auto xpc : xpcs) {
    int c = xpc[2];
    txpcs[c].push_back(xpc);
  }
  for (auto txpc : txpcs) ans -= calc(txpc);
  out(ans);
}
