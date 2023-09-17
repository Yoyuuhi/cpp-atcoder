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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  ll a0, a1;
  cin >> a0 >> a1;

  vector<ll> as(n - 2);
  rep(i, n - 2) cin >> as[i];
  sort(all(as));

  n -= 2;
  ll ans = INF;
  for (int i = 0; i + m - 1 < n; i++) {
    int l = as[i];
    int r = as[i + m - 1];
    ll ta = 0;
    ta += max(ll(0), a0 - l);
    ta += max(ll(0), r - a1);
    ans = min(ans, ta);
  }
  out(ans);
}
