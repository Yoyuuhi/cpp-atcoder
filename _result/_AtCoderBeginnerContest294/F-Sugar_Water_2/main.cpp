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

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> as(n), bs(n), cs(m), ds(m);
  rep(i, n) cin >> as[i] >> bs[i];
  rep(i, m) cin >> cs[i] >> ds[i];

  double ng = 0, ok = 1;
  rep(i, 100) {
    double mid = (ng + ok) / 2;
    double z = mid / (1 - mid);
    vector<double> vs(m);
    rep(j, m) vs[j] = cs[j] - ds[j] * z;
    sort(all(vs));

    ll num = 0;
    rep(j, n) {
      double w = as[j] - bs[j] * z;
      num += m - (lower_bound(all(vs), -w) - begin(vs));
    }
    (num < k ? ok : ng) = mid;
  }
  cout << fixed << setprecision(16) << ok * 100 << endl;
}
