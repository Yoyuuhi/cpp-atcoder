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

  ll n, m;
  cin >> n >> m;
  vector<ll> as(n);
  rep(i, n) cin >> as[i];
  sort(all(as));

  vector<ll> mem(n, 0);
  rep2(i, 1, n) {
    mem[i] += mem[i - 1];
    mem[i] += as[i] - as[i - 1];
  }

  ll ans = 0;
  rep(i, n) {
    ll s = mem[i];
    ll t = s + m;
    int idx = lower_bound(all(mem), t) - mem.begin();
    ans = max(ans, ll(idx - i));
  }
  out(ans);
}
